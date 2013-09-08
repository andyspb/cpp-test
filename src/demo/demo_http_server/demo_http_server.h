#ifndef DEMO_HTTP_SERVER_H
#define DEMO_HTTP_SERVER_H

#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include "net/http_server_cp2.h"
#include "transport_defs.h"
#include "net/http_server_handlers_map.h"

using namespace epee;

namespace demo {
class HttpTest {
 public:
  static void test(int argc, char* argv[]);
};

class demo_http_server : public net_utils::http::i_http_server_handler {
 public:
  bool run();
  bool init(const std::string& bind_port = "11112", const std::string& bind_ip =
                "0.0.0.0");
  bool deinit();
  bool send_stop_signal();
 private:

  CHAIN_HTTP_TO_MAP()
  ;  //forward http requests to uri map

  BEGIN_URI_MAP()
    MAP_URI("/requestr_uri_1", on_requestr_uri_1)
    MAP_URI("/requestr_uri_2", on_requestr_uri_1)
    MAP_URI_AUTO_XML("/request_api_xml_1", on_request_api_1, COMMAND_EXAMPLE_1)
    MAP_URI_AUTO_XML("/request_api_xml_2", on_request_api_2, COMMAND_EXAMPLE_2)
    MAP_URI_AUTO_JON("/request_api_json_1", on_request_api_1, COMMAND_EXAMPLE_1)
    MAP_URI_AUTO_JON("/request_api_json_2", on_request_api_2, COMMAND_EXAMPLE_2)
      CHAIN_URI_MAP(on_hosting_request)
    END_URI_MAP()

  bool on_requestr_uri_1(const net_utils::http::http_request_info& query_info,
                         net_utils::http::http_response_info& response,
                         const net_utils::connection_context& m_conn_context);

  bool on_requestr_uri_2(const net_utils::http::http_request_info& query_info,
                         net_utils::http::http_response_info& response,
                         const net_utils::connection_context& m_conn_context);

  bool on_hosting_request(const net_utils::http::http_request_info& query_info,
                          net_utils::http::http_response_info& response,
                          const net_utils::connection_context& m_conn_context);

  bool on_request_api_1(const COMMAND_EXAMPLE_1::request& req,
                        COMMAND_EXAMPLE_1::response& res);
  bool on_request_api_2(const COMMAND_EXAMPLE_2::request& req,
                        COMMAND_EXAMPLE_2::response& res);

  net_utils::boosted_http_server_custum_handling m_net_server;
};
}

#endif  // DEMO_HTTP_SERVER_H
