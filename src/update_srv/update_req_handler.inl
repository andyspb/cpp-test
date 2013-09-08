/****************************************************************************
* (c) Copyright 2013  Hewlett-Packard Development Company, L.P.             *
*                                                                           *
* Confidential computer software. Valid license from HP required for        *
* possession, use or copying. Consistent with FAR 12.211 and 12.212,        *
* Commercial Computer Software, Computer Software Documentation, and        *
* Technical Data for Commercial Items are licensed to the U.S. Government   *
* under vendor's standard commercial license.                               *
****************************************************************************/

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

#include "protocol_defs.h"
#include "storages/inmemtoxml.h"

namespace omaha {
namespace server {
inline
bool update_check_request_handler::handle_request(
    const net_utils::http::http_request_info& query_info,
    net_utils::http::http_response_info& response,
    const net_utils::connection_context& m_conn_context) {
  LOG_PRINT_L0("HTTP IN [req method]" << query_info.m_http_method_str << " "
          << query_info.m_URI);
  LOG_PRINT_L0("BODY [req body]" << "\r\n" << query_info.m_body);
  response.m_response_code = 200;
  response.m_mime_tipe = "application/xml";
  response.m_response_comment = "Ok";

  LOG_PRINT2("service_api.log",
      "[" << (void*) &m_conn_context << "]: REQ: " << query_info.m_URI
          << " |------------------------------------------------------------------\n"
          << query_info.m_body, LOG_LEVEL_0);

  boost::uint64_t ticks = misc_utils::get_tick_count();
  omaha::transport::update_reqest::request_wrapper req;
  omaha::transport::update_reqest::response_wrapper resp;
  StorageNamed::InMemStorageSpace::xml::load_t_from_xml(req, query_info.m_body);
  boost::uint64_t ticks2 = misc_utils::get_tick_count();
  if (!handle_request(req, resp)) {
    LOG_ERROR("Failed to handle_client_api_request");
    response.m_response_code = 500;
    response.m_response_comment = "Internal Server Error";
    return true;
  }
  boost::uint64_t ticks3 = misc_utils::get_tick_count();
  LOG_PRINT("[UPDATE_CHECK_REQUEST] processed with " << ticks3 - ticks << " ms",
      LOG_LEVEL_0);

  response.m_body = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n";
  StorageNamed::InMemStorageSpace::xml::store_t_to_xml_classic(resp,
      response.m_body);
  LOG_PRINT_L0("HTTP OUT: \r\n" << response.m_body);
  LOG_PRINT2("service_api.log",
      "[" << (void*) &m_conn_context << "] RESP: "
          << " |------------------------------------------------------------------\n"
          << response.m_body, LOG_LEVEL_0);

  return true;
}

inline bool get_ver_str_as_big_number(const std::string& ver_str,
    boost::uint64_t& current_val) {
  current_val = 0;
  boost::uint64_t current_multiplier = 1;
  std::vector<std::string> vers;
  boost::split(vers, ver_str, boost::is_any_of(". "), boost::token_compress_on);
  if (vers.size() != 4) {
    LOG_ERROR("Wrong version string");
    return false;
  }
  for (std::vector<std::string>::reverse_iterator it = vers.rbegin();
      it != vers.rend(); it++) {
    boost::uint32_t v = 0;
    if (!string_tools::get_xtype_from_string(v, *it)) {
      LOG_ERROR("Unparsible version number: " << *it << " in " << ver_str);
      return false;
    }
    current_val += current_multiplier * v;
    current_multiplier *= 10000;
  }
  return true;
}

inline
bool update_check_request_handler::handle_request(
    const omaha::transport::update_reqest::request_wrapper& req,
    omaha::transport::update_reqest::response_wrapper& resp) {

  resp.response.daystart.elapsed_seconds = "4";  // TODO: remove this hard code in future
  resp.response.protocol = "3.0";  // as in examples
  resp.response.server = "jedi";
  // for each application in request
  for (std::list<omaha::transport::update_reqest::app_request_entity>::const_iterator it_req_app = req.request.apps.begin();
                            it_req_app != req.request.apps.end();
                            ++it_req_app) 
  {
    resp.response.apps.push_back( omaha::transport::update_reqest::app_response_entity());
    omaha::transport::update_reqest::app_response_entity& en = resp.response.apps.back();
    en.appid = it_req_app->appid;
    en.status = "ok";
    en.ping.enabled = false;
    en.updatecheck.enabled = false;
    en.updatecheck.v.manifest.enabled = false;
    en.updatecheck.v.urls.enabled = false;
    // <ping>
    if (it_req_app->ping.enabled) {
      en.ping.enabled = true;
      en.ping.v.status = "ok";  // always OK.
    }

    // check for events
    if (it_req_app->events.size()) {
      // events should be handled by ping_observer.
      m_pcallback->notify(*it_req_app);
      // and for each event should be filled response "ok"
      omaha::transport::update_reqest::event_response_entity ev_r;
      ev_r.status = "ok";  //always ok
      en.events.resize(it_req_app->events.size(), ev_r);
    }
    // lets start to handle entries
    // <updatecheck/>
    if (it_req_app->updatecheck.enabled) {
      // lookup in config applications
      std::list<omaha::server::config::application_entry>::const_iterator it = 
                m_config_ref.application.begin();
      for (; it != m_config_ref.application.end(); ++it) {
        if (it->app_id == it_req_app->appid) {
          break;
        }
      }
      if (it == m_config_ref.application.end()) {
        // wrong application,
        en.status = "error-unknownApplication";
        continue;
      }
      if (!it->os.size()) {
        en.status = "error";
        continue;
      }

      // want to know update status
      // enable updatecheck response section
      en.updatecheck.enabled = true;

      boost::uint64_t num_ver_ext = 0;
      boost::uint64_t num_ver_int = 0;
      if (!get_ver_str_as_big_number( it->os.begin()->public_release.manifest.version, num_ver_int)) 
      {
        LOG_ERROR("[update_check_request_handler] Failed to get_ver_str_as_big_number()");
        en.status = "error";
        return false;
      }

      std::string trimmed_ver = it_req_app->version;
      boost::trim(trimmed_ver);
      if (trimmed_ver.size()
          && !get_ver_str_as_big_number(trimmed_ver, num_ver_ext)) {
        LOG_ERROR( "[update_check_request_handler] Failed to get_ver_str_as_big_number()");
        en.status = "error";
        return false;
      }
      LOG_PRINT_L0("client version:" << it_req_app->version << "\r\nserver version:"
              << it->os.begin()->public_release.manifest.version);
      if (num_ver_ext >= num_ver_int) {
        // no update
        if (num_ver_ext > num_ver_int)
          LOG_PRINT_L0("Outer application ver ("
                  << it->os.begin()->public_release.manifest.version
                  << ") bigger than internal last build ("
                  << it_req_app->version << ")");

        en.updatecheck.v.status = "noupdate";
      } else {
        // we need to send update info
        en.updatecheck.v.manifest.enabled = true;
        en.updatecheck.v.urls.enabled = true;
        en.updatecheck.v.status = "ok";
        en.updatecheck.v.manifest = it->os.begin()->public_release.manifest;
        en.updatecheck.v.urls = it->os.begin()->public_release.urls;
      }
    }
  }
  return true;
}
}  // namespace server
}  // namespace omaha