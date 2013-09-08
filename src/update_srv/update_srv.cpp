//
// update_srv.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "update_srv.h"
#include "sha1.h"
#include "string_coding.h"
#include "protocol_events_handler.h"
#include "misc_language.h"
#include "storages/inmem_to_json.h"
#include "storages/serializeble_struct_helper.h"

#ifndef DEFINED_REGEXP_CRITICAL_SECTION
#define DEFINED_REGEXP_CRITICAL_SECTION
DEFINE_REGEXP_CRITICAL_SECTION();
#endif // DEFINED_REGEXP_CRITICAL_SECTION

namespace omaha {
namespace backend {

bool print_usage() {
#if defined (_MSC_VER)
  std::cout << "Usage: o_server /run_as_app true /config \"/usr/config.xml\" "
  << std::endl;
#else
  std::cout << "Usage: o_server /config \"/usr/config.xml\" " << std::endl;
#endif

  return true;
}

bool console_handler(omaha::backend::omaha_protol_server* psrv) {
  TRY_ENTRY();
  bool continue_handle = true;
  while (continue_handle) {
    char command_buff[400] = { 0 };
    std::string command;
    std::cin.getline(command_buff, 399);
    if (std::cin.eof() || std::cin.fail()) {
      LOG_PRINT("std::cin.eof() or std::cin.fail(), stopping...", LOG_LEVEL_0);
      psrv->send_stop_signal();
      continue_handle = false;
      break;
    }
    command = command_buff;

    if (!command.compare("exit") || !command.compare("q")) {
      psrv->send_stop_signal();
      continue_handle = false;
    } else {
      std::cout << "...Error: Unknown command: " << command << std::endl;
    }
  }
  return true;CATCH_ENTRY_L0("console_handler", false);
}

// Server entry
static int HttpServer::srv_test(int argc, char* argv[]) {
  TRY_ENTRY();
  string_tools::set_module_name_and_folder(argv[0]);

  std::map<std::string, std::string> cmd_params;
  string_tools::parce_commandline(cmd_params, argc, argv);

#if (defined _MSC_VER)
  if (cmd_params.end() != cmd_params.find("/run_as_app")) {
#endif
  //goes as application
  log_space::get_set_log_detalisation_level(true, LOG_LEVEL_2);
  log_space::log_singletone::add_logger(LOGGER_CONSOLE, NULL, NULL);
  log_space::log_singletone::add_logger(
      LOGGER_FILE, log_space::log_singletone::get_default_log_file().c_str(),
      log_space::log_singletone::get_default_log_folder().c_str());

  log_space::log_singletone::set_max_logfile_size(LOG_FILE_MAX_SIZE);

  LOG_PRINT("Omaha protocol server starting ...", LOG_LEVEL_0);

  omaha::backend::omaha_protol_server srv;

  boost::thread(boost::bind(console_handler, &srv));

  std::string config_path;
  if (!string_tools::get_xparam_from_command_line(cmd_params,
                                                  std::string("/config"),
                                                  config_path)) {
    config_path = string_tools::get_current_module_folder() + "\\"
    + OPS_DEFAULT_CONFIG_FILENAME;}

  LOG_PRINT("Initialaizing with config " << config_path, LOG_LEVEL_0);
  if (!srv.init(config_path)) {
    LOG_ERROR("Failed to initialize srv!");
    return 1;
  }

  srv.run();
  srv.deinit();

  LOG_PRINT("Demo server stoped.", LOG_LEVEL_0);
  return 1;
#if defined (_MSC_VER)
} else if (cmd_params.end() != cmd_params.find("/install"))
{
  log_space::log_singletone::get_set_log_detalisation_level(true,
      LOG_LEVEL_2);
  log_space::log_singletone::add_logger(LOGGER_CONSOLE, NULL, NULL);
  log_space::log_singletone::add_logger(LOGGER_DEBUGGER, NULL, NULL);
  omaha::backend::omaha_protol_server srv;
  srv.install();
} else if (cmd_params.end() != cmd_params.find("/uninstall"))
{
  log_space::log_singletone::get_set_log_detalisation_level(true,
      LOG_LEVEL_2);
  log_space::log_singletone::add_logger(LOGGER_CONSOLE, NULL, NULL);
  log_space::log_singletone::add_logger(LOGGER_DEBUGGER, NULL, NULL);
  omaha::backend::omaha_protol_server srv;
  srv.remove();
} else
{
  //running as windows service
  log_space::get_set_log_detalisation_level(true, LOG_LEVEL_2);
  log_space::log_singletone::add_logger( LOGGER_FILE,
      log_space::log_singletone::get_default_log_file().c_str(),
      log_space::log_singletone::get_default_log_folder().c_str());

  log_space::log_singletone::set_max_logfile_size(LOG_FILE_MAX_SIZE);

  LOG_PRINT("Omaha protocol server starting...", LOG_LEVEL_1);
  std::string conf_path = string_tools::get_current_module_folder() +
  "\\" + OPS_DEFAULT_CONFIG_FILENAME;
  omaha::backend::omaha_protol_server srv;
  if (!srv.init(conf_path))
  {
    LOG_PRINT("\nFailed to initialize server. Exit.", LOG_LEVEL_0);
    return 0;
  }
  LOG_PRINT("Initializing done!", LOG_LEVEL_0);

  LOG_PRINT("Running service...", LOG_LEVEL_0);
  srv.run_service();
  LOG_PRINT("Exiting", LOG_LEVEL_0);
  bool res = srv.deinit();
}
#endif

  CATCH_ENTRY_L0("main", 1);
}

//-----------------------------------------------------------------------------
bool omaha_protol_server::init(const std::string& config_path/*,
 const std::string& bind_port,
 const std::string& bind_ip*/) {
  LOG_PRINT_L0("[omaha_protol_server::init()]");
  m_config_file_stamp = 0;
  m_config_file_path = config_path;
  m_is_stop = 0;
  m_threads_count = 0;
  m_downloads_count = 0;

  if (!reload_config()) {
    LOG_ERROR("Failed to reload config. ");
    return false;
  }

  //in debug purpose
#ifdef _DEBUG
  std::string json_str;
  StorageNamed::InMemStorageSpace::json::store_t_to_json(m_hconfig, json_str);
#endif

  m_http_server.get_config_object().m_phandler = this;

  //m_threads_count = 0;// for future use
  LOG_PRINT_L0(
      "Binding on " << m_hconfig.global_settings.connection.bind_ip << ":" << m_hconfig.global_settings.connection.listen_port);

  return m_http_server.init_server(
      m_hconfig.global_settings.connection.listen_port,
      m_hconfig.global_settings.connection.bind_ip);
}
//-----------------------------------------------------------------------------
bool omaha_protol_server::reload_config() {
  LOG_PRINT_L0("[omaha_protol_server::reload_config()]");

  //get exclusive access
  boost::upgrade_lock<boost::shared_mutex> lock(m_config_lock);
  boost::upgrade_to_unique_lock<boost::shared_mutex> uniqueLock(lock);

  m_hconfig.application.clear();

  time_t ft(0);
  if (!file_io_utils::get_file_time(m_config_file_path, ft)) {
    LOG_ERROR("Failed to get time form config file from " << m_config_file_path);
    return false;
  }

  std::string text_buff;
  if (!file_io_utils::load_file_to_string(m_config_file_path, text_buff)) {
    LOG_ERROR("Failed to load config file from " << m_config_file_path);
    return false;
  }

  StorageNamed::InMemStorageSpace::xml::load_t_from_xml(m_hconfig, text_buff);
  if (!m_hconfig.application.size()) {
    LOG_ERROR("Failed to load xml from file " << m_config_file_path);
    return false;
  }

  LOG_PRINT_L0("Start config initialization ...");
  if (!extra_init_config()) {
    LOG_ERROR("Failed to init config " << m_config_file_path);
    return false;
  }
  m_http_server.get_config_object().m_folder = m_hconfig.global_settings.http
      .home;

  m_config_file_stamp = ft;
  LOG_PRINT_L0("Success done config initialization.");
  return true;
}

//-----------------------------------------------------------------------------
std::string omaha_protol_server::remove_protocol_from_url(
    const std::string& url_) {
  LOG_PRINT_L4("[omaha_protol_server::remove_protocol_from_url()]");
  std::string ress = url_;
  LOG_PRINT_L0("url: " << url_);
  std::string::difference_type off = ress.find("//");
  if (off != std::string::npos) {
    ress.erase(0, off + 2);
  }
  return ress;
}

//-----------------------------------------------------------------------------
bool omaha_protol_server::extra_init_config() {
  LOG_PRINT_L0("[omaha_protol_server::extra_init_config()]");
  if (!m_hconfig.application.size()) {
    LOG_ERROR("[CompatibilityTest]: No applications set.");
    return false;
  }

  for (std::list<omaha::server::config::application_entry>::iterator it =
      m_hconfig.application.begin(); it != m_hconfig.application.end(); ++it) {
    for (std::list<omaha::server::config::application_os>::iterator os_it = it
        ->os.begin(); os_it != it->os.end(); ++os_it) {

      for (std::list<omaha::transport::package_entity>::iterator pack_it = os_it
          ->public_release.manifest.packages.package.begin();
          pack_it != os_it->public_release.manifest.packages.package.end();
          ++pack_it) {

        /*
         a.sabelnikov: we wouldn't recalculate hash for entries, which don't have local path,
         to allow configuring URL with CDN or other hosting, which is not accessible from server filesystem.
         */

        if (!os_it->public_release.local_path.size()) {
          if (!pack_it->hash.size()) {
            LOG_ERROR(
                "No local path and no hash in app " << it->app_id << " " << it->app_name);
            return false;
          }
          LOG_PRINT_L0(
              "Skipping hashing of application " << it->app_id << " " << it->app_name);
        }

        boost::system::error_code ec;
        boost::uintmax_t sz = boost::filesystem::file_size(
            os_it->public_release.local_path + pack_it->name, ec);
        if (ec) {
          LOG_PRINT_L0(
              "[o_server]: At extra_init_config failed to read file size : " << os_it->public_release.local_path + pack_it->name);
          return false;
        }
        pack_it->size = boost::lexical_cast<std::string>(sz);

        LOG_PRINT_L0(
            "Calculating sha1 hash for " << os_it->public_release.local_path + pack_it->name);

        //TODO: THIS CODE SHOULD BE REWITED WITH RIGHT SHA1 LIB ------------
        std::string buff;
        if (!file_io_utils::load_file_to_string(
            os_it->public_release.local_path + pack_it->name, buff)) {
          LOG_PRINT_L0(
              "[o_server]: At extra_init_config failed to read file : " << os_it->public_release.local_path + pack_it->name);
          return false;
        }

        std::vector<unsigned char> hash_vector;
        hash_vector.resize(30, 0);
        sha1::calc((void*) buff.data(), buff.size(), &hash_vector[0]);
        std::string str_buff;
        str_buff.assign((const char*) &hash_vector[0], 20);
        pack_it->hash = string_encoding::base64_encode(str_buff);
        //------------------------------------------------------------------
      }
    }
  }

  for (std::list<omaha::server::config::application_entry>::const_iterator it =
      m_hconfig.application.begin(); it != m_hconfig.application.end(); ++it)
    for (std::list<omaha::server::config::application_os>::const_iterator os_it =
        it->os.begin(); os_it != it->os.end(); ++os_it)
      for (std::list<omaha::transport::url_entity>::const_iterator url_it =
          os_it->public_release.urls.url.begin();
          url_it != os_it->public_release.urls.url.end(); ++url_it)
        for (std::list<omaha::transport::package_entity>::const_iterator pack_it =
            os_it->public_release.manifest.packages.package.begin();
            pack_it != os_it->public_release.manifest.packages.package.end();
            ++pack_it) {
          m_uri_to_locals[remove_protocol_from_url(url_it->codebase)
              + pack_it->name] = os_it->public_release.local_path
              + pack_it->name;
        }

  return true;
}

//-----------------------------------------------------------------------------
#if (defined _MSC_VER)
unsigned omaha_protol_server::service_handler(unsigned control,
    unsigned event_code,
    void *pdata)
{
  if (control == SERVICE_CONTROL_STOP || control == SERVICE_CONTROL_SHUTDOWN)
  {
    (static_cast<service_impl_base*>(this))->set_status(SERVICE_STOP_PENDING);
    this->send_stop_signal();
    return NO_ERROR;
  } else
  {
    return ERROR_CALL_NOT_IMPLEMENTED;
  }
}
#endif

//-----------------------------------------------------------------------------
bool omaha_protol_server::idle_worker() {
  boost::interprocess::ipcdetail::atomic_inc32(&m_threads_count);
  log_space::log_singletone::set_thread_log_prefix("[IDLE]: ");

  while (!m_is_stop) {
    check_config_update();
    misc_utils::sleep_no_w(1000);
  }

  boost::interprocess::ipcdetail::atomic_dec32(&m_threads_count);
  return true;
}

//-----------------------------------------------------------------------------
bool omaha_protol_server::check_config_update() {
  LOG_PRINT_L4("[omaha_protol_server::check_config_update()]");

  time_t ft = 0;
  if (!file_io_utils::get_file_time(m_config_file_path, ft)) {
    LOG_ERROR("Failed to get time form config file from " << m_config_file_path);
    return false;
  }

  if (ft > m_config_file_stamp) {
    if (!reload_config()) {
      //TODO: Figure out, if we really need to stop service ?
      LOG_PRINT_L0("Failed to reload config, stopping service...");
      send_stop_signal();
    }
  }

  return true;
}

//-----------------------------------------------------------------------------
bool omaha_protol_server::run() {
  LOG_PRINT_L0("[omaha_protol_server::run()]");
  // starting idle worker
  m_is_stop = 0;
  boost::thread(boost::bind(&omaha_protol_server::idle_worker, this));

  int thrds_count = 20;  // 5 // just an example
  LOG_PRINT("Run net_service loop( " << thrds_count << " threads)...",
            LOG_LEVEL_0);
  if (!m_http_server.run_server(thrds_count)) {
    LOG_ERROR("Failed to run http tcp server!");
  }
  LOG_PRINT("Net_service loop stopped.", LOG_LEVEL_0);

  size_t wait_count = 0;
  size_t wait_max = 80;
  while (boost::interprocess::ipcdetail::atomic_read32(&m_threads_count)
      && wait_count < wait_max) {
    misc_utils::sleep_no_w(1000);
    LOG_PRINT(
        "Threads  " << m_threads_count << ", wait " << wait_count << " of " << wait_max,
        LOG_LEVEL_0);
    wait_count++;
  }

  LOG_PRINT(
      "Wait other threads finished. m_threads_count = " << m_threads_count << ", wait_count = " << wait_count << " of " << wait_max,
      LOG_LEVEL_0);
  return true;
}

//-----------------------------------------------------------------------------
bool omaha_protol_server::notify(
    const omaha::transport::update_reqest::app_request_entity& app_entry) {
  LOG_PRINT_L0("[omaha_protol_server::notify]");
  return omaha::protocol::handle_omaha_protocol_events(app_entry);
}

//-----------------------------------------------------------------------------
bool omaha_protol_server::deinit() {
  return m_http_server.deinit_server();
}

//-----------------------------------------------------------------------------
bool omaha_protol_server::send_stop_signal() {
  m_is_stop = true;
  m_http_server.send_stop_signal();
  return true;
}

//-----------------------------------------------------------------------------
bool omaha_protol_server::handle_http_request(
    const net_utils::http::http_request_info& query_info,
    net_utils::http::http_response_info& response,
    const net_utils::connection_context& m_conn_context) {
  LOG_PRINT_L0("[omaha_protol_server::handle_http_request()]");
  LOG_PRINT_L0("query_info.m_URI: " << query_info.m_URI);
  response.m_response_code = 200;
  response.m_response_comment = "Ok";
  return handle_http_request_map(query_info, response, m_conn_context);
}
//-----------------------------------------------------------------------------
bool omaha_protol_server::on_service_update2(
    const net_utils::http::http_request_info& query_info,
    net_utils::http::http_response_info& response,
    const net_utils::connection_context& m_conn_context) {
  boost::shared_lock<boost::shared_mutex> lock(m_config_lock);
  return m_update_handler.handle_request(query_info, response, m_conn_context);
}
//-----------------------------------------------------------------------------
bool omaha_protol_server::store_config() {

  std::string buff;
  StorageNamed::InMemStorageSpace::xml::store_t_to_xml(m_hconfig, buff);

  return true;
}
//-----------------------------------------------------------------------------
bool omaha_protol_server::on_service_configure(
    const net_utils::http::http_request_info& query_info,
    net_utils::http::http_response_info& response,
    const net_utils::connection_context& m_conn_context) {

  omaha::server::config::application_entry ap_en;

  bool res = StorageNamed::InMemStorageSpace::json::load_t_from_json(
      ap_en, query_info.m_body);
  CHECK_AND_ASSERT_MES(res, false,
                       "Failed to load json from configure request.");

  //get exclusive access
  boost::upgrade_lock<boost::shared_mutex> lock(m_config_lock);
  boost::upgrade_to_unique_lock<boost::shared_mutex> uniqueLock(lock);

  omaha::server::config::handlers_config hback_conf = m_hconfig;

  //lets find application
  std::list<omaha::server::config::application_entry>::iterator it = m_hconfig
      .application.begin();
  for (; it != m_hconfig.application.end(); it++) {
    if (it->app_id == ap_en.app_id)
      break;
  }

  if (it == m_hconfig.application.end()) {
    //no application with given id found,
    //add new application entry
    LOG_PRINT_L0("Adding new application entry, id: " << ap_en.app_id);
    m_hconfig.application.push_back(ap_en);
  } else {
    LOG_PRINT_L0("Updating existing application entry, id: " << ap_en.app_id);
    *it = ap_en;
  }
  transport::configure_request::configure_response rsp;
  res = extra_init_config();
  if (!res) {
    //roll back config
    m_hconfig = hback_conf;
    response.m_response_code = 406;
    response.m_response_comment = "Not Acceptable";

    rsp.status = "Failed";
    rsp.server_comment = "Config provided do not fit requirements";
    StorageNamed::InMemStorageSpace::json::store_t_to_json(rsp,
                                                           response.m_body);
    LOG_ERROR("Config provided do not fit requirements.");
    return true;
  }
  res = store_config();
  if (!res) {
    //roll back config
    m_hconfig = hback_conf;
    response.m_response_code = 500;
    response.m_response_comment = "Internal Server Error";

    rsp.status = "Failed";
    rsp.server_comment = "Failed to store config";
    StorageNamed::InMemStorageSpace::json::store_t_to_json(rsp,
                                                           response.m_body);
    LOG_ERROR("Failed to store config.");
    return true;
  }

  response.m_response_code = 200;
  response.m_response_comment = "OK";

  rsp.status = "OK";
  rsp.server_comment = "Sucessfull";
  StorageNamed::InMemStorageSpace::json::store_t_to_json(rsp, response.m_body);

  return true;
}
//-----------------------------------------------------------------------------
bool omaha_protol_server::on_hosting_request(
    const net_utils::http::http_request_info& query_info,
    net_utils::http::http_response_info& response,
    const net_utils::connection_context& m_conn_context) {
  LOG_PRINT_L0("Download request: " << m_downloads_count << " \r\n");
  LOG_PRINT_L0(
      "HTTP IN " << query_info.m_http_method_str << " " << query_info.m_URI << " \r\n" << query_info.m_body);
  std::map<std::string, std::string>::iterator it = m_uri_to_locals.find(
      query_info.m_header_info.m_host + query_info.m_uri_content.m_path);
  if (it == m_uri_to_locals.end()) {
    // calculate oz omaha downloads
    if (std::string::npos != query_info.m_URI.find("/OzWebInstall.exe")) {

      if (++m_downloads_count == ULONG_MAX) {
        LOG_PRINT_L0("Number of download is huge: " << m_downloads_count);
        m_downloads_count = 0;
      }
      LOG_PRINT_L0("Download request: " << m_downloads_count << " \r\n");
    }
    // workaround here at now
    net_utils::http::simple_http_connection_handler http_ph(
        NULL, m_http_server.get_config_object());

    return http_ph.handle_request(query_info, response);

  }
  if (!file_io_utils::load_file_to_string(it->second, response.m_body)) {
    LOG_PRINT_L0(
        "[DownloadHandler]: Failed to find mapped file, \nURI:" << query_info.m_full_request_str << " \nlocal_path: " << it->second);
    response.m_response_code = 404;
    response.m_response_comment = "Not found";
    return true;
  }
  response.m_response_code = 200;
  response.m_response_comment = "Ok";
  response.m_mime_tipe = "application/octet-stream";  //just to be sure
  return true;
}
//-----------------------------------------------------------------------------
}// namespace backend
}  // namespace omaha

