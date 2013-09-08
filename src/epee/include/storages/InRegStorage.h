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


#ifndef _INREGSTORRAGE_H_
#define _INREGSTORRAGE_H_


#include <strstream>

#ifndef ASSERT
    #define ASSERT(expression) ATLASSERT(expression)
#endif

#ifndef CHECK_AND_ASSERT
	#define CHECK_AND_ASSERT(expression, fail_return_val) {ASSERT(expression); if(!(expression)) return fail_return_val;}
#endif

#include "reg_utils.h"
namespace epee
{
namespace StorageNamed
{
	namespace InRegStorageSpace
	{

		class CSSection;
		class CValuesArray;
		class CSSectionsArray;
		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		class CSSection
		{
		public:
			explicit CSSection(HKEY hkey, const char* pSubKeyStr, bool createIfNotExist):m_hkey(NULL)
			{
				Open(hkey,pSubKeyStr, createIfNotExist);
			}

			~CSSection()
			{
				if(m_hkey) ::RegCloseKey(m_hkey);
			}


			HKEY GetHandle(){return m_hkey;}

			bool Open(HKEY hParenKey, const char* pSubKeyName, bool createIfNotExist)
			{
				CHECK_AND_ASSERT(hParenKey&&pSubKeyName, false);

				if(m_hkey)
				{
					::RegCloseKey(m_hkey);
					m_hkey = NULL;
				}
				LONG res = ::RegOpenKey(hParenKey, pSubKeyName, &m_hkey);
				if(ERROR_SUCCESS!= res)
				{
					if(createIfNotExist)
					{
						if(::RegCreateKey(hParenKey, pSubKeyName, &m_hkey)!=ERROR_SUCCESS) 
							return false;
					}else
                    	return false;
				}
				return true;
			}

		private:
			HKEY m_hkey;
		};

		inline 
		std::string GetNValueNameInArray(const std::string& valName, size_t index)
		{
			std::ostrstream strToFind;
			strToFind << valName << '#'<< (unsigned int)index << std::ends;
			return strToFind.str();
		}


		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		class CInRegStorage
		{
		public:
			//handle-like aliases
			typedef CSSection*         HSSECTION;  
			typedef CValuesArray*      HSVALARRAY;
			typedef CSSectionsArray*   HSSECARRAY;



			CInRegStorage(HKEY hParentKey, const char* pSubKey, bool createIfNotExist):m_rootSection(hParentKey, pSubKey, createIfNotExist)
			{}


			HSSECTION  OpenSection(const char* pSectionName,  HSSECTION hParentSection = NULL, bool createIfNotExist = false);
			bool       GetValue(const char* pValueName, CMemoryObject* pTargetObj, HSSECTION hParentSection = NULL, unsigned char* pTipFlags = NULL);
			bool       SetValue(const char* pValueName, const CMemoryObject* pTargetObj, HSSECTION hParentSection = NULL, unsigned char  tipFlags = NULL);

			//serial access for arrays of values --------------------------------------
			//values
			HSVALARRAY GetFirstValue(const char* pValueName, CMemoryObject* pTargetObj, HSSECTION hParentSection = NULL, unsigned char* pTipFlags = NULL);
			bool       GetNextValue(HSVALARRAY hValArray, CMemoryObject* pTargetObj);
			HSVALARRAY InsertFirstValue(const char* pValueName, const CMemoryObject* pTargetObj, HSSECTION hParentSection = NULL, unsigned char  tipFlags = NULL);
			bool       InsertNextValue(HSVALARRAY hValArray, const CMemoryObject* pTargetObj);
			//sections
			HSSECARRAY GetFirstSection(const char* pSectionName, HSSECTION* phChildSection, HSSECTION hParentSection = NULL);
			bool       GetNextSection(HSSECARRAY hSecArray, HSSECTION* phChildSection);
			HSSECARRAY InsertFirstSection(const char* pSectionName, HSSECTION* phInsertedChildSection, HSSECTION hParentSection = NULL);
			bool       InsertNextSection(HSSECARRAY hSecArray, HSSECTION* phInsertedChildSection);

			template<class THandle>
			bool       CloseStorageHandle(THandle  storageHandle);
			//------------------------------------------------------------------------

			//delete entry (section, value or array)
			virtual bool       DeleteEntry(const char* pEntryName, HSSECTION hParentSection = NULL);
        protected:
		private:
			friend class CValuesArray;
			friend class CSSectionsArray;
			static bool      GetValue(HKEY parentKey, const char* pValueName, CMemoryObject* pTargetObj, unsigned char* pTipFlags = NULL);
			static bool      SetValue(HKEY parentKey, const char* pValueName, const CMemoryObject* pTargetObj, unsigned char  tipFlags = NULL);

			CSSection m_rootSection;
		};

		typedef CInRegStorage::HSSECTION  HSSECTION;  
		typedef CInRegStorage::HSVALARRAY HSVALARRAY;
		typedef CInRegStorage::HSSECARRAY HSSECARRAY;


		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		class CValuesArray
		{
		public:
			CValuesArray(HKEY hParentKey, const std::string& valName):m_currentIndex(0), m_hParentKey(hParentKey), m_valName(valName)
			{}
			CValuesArray(HKEY hParentKey, const char* pValName):m_currentIndex(0), m_hParentKey(hParentKey), m_valName(pValName)
			{}

			HSVALARRAY   GetFirstValue(CMemoryObject* pTargetObj, unsigned char* pTipFlags = NULL)
			{
				m_currentIndex = 0;
				std::string nValueName = GetNValueNameInArray(m_valName, m_currentIndex++);
				if(CInRegStorage::GetValue(m_hParentKey, nValueName.c_str(), pTargetObj, pTipFlags))
					return this;
				else
					return NULL;
			}

			bool       GetNextValue(CMemoryObject* pTargetObj)
			{
				std::string nValueName = GetNValueNameInArray(m_valName, m_currentIndex++);
				return CInRegStorage::GetValue(m_hParentKey, nValueName.c_str(), pTargetObj);
			}

			HSVALARRAY   InsertFirstValue(const CMemoryObject* pTargetObj, unsigned char  tipFlags = NULL)
			{
				ClearValues();
				m_currentIndex = 0;
				std::string nValueName = GetNValueNameInArray(m_valName, m_currentIndex++);
				if(CInRegStorage::SetValue(m_hParentKey, nValueName.c_str(), pTargetObj, tipFlags))
					return this;
				else
					return NULL;

			}

			bool       InsertNextValue(const CMemoryObject* pTargetObj)
			{
				std::string nValueName = GetNValueNameInArray(m_valName, m_currentIndex++);
				return CInRegStorage::SetValue(m_hParentKey, nValueName.c_str(), pTargetObj);
			}


		private:
			bool ClearValues()
			{
				size_t index=0;
				while(reg_utils::RegRemoveValue(m_hParentKey, GetNValueNameInArray(m_valName, index).c_str()))
					++index;
				return true;
			}
			size_t  m_currentIndex;
			HKEY m_hParentKey;
			const std::string m_valName;
		};

		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		class CSSectionsArray
		{
		public:
			CSSectionsArray(HKEY hParentKey, const char* pSecArrName):m_hParentKey(hParentKey), 
																	  m_SecArrayName(pSecArrName),
																	  m_currentIndex(0)
			{}

			//implementation
			HSSECARRAY   GetFirstSection(HSSECTION* phChildSection)
			{
				CHECK_AND_ASSERT(phChildSection, NULL);
				m_currentIndex = 0;
				std::string nKeyName = GetNValueNameInArray(m_SecArrayName, m_currentIndex++);
				CSSection* pNewSection = new CSSection(m_hParentKey, nKeyName.c_str(), false);
				if(!pNewSection->GetHandle())
				{
					delete pNewSection;
					return NULL;
				}
				*phChildSection = pNewSection;
				return this;
			}
			//---------------------------------------------------------------------------------------------------------------------------------------------
			bool       GetNextSection(HSSECTION* phChildSection)
			{
				std::string nKeyName = GetNValueNameInArray(m_SecArrayName, m_currentIndex++);
				CSSection* pNewSection = new CSSection(m_hParentKey, nKeyName.c_str(), false);
				if(!pNewSection->GetHandle())
				{
					delete pNewSection;
					return false;
				}
				*phChildSection = pNewSection;
				return true;

			}
			//---------------------------------------------------------------------------------------------------------------------------------------------
			HSSECARRAY   InsertFirstSection(HSSECTION* phInsertedChildSection)
			{
				ClearKeys();
				m_currentIndex = 0;
				std::string nKeyName = GetNValueNameInArray(m_SecArrayName, m_currentIndex++);
				CSSection* pNewSection = new CSSection(m_hParentKey, nKeyName.c_str(), true);
				if(!pNewSection->GetHandle())
				{
					delete pNewSection;
					return NULL;
				}
				*phInsertedChildSection = pNewSection;
				return this;
			}
			//---------------------------------------------------------------------------------------------------------------------------------------------
			bool       InsertNextSection(HSSECTION* phInsertedChildSection)
			{
				std::string nKeyName = GetNValueNameInArray(m_SecArrayName, m_currentIndex++);
				CSSection* pNewSection = new CSSection(m_hParentKey, nKeyName.c_str(), true);
				if(!pNewSection->GetHandle())
				{
					delete pNewSection;
					return false;
				}
				*phInsertedChildSection = pNewSection;
				return true;
			}
			//---------------------------------------------------------------------------------------------------------------------------------------------

		private:
			bool ClearKeys()
			{
				size_t index=0;
				while(reg_utils::RegRemoveKey(m_hParentKey, GetNValueNameInArray(m_SecArrayName, index).c_str()))
					++index;
				return true;
			}

			HKEY        m_hParentKey;
			std::string m_SecArrayName;
			size_t      m_currentIndex;
		};


		//============================================================================================================================================
		HSSECTION CInRegStorage::OpenSection(const char* pSectionName,  HSSECTION hParentSection, bool createIfNotExist)
		{
			CHECK_AND_ASSERT(pSectionName, NULL);
			CSSection* pParentSection = hParentSection ? hParentSection:&m_rootSection;
			HKEY parentKey = pParentSection->GetHandle();

			CSSection* pnew_section = new CSSection(parentKey, pSectionName, createIfNotExist);
			if(!pnew_section->GetHandle())
			{
				delete pnew_section;
				return NULL;
			}
			return pnew_section;
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------
		bool      CInRegStorage::GetValue(HKEY parentKey, const char* pValueName, CMemoryObject* pTargetObj, unsigned char* pTipFlags)
		{
			DWORD regType = 0;
			if(!reg_utils::RegGetRAWValue(parentKey, pValueName, *pTargetObj, &regType))
				return false;

			if(pTipFlags)
			{//analyze registry type and make appropriate tip flags
				if(regType == REG_SZ)
					*pTipFlags = STORAGE_TYPE_ANSI_STRING;
				else if(regType == REG_BINARY)
					*pTipFlags = STORAGE_TYPE_SKALAR;
				else
					*pTipFlags = STORAGE_TYPE_UNDEFINED;
			}

			return true;
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------
		bool      CInRegStorage::SetValue(HKEY parentKey, const char* pValueName, const CMemoryObject* pTargetObj, unsigned char  tipFlags)
		{
			DWORD regType = 0;
			if(STORAGE_TYPE_ANSI_STRING == tipFlags)
				regType = REG_SZ;
			else 
				regType = REG_BINARY;

			return reg_utils::RegSetRAWValue(parentKey, pValueName, *pTargetObj, regType);
		}
		//--------------------------------------------------------------------------------------------------------------------------------------------

		bool      CInRegStorage::GetValue(const char* pValueName, CMemoryObject* pTargetObj, HSSECTION hParentSection, unsigned char* pTipFlags)
		{
			CHECK_AND_ASSERT(pValueName&&pTargetObj, false);
			CSSection* pParentSection = hParentSection ? hParentSection:&m_rootSection;

			return CInRegStorage::GetValue(pParentSection->GetHandle(), pValueName, pTargetObj, pTipFlags);
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------
		bool      CInRegStorage::SetValue(const char* pValueName, const CMemoryObject* pTargetObj, HSSECTION hParentSection, unsigned char  tipFlags)
		{
			CHECK_AND_ASSERT(pValueName&&pTargetObj, false);
			CSSection* pParentSection = hParentSection ? hParentSection:&m_rootSection;
			return CInRegStorage::SetValue(pParentSection->GetHandle(), pValueName, pTargetObj, tipFlags);
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------

		//serial access for arrays of values --------------------------------------
		//values
		HSVALARRAY   CInRegStorage::GetFirstValue(const char* pValueName, CMemoryObject* pTargetObj, HSSECTION hParentSection, unsigned char* pTipFlags)
		{
			CHECK_AND_ASSERT(pValueName&&pTargetObj, false);
			CSSection* pParentSection = hParentSection ? hParentSection:&m_rootSection;
			
			CValuesArray* pNewValArray = new CValuesArray(pParentSection->GetHandle(), pValueName);
			
			HSVALARRAY hValArrHandle = pNewValArray->GetFirstValue(pTargetObj, pTipFlags);
			if(!hValArrHandle)
			{
				delete pNewValArray;
				return NULL;
			}
			else
				return hValArrHandle;
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------
		bool       CInRegStorage::GetNextValue(HSVALARRAY hValArray, CMemoryObject* pTargetObj)
		{
			CHECK_AND_ASSERT(hValArray, false);
			CValuesArray* pValArray = hValArray;

			return pValArray->GetNextValue(pTargetObj);
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------	
		HSVALARRAY   CInRegStorage::InsertFirstValue(const char* pValueName, const CMemoryObject* pTargetObj, HSSECTION hParentSection, unsigned char  tipFlags)
		{

			CHECK_AND_ASSERT(pValueName&&pTargetObj, false);
			CSSection* pParentSection = hParentSection ? hParentSection:&m_rootSection;

			CValuesArray* pNewValArray = new CValuesArray(pParentSection->GetHandle(), pValueName);

			HSVALARRAY hValArrHandle = pNewValArray->InsertFirstValue(pTargetObj, tipFlags);
			if(!hValArrHandle)
			{
				delete pNewValArray;
				return NULL;
			}
			else
				return hValArrHandle;
			return NULL;
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------
		bool       CInRegStorage::InsertNextValue(HSVALARRAY hValArray, const CMemoryObject* pTargetObj)
		{
			CHECK_AND_ASSERT(hValArray, false);
			CValuesArray* pValArray = hValArray;

			return pValArray->InsertNextValue(pTargetObj);
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------
		//sections
		HSSECARRAY   CInRegStorage::GetFirstSection(const char* pSectionName, HSSECTION* phChildSection, HSSECTION hParentSection)
		{
			CHECK_AND_ASSERT(pSectionName&&phChildSection, NULL);
			CSSection* pParentSection = hParentSection ? hParentSection:&m_rootSection;

			CSSectionsArray* pSecErray = new CSSectionsArray(pParentSection->GetHandle(), pSectionName);
			HSSECARRAY res = pSecErray->GetFirstSection(phChildSection);
			if(!res)
			{
				delete pSecErray;
				return NULL;
			}

			return res;
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------
		bool       CInRegStorage::GetNextSection(HSSECARRAY hSecArray, HSSECTION* phChildSection)
		{
			CHECK_AND_ASSERT(hSecArray&&phChildSection, false);
			CSSectionsArray* pSecErray = hSecArray;
			return pSecErray->GetNextSection(phChildSection);
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------
		HSSECARRAY   CInRegStorage::InsertFirstSection(const char* pSectionName, HSSECTION* phInsertedChildSection, HSSECTION hParentSection)
		{
			CHECK_AND_ASSERT(pSectionName&&phInsertedChildSection, NULL);
			CSSection* pParentSection = hParentSection ? hParentSection:&m_rootSection;

			CSSectionsArray* pSecErray = new CSSectionsArray(pParentSection->GetHandle(), pSectionName);
			HSSECARRAY res = pSecErray->InsertFirstSection(phInsertedChildSection);
			if(!res)
			{
				delete pSecErray;
				return NULL;
			}

			return res;
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------
		bool       CInRegStorage::InsertNextSection(HSSECARRAY hSecArray, HSSECTION* phInsertedChildSection)
		{
			CHECK_AND_ASSERT(hSecArray&&phInsertedChildSection, false);
			CSSectionsArray* pSecErray = hSecArray;
			return pSecErray->InsertNextSection(phInsertedChildSection);
		}	
		//---------------------------------------------------------------------------------------------------------------------------------------------
		template<class THandle>
		bool       CInRegStorage::CloseStorageHandle(THandle  storageHandle)
		{
			delete storageHandle;
			return true;
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------
		bool       CInRegStorage::DeleteEntry(const char* pEntryName, HSSECTION hParentSection)
		{
			CHECK_AND_ASSERT(pEntryName, NULL);
			CSSection* pParentSection = hParentSection ? hParentSection:&m_rootSection;

			if(!reg_utils::RegRemoveKey(pParentSection->GetHandle(), pEntryName))
				return reg_utils::RegRemoveValue(pParentSection->GetHandle(), pEntryName);
			return true;
		}
	}
	typedef InRegStorageSpace::CInRegStorage CInRegStorage;
}
}

#endif //_INREGSTORRAGE_H_
