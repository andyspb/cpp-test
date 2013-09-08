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


#ifndef _TRACE_SERIALIZEBLE_STRUCT_H_
#define _TRACE_SERIALIZEBLE_STRUCT_H_


#include "storages/inmemstorage.h"
#include "file_io_utils.h"
namespace epee
{
namespace StorageNamed
{
	template <class TSerializeble_struct>
	bool trace_as_xml(TSerializeble_struct& in_struct, std::string& buffer)
	{
		StorageNamed::CInMemStorage stg;
		in_struct.Store(&stg);
		stg.TraceAsXML(buffer);
		return true;
	};

	template <class TSerializeble_struct>
	std::string trace_as_xml(TSerializeble_struct& in_struct)
	{
		std::string buffer;
		trace_as_xml(in_struct, buffer);
		return buffer;
	};

	template <class TSerializeble_struct>
	bool save_struct_as_storage_to_file(TSerializeble_struct& in_struct, const std::string& pfile_path, const char *section = 0 )
	{

		StorageNamed::CInMemStorage stg;

		// first need to load from file
		std::string raw_buff;
//		if( file_io_utils::load_file_to_string( pfile_path, raw_buff ) )
//			stg.LoadFromSolidBuffer( raw_buff );

		if(section)
			stg.DeleteEntry( section );

		StorageNamed::CInMemStorage::HSSECTION	hsection = 0;
		if( section && *section )
			hsection = stg.OpenSection( section, 0, true );

		in_struct.Store(&stg, hsection );
		raw_buff.clear();
		stg.PackToSolidBuffer(raw_buff);
		return file_io_utils::save_string_to_file(pfile_path, raw_buff);
	};

	template <class TSerializeble_struct>
	bool save_struct_as_storage_to_buff(const TSerializeble_struct& in_struct_, std::string& buff, const char *section = 0 )
	{
		StorageNamed::CInMemStorage stg;
		// first need to load from file
		StorageNamed::CInMemStorage::HSSECTION	hsection = 0;
		if( section && *section )
			hsection = stg.OpenSection( section, 0, true );

		TSerializeble_struct& in_struct = const_cast<TSerializeble_struct&>(in_struct_);

		in_struct.Store(&stg, hsection );
		buff.clear();
		stg.PackToSolidBuffer(buff);
		return true;
	};


	template <class TSerializeble_struct>
	bool load_struct_from_storage_file(TSerializeble_struct& out_struct, const std::string& file_path, const char *section = 0)
	{

		std::string raw_buff;
		if(!file_io_utils::load_file_to_string(file_path, raw_buff))
		{
			LOG_PRINT("Filed to load file " << file_path, LOG_LEVEL_0);
			return false;
		}

		return load_struct_from_storage_buff(out_struct, raw_buff, section);
	};


	template <class TSerializeble_struct>
	bool load_struct_from_storage_buff(TSerializeble_struct& out_struct, const std::string& raw_buff, const char *section = 0)
	{
		StorageNamed::CInMemStorage stg;
		if(!stg.LoadFromSolidBuffer(raw_buff))
		{
			LOG_PRINT("Filed to load storage from solid buffer", LOG_LEVEL_0);
			return false;
		}

		StorageNamed::CInMemStorage::HSSECTION	hsection = 0;
		if( section && *section )
			hsection = stg.OpenSection( section );

		out_struct.Load(&stg, hsection);

		return true;
	}

	//-------------------------------

	template <class TSerializeble_struct, class t_storage_type>
	bool save_struct_as_storage_to_file_t(TSerializeble_struct& in_struct, const std::string& pfile_path)
	{

		t_storage_type stg;


		std::string raw_buff;

		in_struct.Store(&stg);
		raw_buff.clear();
		stg.PackToSolidBuffer(raw_buff);
		return file_io_utils::save_string_to_file(pfile_path, raw_buff);
	};

	template <class TSerializeble_struct, class t_storage_type>
	bool save_struct_as_storage_to_buff_t(const TSerializeble_struct& in_struct_, std::string& buff)
	{
		t_storage_type stg;
		// first need to load from file
		TSerializeble_struct& in_struct = const_cast<TSerializeble_struct&>(in_struct_);

		in_struct.Store(&stg);
		buff.clear();
		stg.PackToSolidBuffer(buff);
		return true;
	};

	template <class TSerializeble_struct, class t_storage_type>
	bool load_struct_from_storage_buff_t(TSerializeble_struct& out_struct, const std::string& raw_buff)
	{
		t_storage_type stg;
		if(!stg.LoadFromSolidBuffer(raw_buff))
		{
			LOG_PRINT("Filed to load storage from solid buffer", LOG_LEVEL_0);
			return false;
		}

		out_struct.Load(&stg);
		return true;
	}

	template <class TSerializeble_struct, class t_storage_type>
	bool load_struct_from_storage_file_t(TSerializeble_struct& out_struct, const std::string& file_path)
	{

		std::string raw_buff;
		if(!file_io_utils::load_file_to_string(file_path, raw_buff))
		{
			LOG_PRINT("Filed to load file " << file_path, LOG_LEVEL_0);
			return false;
		}

		return load_struct_from_storage_buff_t<TSerializeble_struct, t_storage_type>(out_struct, raw_buff);
	};


	
}
}

#endif //_TRACE_SERIALIZEBLE_STRUCT_H_
