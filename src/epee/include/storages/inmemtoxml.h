// Copyright (c) 2006-2013, Andrey N. Sabelnikov, www.sabelnikov.net
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// * Neither the name of the Andrey N. Sabelnikov nor the
// names of its contributors may be used to endorse or promote products
// derived from this software without specific prior written permission.
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


#ifndef _INMEMTOXML_H_
#define _INMEMTOXML_H_

#include <boost/regex.hpp>
#include "storages/inmemstorage.h"
#include "serialization/NamedSerialize.h"
//#include "syncobj.h"
#include "string_tools.h"
#include "reg_exp_definer.h"
#include "to_nonconst_iterator.h"
#include "parserse_base_utils.h"

DECLARE_REGEXP_CRITICAL_SECTION();
namespace epee
{
using namespace misc_utils::parse;

namespace StorageNamed
{
	namespace InMemStorageSpace
	{

		class xml
		{
		public:
			static bool load_from_xml(const std::string& buff_xml, CInMemStorage& stg)
			{
				std::string::const_iterator sec_buf_begin  = buff_xml.begin();
				return run_tag_handler(NULL, sec_buf_begin, buff_xml.end(), stg, "root");
			};

      static bool load_from_xml_fast(const std::string& buff_xml, CInMemStorage& stg)
      {
        std::string::const_iterator sec_buf_begin  = buff_xml.begin();
        return run_tag_handler2(NULL, sec_buf_begin, buff_xml.end(), stg, "root");
      };

      template<class t_storage>
      static bool store_to_xml(std::string& buff_xml, t_storage& stg, const std::string& root_name = "")
			{
				return stg.TraceAsXML(buff_xml, root_name); //run_tag_handler(NULL, buff_xml.begin(), buff_xml.end(), stg, "root");
			};
	
			template<class t_struct>
      static bool load_t_from_xml(t_struct& out, const std::string& xml_buff, const std::string& opener_sec = "")
			{
				StorageNamed::CInMemStorage stg;
				bool rs = StorageNamed::InMemStorageSpace::xml::load_from_xml(xml_buff, stg);
				if(!rs)
					return false;
				
#ifdef _DEBUG 
				int i = 0;
				if(i = 1)
				{
					std::string s;
					stg.TraceAsXML(s);
					s = "";
				}
#endif	
        StorageNamed::CInMemStorage::HSSECTION ps = NULL;

        if(opener_sec.size())
        {
           ps = stg.OpenSection(opener_sec.c_str());
        }
        
				out.Load(&stg, ps);
        stg.CloseStorageHandle(ps);
				return true;
			}



			template<typename t_struct>
			static bool store_t_to_xml(t_struct& out, std::string& xml_buff)
			{
				StorageNamed::CInMemStorage stg;
				out.Store(&stg);

				bool rs = StorageNamed::InMemStorageSpace::xml::store_to_xml(xml_buff, stg);
				if(!rs)
					return false;

				return true;
			}


      template<typename t_struct>
      static bool store_t_to_xml_classic(t_struct& out, std::string& xml_buff)
      {
        StorageNamed::CInMemStorage_xml2 stg;
        out.Store(&stg);

        bool rs = StorageNamed::InMemStorageSpace::xml::store_to_xml(xml_buff, stg);
        if(!rs)
          return false;

        return true;
      }


      template<class t_storage, typename t_struct>
      static bool store_t_to_xml_t(t_struct& out, std::string& xml_buff, const std::string& root_name = "" )
      {
        t_storage stg;
        out.Store(&stg);

        bool rs = StorageNamed::InMemStorageSpace::xml::store_to_xml(xml_buff, stg, root_name);
        if(!rs)
          return false;

        return true;
      }


		private:
      struct match_tag_param
      {
          bool tag_is_single;
          bool tag_is_definition;
          bool is_tag_closing; 
          std::string::const_iterator tag_start_pos;
          std::string::const_iterator tag_end_pos; 
          std::string sec_name;

          std::list<std::pair<std::string, std::string> > tag_params;
      };

      static bool match_tag(std::string::const_iterator sec_buf_begin, std::string::const_iterator xml_buf_end, match_tag_param& pm)
      {
        enum local_state
        {
          ls_matching_opener, 
          ls_matching_tag_type,
          ls_matching_name, 
          ls_walk_inside,
//          ls_matching_param_name, 
          ls_matching_after_param_name,
          ls_matching_param_body, 
          ls_matching_comments,  //TODO: not implemeted yet
          ls_error_state //TODO: not implemeted yet
        };
        
        pm.tag_is_single = pm.is_tag_closing = pm.tag_is_definition = false;
        local_state ls = ls_matching_opener;
        std::string::const_iterator it = sec_buf_begin;
        std::string current_param_name;
        for(;it != xml_buf_end; ++it)
        {
          switch(ls)
          {
          case ls_matching_opener: 
            {
              if(*it == '<')
              {
                pm.tag_start_pos = it;
                ls = ls_matching_tag_type;
              }
            }
            break;
          case ls_matching_tag_type: 
            if(*it == '?')
            {
              pm.tag_is_definition = true;
              break;
            }
            else if(*it == '/')
            {
              pm.is_tag_closing = true;
              break;
            }
            else if(*it == '-')
            {
              ls = ls_matching_comments;
              break;
            }

            ls = ls_matching_name;
          case ls_matching_name: 
            {
              bool res = match_word_with_extrasymb(it, xml_buf_end, pm.sec_name);
              CHECK_AND_ASSERT_MES(res, false, "failed to match_word_with_extrasymb :" << std::string(it, xml_buf_end));
              ls = ls_walk_inside;
            }
            break;
          case ls_walk_inside: 
            {
              if(*it == '/')
              {
                pm.tag_is_single = true;
                continue;
              }else if (pm.tag_is_single && *it != '>')
              {
                LOG_ERROR("'/' not at the '>'!!!: " << std::string(it, xml_buf_end));
                return false;
              }else if(*it == '?')
              {
                if(!pm.tag_is_definition)
                {
                  LOG_ERROR("'?' without tag_is_definition: " << std::string(it, xml_buf_end));
                  return false;
                }
                continue;
              }
              else if(*it == '>')
              {
                  pm.tag_end_pos = it;pm.tag_end_pos++;
                  return true;
              }
              else if(isalnum(*it) || *it == '_' || *it == '-')
              {
                std::string::const_iterator it_start = it;
                std::string::const_iterator it_end;
                bool res = match_word_til_equal_mark(it, xml_buf_end, it_end);
                CHECK_AND_ASSERT_MES(res, false, "failed to match_word_til_equal_mark :" << std::string(it, xml_buf_end));
                current_param_name.assign(it_start, it_end);
                ls = ls_matching_after_param_name;
                //started parametr
              }else if(!isspace(*it))
                return false;
            }
            break;
          case ls_matching_after_param_name: 
            {
              if(*it == '"')
              {
                std::string val;
                bool res = match_string(it, xml_buf_end, val);
                CHECK_AND_ASSERT_MES(res, false, "failed to match_string :" << std::string(it, xml_buf_end));
                pm.tag_params.push_back(std::pair<std::string, std::string>(current_param_name, val));
                current_param_name.clear();
                ls = ls_walk_inside;
              }
              else if(!isspace(*it))
                  return false;
            }
            break;
          case ls_matching_comments: 
            {
              LOG_ERROR("TODO: Comment in xml: not supported yet!");/*TODO*/
              return false;
            }
            break;
          case ls_error_state: 
            {
              LOG_ERROR("ls_error_state :(");
              return false;
            }
            break;
          default: 
            LOG_ERROR("Wrong state: " << static_cast<int>(ls));
            return false;
          }
          //it++;
        }
        //apparently not matched :(
        return false;
      }

      static bool fill_section_fields2(const std::list<std::pair<std::string, std::string> >& lst, CInMemStorage& stg, CInMemStorage::HSSECTION current_section)
      {
        //									  1           2
        for(std::list<std::pair<std::string, std::string> >::const_iterator it = lst.begin(); it != lst.end(); it++)
        {
          fake_mem_block fk_mb(it->second.data(), it->second.size());
          stg.SetValue(it->first.c_str(), &fk_mb, current_section, STORAGE_TYPE_ANSI_STRING);
        }
        return true;
      }


      static bool run_tag_handler2(CInMemStorage::HSSECTION current_section, std::string::const_iterator& sec_buf_begin, std::string::const_iterator xml_buf_end, CInMemStorage& stg, const std::string& paren_sec_name)
      {
        //(<(\?)?(/)?([\w!?]+)(.*?)?(/)?>)
        //1 2    3   4        5     6  
        //boost::match_results<std::string::const_iterator> result;
        bool stop = false;
        while(!stop)
        {
          //std::string::const_iterator it_begin = sec_buf_begin;
          //std::string::const_iterator it_end = xml_buf_end;
          match_tag_param mp;
          if(match_tag(sec_buf_begin, xml_buf_end, mp)) ///*boost::regex_search(sec_buf_begin, xml_buf_end, result, rexp_match_tag, boost::match_default)*/true)
          {
            bool was_sub_section = false;
            //matched some tag
            //std::string sub_sec_name(mp.tag_name_start, mp.tag_name_end );

            if(!mp.is_tag_closing)
            {//openening tag, new section
              was_sub_section = true;

              sec_buf_begin = mp.tag_end_pos;//result[0].second;//sec_buf_begin + std::distance(std::string::const_iterator(sec_buf_begin), result[0].second);
              CInMemStorage::HSSECTION new_sec = NULL;
              CInMemStorage::HSSECARRAY sec_array = NULL;
              CInMemStorage::HSSECTION tmp_section = NULL;
              sec_array  = stg.GetFirstSection(mp.sec_name.c_str(), &tmp_section, current_section);
              if(sec_array)
              {   //already have array of sec, add to the end
                stg.InsertNextSection(sec_array, &new_sec);
                //tempo sec kill right now
                stg.CloseStorageHandle(tmp_section);
              }
              else
                sec_array = stg.InsertFirstSection(mp.sec_name.c_str(), &new_sec, current_section);


              fill_section_fields2(mp.tag_params, stg, new_sec);

              if(!mp.tag_is_definition && !mp.is_tag_closing && !mp.tag_is_single )//!result[2].matched && !result[6].matched && !result[3].matched)//будет закрывающий тег
                if(!run_tag_handler2(new_sec, sec_buf_begin, xml_buf_end, stg, mp.sec_name))
                  return false;

              if(sec_array) stg.CloseStorageHandle(sec_array);
              if(new_sec)   stg.CloseStorageHandle(new_sec);
            }else
            {//closing tag, section is over
              if(mp.sec_name != paren_sec_name)
              {
                //LOCAL_ASSERT(0);

                LOG_ERROR("Wrong XML sub_sec_name != paren_sec_name");
                return false;
              }
              if(!was_sub_section)
              {//take care of between tags data, and look if there something interesting 
                std::string betwin_tags_data(sec_buf_begin, mp.tag_start_pos);
                string_tools::trim(betwin_tags_data);
                if(betwin_tags_data.size())
                {
                  fake_mem_block mbl((void*)betwin_tags_data.data(), betwin_tags_data.size());
                  stg.SetValue("_internal_", &mbl, current_section, STORAGE_TYPE_ANSI_STRING);
                }
              }
              sec_buf_begin = mp.tag_end_pos;
              stop = true;
            }
          }else
            stop = true;
        }

        return true;
      }


			static bool run_tag_handler(CInMemStorage::HSSECTION current_section, std::string::const_iterator& sec_buf_begin, std::string::const_iterator xml_buf_end, CInMemStorage& stg, const std::string& paren_sec_name)
			{
				STATIC_REGEXP_EXPR_1(rexp_match_tag, "(<(\\?)?(/)?([\\w!?]+)(.*?)?(/)?>)", boost::regex::icase | boost::regex::normal);
				//                									  1 2     3   4         5     6  (<(\?)?(/)?([\w!?]+)(.*?)?(/)?>)
				boost::match_results<std::string::const_iterator> result;
				bool stop = false;
				while(!stop)
				{
					std::string::const_iterator it_begin = sec_buf_begin;
					//std::string::const_iterator it_end = xml_buf_end;
					if(boost::regex_search(sec_buf_begin, xml_buf_end, result, rexp_match_tag, boost::match_default))
					{
						bool was_sub_section = false;
						//matched some tag
						std::string sub_sec_name = result[4];

						if(!result[3].matched)
						{//openening tag, new section
							was_sub_section = true;

							sec_buf_begin = result[0].second;//sec_buf_begin + std::distance(std::string::const_iterator(sec_buf_begin), result[0].second);
							CInMemStorage::HSSECTION new_sec = NULL;
							CInMemStorage::HSSECARRAY sec_array = NULL;
							CInMemStorage::HSSECTION tmp_section = NULL;
							sec_array  = stg.GetFirstSection(sub_sec_name.c_str(), &tmp_section, current_section);
							if(sec_array)
							{   //already have array of sec, add to the end
								stg.InsertNextSection(sec_array, &new_sec);
								//tempo sec kill right now
								stg.CloseStorageHandle(tmp_section);
							}
							else
								sec_array = stg.InsertFirstSection(sub_sec_name.c_str(), &new_sec, current_section);

							
							fill_section_fields(result[5].first, result[5].second, stg, new_sec);

							if(!result[2].matched && !result[6].matched && !result[3].matched)//будет закрывающий тег
								if(!run_tag_handler(new_sec, sec_buf_begin, xml_buf_end, stg, sub_sec_name))
									return false;
							
							if(sec_array) stg.CloseStorageHandle(sec_array);
							if(new_sec)   stg.CloseStorageHandle(new_sec);
						}else
						{//closing tag, section is over
							if(sub_sec_name != paren_sec_name)
							{
								LOCAL_ASSERT(0);
								return false;
							}
							if(!was_sub_section)
							{//take care of between tags data, and look if there something interesting 
								std::string betwin_tags_data(sec_buf_begin, result[0].first);
								string_tools::trim(betwin_tags_data);
								if(betwin_tags_data.size())
								{
									fake_mem_block mbl((void*)betwin_tags_data.data(), betwin_tags_data.size());
									stg.SetValue("_internal_", &mbl, current_section, STORAGE_TYPE_ANSI_STRING);
								}
							}
							sec_buf_begin = result[0].second;
							stop = true;
						}
					}else
						stop = true;
				}

				return true;
			}

			static bool fill_section_fields(std::string::const_iterator buff_begin, std::string::const_iterator buff_end, CInMemStorage& stg, CInMemStorage::HSSECTION current_section)
			{
				if(buff_end == buff_begin)
					return true;

				STATIC_REGEXP_EXPR_1(rexp_match_tag, "([^ ]+)\\s?=\\s?\\\"(.*?)\\\"", boost::regex::icase | boost::regex::normal);
				//									  1           2
				boost::match_results<std::string::const_iterator> result;
				std::string::const_iterator current_buff_begin = buff_begin;
				while(boost::regex_search(current_buff_begin, buff_end, result, rexp_match_tag, boost::match_default))
				{
					std::string param_name = result[1];
					std::string param_value = result[2];
					fake_mem_block fk_mb(param_value.data(), param_value.size());
					stg.SetValue(param_name.c_str(), &fk_mb, current_section, STORAGE_TYPE_ANSI_STRING);
					
					current_buff_begin = result[0].second;
				}
				return true;

			}
		};
	}
}
}
#endif //_INMEMTOXML_H_
