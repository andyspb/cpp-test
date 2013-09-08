/****************************************************************************
 * (c) Copyright 2013  Hewlett-Packard Development Company, L.P.             *
 *                                                                           *
 * Confidential computer software. Valid license from HP required for        *
 * possession, use or copying. Consistent with FAR 12.211 and 12.212,        *
 * Commercial Computer Software, Computer Software Documentation, and        *
 * Technical Data for Commercial Items are licensed to the U.S. Government   *
 * under vendor's standard commercial license.                               *
 ****************************************************************************/

#ifndef UPDATE_REQ_HANDLER_H
#define UPDATE_REQ_HANDLER_H

#include "include_base_utils.h"
#include "net/net_utils_base.h"
#include "net/http_base.h"
#include "protocol_defs.h"
#include "handlers_config.h"

namespace omaha {
namespace server {
struct i_update_check_callback {
  virtual ~i_update_check_callback() {
  }

  virtual bool notify(
      const omaha::transport::update_reqest::app_request_entity& app_entry) = 0;
};

class update_check_request_handler {
 public:
  update_check_request_handler(
      const omaha::server::config::handlers_config& conf,
      i_update_check_callback* pcallback)
      : m_config_ref(conf),
        m_pcallback(pcallback) {
  }

  bool handle_request(const net_utils::http::http_request_info& query_info,
                      net_utils::http::http_response_info& response,
                      const net_utils::connection_context& m_conn_context);

 private:
  bool handle_request(
      const omaha::transport::update_reqest::request_wrapper& req,
      omaha::transport::update_reqest::response_wrapper& resp);

  const omaha::server::config::handlers_config& m_config_ref;
  i_update_check_callback* m_pcallback;
};
}  // namespace server
}  // namespace omaha

#include "update_req_handler.inl"
#endif  // UPDATE_REQ_HANDLER_H
