#ifndef INMEM_TO_JSON_H
#define INMEM_TO_JSON_H

#include "parserse_base_utils.h"

namespace epee {
using namespace misc_utils::parse;

namespace StorageNamed {
namespace InMemStorageSpace {
namespace json {

#define CHECK_ISSPACE() \
  if(!isspace(*it)) {\
    LOG_ERROR("Wrong JSON character: " << std::string(it, buf_end));\
    return parse_error();\
  }

inline bool parse_error() {
  LOG_ERROR("json parse error");
  return false;
}

inline bool run_tag_handler(CInMemStorage::HSSECTION current_section,
                            std::string::const_iterator& sec_buf_begin,
                            std::string::const_iterator buf_end,
                            CInMemStorage& stg,
                            const std::string& paren_sec_name) {

  std::string::const_iterator sub_element_start;
  std::string name;
  CInMemStorage::HSVALARRAY h_values_array = NULL;
  CInMemStorage::HSSECARRAY h_sec_array = NULL;
  enum match_state {
    match_state_lookup_for_section_start,
    match_state_lookup_for_name,
    match_state_waiting_separator,
    match_state_wonder_after_separator,
    match_state_wonder_after_value,
    match_state_wonder_array,
    match_state_array_after_value,
    match_state_array_waiting_value,
    match_state_error
  };

  enum array_mode {
    array_mode_undifined = 0,
    array_mode_sections,
    array_mode_string,
    array_mode_numbers,
    array_mode_booleans
  };

  match_state state = match_state_lookup_for_section_start;
  array_mode array_md = array_mode_undifined;
  std::string::const_iterator it = sec_buf_begin;
  for (; it != buf_end; it++) {
    switch (state) {
      case match_state_lookup_for_section_start:
        if (*it == '{')
          state = match_state_lookup_for_name;
        else if (!isspace(*it))
          return parse_error();
        break;
      case match_state_lookup_for_name:
        if (*it == '"') {
          if (!match_string(it, buf_end, name))
            return parse_error();
          state = match_state_waiting_separator;
        } else if (*it == '}') {
          //this is it! section ends here.
          //seems that it is empty section
          sec_buf_begin = it;
          return true;
        } else if (!isspace(*it))
          return parse_error();
        break;
      case match_state_waiting_separator:
        if (*it == ':')
          state = match_state_wonder_after_separator;
        else if (!isspace(*it))
          return parse_error();
        break;
      case match_state_wonder_after_separator:
        if (*it == '"') {              //just a named string value started
          std::string val;
          bool res = match_string(it, buf_end, val);
          CHECK_AND_ASSERT_MES(
              res,
              false,
              "Failed to match string in json on this area: "
                  << std::string(it, buf_end));
          //insert text value
          fake_mem_block fk_mb(val.data(), val.size());
          res = stg.SetValue(name.c_str(), &fk_mb, current_section,
                             STORAGE_TYPE_ANSI_STRING);
          CHECK_AND_ASSERT_MES(res, false, "Failed to SetValue");
          state = match_state_wonder_after_value;
        } else if (isdigit(*it) || *it == '-') {  //just a named number value started
          std::string val;
          bool res = match_number(it, buf_end, val);  //TODO: Add scientific notation support
          CHECK_AND_ASSERT_MES(
              res,
              false,
              "Failed to match number in json on this area: "
                  << std::string(it, buf_end));
          boost::int64_t nval = 0;
          res = string_tools::string_to_num_fast(val, nval);
          if (nval < 0) {
            LOG_ERROR("Negative nummebers is not supported yet, sorry :(");
            return parse_error();
          }
          CHECK_AND_ASSERT_MES(
              res,
              false,
              "Failed to consvert number in json on this area: "
                  << std::string(it, buf_end));
          fake_mem_block fk_mb(&nval, sizeof(nval));
          res = stg.SetValue(name.c_str(), &fk_mb, current_section,
                             STORAGE_TYPE_SKALAR);
          CHECK_AND_ASSERT_MES(res, false, "Failed to SetValue");
          state = match_state_wonder_after_value;
        } else if (isalpha(*it)) {              // could be null, true or false
          std::string word;
          bool res = match_word(it, buf_end, word);
          CHECK_AND_ASSERT_MES(
              res, false,
              "Failed to find out value keyword: " << std::string(it, buf_end));
          if (boost::iequals(word, "null")) {
            state = match_state_wonder_after_value;
            //just skip this,
          } else if (boost::iequals(word, "true")) {
            bool bv = true;
            fake_mem_block fk_mb(&bv, sizeof(bv));
            bool res = stg.SetValue(name.c_str(), &fk_mb, current_section,
                                    STORAGE_TYPE_SKALAR);
            CHECK_AND_ASSERT_MES(res, false, "Failed to SetValue");
            state = match_state_wonder_after_value;
          } else if (boost::iequals(word, "false")) {
            bool bv = false;
            fake_mem_block fk_mb(&bv, sizeof(bv));
            bool res = stg.SetValue(name.c_str(), &fk_mb, current_section,
                                    STORAGE_TYPE_SKALAR);
            CHECK_AND_ASSERT_MES(res, false, "Failed to SetValue");
            state = match_state_wonder_after_value;
          } else {
            LOG_ERROR("Unknown value keyword " << word);
            return parse_error();
          }
        } else if (*it == '{') {
          //sub section here
          CInMemStorage::HSSECTION new_sec = NULL;

          new_sec = stg.OpenSection(name.c_str(), current_section, true);
          CHECK_AND_ASSERT_MES(
              new_sec,
              false,
              "Failed to insert new section in json: "
                  << std::string(it, buf_end));
          if (!run_tag_handler(new_sec, it, buf_end, stg, name))
            return parse_error();

          stg.CloseStorageHandle(new_sec);
          state = match_state_wonder_after_value;
        } else if (*it == '[') {              //array of object
          state = match_state_wonder_array;
        } else CHECK_ISSPACE()
        ;
        break;
      case match_state_wonder_after_value:
        if (*it == ',')
          state = match_state_lookup_for_name;
        else if (*it == '}') {
          //this is it! section ends here.
          sec_buf_begin = it;
          return true;
        } else CHECK_ISSPACE()
        ;
        break;
      case match_state_wonder_array:
        if (*it == '{') {
          //mean array of strings
          CInMemStorage::HSSECTION new_sec = NULL;
          h_sec_array = stg.InsertFirstSection(name.c_str(), &new_sec,
                                               current_section);
          CHECK_AND_ASSERT_MES(h_sec_array && new_sec, false,
                               "failed to create new section");

          if (!run_tag_handler(new_sec, it, buf_end, stg, name))
            return parse_error();

          state = match_state_array_after_value;
          array_md = array_mode_sections;
        } else if (*it == '"') {
          //mean array of strings
          std::string val;
          bool res = match_string(it, buf_end, val);
          CHECK_AND_ASSERT_MES(
              res,
              false,
              "failed to match string value in strings array: "
                  << std::string(it, buf_end));
          fake_mem_block fk_mb(val.data(), val.size());
          h_values_array = stg.InsertFirstValue(name.c_str(), &fk_mb,
                                                current_section,
                                                STORAGE_TYPE_ANSI_STRING);
          CHECK_AND_ASSERT_MES(h_values_array, false,
                               " failed to insert values entry");
          state = match_state_array_after_value;
          array_md = array_mode_string;
        } else if (isdigit(*it) || *it == '-') {  //array of numbers value started
          std::string val;
          bool res = match_number(it, buf_end, val);  //TODO: Add scientific notation support
          CHECK_AND_ASSERT_MES(
              res,
              false,
              "Failed to match number in json on this area: "
                  << std::string(it, buf_end));
          boost::int64_t nval = 0;
          res = string_tools::string_to_num_fast(val, nval);
          CHECK_AND_ASSERT_MES(
              res,
              false,
              "Failed to consvert number in json on this area: "
                  << std::string(it, buf_end));
          fake_mem_block fk_mb(&nval, sizeof(nval));
          h_values_array = stg.InsertFirstValue(name.c_str(), &fk_mb,
                                                current_section,
                                                STORAGE_TYPE_SKALAR);
          CHECK_AND_ASSERT_MES(h_values_array, false,
                               " failed to insert values section entry");
          state = match_state_array_after_value;
          array_md = array_mode_numbers;
        } else if (isalpha(*it)) {              // array of booleans
          std::string word;
          bool res = match_word(it, buf_end, word);
          CHECK_AND_ASSERT_MES(
              res, false,
              "Failed to find out value keyword: " << std::string(it, buf_end));
          if (boost::iequals(word, "true")) {
            bool bv = true;
            fake_mem_block fk_mb(&bv, sizeof(bv));
            h_values_array = stg.InsertFirstValue(name.c_str(), &fk_mb,
                                                  current_section,
                                                  STORAGE_TYPE_SKALAR);
            CHECK_AND_ASSERT_MES(h_values_array, false,
                                 " failed to insert values section entry");
            state = match_state_array_after_value;
            array_md = array_mode_booleans;
          } else if (boost::iequals(word, "false")) {
            bool bv = false;
            fake_mem_block fk_mb(&bv, sizeof(bv));
            h_values_array = stg.InsertFirstValue(name.c_str(), &fk_mb,
                                                  current_section,
                                                  STORAGE_TYPE_SKALAR);
            CHECK_AND_ASSERT_MES(h_values_array, false,
                                 " failed to insert values section entry");
            state = match_state_array_after_value;
            array_md = array_mode_booleans;
          } else {
            LOG_ERROR("Unknown value keyword " << word);
            return parse_error();
          }
        } else CHECK_ISSPACE()
        ;
        break;
      case match_state_array_after_value:
        if (*it == ',')
          state = match_state_array_waiting_value;
        else if (*it == ']') {
          if (h_values_array) {
            stg.CloseStorageHandle(h_values_array);
            h_values_array = NULL;
          } else if (h_sec_array) {
            stg.CloseStorageHandle(h_sec_array);
            h_values_array = NULL;
          } else {
            LOG_ERROR("Closing array but now opened sec");
            return parse_error();
          }
          array_md = array_mode_undifined;
          state = match_state_wonder_after_value;
        } else CHECK_ISSPACE()
        ;
        break;
      case match_state_array_waiting_value:
        switch (array_md) {
          case array_mode_sections:
            if (*it == '{') {
              CInMemStorage::HSSECTION new_sec = NULL;
              bool res = stg.InsertNextSection(h_sec_array, &new_sec);
              CHECK_AND_ASSERT_MES(res && new_sec, false,
                                   "failed to create new section");

              if (!run_tag_handler(new_sec, it, buf_end, stg, name))
                return parse_error();
              state = match_state_array_after_value;
            } else CHECK_ISSPACE()
            ;
            break;
          case array_mode_string:
            if (*it == '"') {
              std::string val;
              bool res = match_string(it, buf_end, val);
              CHECK_AND_ASSERT_MES(
                  res,
                  false,
                  "failed to match string value in strings array: "
                      << std::string(it, buf_end));
              fake_mem_block fk_mb(val.data(), val.size());
              res = stg.InsertNextValue(h_values_array, &fk_mb);
              CHECK_AND_ASSERT_MES(res, false, " failed to insert values");
              state = match_state_array_after_value;
            } else CHECK_ISSPACE()
            ;
            break;
          case array_mode_numbers:
            if (isdigit(*it) || *it == '-') {   //array of numbers value started
              std::string val;
              bool res = match_number(it, buf_end, val);  //TODO: Add scientific notation support
              CHECK_AND_ASSERT_MES(
                  res,
                  false,
                  "Failed to match number in json on this area: "
                      << std::string(it, buf_end));
              boost::int64_t nval = 0;
              res = string_tools::string_to_num_fast(val, nval);
              CHECK_AND_ASSERT_MES(
                  res,
                  false,
                  "Failed to consvert number in json on this area: "
                      << std::string(it, buf_end));
              fake_mem_block fk_mb(&nval, sizeof(nval));
              res = stg.InsertNextValue(h_values_array, &fk_mb);
              CHECK_AND_ASSERT_MES(res, false, " failed to insert value");
              state = match_state_array_after_value;
              array_md = array_mode_numbers;
            } else CHECK_ISSPACE()
            ;
            break;
          case array_mode_booleans:
            if (isalpha(*it)) {              // array of booleans
              std::string word;
              bool res = match_word(it, buf_end, word);
              CHECK_AND_ASSERT_MES(
                  res,
                  false,
                  "Failed to find out value keyword: "
                      << std::string(it, buf_end));
              if (string_tools::compare_no_case(word, "true")) {
                bool bv = true;
                fake_mem_block fk_mb(&bv, sizeof(bv));
                bool res = stg.InsertNextValue(h_values_array, &fk_mb);
                CHECK_AND_ASSERT_MES(res, false,
                                     "failed to insert value entry");
                state = match_state_array_after_value;
              } else if (string_tools::compare_no_case(word, "false")) {
                bool bv = false;
                fake_mem_block fk_mb(&bv, sizeof(bv));
                bool res = stg.InsertNextValue(h_values_array, &fk_mb);
                CHECK_AND_ASSERT_MES(res, false,
                                     "failed to insert value entry");
                state = match_state_array_after_value;
              } else {
                LOG_ERROR("Unknown value keyword " << word);
                return parse_error();
              }
            } else CHECK_ISSPACE()
            ;
            break;
          case array_mode_undifined:
          default:
            LOG_ERROR("Bat array state");
            return parse_error();
        }
        break;
      case match_state_error:
      default:
        LOG_ERROR("WRONG JSON STATE");
        return parse_error();

    }
  }
  return true;
}
/*
 {
 "firstName": "John",
 "lastName": "Smith",
 "age": 25,
 "address": {
 "streetAddress": "21 2nd Street",
 "city": "New York",
 "state": "NY",
 "postalCode": -10021,
 "have_boobs": true,
 "have_balls": false
 },
 "phoneNumber": [
 {
 "type": "home",
 "number": "212 555-1234"
 },
 {
 "type": "fax",
 "number": "646 555-4567"
 }
 ],
 "phoneNumbers": [
 "812 123-1234",
 "916 123-4567"
 ]
 }
 */

static bool load_from_json(const std::string& buff_json, CInMemStorage& stg) {
  std::string::const_iterator sec_buf_begin = buff_json.begin();
  return run_tag_handler(NULL, sec_buf_begin, buff_json.end(), stg, "root");
}
;

template<class t_struct>
static bool load_t_from_json(t_struct& out, const std::string& json_buff) {
  StorageNamed::CInMemStorage stg;
  bool rs = StorageNamed::InMemStorageSpace::json::load_from_json(json_buff,
                                                                  stg);
  if (!rs)
    return false;

  out.Load(&stg);
  return true;
}

template<class t_struct>
static bool store_t_to_json(t_struct& str_in, std::string& json_buff) {
  StorageNamed::CInMemStorage stg;
  str_in.Store(&stg);
  stg.TraceAsJson(json_buff);

  return true;
}

}
}
}
}

#endif  // INMEM_TO_JSON_H
