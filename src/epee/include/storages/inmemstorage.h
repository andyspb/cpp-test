#ifndef _STORAGE_H_
#define _STORAGE_H_

#include <list>
#include <map>
#include <string>
#include <boost/smart_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/cstdint.hpp>
#include "../serialization/mem_block.h"
#include "../serialization/NamedSerialize.h"
#include "parserse_base_utils.h"

#ifndef ASSERT_INTERNAL
#define ASSERT_INTERNAL(expression) assert(expression)
#endif

#ifndef CHECK_AND_ASSERT
#define CHECK_AND_ASSERT(expression, fail_return_val) \
  { \
    ASSERT_INTERNAL(expression);\
    if(!(expression)) \
      return fail_return_val;\
  }
#endif

//ENTRY TYPES
#define STORAGE_ENTRY_TYPE_SECTION        1
#define STORAGE_ENTRY_TYPE_VAL            2
#define STORAGE_ENTRY_TYPE_SECTION_ARRAY  3
#define STORAGE_ENTRY_TYPE_VALUE_ARRAY    4
#define STORAGE_ENTRY_TYPE_NAKED_OBJECT   5

#define STORAGE_SIGNATUREA 0xF34D49A2
#define STORAGE_SIGNATUREB 0x889F1ED9
#define CURRENT_FORMAT_VER 1

#define RAW_SIZE_MARK_MASK   0x03
#define RAW_SIZE_MARK_BYTE   0
#define RAW_SIZE_MARK_WORD   1
#define RAW_SIZE_MARK_DWORD  2
#define RAW_SIZE_MARK_INT64  3

#define SHIFT_TO_INDEX_LEFT(val, shift_count) ((val) << shift_count)
#define SHIFT_TO_INDEX_RIGHT(val, shift_count) ((val) >> shift_count)

#ifdef _DEBUG
//#define ENABLE_DETAILED_CHECK
#endif

#ifdef ENABLE_DETAILED_CHECK
#define CHECK_REMAIN_SIZE() \
  if(!CheckBufferSizeForEntry(run_ptr.get_remain_size(), this)) \
    return 0
#else
#define CHECK_REMAIN_SIZE()
#endif

namespace epee {
namespace StorageNamed {
namespace InMemStorageSpace {

typedef unsigned char s_byte;
typedef boost::uint16_t s_word;
typedef boost::uint32_t s_dword;
typedef boost::uint64_t s_int64;

class running_ptr {
 public:
  running_ptr()
      : m_pbuff_base(0),
        m_prunning_pointer(0),
        m_cb(0) {
  }
  virtual ~running_ptr() {
  }
  void attach(void* pbuff, size_t cb) {
    m_prunning_pointer = m_pbuff_base = (s_byte*) pbuff;
    m_cb = cb;
  }
  running_ptr& operator++(int) {
    if (check_increment(1))
      m_prunning_pointer++;
    return *this;
  }

  running_ptr& operator+=(size_t size) {
    if (check_increment(size))
      m_prunning_pointer += size;
    return *this;
  }

  s_byte* get_current_ptr() {
    return m_prunning_pointer;
  }

  s_byte* get_base_ptr() {
    return m_prunning_pointer;
  }

  size_t get_remain_size() {
    return m_cb - (m_prunning_pointer - m_pbuff_base);
  }

 protected:
 private:
  bool check_increment(size_t increment_val) {
    if ((size_t) ((m_prunning_pointer + increment_val) - m_pbuff_base) > m_cb) {
      ASSERT_INTERNAL(0);
      return false;
    }
    return true;
  }

  s_byte* m_pbuff_base;
  s_byte* m_prunning_pointer;
  size_t m_cb;
};

/************************************************************************/
/*                                                                      */
/************************************************************************/
struct ISSectionEntry;

typedef bool (*penum_func)(void* pparam, ISSectionEntry* pchild,
                           const char* pEntryName);

struct ISSectionEntry {
  virtual ~ISSectionEntry() {
  }
  virtual s_byte GetEntryType()=0;
  virtual size_t GetInRawSize()=0;
  virtual size_t PackEntryToBuff(running_ptr& run_ptr)=0;
  virtual size_t UnPackEntryFromBuff(running_ptr& run_ptr)=0;
  virtual bool TraseEntryAsXml(std::stringstream& general_stream,
                               std::stringstream& in_sectionstream,
                               size_t indent, const std::string& sec_name)=0;
  virtual bool TraseEntryAsJson(std::stringstream& general, size_t indent)=0;
  virtual bool EnumChilds(penum_func enum_func, void* pparam) {
    return false;
  }
};
/************************************************************************/
/*                                                                      */
/************************************************************************/
template<class output_policy>
ISSectionEntry* BuildEntryByType(s_byte type);

inline size_t GetUnsignedCompactSize(size_t unsigned_digit) {
  if (unsigned_digit <= 63)  //mean enough one byte
    return sizeof(s_byte);
  else if (unsigned_digit <= 16383)  //mean need word
    return sizeof(s_word);
  else if (unsigned_digit <= 1073741824)  //mean need dword
    return sizeof(s_dword);
  else
    //mean need int64 - something very big!!! ;)
    return sizeof(s_int64);
  //must never comes here!!!
  ASSERT_INTERNAL(0);
  return 0;
}

inline size_t PutUnsignedCompact(running_ptr& run_ptr, size_t unsigned_digit) {  //the first two bits always reserved for size information

  if (unsigned_digit <= 63) {   //mean enough one byte
    *run_ptr.get_current_ptr() = (*((s_byte*) &unsigned_digit)) << 2;
    //shift byte in two bits
    //(*run_ptr.get_current_ptr()) >> 2;
    run_ptr++;
    return sizeof(s_byte);
  } else if (unsigned_digit <= 16383) {				//mean need word
    *((s_word*) run_ptr.get_current_ptr()) = (*((s_word*) &unsigned_digit))
        << 2;
    //shift s_word in two bits
    //(*((s_word*)run_ptr.get_current_ptr())) >> 2;
    //set size info
    *((s_word*) run_ptr.get_current_ptr()) |= RAW_SIZE_MARK_WORD;

    run_ptr += sizeof(s_word);
    return sizeof(s_word);
  } else if (unsigned_digit <= 1073741824) {				//mean need dword
    *((s_dword*) run_ptr.get_current_ptr()) = (*((s_dword*) &unsigned_digit))
        << 2;
    //shift s_word in two bits
    //(*((s_dword*)run_ptr.get_current_ptr())) >> 2;
    //set size info
    *((s_dword*) run_ptr.get_current_ptr()) |= RAW_SIZE_MARK_DWORD;
    run_ptr += sizeof(s_dword);
    return sizeof(s_dword);
  } else {				//mean need int64 - something very big!!! ;)
    *((s_int64*) run_ptr.get_current_ptr()) = (*((s_int64*) &unsigned_digit))
        << 2;
    //shift s_word in two bits
    //(*((s_int64*)run_ptr.get_current_ptr())) >> 2;
    //set size info
    *((s_int64*) run_ptr.get_current_ptr()) |= RAW_SIZE_MARK_INT64;
    run_ptr += sizeof(s_int64);
    return sizeof(s_int64);
  }
  ASSERT_INTERNAL(0);
  return 0;
}
inline size_t PopUnsignedCompact(running_ptr& run_ptr,
                                 size_t* punsigned_digit) {
  *punsigned_digit = 0;
  s_byte size_mark = (*run_ptr.get_current_ptr()) & RAW_SIZE_MARK_MASK;
  if (size_mark == RAW_SIZE_MARK_BYTE) {
    *punsigned_digit = (*run_ptr.get_current_ptr()) >> 2;
    //(*punsigned_digit) << 2;
    run_ptr++;
    return sizeof(s_byte);
  } else if (size_mark == RAW_SIZE_MARK_WORD) {
    *punsigned_digit = (*((s_word*) run_ptr.get_current_ptr())) >> 2;
    //(*punsigned_digit) << 2;
    run_ptr += sizeof(s_word);
    return sizeof(s_word);
  } else if (size_mark == RAW_SIZE_MARK_DWORD) {
    *punsigned_digit = (*((s_dword*) run_ptr.get_current_ptr())) >> 2;
    //(*punsigned_digit) << 2;
    run_ptr += sizeof(s_dword);
    return sizeof(s_dword);
  } else if (size_mark == RAW_SIZE_MARK_INT64) {
#pragma warning (disable:4244)
    *punsigned_digit = (*((s_int64*) run_ptr.get_current_ptr())) >> 2;
#pragma warning (default:4244)
    //(*punsigned_digit) << 2;
    run_ptr += sizeof(s_int64);
    return sizeof(s_int64);
  }
  //nust newer come here
  ASSERT_INTERNAL(0);
  return 0;
}

class memory_object_xml_policy_big {
 public:
  static bool TraseEntryAsXml(std::stringstream& general_stream,
                              std::stringstream& in_sectionstream,
                              size_t indent, const std::string& sec_name,
                              s_byte suggestion_flag,
                              const std::string& str_repr) {
    std::string indent_str(indent * 2, ' ');
    if (sec_name != "_internal_") {
      general_stream << indent_str << "<" << sec_name << " value=\"" << str_repr
                     << "\">\r\n";
    } else {
      general_stream << str_repr;
    }
    return true;
  }
};

class memory_object_xml_policy_classic {
 public:
  static bool TraseEntryAsXml(std::stringstream& general_stream,
                              std::stringstream& in_sectionstream,
                              size_t indent, const std::string& sec_name,
                              s_byte suggestion_flag,
                              const std::string& str_repr) {
    in_sectionstream << " " << sec_name << "=\"" << str_repr << "\"";
    return true;
  }
};

/************************************************************************/
/*                                                                      */
/************************************************************************/
template<class output_policy>
class CMemoryObjectEx : public ISSectionEntry, public CMemoryObject {
 public:
  CMemoryObjectEx() {
  }
  CMemoryObjectEx(const CMemoryObject& base_obj)
      : CMemoryObject(base_obj) {
  }
  virtual ~CMemoryObjectEx() {
  }

  virtual s_byte GetEntryType() {
    return STORAGE_ENTRY_TYPE_NAKED_OBJECT;
  }

  size_t PackEntryToBuff(running_ptr& run_ptr) {
    size_t enter_size = run_ptr.get_remain_size();
    size_t val_size = get_size();
    PutUnsignedCompact(run_ptr, val_size);
    memcpy(run_ptr.get_current_ptr(), get(0), val_size);
    run_ptr += val_size;
    return enter_size - run_ptr.get_remain_size();
  }

  size_t UnPackEntryFromBuff(running_ptr& run_ptr) {
    size_t enter_size = run_ptr.get_remain_size();
    //raw data
    size_t data_size = 0;
    PopUnsignedCompact(run_ptr, &data_size);
    set(run_ptr.get_current_ptr(), data_size);
    run_ptr += data_size;
    return enter_size - run_ptr.get_remain_size();
  }

  size_t GetInRawSize() {
    return get_size() + GetUnsignedCompactSize(get_size());
  }

  bool TraseEntryAsXml(std::stringstream& general_stream,
                       std::stringstream& in_sectionstream, size_t indent,
                       const std::string& sec_name) {

    //just a stub here!
    ASSERT_INTERNAL(false);
    return false;
  }
  virtual bool TraseEntryAsJson(std::stringstream& general, size_t indent) {
    //just a stub here!
    ASSERT_INTERNAL(false);
    return false;
  }

  bool TraseEntryAsXml(std::stringstream& general_stream,
                       std::stringstream& in_sectionstream, size_t indent,
                       const std::string& sec_name, s_byte suggestion_flag) {
    return output_policy::TraseEntryAsXml(
        general_stream, in_sectionstream, indent, sec_name, suggestion_flag,
        get_string_representation(suggestion_flag));
  }

  virtual bool TraseEntryAsJson(std::stringstream& general, size_t indent,
                                s_byte suggestion_flag) {
    if (suggestion_flag == STORAGE_TYPE_ANSI_STRING)
      general
          << "\""
          << misc_utils::parse::transform_to_escape_sequence(
              get_string_representation(suggestion_flag))
          << "\"";				//TODO: ADD MASKING HERE!!
    else
      general << get_string_representation(suggestion_flag);

    return true;
  }

  std::string get_string_representation(s_byte suggestion) {
    std::string res;
    if (suggestion == STORAGE_TYPE_ANSI_STRING) {
      if (CMemoryObject::get_size())
        res.assign((char*) CMemoryObject::get(0), CMemoryObject::get_size());
      else
        res = "";
    } else if (suggestion == STORAGE_TYPE_SKALAR) {
      if (CMemoryObject::get_size() == 1) {
        s_byte digit_maximum = 0;
        memcpy(&digit_maximum, CMemoryObject::get(0),
               CMemoryObject::get_size());
        if (digit_maximum == 1 || digit_maximum == 0) {
          res = digit_maximum ? "true" : "false";
        } else {
          res = boost::lexical_cast<std::string>(digit_maximum);
        }
      } else if (CMemoryObject::get_size() <= 4) {
        s_dword digit_maximum = 0;
        memcpy(&digit_maximum, CMemoryObject::get(0),
               CMemoryObject::get_size());
        res = boost::lexical_cast<std::string>(digit_maximum);
      } else if (CMemoryObject::get_size() == 8) {
        s_int64 digit_maximum = 0;
        memcpy(&digit_maximum, CMemoryObject::get(0),
               CMemoryObject::get_size());
        res = boost::lexical_cast<std::string>(digit_maximum);
      } else
        res += "[not implemented yet for size = "
            + boost::lexical_cast<std::string>(CMemoryObject::get_size()) + "]";
    } else
      res = "[not implemented yet]";

    return res;
  }

  CMemoryObjectEx& operator=(const CMemoryObject& obj) {
    CMemoryObject::operator =(obj);
    return *this;
  }

 protected:
 private:
};

//-----------------------------------------------------------------------------------------------
template<class T>
bool CheckBufferSizeForEntry(size_t cb, T* pSectionEntry) {
  if (cb < pSectionEntry->GetInRawSize()) {
    ASSERT_INTERNAL(0);
    return false;
  }
  return true;
}

inline size_t GetPackedNameEntrySize(const std::string& sec_name) {
  const char* pstr = sec_name.c_str();
  size_t str_len = strlen(pstr);
  return str_len + 1;
}

inline size_t UnPackNameEntry(std::string& sec_name, running_ptr& run_ptr) {
  const char* pstr = (const char*) run_ptr.get_current_ptr();
  size_t str_size = strlen(pstr);
  sec_name = pstr;
  run_ptr += str_size + 1;
  return str_size + 1;
}

inline size_t PackNameEntry(const std::string& sec_name, running_ptr& run_ptr) {
  const char* pstr = sec_name.c_str();
  size_t str_len = strlen(pstr);
  memcpy(run_ptr.get_current_ptr(), pstr, str_len + 1);
  run_ptr += str_len + 1;
  return str_len + 1;
}

#ifdef ENABLE_DETAILED_CHECK
#define CHECK_PACKING() CheckInEndPack(this, enter_size, run_ptr)
#else
#define CHECK_PACKING()
#endif

template<class T>
bool CheckInEndPack(T* pEntry, size_t enter_size, running_ptr& run_ptr) {
  bool res = CheckEntryLoad(
      pEntry,
      run_ptr.get_current_ptr() - (enter_size - run_ptr.get_remain_size()),
      enter_size - run_ptr.get_remain_size());
  ASSERT_INTERNAL(res);
  return res;
}

template<class T>
bool CheckEntryLoad(T* pEntry, void* pbuff, size_t cb) {
  running_ptr run_ptr;
  run_ptr.attach(pbuff, cb);
  size_t loaded_size = pEntry->UnPackEntryFromBuff(run_ptr);
  if (cb != loaded_size)
    return false;
  return true;
}

template<class output_policy>
struct CSSection : public ISSectionEntry {
  //----- ISectionEntry -----------------------------------------
  virtual s_byte GetEntryType() {
    return STORAGE_ENTRY_TYPE_SECTION;
  }
  virtual size_t GetInRawSize() {
    size_t size = 1  //type byte
    + GetUnsignedCompactSize(m_section_entries.size());  //count of entries
    for (section_container::iterator it = m_section_entries.begin();
        it != m_section_entries.end(); it++) {
      size += GetPackedNameEntrySize(it->first);
      size += it->second->GetInRawSize();
    }
    return size;
  }
  //-----------------------------------------------------------------------------------------------------
  virtual bool EnumChilds(penum_func enum_func, void* pparam) {
    for (section_container::iterator it = m_section_entries.begin();
        it != m_section_entries.end(); it++)
      enum_func(pparam, it->second.get(), it->first.c_str());

    return true;
  }
  //-----------------------------------------------------------------------------------------------------
  virtual size_t PackEntryToBuff(running_ptr& run_ptr) {
    CHECK_REMAIN_SIZE();
    size_t enter_size = run_ptr.get_remain_size();
    //first byte must be a type identifier
    *run_ptr.get_current_ptr() = GetEntryType();
    run_ptr++;
    //put count of entries in section
    PutUnsignedCompact(run_ptr, m_section_entries.size());
    //enum all entries
    for (section_container::iterator it = m_section_entries.begin();
        it != m_section_entries.end(); it++) {
      size_t packed_size = PackNameEntry(it->first, run_ptr);
      packed_size = it->second->PackEntryToBuff(run_ptr);
    } CHECK_PACKING();
    return enter_size - run_ptr.get_remain_size();
  }

  //-----------------------------------------------------------------------------------------------------
  virtual size_t UnPackEntryFromBuff(running_ptr& run_ptr) {
    m_section_entries.clear();
    size_t entry_size = run_ptr.get_remain_size();
    //first byte must be a type identifier
    if (*run_ptr.get_current_ptr() != GetEntryType()) {
      ASSERT_INTERNAL(0);
      return 0;
    }
    run_ptr++;
    size_t entries_count = 0;
    PopUnsignedCompact(run_ptr, &entries_count);
    std::string str_name;
    for (size_t i = 0; i < entries_count; i++) {
      UnPackNameEntry(str_name, run_ptr);
      ISSectionEntry* pSecEntry = BuildEntryByType<output_policy>(
          *run_ptr.get_current_ptr());
      if (!pSecEntry) {
        ASSERT_INTERNAL(0);
        break;
      }  //some unknown section
      pSecEntry->UnPackEntryFromBuff(run_ptr);
      boost::shared_ptr<ISSectionEntry> smart_ptr(pSecEntry);
      m_section_entries[str_name] = smart_ptr;
    }
    return entry_size - run_ptr.get_remain_size();
  }

  virtual bool TraseEntryAsJson(std::stringstream& general, size_t indent) {
    size_t local_indent = indent + 1;
    general << "{\r\n";

    std::string indent_str(local_indent * 2, ' ');
    section_container::iterator it2 = m_section_entries.begin();
    if (it2 != m_section_entries.end())
      ++it2;
    for (section_container::iterator it = m_section_entries.begin();
        it != m_section_entries.end(); it++) {
      general << indent_str << "\""
              << misc_utils::parse::transform_to_escape_sequence(it->first)
              << "\"" << ": ";
      it->second.get()->TraseEntryAsJson(general, local_indent + 1);
      if (it2 != m_section_entries.end()) {
        general << ",";
        it2++;
      }
      general << "\r\n";
    }
    std::string fstindent_str(indent, ' ');
    general << fstindent_str << "}";

    return true;
  }
  virtual bool TraseEntryAsXml(std::stringstream& general_stream,
                               std::stringstream& in_sectionstream,
                               size_t indent, const std::string& sec_name) {

    std::stringstream sub_general_stream;
    std::stringstream sub_in_section_stream;
    size_t intdent_plus = 0;
    if (sec_name.size()) {
      sub_in_section_stream << "<" << sec_name;
      intdent_plus = 1;
    }

    bool interna_subval = false;
    if (m_section_entries.size() == 1
        && m_section_entries.begin()->first == "_internal_")
      interna_subval = true;

    for (section_container::iterator it = m_section_entries.begin();
        it != m_section_entries.end(); it++)
      it->second.get()->TraseEntryAsXml(sub_general_stream,
                                        sub_in_section_stream,
                                        indent + intdent_plus, it->first);

    //
    if (sec_name.size()) {
      if (interna_subval)
        sub_in_section_stream << ">";
      else {
        if (!sub_general_stream.str().size())
          sub_in_section_stream << "/";  // empty inner stream

        sub_in_section_stream << ">\r\n";
      }
    }

    std::string indent_str(indent * 2, ' ');
    if (interna_subval) {
      general_stream << indent_str << sub_in_section_stream.str()
                     << sub_general_stream.str() << "</" << sec_name << ">\r\n";
    } else {

      general_stream << indent_str << sub_in_section_stream.str()
                     << sub_general_stream.str();
      if (sub_general_stream.str().size() && sec_name.size()) {
        general_stream << indent_str << "</" << sec_name << ">\r\n";
      }
    }

    return true;

  }
  //-----------------------------------------------------------------------------------------------------
  typedef std::map<std::string, boost::shared_ptr<ISSectionEntry> > section_container;
  section_container m_section_entries;
};
/************************************************************************/
/*                                                                      */
/************************************************************************/
template<class output_policy>
struct CSValue : public ISSectionEntry {
  CSValue()
      : m_suggestion_type(0) {
  }
  //----- ISectionEntry -----------------------------------------
  virtual s_byte GetEntryType() {
    return STORAGE_ENTRY_TYPE_VAL;
  }
  virtual size_t GetInRawSize() {
    return 1/*type identifier*/+ 1/*m_suggestion_type*/+ m_val.GetInRawSize();
  }
  virtual size_t PackEntryToBuff(running_ptr& run_ptr) {
    CHECK_REMAIN_SIZE();
    size_t enter_size = run_ptr.get_remain_size();
    //put type identifier
    *run_ptr.get_current_ptr() = GetEntryType();
    run_ptr++;
    //sugestion byte
    *run_ptr.get_current_ptr() = m_suggestion_type;
    run_ptr++;
    //raw data
    m_val.PackEntryToBuff(run_ptr);
    CHECK_PACKING();
    return enter_size - run_ptr.get_remain_size();
  }

  virtual size_t UnPackEntryFromBuff(running_ptr& run_ptr) {
    size_t enter_size = run_ptr.get_remain_size();
    if (*run_ptr.get_current_ptr() != GetEntryType()) {
      ASSERT_INTERNAL(0);
      return 0;
    }
    run_ptr++;
    //load suggestion byte
    m_suggestion_type = *run_ptr.get_current_ptr();
    run_ptr++;
    //raw data
    m_val.UnPackEntryFromBuff(run_ptr);
    return enter_size - run_ptr.get_remain_size();
  }
  virtual bool TraseEntryAsXml(std::stringstream& general_stream,
                               std::stringstream& in_sectionstream,
                               size_t indent, const std::string& sec_name) {
    return m_val.TraseEntryAsXml(general_stream, in_sectionstream, indent,
                                 sec_name, m_suggestion_type);
  }
  virtual bool TraseEntryAsJson(std::stringstream& general, size_t indent) {
    return m_val.TraseEntryAsJson(general, indent, m_suggestion_type);
  }
  //-----
  s_byte m_suggestion_type;
  CMemoryObjectEx<output_policy> m_val;
};
/************************************************************************/
/*                                                                      */
/************************************************************************/
template<class T>
struct CSEntriesArrayBase {
  virtual s_byte GetEntryType()=0;
  virtual size_t GetInRawSize()=0;
  virtual size_t PackEntryToBuff(running_ptr& run_ptr)=0;
  virtual size_t UnPackEntryFromBuff(running_ptr& run_ptr)=0;

  size_t GetInRawSize(std::list<boost::shared_ptr<T> >& entries_array,
                      bool is_suggestion_flag) {
    size_t size = 1/*type*/+ (is_suggestion_flag ? 1 : 0)
        + GetUnsignedCompactSize(entries_array.size());
    for (typename std::list<boost::shared_ptr<T> >::iterator it = entries_array
        .begin(); it != entries_array.end(); it++)
      size += it->get()->GetInRawSize();
    return size;
  }
  //----------------------------------------------------------------------------------------------
  size_t PackEntryToBuff(running_ptr& run_ptr,
                         std::list<boost::shared_ptr<T> >& entries_array,
                         s_byte* psuggestion_byte = 0) {
    CHECK_REMAIN_SIZE();
    size_t enter_size = run_ptr.get_remain_size();
    //first byte must be a type identifier
    *run_ptr.get_current_ptr() = GetEntryType();
    run_ptr++;
    //put suggestion byte if need
    if (psuggestion_byte) {
      *run_ptr.get_current_ptr() = *psuggestion_byte;
      run_ptr++;
    }
    //put count of entries in section
    PutUnsignedCompact(run_ptr, entries_array.size());
    //enum all entries
    size_t packed_size = 0;
    for (typename std::list<boost::shared_ptr<T> >::iterator it = entries_array
        .begin(); it != entries_array.end(); it++)
      packed_size += it->get()->PackEntryToBuff(run_ptr);
    CHECK_PACKING();
    return enter_size - run_ptr.get_remain_size();;
  }
  //----------------------------------------------------------------------------------------------
  size_t UnPackEntryFromBuff(running_ptr& run_ptr,
                             std::list<boost::shared_ptr<T> >& entries_array,
                             s_byte* psuggestion_byte = 0) {
    entries_array.clear();
    size_t entry_size = run_ptr.get_remain_size();
    //first byte must be a type identifier
    if (*run_ptr.get_current_ptr() != GetEntryType()) {
      ASSERT_INTERNAL(0);
      return 0;
    }
    run_ptr++;
    //load suggestion byte if need
    if (psuggestion_byte) {
      *psuggestion_byte = *run_ptr.get_current_ptr();
      run_ptr++;
    }
    //load next data
    size_t entries_count = 0;
    size_t unpacked_size = 0;
    PopUnsignedCompact(run_ptr, &entries_count);
    for (size_t i = 0; i < entries_count; i++) {
      entries_array.push_back(boost::shared_ptr<T>(new T()));
      unpacked_size = entries_array.rbegin()->get()->UnPackEntryFromBuff(
          run_ptr);
    }
    //reset begin iterator
    return entry_size - run_ptr.get_remain_size();
  }
  //----------------------------------------------------------------------------------------------
  bool TraseEntryAsXml(std::list<boost::shared_ptr<T> >& entries_array,
                       std::stringstream& general_stream,
                       std::stringstream& in_sectionstream, size_t indent,
                       const std::string& sec_name) {
    for (typename std::list<boost::shared_ptr<T> >::iterator it = entries_array
        .begin(); it != entries_array.end(); it++)
      it->get()->TraseEntryAsXml(general_stream, in_sectionstream, indent,
                                 sec_name);

    return true;
  }

  bool TraseEntryAsJson(std::list<boost::shared_ptr<T> >& entries_array,
                        std::stringstream& general, size_t indent) {
    general << "[";
    typename std::list<boost::shared_ptr<T> >::iterator it2 = entries_array
        .begin();
    if (it2 != entries_array.end())
      ++it2;

    for (typename std::list<boost::shared_ptr<T> >::iterator it = entries_array
        .begin(); it != entries_array.end(); it++) {
      it->get()->TraseEntryAsJson(general, indent);
      if (it2 != entries_array.end()) {
        general << ",";
        it2++;
      }
    }
    general << "]";

    return true;

  }

};

/************************************************************************/
/*                                                                      */
/************************************************************************/
template<class output_policy>
struct CSSectionsArray : public ISSectionEntry, public CSEntriesArrayBase<
    CSSection<output_policy> > {
  CSSectionsArray() {
    m_current_it = m_sections.begin();
  }
  //----- ISectionEntry -----------------------------------------
  virtual s_byte GetEntryType() {
    return STORAGE_ENTRY_TYPE_SECTION_ARRAY;
  }
  virtual size_t GetInRawSize() {
    return CSEntriesArrayBase<CSSection<output_policy> >::GetInRawSize(
        m_sections, false);
  }

  //-----------------------------------------------------------------------------------------------------
  virtual bool EnumChilds(penum_func enum_func, void* pparam) {
    size_t countet = 0;
    std::string name;
    for (typename sections_container::iterator it = m_sections.begin();
        it != m_sections.end(); it++, countet++)
      enum_func(
          pparam,
          it->get(),
          (name = std::string("[") + boost::lexical_cast<std::string>(countet)
              + "]").c_str());

    return true;
  }
  //-----------------------------------------------------------------------------------------------------
  virtual size_t PackEntryToBuff(running_ptr& run_ptr) {
    return CSEntriesArrayBase<CSSection<output_policy> >::PackEntryToBuff(
        run_ptr, m_sections);
  }
  //-----------------------------------------------------------------------------------------------------
  virtual bool TraseEntryAsXml(std::stringstream& general_stream,
                               std::stringstream& in_sectionstream,
                               size_t indent, const std::string& sec_name) {
    return CSEntriesArrayBase<CSSection<output_policy> >::TraseEntryAsXml(
        m_sections, general_stream, in_sectionstream, indent, sec_name);
  }
  //-----------------------------------------------------------------------------------------------------
  virtual bool TraseEntryAsJson(std::stringstream& general, size_t indent) {
    return CSEntriesArrayBase<CSSection<output_policy> >::TraseEntryAsJson(
        m_sections, general, indent);
  }
  virtual size_t UnPackEntryFromBuff(running_ptr& run_ptr) {
    size_t unpacked_size =
        CSEntriesArrayBase<CSSection<output_policy> >::UnPackEntryFromBuff(
            run_ptr, m_sections);
    m_current_it = m_sections.begin();
    return unpacked_size;
  }
  //-----
  typedef std::list<boost::shared_ptr<CSSection<output_policy> > > sections_container;
  sections_container m_sections;
  //current enum pointer
  typename sections_container::iterator m_current_it;
};

/************************************************************************/
/*                                                                      */
/************************************************************************/
template<class output_policy>
struct CSValuesArray : public ISSectionEntry, public CSEntriesArrayBase<
    CMemoryObjectEx<output_policy> > {
  CSValuesArray()
      : m_suggestion_type(0) {
    m_current_it = m_values.begin();
  }
  typedef std::list<boost::shared_ptr<CMemoryObjectEx<output_policy> > > values_container;
  //----- ISectionEntry -----------------------------------------
  virtual s_byte GetEntryType() {
    return STORAGE_ENTRY_TYPE_VALUE_ARRAY;
  }
  virtual size_t GetInRawSize() {
    return CSEntriesArrayBase<CMemoryObjectEx<output_policy> >::GetInRawSize(
        m_values, true);
  }
  virtual size_t PackEntryToBuff(running_ptr& run_ptr) {
    return CSEntriesArrayBase<CMemoryObjectEx<output_policy> >::PackEntryToBuff(
        run_ptr, m_values, &m_suggestion_type);
  }
  //-----------------------------------------------------------------------------------------------------
  virtual bool EnumChilds(penum_func enum_func, void* pparam) {
    size_t countet = 0;
    std::string name;
    for (typename values_container::iterator it = m_values.begin();
        it != m_values.end(); it++, countet++)
      enum_func(
          pparam,
          it->get(),
          (name = std::string("[") + boost::lexical_cast<std::string>(countet)
              + "]").c_str());

    return true;
  }
  //-----------------------------------------------------------------------------------------------------
  virtual bool TraseEntryAsXml(std::stringstream& general_stream,
                               std::stringstream& in_sectionstream,
                               size_t indent, const std::string& sec_name) {
    for (typename values_container::iterator it = m_values.begin();
        it != m_values.end(); it++)
      it->get()->TraseEntryAsXml(general_stream, in_sectionstream, indent,
                                 sec_name, m_suggestion_type);

    return true;
  }
  //-----------------------------------------------------------------------------------------------------
  virtual bool TraseEntryAsJson(std::stringstream& general, size_t indent) {

    general << "[";
    typename values_container::iterator it2 = m_values.begin();
    if (it2 != m_values.end())
      ++it2;

    for (typename values_container::iterator it = m_values.begin();
        it != m_values.end(); it++) {
      it->get()->TraseEntryAsJson(general, indent, m_suggestion_type);
      if (it2 != m_values.end()) {
        general << ",";
        it2++;
      }
    }
    general << "]";

    return true;
  }
  //-----------------------------------------------------------------------------------------------------
  virtual size_t UnPackEntryFromBuff(running_ptr& run_ptr) {
    size_t unpacked_size =
        CSEntriesArrayBase<CMemoryObjectEx<output_policy> >::UnPackEntryFromBuff(
            run_ptr, m_values, &m_suggestion_type);
    m_current_it = m_values.begin();
    return unpacked_size;
  }
  //-----
  s_byte m_suggestion_type;
  values_container m_values;
  //current enum pointer
  typename values_container::iterator m_current_it;
};

//factory method
template<class output_policy>
inline ISSectionEntry* BuildEntryByType(s_byte type) {
  switch (type) {
    case STORAGE_ENTRY_TYPE_SECTION:
      return new CSSection<output_policy> ;
    case STORAGE_ENTRY_TYPE_VAL:
      return new CSValue<output_policy> ;
    case STORAGE_ENTRY_TYPE_SECTION_ARRAY:
      return new CSSectionsArray<output_policy> ;
    case STORAGE_ENTRY_TYPE_VALUE_ARRAY:
      return new CSValuesArray<output_policy> ;
  }
  ASSERT_INTERNAL(0);
  return NULL;
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
template<class output_policy>
class CInMemStorageImpl {
 public:

  //handle-like aliases
  typedef CSSection<output_policy>* HSSECTION;
  typedef CSValuesArray<output_policy>* HSVALARRAY;
  typedef CSSectionsArray<output_policy>* HSSECARRAY;

  CInMemStorageImpl() {
  }
  virtual ~CInMemStorageImpl() {
  }
  //----- IStorage ----------------------------------------------
  HSSECTION OpenSection(const char* pSectionName, HSSECTION hParentSection =
                            NULL,
                        bool createIfNotExist = false);
  bool GetValue(const char* pValueName, CMemoryObject* pTargetObj,
                HSSECTION hParentSection = NULL,
                unsigned char* pTipFlags = NULL);
  bool SetValue(const char* pValueName, const CMemoryObject* pTargetObj,
                HSSECTION hParentSection = NULL, unsigned char tipFlags = NULL);

  //serial access for arrays of values --------------------------------------
  //values
  HSVALARRAY GetFirstValue(const char* pValueName, CMemoryObject* pTargetObj,
                           HSSECTION hParentSection = NULL,
                           unsigned char* pTipFlags = NULL);
  bool GetNextValue(HSVALARRAY hValArray, CMemoryObject* pTargetObj);
  HSVALARRAY InsertFirstValue(const char* pValueName,
                              const CMemoryObject* pTargetObj,
                              HSSECTION hParentSection = NULL,
                              unsigned char tipFlags = NULL);
  bool InsertNextValue(HSVALARRAY hValArray, const CMemoryObject* pTargetObj);
  //sections
  HSSECARRAY GetFirstSection(const char* pSectionName,
                             HSSECTION* phChildSection,
                             HSSECTION hParentSection = NULL);
  bool GetNextSection(HSSECARRAY hSecArray, HSSECTION* phChildSection);
  HSSECARRAY InsertFirstSection(const char* pSectionName,
                                HSSECTION* phInsertedChildSection,
                                HSSECTION hParentSection = NULL);
  bool InsertNextSection(HSSECARRAY hSecArray,
                         HSSECTION* phInsertedChildSection);

  template<class THandle>
  bool CloseStorageHandle(THandle storageHandle) {
    return true;
  }
  //------------------------------------------------------------------------
  //delete entry (section, value or array)
  virtual bool DeleteEntry(const char* pEntryName, HSSECTION hParentSection =
                               NULL);

  //-------------------------------------------------------------------------------
  size_t PackToSolidBuffer(CMemoryObject* pTargetObj);
  size_t LoadFromSolidBuffer(CMemoryObject* pTargetObj);
  size_t PackToSolidBuffer(std::string& pTargetObj);
  size_t LoadFromSolidBuffer(const std::string& pTargetObj);

  //HSSECARRAY  TrasformSectionToSectionArray(HSSECTION hParentSection, HSSECTION hSectionToTransform);
  bool TraceAsXML(std::string& targetObj, const std::string& root_name = "");
  bool TraceAsXML2(std::string& targetObj);
  HSSECTION GetRootSection() {
    return &m_rootSection;
  }
  bool TraceAsJson(std::string& targetObj);

 protected:
 private:
  CSSection<output_policy> m_rootSection;

  ISSectionEntry* GetSecEntry(const char* pEntryName,
                              CSSection<output_policy>* pSection = NULL);
  bool InsertSecEntry(const char* pEntryName, ISSectionEntry* pEntry,
                      CSSection<output_policy>* pSection = NULL);
#pragma pack(push)
#pragma pack(1)
  struct StorageMemBlockHeader {
    s_dword m_SignatureA;
    s_dword m_SignatureB;
    s_byte m_FormatVer;
    StorageMemBlockHeader()
        : m_SignatureA(STORAGE_SIGNATUREA),
          m_SignatureB(STORAGE_SIGNATUREB),
          m_FormatVer(CURRENT_FORMAT_VER) {
    }
  };
#pragma pack(pop)
};

/*
 template<class output_policy>
 class CInMemStorageImpl2: public CInMemStorageImpl<output_policy>
 {

 }*/

/*
 typedef CInMemStorage<xml_policy>::HSSECTION  HSSECTION;
 typedef CInMemStorage<xml_policy>::HSVALARRAY HSVALARRAY;
 typedef CInMemStorage<xml_policy>::HSSECARRAY HSSECARRAY;
 */
template<class output_policy>
inline ISSectionEntry* CInMemStorageImpl<output_policy>::GetSecEntry(
    const char* pEntryName, CSSection<output_policy>* pSection) {
  if (!pSection)
    pSection = &m_rootSection;
  typename CSSection<output_policy>::section_container::iterator it = pSection
      ->m_section_entries.find(pEntryName);
  //check section entry existence
  if (it == pSection->m_section_entries.end())
    return NULL;
  return it->second.get();
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::InsertSecEntry(
    const char* pEntryName, ISSectionEntry* pEntry,
    CSSection<output_policy>* pSection) {
  if (!pSection)
    pSection = &m_rootSection;
  boost::shared_ptr<ISSectionEntry> entry_ptr(pEntry);
  pSection->m_section_entries[pEntryName] = entry_ptr;
  return true;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline typename CInMemStorageImpl<output_policy>::HSSECTION CInMemStorageImpl<
    output_policy>::OpenSection(const char* pSectionName,
                                HSSECTION hParentSection,
                                bool createIfNotExist) {
  CHECK_AND_ASSERT(pSectionName, NULL);
  CSSection<output_policy>* pCurrentSection =
      hParentSection ? hParentSection : &m_rootSection;
  ISSectionEntry* pEntry = GetSecEntry(pSectionName, pCurrentSection);
  if (!pEntry) {
    if (!createIfNotExist)
      return NULL;
    if (!InsertSecEntry(pSectionName, pEntry = new CSSection<output_policy>,
                        pCurrentSection))
      return NULL;
  }
  CHECK_AND_ASSERT(pEntry, NULL);
  //check that section_entry we find is real "CSSection"
  if (STORAGE_ENTRY_TYPE_SECTION_ARRAY == pEntry->GetEntryType()) {	//Òóò ïðîñòî âåðí¸ì ïåðâóþ ñåêöèþ
    CSSectionsArray<output_policy>* pSecArray =
        (CSSectionsArray<output_policy>*) pEntry;
    if (!pSecArray->m_sections.size())
      return NULL;
    ISSectionEntry* pArrayEntry = pSecArray->m_sections.front().get();
    if (STORAGE_ENTRY_TYPE_SECTION != pArrayEntry->GetEntryType())
      return NULL;
    return (HSSECTION) pArrayEntry;
  }

  if (STORAGE_ENTRY_TYPE_SECTION != pEntry->GetEntryType())
    return NULL;

  return (HSSECTION) pEntry;
}
//----------------------------------------------------------------------------------------------------------------------------------------
/*inline HSSECARRAY  CInMemStorage::TrasformSectionToSectionArray(HSSECTION hParentSection, HSSECTION hSectionToTransform)
 {
 if(!hParentSection || !hSectionToTransform)
 return NULL;
 CSSection* pParentSection = hParentSection;
 CSSection::section_container::iterator it = pParentSection->m_section_entries.begin();
 for(; it!=pParentSection->m_section_entries.end(); it++)
 if(it->second.get() == hSectionToTransform)
 break;

 if(it==pParentSection->m_section_entries.end())
 return NULL;

 //Ñêîïèðîâàëè ññûëêó íà ñåêöèþ
 boost::shared_ptr<ISSectionEntry> old_sec = it->second;
 //old_sec.swap()

 //CSSectionsArray* pnew_sec_array = new CSSectionsArray();
 //it->second.reset(pnew_sec_array);

 //pnew_sec_array->m_sections.push_back( old_sec);

 return NULL;
 }*/
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::GetValue(
    const char* pValueName, CMemoryObject* pTargetObj, HSSECTION hParentSection,
    s_byte* pTipFlags) {
  CHECK_AND_ASSERT(pValueName && pTargetObj, NULL);
  ISSectionEntry* pEntry = GetSecEntry(pValueName, hParentSection);
  if (!pEntry)
    return false;

  //check entry type
  int sec_type = pEntry->GetEntryType();
  if (STORAGE_ENTRY_TYPE_VAL == sec_type) {
    CSValue<output_policy>* pValue = (CSValue<output_policy>*) pEntry;
    *pTargetObj = pValue->m_val;			//copy raw data
    if (pTipFlags)
      *pTipFlags = pValue->m_suggestion_type;
    return true;
  } else if (STORAGE_ENTRY_TYPE_VALUE_ARRAY == sec_type) {  //Âåðí¸ì ïåðâûé ýëåìåíò, íàì íåæàëêî
    CSValuesArray<output_policy>* pValuesArray =
        (CSValuesArray<output_policy>*) pEntry;
    if (!pValuesArray->m_values.size())
      return false;
    *pTargetObj = *pValuesArray->m_values.front().get();
    return true;
  } else
    //entry is not can't be value
    return false;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::SetValue(
    const char* pValueName, const CMemoryObject* pTargetObj,
    HSSECTION hParentSection, s_byte tipFlags) {
  CHECK_AND_ASSERT(pValueName && pTargetObj, NULL);
  CSSection<output_policy>*pCurrentSection =
      hParentSection ?
          (CSSection<output_policy>*) hParentSection : &m_rootSection;
  ISSectionEntry* pEntry = GetSecEntry(pValueName, pCurrentSection);
  if (!pEntry)   //need to create new entry
    InsertSecEntry(pValueName, pEntry = new CSValue<output_policy>,
                   pCurrentSection);

  //check entry type
  int sec_type = pEntry->GetEntryType();
  if (STORAGE_ENTRY_TYPE_VAL == sec_type) {
    CSValue<output_policy>* pValue = (CSValue<output_policy>*) pEntry;
    pValue->m_val = *pTargetObj;   //copy raw data
    pValue->m_suggestion_type = tipFlags;
    return true;
  } else if (STORAGE_ENTRY_TYPE_VALUE_ARRAY == sec_type) {
    //TODO
    return false;
  } else
    //entry is not can't be value
    return false;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline typename CInMemStorageImpl<output_policy>::HSVALARRAY CInMemStorageImpl<
    output_policy>::GetFirstValue(const char* pValueName,
                                  CMemoryObject* pTargetObj,
                                  HSSECTION hParentSection, s_byte* pTipFlags) {
  CHECK_AND_ASSERT(pValueName && pTargetObj, NULL);
  ISSectionEntry* pEntry = GetSecEntry(
      pValueName, (CSSection<output_policy>*) hParentSection);
  if (!pEntry)
    return NULL;

  int entry_type = pEntry->GetEntryType();
  if (STORAGE_ENTRY_TYPE_VALUE_ARRAY == entry_type) {   //good!
    CSValuesArray<output_policy>* pValArray =
        (CSValuesArray<output_policy>*) pEntry;
    if (!pValArray->m_values.size())
      return NULL;   //dubious way ;)
    pValArray->m_current_it = pValArray->m_values.begin();
    *pTargetObj = *pValArray->m_current_it->get();
    pValArray->m_current_it++;
    return pValArray;
  } else if (STORAGE_ENTRY_TYPE_VAL == entry_type) {
    //TODO
    return NULL;
  } else
    return NULL;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::GetNextValue(
    HSVALARRAY hValArray, CMemoryObject* pTargetObj) {
  CHECK_AND_ASSERT(hValArray && pTargetObj, false);
  CSValuesArray<output_policy>* pValArray = hValArray;
  if (pValArray->m_current_it == pValArray->m_values.end())
    return false;
  *pTargetObj = *pValArray->m_current_it->get();
  pValArray->m_current_it++;
  return true;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline typename CInMemStorageImpl<output_policy>::HSVALARRAY CInMemStorageImpl<
    output_policy>::InsertFirstValue(const char* pValueName,
                                     const CMemoryObject* pTargetObj,
                                     HSSECTION hParentSection,
                                     s_byte tipFlags) {
  CHECK_AND_ASSERT(pValueName && pTargetObj, NULL);
  CSValuesArray<output_policy>* pValuesArray = NULL;
  CSSection<output_policy>* pCurrentSection =
      hParentSection ? hParentSection : &m_rootSection;
  ISSectionEntry* pEntry = GetSecEntry(pValueName, pCurrentSection);
  if (!pEntry)   //initialize new values array
    InsertSecEntry(pValueName, pValuesArray = new CSValuesArray<output_policy>,
                   pCurrentSection);
  else {   //some entry with this name already exist, check it
    int entry_type = pEntry->GetEntryType();
    if (STORAGE_ENTRY_TYPE_SECTION == entry_type)   //i worry about sections
      return NULL;
    else if (STORAGE_ENTRY_TYPE_VAL == entry_type)  //i don't worry about values, delete value and insert new values array
      InsertSecEntry(pValueName, pValuesArray =
                         new CSValuesArray<output_policy>,
                     pCurrentSection);
    else if (STORAGE_ENTRY_TYPE_VALUE_ARRAY == entry_type)  //good! that what we actually search!
      pValuesArray = (CSValuesArray<output_policy>*) pEntry;
    else
      //and i worry  about everything else
      return NULL;
  }
  //now pValuesArray mast have valid pointer
  CHECK_AND_ASSERT(pValuesArray, NULL);
  if (pValuesArray->m_values.size())
    pValuesArray->m_values.clear();
  //set first value and flags
  pValuesArray->m_suggestion_type = tipFlags;
  pValuesArray->m_values.push_back(
      boost::shared_ptr<CMemoryObjectEx<output_policy> >(
          new CMemoryObjectEx<output_policy>(*pTargetObj)));

  return pValuesArray;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::InsertNextValue(
    HSVALARRAY hValArray, const CMemoryObject* pTargetObj) {
  CHECK_AND_ASSERT(hValArray && pTargetObj, false);
  CSValuesArray<output_policy>* pValuesArray = hValArray;
  pValuesArray->m_values.push_back(
      boost::shared_ptr<CMemoryObjectEx<output_policy> >(
          new CMemoryObjectEx<output_policy>(*pTargetObj)));
  return true;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline typename CInMemStorageImpl<output_policy>::HSSECARRAY CInMemStorageImpl<
    output_policy>::GetFirstSection(const char* pSectionName,
                                    HSSECTION* phChildSection,
                                    HSSECTION hParentSection) {
  CHECK_AND_ASSERT(pSectionName && phChildSection, NULL);
  ISSectionEntry* pEntry = GetSecEntry(pSectionName, hParentSection);
  if (!pEntry)
    return NULL;

  int entry_type = pEntry->GetEntryType();
  if (STORAGE_ENTRY_TYPE_SECTION_ARRAY == entry_type) {  //good!
    CSSectionsArray<output_policy>* pSecArray =
        (CSSectionsArray<output_policy>*) pEntry;
    if (!pSecArray->m_sections.size())
      return NULL;  //dubious way ;)
    pSecArray->m_current_it = pSecArray->m_sections.begin();
    *phChildSection = pSecArray->m_current_it->get();
    pSecArray->m_current_it++;
    return pSecArray;
  } else if (STORAGE_ENTRY_TYPE_SECTION == entry_type) {
    //TODO
    return NULL;
  } else
    return NULL;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::GetNextSection(
    HSSECARRAY hSecArray, HSSECTION* phChildSection) {
  CHECK_AND_ASSERT(hSecArray && phChildSection, false);
  CSSectionsArray<output_policy>* pSecArray = hSecArray;
  if (pSecArray->m_current_it == pSecArray->m_sections.end())
    return false;  //matched end of the array
  *phChildSection = pSecArray->m_current_it->get();
  pSecArray->m_current_it++;
  return true;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline typename CInMemStorageImpl<output_policy>::HSSECARRAY CInMemStorageImpl<
    output_policy>::InsertFirstSection(const char* pSectinName,
                                       HSSECTION* phInsertedChildSection,
                                       HSSECTION hParentSection) {
  CHECK_AND_ASSERT(pSectinName && phInsertedChildSection, NULL);
  CSSectionsArray<output_policy>* pSectionsArray = NULL;
  CSSection<output_policy>* pCurrentSection =
      hParentSection ? hParentSection : &m_rootSection;
  ISSectionEntry* pEntry = GetSecEntry(pSectinName, pCurrentSection);
  if (!pEntry)  //initialize new sections array
    InsertSecEntry(pSectinName,
                   pSectionsArray = new CSSectionsArray<output_policy>,
                   pCurrentSection);
  else {  //some entry with this name already exist, check it
    int entry_type = pEntry->GetEntryType();
    if (STORAGE_ENTRY_TYPE_SECTION == entry_type)  //i worry about sections
      return NULL;
    else if (STORAGE_ENTRY_TYPE_VAL == entry_type)  //i don't worry about values, delete value and insert new sections array
      InsertSecEntry(pSectinName,
                     pSectionsArray = new CSSectionsArray<output_policy>,
                     pCurrentSection);
    else if (STORAGE_ENTRY_TYPE_SECTION_ARRAY == entry_type)  //good! that what we actually search!
      pSectionsArray = (CSSectionsArray<output_policy>*) pEntry;
    else
      //and i worry  about everything else
      return NULL;
  }
  //now pValuesArray mast have valid pointer
  CHECK_AND_ASSERT(pSectionsArray, NULL);
  if (pSectionsArray->m_sections.size())
    pSectionsArray->m_sections.clear();
  //set first value and flags
  pSectionsArray->m_sections.push_back(
      boost::shared_ptr<CSSection<output_policy> >(
          new CSSection<output_policy>));
  *phInsertedChildSection = pSectionsArray->m_sections.rbegin()->get();
  return pSectionsArray;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::InsertNextSection(
    HSSECARRAY hSecArray, HSSECTION* phInsertedChildSection) {
  CHECK_AND_ASSERT(hSecArray && phInsertedChildSection, false);
  CSSectionsArray<output_policy>* pSectionsArray = hSecArray;
  pSectionsArray->m_sections.push_back(
      boost::shared_ptr<CSSection<output_policy> >(
          new CSSection<output_policy>));
  *phInsertedChildSection = pSectionsArray->m_sections.rbegin()->get();
  return true;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::DeleteEntry(
    const char* pEntryName, HSSECTION hParentSection) {
  CHECK_AND_ASSERT(pEntryName, false);
  CSSection<output_policy>* pCurrentSection =
      hParentSection ? hParentSection : &m_rootSection;
  if (pCurrentSection->m_section_entries.erase(pEntryName))
    return true;
  else
    return false;
}

//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline size_t CInMemStorageImpl<output_policy>::PackToSolidBuffer(
    CMemoryObject* pTargetObj) {
  CHECK_AND_ASSERT(pTargetObj, false);
  size_t all_size = m_rootSection.GetInRawSize();
  StorageMemBlockHeader storage_header;
  char* pbuff = (char*) pTargetObj->alloc_buff(
      all_size + sizeof(storage_header));
  CHECK_AND_ASSERT(pbuff, false);
  memcpy(pbuff, &storage_header, sizeof(storage_header));
  running_ptr run_ptr;
  run_ptr.attach(pbuff + sizeof(storage_header), all_size);
  size_t packed_size = m_rootSection.PackEntryToBuff(run_ptr);
  return packed_size + sizeof(storage_header);
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline size_t CInMemStorageImpl<output_policy>::LoadFromSolidBuffer(
    CMemoryObject* pTargetObj) {
  size_t buff_size = 0;
  s_byte* pbuff = (s_byte*) pTargetObj->get(&buff_size);
  if (buff_size <= sizeof(StorageMemBlockHeader))
    return 0;
  StorageMemBlockHeader* pStorageHeader = (StorageMemBlockHeader*) pbuff;
  if (pStorageHeader->m_SignatureA != STORAGE_SIGNATUREA
      || pStorageHeader->m_SignatureB != STORAGE_SIGNATUREB)
    return 0;
  if (pStorageHeader->m_FormatVer > CURRENT_FORMAT_VER)
    return 0;

  running_ptr run_ptr;
  run_ptr.attach(pbuff + sizeof(StorageMemBlockHeader),
                 buff_size - sizeof(StorageMemBlockHeader));
  size_t unpacked_size = m_rootSection.UnPackEntryFromBuff(run_ptr);
  return unpacked_size + sizeof(StorageMemBlockHeader);
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline size_t CInMemStorageImpl<output_policy>::PackToSolidBuffer(
    std::string& targetObj) {
  size_t all_size = m_rootSection.GetInRawSize();
  StorageMemBlockHeader storage_header;
  targetObj.resize(all_size + sizeof(storage_header));
  char* pbuff = (char*) targetObj.data();
  CHECK_AND_ASSERT(pbuff, false);
  memcpy(pbuff, &storage_header, sizeof(storage_header));
  running_ptr run_ptr;
  run_ptr.attach(pbuff + sizeof(storage_header), all_size);
  size_t packed_size = m_rootSection.PackEntryToBuff(run_ptr);
  return packed_size + sizeof(storage_header);
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline size_t CInMemStorageImpl<output_policy>::LoadFromSolidBuffer(
    const std::string& targetObj) {
  size_t buff_size = targetObj.size();
  s_byte* pbuff = (s_byte*) targetObj.data();
  if (buff_size <= sizeof(StorageMemBlockHeader))
    return 0;
  StorageMemBlockHeader* pStorageHeader = (StorageMemBlockHeader*) pbuff;
  if (pStorageHeader->m_SignatureA != STORAGE_SIGNATUREA
      || pStorageHeader->m_SignatureB != STORAGE_SIGNATUREB)
    return 0;
  if (pStorageHeader->m_FormatVer > CURRENT_FORMAT_VER)
    return 0;

  running_ptr run_ptr;
  run_ptr.attach(pbuff + sizeof(StorageMemBlockHeader),
                 buff_size - sizeof(StorageMemBlockHeader));
  size_t unpacked_size = m_rootSection.UnPackEntryFromBuff(run_ptr);
  return unpacked_size + sizeof(StorageMemBlockHeader);
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::TraceAsXML(
    std::string& targetObj, const std::string& root_name) {
  std::stringstream strm_genral;
  std::stringstream strm_in_section;
  m_rootSection.TraseEntryAsXml(strm_genral, strm_in_section, 0, root_name);

  targetObj += strm_genral.str();
  return true;
}
//----------------------------------------------------------------------------------------------------------------------------------------
template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::TraceAsXML2(
    std::string& targetObj) {
  std::stringstream strm_genral;
  std::stringstream strm_in_section;
  m_rootSection.TraseEntryAsXml(strm_genral, strm_in_section, 0, "root");

  targetObj = strm_genral.str();
  return true;
}

template<class output_policy>
inline bool CInMemStorageImpl<output_policy>::TraceAsJson(
    std::string& targetObj) {
  std::stringstream strm;
  m_rootSection.TraseEntryAsJson(strm, 0);
  targetObj = strm.str();
  return true;
}

//----------------------------------------------------------------------------------------------------------------------------------------
//inline bool	 CInMemStorage::TraceSectionAsXML(HSSECTION hsec, std::stringstream& general_stream, std::stringstream& in_sectionstream, size_t indent, const std::string& sec_name)
//{
//}
//----------------------------------------------------------------------------------------------------------------------------------------

typedef CInMemStorageImpl<memory_object_xml_policy_big> CInMemStorage;
typedef CInMemStorageImpl<memory_object_xml_policy_classic> CInMemStorage_xml2;
}

typedef InMemStorageSpace::CInMemStorage CInMemStorage;
typedef InMemStorageSpace::CInMemStorage_xml2 CInMemStorage_xml2;
}
}

#endif //_STORAGE_H_
