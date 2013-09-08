
#include "stdafx.h"
#include "console_handler.h"
#include "demo_http_server.h"

//#ifndef DEFINED_REGEXP_CRITICAL_SECTION
//#define DEFINED_REGEXP_CRITICAL_SECTION
//DEFINE_REGEXP_CRITICAL_SECTION();
//#endif // DEFINED_REGEXP_CRITICAL_SECTION

namespace demo {
static
void HttpTest::test(int argc, char* argv[]) {
  TRY_ENTRY();
  string_tools::set_module_name_and_folder(argv[0]);

  //set up logging options
  log_space::get_set_log_detalisation_level(true, LOG_LEVEL_2);
  log_space::log_singletone::add_logger(LOGGER_CONSOLE, NULL, NULL);
  log_space::log_singletone::add_logger(
      LOGGER_FILE, log_space::log_singletone::get_default_log_file().c_str(),
      log_space::log_singletone::get_default_log_folder().c_str());

  LOG_PRINT("Demo server starting ...", LOG_LEVEL_0);

  demo::demo_http_server srv;

  start_default_console(&srv);

  std::string bind_param = "127.0.0.1";
  std::string port = "80";

  if (!srv.init(port, bind_param)) {
    LOG_ERROR("Failed to initialize srv!");
    return; // 1;
  }

  //log loop
  srv.run();

  srv.deinit();

  LOG_PRINT("Demo server stoped.", LOG_LEVEL_0);

  CATCH_ENTRY_L0("main", 1);
//  return 1;
}


bool demo_http_server::init(const std::string& bind_port,
                            const std::string& bind_ip) {

  //set self as callback handler
  m_net_server.get_config_object().m_phandler = this;

  //here set folder for hosting reqests
  m_net_server.get_config_object().m_folder = "";

  LOG_PRINT_L0("Binding on " << bind_ip << ":" << bind_port);
  return m_net_server.init_server(bind_port, bind_ip);
}

bool demo_http_server::run() {
  //here you can set worker threads count
  int thrds_count = 4;

  //go to loop
  LOG_PRINT("Run net_service loop( " << thrds_count << " threads)...",
            LOG_LEVEL_0);
  if (!m_net_server.run_server(thrds_count)) {
    LOG_ERROR("Failed to run net tcp server!");
  }

  LOG_PRINT("net_service loop stopped.", LOG_LEVEL_0);
  return true;
}

bool demo_http_server::deinit() {
  return m_net_server.deinit_server();
}

bool demo_http_server::send_stop_signal() {
  m_net_server.send_stop_signal();
  return true;
}

bool demo_http_server::on_requestr_uri_1(
    const net_utils::http::http_request_info& query_info,
    net_utils::http::http_response_info& response,
    const net_utils::connection_context& m_conn_context) {
  return true;
}

bool demo_http_server::on_requestr_uri_2(
    const net_utils::http::http_request_info& query_info,
    net_utils::http::http_response_info& response,
    const net_utils::connection_context& m_conn_context) {
  return true;
}

bool demo_http_server::on_hosting_request(
    const net_utils::http::http_request_info& query_info,
    net_utils::http::http_response_info& response,
    const net_utils::connection_context& m_conn_context) {
  return true;
}

bool demo_http_server::on_request_api_1(const COMMAND_EXAMPLE_1::request& req,
                                        COMMAND_EXAMPLE_1::response& res) {
  return true;
}
bool demo_http_server::on_request_api_2(const COMMAND_EXAMPLE_2::request& req,
                                        COMMAND_EXAMPLE_2::response& res) {
  return true;
}

}  // namespace demo
