
#ifndef _SERIALIZESTORAGE_H_
#define _SERIALIZESTORAGE_H_

#include "mem_block.h"

#ifndef LC_ASSERT
#define LC_ASSERT(expression)
#endif

#ifndef CHECK_AND_ASSERT
#define CHECK_AND_ASSERT(expression, fail_return_val) {LC_ASSERT(expression); if(!(expression)) return fail_return_val;}
#endif

namespace epee {
//data types (suggestion flags)
#define STORAGE_TYPE_UNDEFINED            0
#define STORAGE_TYPE_SKALAR               1
#define STORAGE_TYPE_ANSI_STRING          2
#define STORAGE_TYPE_UNICODE_STRING       3

/************************************************************************/
/* Serialize map declarations                                           */
/************************************************************************/
#define BEGIN_NAMED_SERIALIZE_MAP() \
public: \
	template<class StorageType> \
	bool Store( StorageType* pStorage, typename StorageType::HSSECTION hParentSection = NULL)\
{\
	return SerializeMap(pStorage, hParentSection, true);\
}\
	template<class StorageType> \
	bool Load ( StorageType* pStorage, typename StorageType::HSSECTION hParentSection = NULL)\
{\
	return SerializeMap(pStorage, hParentSection, false);\
}\
	template<class StorageType> \
	bool SerializeMap(StorageType* pStorage, typename StorageType::HSSECTION hParentSection, bool bSerialze) \
{ \
	/*int count = 0;*/ \
	bool res = 0;

#define BEGIN_NAMED_SERIALIZE_MAP_OVERRIDE_STORE() \
public: \
	template<class StorageType> \
	bool Store_( StorageType* pStorage, typename StorageType::HSSECTION hParentSection = NULL)\
{\
	return SerializeMap(pStorage, hParentSection, true);\
}\
	template<class StorageType> \
	bool Load ( StorageType* pStorage, typename StorageType::HSSECTION hParentSection = NULL)\
{\
	return SerializeMap(pStorage, hParentSection, false);\
}\
	template<class StorageType> \
	bool SerializeMap(StorageType* pStorage, typename StorageType::HSSECTION hParentSection, bool bSerialze) \
{ \
	/*int count = 0;*/ \
	bool res = 0;

#define BEGIN_NAMED_SERIALIZE_MAP_OVERRIDE_LOAD() \
public: \
	template<class StorageType> \
	bool Store( StorageType* pStorage, typename StorageType::HSSECTION hParentSection = NULL)\
{\
	return SerializeMap(pStorage, hParentSection, true);\
}\
	template<class StorageType> \
	bool Load_ ( StorageType* pStorage, typename StorageType::HSSECTION hParentSection = NULL)\
{\
	return SerializeMap(pStorage, hParentSection, false);\
}\
	template<class StorageType> \
	bool SerializeMap(StorageType* pStorage, typename StorageType::HSSECTION hParentSection, bool bSerialze) \
{ \
	/*int count = 0;*/ \
	bool res = 0;

#define BEGIN_NAMED_SERIALIZE_MAP_OVERRIDE() \
public: \
	template<class StorageType> \
	bool Store_( StorageType* pStorage, typename StorageType::HSSECTION hParentSection = NULL)\
{\
	return SerializeMap(pStorage, hParentSection, true);\
}\
	template<class StorageType> \
	bool Load_ ( StorageType* pStorage, typename StorageType::HSSECTION hParentSection = NULL)\
{\
	return SerializeMap(pStorage, hParentSection, false);\
}\
	template<class StorageType> \
	bool SerializeMap(StorageType* pStorage, typename StorageType::HSSECTION hParentSection, bool bSerialze) \
{ \
	/*int count = 0;*/ \
	bool res = 0;

#define N_SERIALIZE_POD(varialble, val_name) \
	if(bSerialze) \
  res |= epee::CStorageSerialize::SerializeNative(varialble, pStorage, hParentSection, val_name); \
	else \
	res |= epee::CStorageSerialize::UnSerializeNative(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

#define N_SERIALIZE_ANSI_STRING(varialble, val_name) \
	if(bSerialze) \
	res |= epee::CStorageSerialize::SerializeStringAnsi(varialble, pStorage, hParentSection, val_name); \
	else \
	res	|= epee::CStorageSerialize::UnSerializeStringAnsi(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

#define N_SERIALIZE_UNICODE_STRING(varialble, val_name) \
	if(bSerialze) \
	res |= epee::CStorageSerialize::SerializeStringUnicode(varialble, pStorage, hParentSection, val_name); \
	else \
	res	|= epee::CStorageSerialize::UnSerializeStringUnicode(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

#define N_SERIALIZE_STL_ANSI_STRING(varialble, val_name) \
	if(bSerialze) \
	res |= epee::CStorageSerialize::SerializeStlStringAnsi(varialble, pStorage, hParentSection, val_name); \
	else \
	res	|= epee::CStorageSerialize::UnSerializeStlStringAnsi(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

#define N_SERIALIZE_STL_UNICODE_STRING(varialble, val_name) \
	if(bSerialze) \
	res |= epee::CStorageSerialize::SerializeStlStringUnicode(varialble, pStorage, hParentSection, val_name); \
	else \
	res	|= epee::CStorageSerialize::UnSerializeStlStringUnicode(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

// serialize stl container like std::list<> and std::vector<> with POD types
#define N_SERIALIZE_STL_CONTAINER_POD(varialble, val_name) \
	if(bSerialze) \
	res |= epee::CStorageSerialize::SerializeSTL_Pod(varialble, pStorage, hParentSection, val_name); \
	else \
	res |= epee::CStorageSerialize::UnSerializeSTL_Pod(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

// serialize stl container like std::list<> and std::vector<> with serializeble types
#define N_SERIALIZE_STL_CONTAINER_T(varialble, val_name) \
	if(bSerialze) \
	res |= epee::CStorageSerialize::SerializeSTL_T(varialble, pStorage, hParentSection, val_name); \
	else \
	res |= epee::CStorageSerialize::UnSerializeSTL_T(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

//
#define N_SERIALIZE_STL_CONTAINER_ANSII_STRING(varialble, val_name) \
	if(bSerialze) \
	res |= epee::CStorageSerialize::SerializeSTLContainerTString(varialble, pStorage, hParentSection, val_name, STORAGE_TYPE_ANSI_STRING); \
	else \
	res |= epee::CStorageSerialize::UnSerializeSTLContainerTString(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

#define N_SERIALIZE_STL_CONTAINER_UNICODE_STRING(varialble, val_name) \
	if(bSerialze) \
	res |= epee::CStorageSerialize::SerializeSTLContainerTString(varialble, pStorage, hParentSection, val_name, STORAGE_TYPE_UNICODE_STRING); \
	else \
	res |= epee::CStorageSerialize::UnSerializeSTLContainerTString(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

#define N_SERIALIZE_T(varialble, val_name) \
	if(bSerialze) \
	res |= epee::CStorageSerialize::SerializeT(varialble, pStorage, hParentSection, val_name); \
	else \
	res |= epee::CStorageSerialize::UnSerializeT(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

#define N_SERIALIZE_MEM_BLOCK(varialble, val_name) \
	if(bSerialze) \
	res |= epee::CStorageSerialize::SerializeMemBlock(varialble, pStorage, hParentSection, val_name); \
	else \
	res |= epee::CStorageSerialize::UnSerializeMemBlock(varialble, pStorage, hParentSection, val_name); \
	if(/*!res*/false) return res;

#define END_NAMED_SERIALIZE_MAP() \
	return res;}

#define SERIALIZE_POD(varialble)                  N_SERIALIZE_POD(varialble, #varialble)
#define SERIALIZE_ANSI_STRING(varialble)          N_SERIALIZE_ANSI_STRING(varialble, #varialble)
#define SERIALIZE_UNICODE_STRING(varialble)       N_SERIALIZE_UNICODE_STRING(varialble, #varialble)
#define SERIALIZE_STL_ANSI_STRING(varialble)      N_SERIALIZE_STL_ANSI_STRING(varialble, #varialble)
#define SERIALIZE_STL_UNICODE_STRING(varialble)   N_SERIALIZE_STL_UNICODE_STRING(varialble, #varialble)
#define SERIALIZE_STL_CONTAINER_POD(varialble)    N_SERIALIZE_STL_CONTAINER_POD(varialble, #varialble)
#define SERIALIZE_STL_CONTAINER_T(varialble)      N_SERIALIZE_STL_CONTAINER_T(varialble, #varialble)
#define SERIALIZE_T(varialble)                    N_SERIALIZE_T(varialble, #varialble)
#define SERIALIZE_MEM_BLOCK(varialble)            N_SERIALIZE_MEM_BLOCK(varialble, #varialble)
#define SERIALIZE_STL_CONTAINER_ANSII_STRING(varialble)      N_SERIALIZE_STL_CONTAINER_ANSII_STRING(varialble, #varialble)
#define SERIALIZE_STL_CONTAINER_UNICODE_STRING(varialble)    N_SERIALIZE_STL_CONTAINER_UNICODE_STRING(varialble, #varialble)

//std::pair

template<class t_obj>
struct enableable {
  t_obj v;
  bool enabled;

  enableable()
      : v(t_obj()),
        enabled(true) {  // construct from defaults
  }

  enableable(const t_obj& _v)
      : v(_v),
        enabled(true) {  // construct from specified values
  }

  enableable(const enableable<t_obj>& _v)
      : v(_v.v),
        enabled(_v.enabled) {  // construct from specified values
  }

};

/************************************************************************/
/*  CStorageSerialize -                                                    */
/************************************************************************/
class CStorageSerialize {
  //decleare private constructor and destructor to avoid creating of instance
  CStorageSerialize() {
  }
  virtual ~CStorageSerialize() {
  }
 public:

  template<class Native, class StorageType>
  static bool SerializeNative(const Native& nativeData, StorageType* pStorage,
                              typename StorageType::HSSECTION hParentSection,
                              const char* pValName) {
    fake_mem_block fkmb(&nativeData, sizeof(nativeData));
    return pStorage->SetValue(pValName, &fkmb, hParentSection,
                              STORAGE_TYPE_SKALAR);
  }
  //-------------------------------------------------------------------------------------------------------------------
  template<class Native, class StorageType>
  static bool UnSerializeNative(Native& nativeData, StorageType* pStorage,
                                typename StorageType::HSSECTION hParentSection,
                                const char* pValName) {
    memset(&nativeData, 0, sizeof(nativeData));

    mem_block tmp_obj;
    bool res = pStorage->GetValue(pValName, &tmp_obj, hParentSection);
    if (res) {
      size_t loadedSize = tmp_obj.get_size();
      memcpy((void*) &nativeData, tmp_obj.get(0),
             loadedSize > sizeof(nativeData) ? sizeof(nativeData) : loadedSize);
    }
    return res;
  }

  //-------------------------------------------------------------------------------------------------------------------
  template<class SerializibleClass, class StorageType>
  static bool SerializeT(SerializibleClass& sObject, StorageType* pStorage,
                         typename StorageType::HSSECTION hParentSection,
                         const char* pValName) {
    bool res = false;
    if (pValName)  //if val name is NULL serialize to the same node
    {
      typename StorageType::HSSECTION hChildSection = pStorage->OpenSection(
          pValName, hParentSection, true);
      //pStorage->open_section( pValName, hParentSection, &child_cookie, STORAGE_FLAG_CREATE|STORAGE_FLAG_WRITE );
      res = sObject.Store(pStorage, hChildSection);
      pStorage->CloseStorageHandle(hChildSection);
    } else
      res = sObject.Store(pStorage, hParentSection);
    return res;
  }
  //-------------------------------------------------------------------------------------------------------------------
  template<class SerializibleClass, class StorageType>
  static bool UnSerializeT(SerializibleClass& sObject, StorageType* pStorage,
                           typename StorageType::HSSECTION hParentSection,
                           const char* pValName) {
    bool res = false;
    if (pValName)  //if val name is NULL unserialize from the same node
    {
      typename StorageType::HSSECTION hChildSection = pStorage->OpenSection(
          pValName, hParentSection, false);
      if (!hChildSection) {
        sObject = SerializibleClass();  // value initialization
        return false;
      }
      res = sObject.Load(pStorage, hChildSection);
      pStorage->CloseStorageHandle(hChildSection);
    } else
      res = sObject.Load(pStorage, hParentSection);

    return res;
  }
  //-------------------------------------------------------------------------------------------------------------------
  template<class SerializibleClass, class StorageType>
  static bool SerializeT(enableable<SerializibleClass>& sObject,
                         StorageType* pStorage,
                         typename StorageType::HSSECTION hParentSection,
                         const char* pValName) {
    if (!sObject.enabled)
      return true;

    bool res = false;
    if (pValName)  //if val name is NULL serialize to the same node
    {
      typename StorageType::HSSECTION hChildSection = pStorage->OpenSection(
          pValName, hParentSection, true);
      //pStorage->open_section( pValName, hParentSection, &child_cookie, STORAGE_FLAG_CREATE|STORAGE_FLAG_WRITE );
      res = sObject.v.Store(pStorage, hChildSection);
      pStorage->CloseStorageHandle(hChildSection);
    } else
      res = sObject.v.Store(pStorage, hParentSection);
    return res;
  }
  //-------------------------------------------------------------------------------------------------------------------
  template<class SerializibleClass, class StorageType>
  static bool UnSerializeT(enableable<SerializibleClass>& sObject,
                           StorageType* pStorage,
                           typename StorageType::HSSECTION hParentSection,
                           const char* pValName) {
    bool res = false;
    if (pValName)  //if val name is NULL unserialize from the same node
    {
      typename StorageType::HSSECTION hChildSection = pStorage->OpenSection(
          pValName, hParentSection, false);
      if (!hChildSection) {
        sObject.v = SerializibleClass();  // value initialization
        sObject.enabled = false;
        return false;
      }
      res = sObject.v.Load(pStorage, hChildSection);
      pStorage->CloseStorageHandle(hChildSection);
    } else
      res = sObject.v.Load(pStorage, hParentSection);

    sObject.enabled = true;
    return res;
  }
  //-------------------------------------------------------------------------------------------------------------------
  template<class CSerializibleString, class StorageType>
  static bool SerializeStringAnsi(
      CSerializibleString& str, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName) {
    return pStorage->SetValue(
        pValName, &fake_mem_block((const char*) str, str.GetLength() + 1),
        hParentSection, STORAGE_TYPE_ANSI_STRING);
  }
  //-------------------------------------------------------------------------------------------------------------------
  template<class CSerializibleString, class StorageType>
  static bool UnSerializeStringAnsi(
      CSerializibleString &str, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName) {
    CMemoryObject mem_obj;
    bool res = pStorage->GetValue(pValName, &mem_obj, hParentSection);
    if (res)
      str = (const char*) mem_obj.get(0);  //i think there is exist terminating zero
    return res;
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class CSerializibleString, class StorageType>
  static bool SerializeStringUnicode(
      CSerializibleString& str, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName) {
    return pStorage->SetValue(
        pValName,
        &fake_mem_block((const wchar_t*) str,
                        (str.GetLength() + 1) * sizeof(wchar_t)),
        hParentSection, STORAGE_TYPE_UNICODE_STRING);
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class CSerializibleString, class StorageType>
  static bool UnSerializeStringUnicode(
      CSerializibleString &str, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName) {
    CMemoryObject mem_obj;
    bool res = pStorage->GetValue(pValName, &mem_obj, hParentSection);
    if (res)
      str = (const wchar_t*) mem_obj.get(0);	//i think there is exist terminating zero
    return res;
  }

  //-------------------------------------------------------------------------------------------------------------------
  template<class CSerializibleString, class StorageType>
  static bool SerializeStlStringAnsi(
      CSerializibleString& str, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName) {
    fake_mem_block f(str.data(), str.size());
    return pStorage->SetValue(pValName, &f, hParentSection,
                              STORAGE_TYPE_ANSI_STRING);
  }
  //-------------------------------------------------------------------------------------------------------------------
  template<class CSerializibleString, class StorageType>
  static bool UnSerializeStlStringAnsi(
      CSerializibleString &str, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName) {
    CMemoryObject mem_obj;
    bool res = pStorage->GetValue(pValName, &mem_obj, hParentSection);
    if (res) {
      if (mem_obj.get_size() && mem_obj.get(0))
        str.assign((char*) mem_obj.get(0), mem_obj.get_size());
      else
        str.clear();
    }

    return res;
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class CSerializibleString, class StorageType>
  static bool SerializeStlStringUnicode(
      CSerializibleString& str, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName) {
    return pStorage->SetValue(
        pValName,
        &fake_mem_block((const wchar_t*) str.c_str(),
                        (str.length() + 1) * sizeof(wchar_t)),
        hParentSection, STORAGE_TYPE_UNICODE_STRING);
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class CSerializibleString, class StorageType>
  static bool UnSerializeStlStringUnicode(
      CSerializibleString &str, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName) {
    CMemoryObject mem_obj;
    bool res = pStorage->GetValue(pValName, &mem_obj, hParentSection);
    if (res)
      str = (const wchar_t*) mem_obj.get(0);	//i think there is exist terminating zero
    return res;
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class stl_container, class StorageType>
  static bool SerializeSTL_Pod(stl_container& container, StorageType* pStorage,
                               typename StorageType::HSSECTION hParentSection,
                               const char* pValName) {
    if (!container.size())
      return true;
    typename stl_container::iterator it = container.begin();
    fake_mem_block f(&(*it), sizeof(typename stl_container::value_type));
    typename StorageType::HSVALARRAY hValArray = pStorage->InsertFirstValue(
        pValName, &f, hParentSection, STORAGE_TYPE_SKALAR);
    CHECK_AND_ASSERT(hValArray, false);
    it++;
    for (; it != container.end(); it++) {
      fake_mem_block f(&(*it), sizeof(typename stl_container::value_type));
      pStorage->InsertNextValue(hValArray, &f);
    }

    pStorage->CloseStorageHandle(hValArray);
    return true;
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class stl_container, class StorageType>
  static bool UnSerializeSTL_Pod(stl_container& container,
                                 StorageType* pStorage,
                                 typename StorageType::HSSECTION hParentSection,
                                 const char* pValName) {
    bool res = false;
    container.clear();
    typename stl_container::value_type val;
    fake_mem_block f(&val, sizeof(val));
    typename StorageType::HSVALARRAY hValArray = pStorage->GetFirstValue(
        pValName, &f, hParentSection);
    if (!hValArray)
      return false;
    container.push_back(val);
    fake_mem_block f2(&val, sizeof(val));
    res = true;
    while (pStorage->GetNextValue(hValArray, &f2))
      container.push_back(val);

    pStorage->CloseStorageHandle(hValArray);
    return res;
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class stl_container, class StorageType>
  static bool SerializeSTL_T(stl_container& container, StorageType* pStorage,
                             typename StorageType::HSSECTION hParentSection,
                             const char* pValName) {
    bool res = false;
    if (!container.size())
      return true;
    typename stl_container::iterator it = container.begin();
    typename StorageType::HSSECTION hChildsection = NULL;
    typename StorageType::HSSECARRAY hSecArray = pStorage->InsertFirstSection(
        pValName, &hChildsection, hParentSection);
    CHECK_AND_ASSERT(hSecArray && hChildsection, false);
    res |= it->Store(pStorage, hChildsection);
    pStorage->CloseStorageHandle(hChildsection);
    it++;
    for (; it != container.end(); it++) {
      pStorage->InsertNextSection(hSecArray, &hChildsection);
      res |= it->Store(pStorage, hChildsection);
      pStorage->CloseStorageHandle(hChildsection);
    }

    pStorage->CloseStorageHandle(hSecArray);
    return res;
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class stl_container, class StorageType>
  static bool UnSerializeSTL_T(stl_container& container, StorageType* pStorage,
                               typename StorageType::HSSECTION hParentSection,
                               const char* pValName) {
    bool res = false;
    container.clear();
    typename stl_container::value_type val =
        typename stl_container::value_type();
    typename StorageType::HSSECTION hChildsection = NULL;
    typename StorageType::HSSECARRAY hSecArray = pStorage->GetFirstSection(
        pValName, &hChildsection, hParentSection);
    if (!hSecArray || !hChildsection)
      return false;
    val.Load(pStorage, hChildsection);
    pStorage->CloseStorageHandle(hChildsection);
    container.push_back(val);
    while (pStorage->GetNextSection(hSecArray, &hChildsection)) {
      typename stl_container::value_type val_l =
          typename stl_container::value_type();
      res |= val_l.Load(pStorage, hChildsection);
      container.push_back(val_l);
      pStorage->CloseStorageHandle(hChildsection);
    }

    pStorage->CloseStorageHandle(hSecArray);
    return res;
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class stl_container, class StorageType>
  static bool SerializeSTLContainerTString(
      stl_container& container, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName,
      int suggestion_type) {
    if (!container.size())
      return true;

    typename stl_container::iterator it = container.begin();
    typename StorageType::HSVALARRAY hValArray = pStorage->InsertFirstValue(
        pValName,
        &fake_mem_block(
            it->data(),
            it->size()
                * sizeof(typename stl_container::value_type::value_type)),
        hParentSection, suggestion_type);
    CHECK_AND_ASSERT(hValArray, false);
    it++;
    for (; it != container.end(); it++)
      pStorage->InsertNextValue(
          hValArray,
          &fake_mem_block(
              it->data(),
              it->size()
                  * sizeof(typename stl_container::value_type::value_type)));

    pStorage->CloseStorageHandle(hValArray);
    return true;
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class stl_container, class StorageType>
  static bool UnSerializeSTLContainerTString(
      stl_container& container, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName) {
    bool res = false;
    container.clear();
    mem_block reciever;
    typename StorageType::HSVALARRAY hValArray = pStorage->GetFirstValue(
        pValName, &reciever, hParentSection);
    if (!hValArray)
      return false;
    container.push_back(typename stl_container::value_type());
    container.back().assign(
        (const typename stl_container::value_type::value_type*) reciever.get(0),
        reciever.get_size()
            / sizeof(typename stl_container::value_type::value_type));

    res = true;
    while (pStorage->GetNextValue(hValArray, &reciever)) {
      container.push_back(typename stl_container::value_type());
      container.back().assign(
          (const typename stl_container::value_type::value_type*) reciever.get(
              0),
          reciever.get_size()
              / sizeof(typename stl_container::value_type::value_type));
    }
    pStorage->CloseStorageHandle(hValArray);
    return res;
  }
  //--------------------------------------------------------------------------------------------------------------------
  /*template<class stl_container, class StorageType>
   static bool SerializeSTLContainerUnicodeString  (stl_container& container, StorageType* pStorage, typename StorageType::HSSECTION hParentSection, const char* pValName)
   {
   if(!container.size()) return true;

   std::string::value_type

   stl_container::iterator it = container.begin();
   StorageType::HSVALARRAY hValArray = pStorage->InsertFirstValue(pValName, &fake_mem_block( it->data(), it->size()*sizeof(stl_container::value_type::value_type), hParentSection, STORAGE_TYPE_UNICODE_STRING);
   CHECK_AND_ASSERT(hValArray, false);
   it++;
   for(;it!= container.end();it++)
   pStorage->InsertNextValue(hValArray, &fake_mem_block( it->data(), it->size()));

   pStorage->CloseStorageHandle(hValArray);
   return true;
   }
   //--------------------------------------------------------------------------------------------------------------------
   template<class stl_container, class StorageType>
   static bool UnSerializeSTLContainerUnicodeString(stl_container& container, StorageType* pStorage, typename StorageType::HSSECTION hParentSection, const char* pValName)
   {
   bool res = false;
   container.clear();
   mem_block reciever;
   StorageType::HSVALARRAY hValArray = pStorage->GetFirstValue(pValName, &reciever, hParentSection);
   if(!hValArray) return false;
   container.push_back(stl_container::value_type());
   container.back().assign((const wchar_t*)reciever.get(0), reciever.get_size());

   res = true;
   while(pStorage->GetNextValue(hValArray, &reciever))
   {
   container.push_back(stl_container::value_type());
   container.back().assign((const stl_container::value_type::value_type*)reciever.get(0), reciever.get_size());
   }
   pStorage->CloseStorageHandle(hValArray);
   return res;
   }*/
  //--------------------------------------------------------------------------------------------------------------------
  template<class mem_block_class, class StorageType>
  static bool SerializeMemBlock(mem_block_class& raw_buff,
                                StorageType* pStorage,
                                typename StorageType::HSSECTION hParentSection,
                                const char* pValName) {
    return pStorage->SetValue(pValName, &raw_buff, hParentSection,
                              STORAGE_TYPE_UNDEFINED);
  }
  //--------------------------------------------------------------------------------------------------------------------
  template<class mem_block_class, class StorageType>
  static bool UnSerializeMemBlock(
      mem_block_class& raw_buff, StorageType* pStorage,
      typename StorageType::HSSECTION hParentSection, const char* pValName) {
    return pStorage->GetValue(pValName, &raw_buff, hParentSection);
  }
 private:
};
//========= Implementations ========================================================================================
}
#endif //_SERIALIZESTORAGE_H_
