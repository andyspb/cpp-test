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




#ifndef _ABSTRACT_INVOKE_H_
#define _ABSTRACT_INVOKE_H_

#include "inmemstorage.h"

#include "storages/inmemtoxml.h"
#include "net/http_base.h"

//#include "anmp/anmp_server.h"

namespace epee
{
template<class TArg, class TResult, class TTransport>
bool invoke_http_xml_remote_command(TArg& out_struct, TResult& result_struct, TTransport& transport, const std::string& uri)
{

	std::string xml_buf;
	StorageNamed::InMemStorageSpace::xml::store_t_to_xml(out_struct, xml_buf);
	const net_utils::http::http_response_info * prspinfo = NULL;
	if(!transport.invoke_get(uri, xml_buf, &prspinfo))
		return false;

	if(!prspinfo)
		return false;
	StorageNamed::InMemStorageSpace::xml::load_t_from_xml(result_struct, prspinfo->m_body);
	return true;
}
/*

template<class TArg, class TResult, class TTransport>
bool invoke_remote_command(int command, TArg& out_struct, TResult& result_struct, TTransport& transport)
{
	if(!transport.is_connected())
		return false;

	typename StorageNamed::DefaultStorageType stg;
	out_struct.Store(&stg);
	std::string buff_to_send, buff_to_recv;
	stg.PackToSolidBuffer(buff_to_send);

	int res = transport.invoke(command, buff_to_send, buff_to_recv);
	if( res <=0 )
	{
		LOG_PRINT_L1("Failed to invoke command " << command << " return code " << res);
		return false;
	}
	typename StorageNamed::DefaultStorageType stg_ret;
	if(!stg_ret.LoadFromSolidBuffer(buff_to_recv))
	{
		LOG_ERROR("Failed to LoadFromSolidBuffer on command " << command);
		return false;
	}
	result_struct.Load(&stg_ret);
	return true;
}

template<class TArg, class TTransport>
bool notify_remote_command(int command, TArg& out_struct, TTransport& transport)
{
	if(!transport.is_connected())
		return false;

	StorageNamed::DefaultStorageType stg;
	out_struct.Store(&stg);
	std::string buff_to_send, buff_to_recv;
	stg.PackToSolidBuffer(buff_to_send);



	int res = transport.notify(command, buff_to_send);
	if(res <=0 )
	{
		LOG_ERROR("Failed to notify command " << command << " return code " << res);
		return false;
	}
	return true;
}
*/
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


/*template<class TOwner, class TIn, class TOut, class TContext>
int marshaled_call_handler_2a(TOwner* powner, int command, const std::string& in_buff, std::string& buff_out,
							  int (TOwner::*m_p_func)(int command, TIn& in_param, TOut& out_prarm, const TContext& context),
							  const TContext& context
							  )
{
	StorageNamed::DefaultStorageType strg;
	if(!strg.LoadFromSolidBuffer(in_buff))
	{
		LOG_ERROR("Failed to LoadFromSolidBuffer in command" << command);
		return -1;
	}
	TIn* ptin = new TIn();
	TOut* ptout = new TOut();
	TIn  in_struct = *ptin;//value initialization;
	TOut out_struct = *ptout;//value initialization
	delete ptin;
	delete ptout;

	in_struct.Load(&strg);
	int res = (powner->*m_p_func)(command, in_struct, out_struct, context);
	StorageNamed::DefaultStorageType strg_out;
	out_struct.Store(&strg_out);

	if(!strg_out.PackToSolidBuffer(buff_out))
	{
		LOG_ERROR("Failed to PackToSolidBuffer in command" << command);
		return -1;
	}

	return res;
};


template<class TOwner, class TIn, class TContext>
int marshaled_call_handler_1a(TOwner* powner, int command, const std::string& in_buff,
							  int (TOwner::*m_p_func)(int command, TIn& in_param, const TContext& context),
							  const TContext& context
							  )
{
	StorageNamed::DefaultStorageType strg;
	if(!strg.LoadFromSolidBuffer(in_buff))
	{
		LOG_ERROR("Failed to LoadFromSolidBuffer in command" << command);
		return -1;
	}
	TIn  in_struct;

	in_struct.Load(&strg);
	return (powner->*m_p_func)(command, in_struct, context);
};
*/


#define BEGIN_INVOKE_MAP(owner_type) \
public: \
	template <class TContext> int handle_invoke_map(bool is_notify, int command, const std::string& in_buff, std::string& buff_out, TContext& context, bool& handled) \
	{ \
		typedef owner_type internal_owner_type_name;

#define HANDLE_INVOKE(command_id, func, type_name_in, typename_out) \
	if(!is_notify && command_id == command) \
		{handled=true;return marshaled_call_handler_2a<internal_owner_type_name, type_name_in, typename_out>(this, command, in_buff, buff_out, func, context);}

#define HANDLE_INVOKE_T(COMMAND, func) \
	if(!is_notify && COMMAND::ID == command) \
		{handled=true;return marshaled_call_handler_2a<internal_owner_type_name, COMMAND::argument, COMMAND::response>(this, command, in_buff, buff_out, func, context);}

#define HANDLE_ID_INVOKE_T(target_ID, COMMAND, func) \
	if(!is_notify && target_ID == target && COMMAND::ID == command) \
		{handled=true;return marshaled_call_handler_2a<internal_owner_type_name, COMMAND::argument, COMMAND::response>(this, command, in_buff, buff_out, func, context);}


#define HANDLE_NOTIFY(command_id, func, type_name_in) \
	if(is_notify && command_id == command) \
		{handled=true;return marshaled_call_handler_1a<internal_owner_type_name, type_name_in>(this, command, in_buff, func, context);}

#define HANDLE_NOTIFY_T(NOTIFY, func) \
	if(is_notify && NOTIFY::ID == command) \
		{handled=true;return marshaled_call_handler_1a<internal_owner_type_name, NOTIFY::argument>(this, command, in_buff, func, context);}

#define HANDLE_ID_NOTIFY_T(target_ID, NOTIFY, func) \
	if(is_notify && target_ID == target && NOTIFY::ID == command) \
		{handled=true;return marshaled_call_handler_1a<internal_owner_type_name, NOTIFY::argument>(this, command, in_buff, func, context);}


#define CHAIN_INVOKE_MAP(func) \
	{ \
		int res = func(is_notify, command, in_buff, buff_out, context, handled); \
		if(handled) \
			return res; \
	}


#define END_INVOKE_MAP() \
	LOG_ERROR("Unkonown command:" << command); \
	return 0; \
	}

/*
class activity_printer_base
{
public:
	activity_printer_base(){}
	virtual ~activity_printer_base(){}
};

template<class A>
class notify_activity_printer: public activity_printer_base
{
public:
	notify_activity_printer(int level, A& arg, bool is_notify_mode = true):m_ref_arg(arg), m_level(level), m_is_notify_mode(is_notify_mode)
	{
		m_command_name = typeid(m_ref_arg).name();
		m_command_name.erase(0, 7);
		m_command_name.erase(m_command_name.size()-10,  m_command_name.size()-1);
		if(level == log_space::get_set_log_detalisation_level())
		{
			LOG_PRINT(m_command_name, level);
		}
		else if(level+1 == log_space::get_set_log_detalisation_level())
		{
			LOG_PRINT(" -->>" << m_command_name, level);
		}
		else if(level+2 == log_space::get_set_log_detalisation_level())
		{
			LOG_PRINT(" -->>" << m_command_name << "\n" << StorageNamed::trace_as_xml(m_ref_arg), level);
		}
	}

	virtual ~notify_activity_printer()
	{
		if(m_is_notify_mode)
		{
			if(m_level+1 == log_space::get_set_log_detalisation_level())
			{
				LOG_PRINT(" <<--" << m_command_name, m_level);
			}
		}
	}
	protected:
		std::string m_command_name;
		A& m_ref_arg;
		int m_level;
		bool m_is_notify_mode;
};

template<class A, class R>
class command_activity_printer: public notify_activity_printer<A>
{
public:
	command_activity_printer(int level, A& arg, R& rsp):notify_activity_printer(level, arg, false), m_ref_rsp(rsp)
	{
	}

	virtual ~command_activity_printer()
	{
		if(m_level+1 == log_space::get_set_log_detalisation_level())
		{
			LOG_PRINT(" <<--" << m_command_name, m_level);
		}
		else if(m_level+2 == log_space::get_set_log_detalisation_level())
		{
			LOG_PRINT(" <<--" << m_command_name << "\n" << StorageNamed::trace_as_xml(m_ref_rsp), m_level);
		}
	}
private:
	R& m_ref_rsp;
};

template<class A, class R>
activity_printer_base* create_activity_printer(int level, A& arg, R& rsp)
{
	return new command_activity_printer<A, R>(level, arg, rsp);
}

template<class A>
activity_printer_base* create_activity_printer(int level, A& arg)
{
	return new notify_activity_printer<A>(level, arg);
}

#define PRINT_COMMAND_ACTIVITY(level) boost::shared_ptr<activity_printer_base> local_activity_printer(create_activity_printer(level, in_struct, out_struct));
#define PRINT_NOTIFY_ACTIVITY(level) boost::shared_ptr<activity_printer_base> local_activity_printer(create_activity_printer(level, in_struct));

#define PRINT_ACTIVITY(level) \
{std::string some_str = typeid(in_struct).name(); \
	some_str.erase(0, 7); \
	some_str.erase(some_str.size()-10,  some_str.size()-1); \
	LOG_PRINT(some_str, level);}
*/
}

#endif //_ABSTRACT_INVOKE_H_
