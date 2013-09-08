// Copyright (c) 2006-2013, Andrey N. Sabelnikov, www.sabelnikov.net
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//     * Neither the name of the Andrey N. Sabelnikov nor the
//     names of its contributors may be used to endorse or promote products
//     derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER  BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 


#pragma once 

#include "storages/inmemtoxml.h"
#include "storages/inmem_to_json.h"
#include "http_base.h"

namespace epee
{
  
}


#define CHAIN_HTTP_TO_MAP() bool handle_http_request(const net_utils::http::http_request_info& query_info, \
              net_utils::http::http_response_info& response, \
              const net_utils::connection_context& m_conn_context) \
{\
  LOG_PRINT_L2("HTTP [" << string_tools::get_ip_string_from_int32(m_conn_context.m_remote_ip ) << "] " << query_info.m_http_method_str << " " << query_info.m_URI); \
  response.m_response_code = 200; \
  response.m_response_comment = "Ok"; \
  if(!handle_http_request_map(query_info, response, m_conn_context)) \
  {response.m_response_code = 404;response.m_response_comment = "Not found";} \
  return true; \
}



#define BEGIN_URI_MAP()   bool handle_http_request_map(const net_utils::http::http_request_info& query_info, \
  net_utils::http::http_response_info& response_info, \
  const net_utils::connection_context& m_conn_context) { \
  bool handled = false; \
  if(false) return true; //just a stub to have "else if"

#define MAP_URI(pattern, callback)  else if(std::string::npos != query_info.m_URI.find(pattern)) return callback(query_info, response_info, m_conn_context);

#define MAP_URI_AUTO_XML(s_pattern, callback_f, type_space) \
    else if(query_info.m_URI == s_pattern) \
    { \
      handled = true; \
      type_space::request req; \
      bool parse_res = StorageNamed::InMemStorageSpace::xml::load_t_from_xml(req, query_info.m_body); \
      type_space::response res; \
      boost::uint64_t ticks = misc_utils::get_tick_count(); \
      if(!callback_f(req, res)) \
      { \
        LOG_ERROR("Failed to " << #callback_f << "()"); \
        response_info.m_response_code = 500;  \
        response_info.m_response_comment = "Internal Server Error"; \
        return true; \
      } \
      boost::uint64_t ticks2 = misc_utils::get_tick_count(); \
      LOG_PRINT(#callback_f "() processed with " << ticks2-ticks << "ms", LOG_LEVEL_0); \
      StorageNamed::InMemStorageSpace::xml::store_t_to_xml(res, response_info.m_body); \
      response_info.m_mime_tipe = "application/xml"; \
    }

#define MAP_URI_AUTO_JON(s_pattern, callback_f, type_space) \
    else if(query_info.m_URI == s_pattern) \
    { \
      handled = true; \
      boost::uint64_t ticks = misc_utils::get_tick_count(); \
      type_space::request req; \
      bool parse_res = StorageNamed::InMemStorageSpace::json::load_t_from_json(req, query_info.m_body); \
      CHECK_AND_ASSERT_MES(parse_res, false, "Failed to parse json: \r\n" << query_info.m_body); \
      type_space::response resp; \
      if(!callback_f(req, resp)) \
      { \
        LOG_ERROR("Failed to " << #callback_f << "()"); \
        response_info.m_response_code = 500; \
        response_info.m_response_comment = "Internal Server Error"; \
        return true; \
      } \
      StorageNamed::InMemStorageSpace::json::store_t_to_json(resp, response_info.m_body); \
      boost::uint64_t ticks2 = misc_utils::get_tick_count(); \
      response_info.m_mime_tipe = "application/json"; \
      response_info.m_header_info.m_content_type = " application/json"; \
      LOG_PRINT( #callback_f << "() processed with " << ticks2-ticks << "ms", LOG_LEVEL_0); \
    }

#define CHAIN_URI_MAP(callback) else {callback(query_info, response_info, m_conn_context);handled = true;}


#define END_URI_MAP() return handled;}
