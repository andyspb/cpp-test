#ifndef PARSERSE_BASE_UTILS_H
#define PARSERSE_BASE_UTILS_H

namespace epee {
namespace misc_utils {
namespace parse {

inline std::string transform_to_escape_sequence(const std::string& src) {
  //std::stringstream res;
  std::string res;
  for (std::string::const_iterator it = src.begin(); it != src.end(); ++it) {
    switch (*it) {
      case '\b':  //Backspace (ascii code 08)
        res += "\\b";
        break;
      case '\f':  //Form feed (ascii code 0C)
        res += "\\f";
        break;
      case '\n':  //New line
        res += "\\n";
        break;
      case '\r':  //Carriage return
        res += "\\r";
        break;
      case '\t':  //Tab
        res += "\\t";
        break;
      case '\v':  //Vertical tab
        res += "\\v";
        break;
        //case '\'':  //Apostrophe or single quote
        //  res+="\\'"; break;
      case '"':  //Double quote
        res += "\\\"";
        break;
      case '\\':  //Backslash caracter
        res += "\\\\";
        break;
      case '/':  //Backslash caracter
        res += "\\/";
        break;
      default:
        res.push_back(*it);
    }
  }
  return res;
}
/*

 \b  Backspace (ascii code 08)
 \f  Form feed (ascii code 0C)
 \n  New line
 \r  Carriage return
 \t  Tab
 \v  Vertical tab
 \'  Apostrophe or single quote
 \"  Double quote
 \\  Backslash caracter

 */
inline bool match_string(std::string::const_iterator& star_end_string,
                         std::string::const_iterator buf_end,
                         std::string& val) {
  val.clear();
  //std::string::value_type prev_ch = 0;
  bool escape_mode = false;
  std::string::const_iterator it = star_end_string;
  ++it;
  for (; it != buf_end; it++) {
    if (escape_mode/*prev_ch == '\\'*/) {
      switch (*it) {
        case 'b':  //Backspace (ascii code 08)
          val.push_back(0x08);
          break;
        case 'f':  //Form feed (ascii code 0C)
          val.push_back(0x0C);
          break;
        case 'n':  //New line
          val.push_back('\n');
          break;
        case 'r':  //Carriage return
          val.push_back('\r');
          break;
        case 't':  //Tab
          val.push_back('\t');
          break;
        case 'v':  //Vertical tab
          val.push_back('\v');
          break;
        case '\'':  //Apostrophe or single quote
          val.push_back('\'');
          break;
        case '"':  //Double quote
          val.push_back('"');
          break;
        case '\\':  //Backslash caracter
          val.push_back('\\');
          break;
        default:
          val.push_back(*it);
          LOG_PRINT_L0("Unknown escape sequence :\"\\" << *it << "\"");
      }
      escape_mode = false;
    } else if (*it == '"') {
      star_end_string = it;
      return true;
    } else if (*it == '\\') {
      escape_mode = true;
    } else {
      val.push_back(*it);
    }
  }
  return false;
}

inline bool match_number(std::string::const_iterator& star_end_string,
                         std::string::const_iterator buf_end,
                         std::string& val) {
  val.clear();

  for (std::string::const_iterator it = star_end_string; it != buf_end; it++) {
    if (isdigit(*it) || (it == star_end_string && *it == '-'))
      val.push_back(*it);
    else {
      if (val.size()) {
        star_end_string = --it;
        return true;
      } else
        return false;
    }
  }
  return false;
}

inline bool match_word(std::string::const_iterator& star_end_string,
                       std::string::const_iterator buf_end, std::string& val) {
  val.clear();

  for (std::string::const_iterator it = star_end_string; it != buf_end; it++) {
    if (!isalpha(*it)) {
      val.assign(star_end_string, it);
      if (val.size()) {
        star_end_string = --it;
        return true;
      } else
        return false;
    }
  }
  return false;
}

inline bool match_word_with_extrasymb(
    std::string::const_iterator& star_end_string,
    std::string::const_iterator buf_end, std::string& val) {
  val.clear();

  for (std::string::const_iterator it = star_end_string; it != buf_end; it++) {
    if (!isalnum(*it) && *it != '-' && *it != '_') {
      val.assign(star_end_string, it);
      if (val.size()) {
        star_end_string = --it;
        return true;
      } else
        return false;
    }
  }
  return false;
}

inline bool match_word_til_equal_mark(
    std::string::const_iterator& star_end_string,
    std::string::const_iterator buf_end,
    std::string::const_iterator& word_end) {
  word_end = star_end_string;
  bool space_mode = false;
  for (std::string::const_iterator it = star_end_string; it != buf_end; it++) {
    if (isspace(*it)) {
      space_mode = true;
      continue;
    } else if (*it == '=') {
      star_end_string = it;
      word_end = it;
      return true;
    }
  }
  return false;
}

}
}
}

#endif  // PARSERSE_BASE_UTILS_H
