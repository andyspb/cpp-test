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



#ifndef _ANMP_PROTOCOL_HANDLER_H_
#define _ANMP_PROTOCOL_HANDLER_H_

#include "anmp_base.h"
//#include "abstract_tcp_server.h"

namespace epee
{
namespace anmp
{
	struct protocl_handler_config
	{
		anmp_commands_handler* m_pcommands_handler;
	};

	class protocol_handler
	{
	public:
		typedef protocl_handler_config config_type;

		protocol_handler(net_utils::i_send_handler* psnd_hndlr, config_type& config, const net_utils::connection_context& conn_context);
		virtual ~protocol_handler(){}

		virtual bool handle_recv(const void* ptr, size_t cb);

		bool after_init_connection(){return true;}
	private:
		enum connection_data_state
		{
			conn_state_reading_head,
			conn_state_reading_body
		};


		config_type& m_config;
		const net_utils::connection_context& m_conn_context;
		net_utils::i_send_handler* m_psnd_hndlr; 
		std::string m_cach_in_buffer;
		connection_data_state m_state;
		bucket_head m_current_head;
	};

	protocol_handler::protocol_handler(net_utils::i_send_handler* psnd_hndlr, config_type& config, const net_utils::connection_context& conn_context):m_config(config), m_psnd_hndlr(psnd_hndlr), 
		m_state(conn_state_reading_head), m_current_head(bucket_head()), m_conn_context(conn_context)
	{}

	bool protocol_handler::handle_recv(const void* ptr, size_t cb)
	{
		if(!m_config.m_pcommands_handler)
		{
			LOG_ERROR("anmp::abstract_handler not set in anmp_protocol_handler config!");
			return false;
		}

		m_cach_in_buffer.append((const char*)ptr, cb);

		bool is_continue = true;
		while(is_continue)
		{
			switch(m_state)
			{
			case conn_state_reading_head:
				if(m_cach_in_buffer.size() < sizeof(bucket_head))
				{
					if(m_cach_in_buffer.size() >= sizeof(boost::uint64_t) && *((boost::uint64_t*)m_cach_in_buffer.data()) != ANMP_SIGNATURE)//�������� ���������� ���� ��
					{
						LOG_ERROR("Signature missmatch on accepted connection");
						return false;
					}
					is_continue = false;
					break;
				}
				{
					bucket_head* phead = (bucket_head*)m_cach_in_buffer.data();
					if(ANMP_SIGNATURE != phead->m_signature)
					{
						LOG_ERROR("Signature missmatch on accepted connection");
						return false;
					}
					m_current_head = *phead;
				}
				m_cach_in_buffer.erase(0, sizeof(bucket_head));
				m_state = conn_state_reading_body;
				break;
			case conn_state_reading_body:
				if(m_cach_in_buffer.size() < m_current_head.m_cb)
				{
					is_continue = false;
					break;
				}
				{
					std::string buff_to_invoke;
					if(m_cach_in_buffer.size()  == m_current_head.m_cb)
						buff_to_invoke.swap(m_cach_in_buffer);
					else
					{
						buff_to_invoke.assign(m_cach_in_buffer, 0, (std::string::size_type)m_current_head.m_cb);
						m_cach_in_buffer.erase(0, (std::string::size_type)m_current_head.m_cb);
					}


					if(m_current_head.m_have_to_return_data)
					{
						std::string return_buff;
						m_current_head.m_return_code = m_config.m_pcommands_handler->invoke(m_current_head.m_command, buff_to_invoke, return_buff, m_conn_context);
						m_current_head.m_cb = return_buff.size();
						m_current_head.m_have_to_return_data = false;
						std::string send_buff((const char*)&m_current_head, sizeof(m_current_head));
						send_buff += return_buff;

						if(!m_psnd_hndlr->handle_send(send_buff.data(), send_buff.size()))
							return false;

					}
					else
						m_config.m_pcommands_handler->notify(m_current_head.m_command, buff_to_invoke, m_conn_context);
				}
				m_state = conn_state_reading_head;
				break;
			default:
				LOG_ERROR("Undefined state in anmp_server_impl::connection_handler, m_state=" << m_state);
				return false;
			}
		}

		return true;
	}
}
}




#endif //_ANMP_PROTOCOL_HANDLER_H_

