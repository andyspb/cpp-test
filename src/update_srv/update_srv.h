/****************************************************************************
 * (c) Copyright 2013  Hewlett-Packard Development Company, L.P.             *
 *                                                                           *
 * Confidential computer software. Valid license from HP required for        *
 * possession, use or copying. Consistent with FAR 12.211 and 12.212,        *
 * Commercial Computer Software, Computer Software Documentation, and        *
 * Technical Data for Commercial Items are licensed to the U.S. Government   *
 * under vendor's standard commercial license.                               *
 ****************************************************************************/

#ifndef OMAHA_TOOLS_OMAHACOMPATIBILITY_IMPL_UPDATE_SRV_H
#define OMAHA_TOOLS_OMAHACOMPATIBILITY_IMPL_UPDATE_SRV_H

/*#include <boost/signals.hpp>*/

#include "net/http_server_cp2.h"
#include "handlers_config.h"
#include "update_req_handler.h"
#if (defined _MSC_VER)
#include "service_impl_base.h"
#endif

#define OPS_SERVICE_NAME          "omaha_server"
#define OPS_SERVICE_CAPTION       "Omaha Control Server"
#define OPS_SERVICE_DESCRIPTION   "OzUpdate server"

#define BEGIN_URI_MAP()   bool handle_http_request_map(const net_utils::http::http_request_info& query_info, \
                          net_utils::http::http_response_info& response, \
                          const net_utils::connection_context& m_conn_context) {

#define MAP_URI(pattern, callback)  if(std::string::npos != query_info.m_URI.find(pattern)) return callback(query_info, response, m_conn_context);
#define CHAIN_URI_MAP(callback) return callback(query_info, response, m_conn_context);

#define END_URI_MAP() }

using namespace epee;
//DEFINE_REGEXP_CRITICAL_SECTION();
#define OPS_DEFAULT_CONFIG_FILENAME "omaha_config.xml"
#define LOG_FILE_MAX_SIZE 2097152

namespace omaha {
namespace backend {

class HttpServer {
 public:
  static int srv_test(int argc, char* argv[]);
};

class omaha_protol_server : public net_utils::http::i_http_server_handler,
    omaha::server::i_update_check_callback
#if (defined _MSC_VER)
, public service_impl_base
#endif
{
 public:
#pragma warning(disable: 4355)
  omaha_protol_server()
      : m_update_handler(m_hconfig, this) {
  }
#pragma warning(default: 4355)

  bool init(const std::string& config_path/*, const std::string& bind_port,
   const std::string& bind_ip*/);
  bool run();
  bool deinit();
  bool send_stop_signal();

 private:
  struct http_connection_cntext {
    http_connection_cntext(
        const net_utils::connection_context& net_context,
        const net_utils::http::http_request_info& http_context)
        : ref_net_context(net_context),
          ref_http_context(http_context) {

    }
    const net_utils::connection_context& ref_net_context;
    const net_utils::http::http_request_info& ref_http_context;
  };

  //----- service_impl_base
#if (defined _MSC_VER)
  virtual const char *get_name() {
    return OPS_SERVICE_NAME;
  }

  virtual const char *get_caption() {
    return OPS_SERVICE_CAPTION;
  }

  virtual const char *get_description() {
    return OPS_SERVICE_DESCRIPTION;
  }

  virtual unsigned service_handler(unsigned control, unsigned event_code,
      void *pdata);
  virtual void service_main() {
    run();
  }
#endif
  //--------------- i_http_server_handler impl ------------------------------
  virtual bool handle_http_request(
      const net_utils::http::http_request_info& query_info,
      net_utils::http::http_response_info& response,
      const net_utils::connection_context& m_conn_context);
  virtual bool init_server_thread() {
    return true;
  }

  virtual bool deinit_server_thread() {
    return true;
  }
  //-------------- i_update_check_callback -----------------------------------
  virtual bool notify(
      const omaha::transport::update_reqest::app_request_entity& app_entry);
  std::string remove_protocol_from_url(const std::string& url);

  bool extra_init_config();
  bool reload_config();
  bool store_config();
  bool idle_worker();
  bool check_config_update();

  BEGIN_URI_MAP()
    MAP_URI("/service/update2", on_service_update2)
    MAP_URI("/service/confugure", on_service_configure)
    CHAIN_URI_MAP(on_hosting_request)END_URI_MAP()

  bool on_service_update2(const net_utils::http::http_request_info& query_info,
                          net_utils::http::http_response_info& response,
                          const net_utils::connection_context& m_conn_context);

  bool on_service_configure(
      const net_utils::http::http_request_info& query_info,
      net_utils::http::http_response_info& response,
      const net_utils::connection_context& m_conn_context);

  bool on_hosting_request(const net_utils::http::http_request_info& query_info,
                          net_utils::http::http_response_info& response,
                          const net_utils::connection_context& m_conn_context);

  net_utils::boosted_http_server_custum_handling m_http_server;
  omaha::server::config::handlers_config m_hconfig;
  omaha::server::update_check_request_handler m_update_handler;
  std::map<std::string, std::string> m_uri_to_locals;
  boost::shared_mutex m_config_lock;
  time_t m_config_file_stamp;
  std::string m_config_file_path;
  volatile boost::uint32_t m_is_stop;
  volatile boost::uint32_t m_threads_count;
  // downloads counter
  unsigned long int m_downloads_count;

  /*
   struct pattern_entry
   {
   std::string pattern;
   boost::signal<bool(const net_utils::http::http_request_info&,
   net_utils::http::http_response_info&,
   const net_utils::connection_context&)> action;
   };*/

};
}  // namespace backend
}  // namespace omaha

#endif  // #define OMAHA_TOOLS_OMAHACOMPATIBILITY_IMPL_UPDATE_SRV_H
