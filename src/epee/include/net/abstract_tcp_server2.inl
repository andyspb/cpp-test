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




#include "net_utils_base.h"

namespace epee
{
namespace net_utils
{
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
#pragma warning(disable: 4355)

	template<class t_protocol_handler>
	connection<t_protocol_handler>::connection(boost::asio::io_service& io_service,
		typename t_protocol_handler::config_type& config, volatile boost::uint32_t& sock_count, i_connection_filter* &pfilter)
		: strand_(io_service),
		socket_(io_service),
		m_protocol_handler(this, config, context), m_want_close_connection(0), m_assync_send_count(0), m_last_send_op_success(false), m_was_shutdown(0), m_ref_sockets_count(sock_count), m_pfilter(pfilter)
	{
	}
#pragma warning(default: 4355)
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	connection<t_protocol_handler>::~connection()
	{
		if(!boost::interprocess::ipcdetail::atomic_read32(&m_was_shutdown))
		{
			LOG_PRINT_L3("Socket destroed without shutdown." << this);
			boost::system::error_code ignored_ec;
			socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
			boost::interprocess::ipcdetail::atomic_write32(&m_was_shutdown, 1);
		}
#ifdef WINDOWS_PLATFORM
		LOG_PRINT_L2("[sock] (" << this << ") Socket destroed");
#else
		LOG_PRINT_L3("[sock] (" << this << ") Socket destroed");
#endif
		boost::interprocess::ipcdetail::atomic_dec32(&m_ref_sockets_count);
	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	boost::asio::ip::tcp::socket& connection<t_protocol_handler>::socket()
	{
		return socket_;
	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	void connection<t_protocol_handler>::start()
	{
		TRY_ENTRY();


		boost::interprocess::ipcdetail::atomic_inc32(&m_ref_sockets_count);


		context.m_remote_ip = boost::asio::detail::socket_ops::host_to_network_long(socket_.remote_endpoint().address().to_v4().to_ulong());
		context.m_remote_port = socket_.remote_endpoint().port();
#ifdef WINDOWS_PLATFORM
		LOG_PRINT_L2("[sock] (" << this << ") Recieved new connection from " << string_tools::get_ip_string_from_int32(context.m_remote_ip) << ", total sockets objects " << m_ref_sockets_count );
#else
		LOG_PRINT_L3("[sock] (" << this << ") Recieved new connection from " << string_tools::get_ip_string_from_int32(context.m_remote_ip) << ", total sockets objects " << m_ref_sockets_count );
#endif

		if(m_pfilter && !m_pfilter->is_remote_ip_allowed(context.m_remote_ip))
		{
			LOG_PRINT_L2("[sock] (" << this << ") Ip denied " << string_tools::get_ip_string_from_int32(context.m_remote_ip) << ", shutdowning connection");
			que_shutdown_connection();
			return;
		}


		m_protocol_handler.after_init_connection();

		socket_.async_read_some(boost::asio::buffer(buffer_),
			strand_.wrap(
			boost::bind(&connection<t_protocol_handler>::handle_read, connection<t_protocol_handler>::shared_from_this(),
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred)));

		CATCH_ENTRY_L0("connection<t_protocol_handler>::start()", void());
	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	void connection<t_protocol_handler>::handle_read(const boost::system::error_code& e,
		std::size_t bytes_transferred)
	{
		LOG_PRINT_L4("Assync read calledback.");
		TRY_ENTRY();
		//LOG_PRINT("connection<t_protocol_handler>::handle_read[" << this << "]", LOG_LEVEL_3);
		if (!e)
		{
			/**/
			LOG_PRINT("[sock] "<< this << " RECV " << bytes_transferred, LOG_LEVEL_4);
			if(!m_protocol_handler.handle_recv(buffer_.data(), bytes_transferred))
			{	
				LOG_PRINT("[" << this << "] protocol_want_close", LOG_LEVEL_4);

				//some error in protocol, protocol handler asc to close connection
				CRITICAL_REGION_BEGIN(m_send_que_lock);
				boost::interprocess::ipcdetail::atomic_write32(&m_want_close_connection, 1);
				if(!boost::interprocess::ipcdetail::atomic_read32(&m_assync_send_count))
				{
					// Initiate graceful connection closure.
					boost::system::error_code ignored_ec;
					socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
					boost::interprocess::ipcdetail::atomic_write32(&m_was_shutdown, 1);
				}
				CRITICAL_REGION_END();
				// Initiate graceful connection closure.
				//boost::system::error_code ignored_ec;
				//socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
			}else
			{
				
				socket_.async_read_some(boost::asio::buffer(buffer_),
					strand_.wrap(
					boost::bind(&connection<t_protocol_handler>::handle_read, connection<t_protocol_handler>::shared_from_this(),
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred)));
				LOG_PRINT_L4("Assync read requested.");
			}

		}else
		{
			LOG_PRINT_L4("Some not success at read: " << e.message());
			if(e.value() != 2)
			{	
				LOG_PRINT_L4("Some problems at read: " << e.message());
			}
		}
		// If an error occurs then no new asynchronous operations are started. This
		// means that all shared_ptr references to the connection object will
		// disappear and the object will be destroyed automatically after this
		// handler returns. The connection class's destructor closes the socket.
		CATCH_ENTRY_L0("connection<t_protocol_handler>::handle_read", void())
	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	bool connection<t_protocol_handler>::handle_send(const void* ptr, size_t cb)
	{
		TRY_ENTRY();

		LOG_PRINT("[sock] "<< this << " SEND " << cb, LOG_LEVEL_4);
		//some data should be wrote to stream
		//request complete
		//boost::interprocess::ipcdetail::atomic_inc32(&m_assync_send_count);
		
		CRITICAL_REGION_BEGIN(m_send_que_lock);

		m_send_que.resize(m_send_que.size()+1);
		m_send_que.back().assign((const char*)ptr, cb);
		
		if(boost::interprocess::ipcdetail::atomic_cas32(&m_assync_send_count, 1, 0))
		{
			//active operation in progress, nothing to do, just que request
		}else
		{
			//no active operation
			if(m_send_que.size()!=1)
			{
				LOG_ERROR("Looks like no active operations, but send que size != 1!!");
				return false;
			}

			boost::asio::async_write(socket_, boost::asio::buffer(m_send_que.front().data(), m_send_que.front().size()),
				strand_.wrap(
				boost::bind(&connection<t_protocol_handler>::handle_write, connection<t_protocol_handler>::shared_from_this(),
				boost::asio::placeholders::error)));
			LOG_PRINT_L4("Assync write requested.");

		}


		CRITICAL_REGION_END();



		/*LOG_PRINT_L0("handle_send:atomic_read32(&m_assync_send_count))-->>");
		while(boost::interprocess::ipcdetail::atomic_read32(&m_assync_send_count))
		{
			boost::this_thread::sleep(boost::posix_time::millisec(200));
		}
		LOG_PRINT_L0("handle_send:atomic_read32(&m_assync_send_count))<<--");

		return boost::interprocess::ipcdetail::atomic_read32(&m_last_send_op_success)?true:false;*/
		return true;

		CATCH_ENTRY_L0("connection<t_protocol_handler>::handle_send", false);
	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	bool connection<t_protocol_handler>::que_shutdown_connection()
	{
		LOG_PRINT_L4("Que Shutdown called.");
		CRITICAL_REGION_BEGIN(m_send_que_lock);
		boost::interprocess::ipcdetail::atomic_write32(&m_want_close_connection, 1);
		if(!boost::interprocess::ipcdetail::atomic_read32(&m_assync_send_count))
		{
			// Initiate graceful connection closure.
			boost::system::error_code ignored_ec;
			socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
			boost::interprocess::ipcdetail::atomic_write32(&m_was_shutdown, 1);
		}
		CRITICAL_REGION_END();
		return true;
	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	void connection<t_protocol_handler>::handle_write(const boost::system::error_code& e)
	{
		LOG_PRINT_L4("Assync write calledback.");

		CRITICAL_REGION_BEGIN(m_send_que_lock);
		if(!m_send_que.size())
		{
			LOG_ERROR("m_send_que.size() == 0 at handle_write!");
			return;
		}

		m_send_que.pop_front();
		if(!m_send_que.size())
		{
			//have more data to send
			boost::interprocess::ipcdetail::atomic_dec32(&m_assync_send_count);
		}else
		{

			boost::asio::async_write(socket_, boost::asio::buffer(m_send_que.front().data(), m_send_que.front().size()),
				strand_.wrap(
				boost::bind(&connection<t_protocol_handler>::handle_write, connection<t_protocol_handler>::shared_from_this(),
				boost::asio::placeholders::error)));
		}
		

		CRITICAL_REGION_END();

		if (!e)
		{
			LOG_PRINT("connection<t_protocol_handler>::handle_write,[" << this << "]", LOG_LEVEL_3);
			 boost::interprocess::ipcdetail::atomic_write32(&m_last_send_op_success, 1);
		}
		else
		{
			LOG_PRINT_L0("Some problems at write: " << e.message());
			boost::interprocess::ipcdetail::atomic_write32(&m_last_send_op_success, 0);
		}



		if(boost::interprocess::ipcdetail::atomic_read32(&m_want_close_connection) && !boost::interprocess::ipcdetail::atomic_read32(&m_assync_send_count))
		{
			// Initiate graceful connection closure.
			boost::system::error_code ignored_ec;
			socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
			boost::interprocess::ipcdetail::atomic_write32(&m_was_shutdown, 1);
		}
		// No new asynchronous operations are started. This means that all shared_ptr
		// references to the connection object will disappear and the object will be
		// destroyed automatically after this handler returns. The connection class's
		// destructor closes the socket.
	}



	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	template<class t_protocol_handler>
	boosted_tcp_server<t_protocol_handler>::boosted_tcp_server():
		acceptor_(io_service_),
		new_connection_(new connection<t_protocol_handler>(io_service_, m_config, m_sockets_count, m_pfilter)), 
		m_stop_signal_sent(false), m_port(0), m_threads_count(0), m_sockets_count(0), m_pfilter(NULL)
	{

	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	bool boosted_tcp_server<t_protocol_handler>::init_server(int port, const std::string address)
	{
		try
		{
			m_stop_signal_sent = false;
			m_port = port;
			m_address = address;
			// Open the acceptor with the option to reuse the address (i.e. SO_REUSEADDR).
			boost::asio::ip::tcp::resolver resolver(io_service_);
			boost::asio::ip::tcp::resolver::query query(address, boost::lexical_cast<std::string>(port));
			boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(query);
			acceptor_.open(endpoint.protocol());
			acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
			acceptor_.bind(endpoint);
			acceptor_.listen();
			acceptor_.async_accept(new_connection_->socket(),
				boost::bind(&boosted_tcp_server<t_protocol_handler>::handle_accept, this,
				boost::asio::placeholders::error));

		}
		catch(const boost::system::system_error& er)
		{
			LOG_PRINT_L0("Failed to init server, message: " << er.what());
			return false;
		}
		catch(...)
		{
			return false;
		}
	

		return true;
	}
  //-----------------------------------------------------------------------------
  template<class t_protocol_handler>
  bool boosted_tcp_server<t_protocol_handler>::init_server(const std::string port, const std::string& address) 
  {
    int p = 0;
    if (!string_tools::get_xtype_from_string(p, port)) {
      return false;
      LOG_ERROR("Failed to convert port no = port");
    }
    return this->init_server(p, address);
  }
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	bool boosted_tcp_server<t_protocol_handler>::worker_thread()
	{
		TRY_ENTRY();
		std::string thread_name = "[NET_SERVER_WORKER";
#ifdef WINDOWS_PLATFORM
		thread_name += " " + boost::lexical_cast<std::string>(::GetCurrentThreadId()) + " ";
#endif
		thread_name += "]";
		log_space::log_singletone::set_thread_log_prefix(thread_name);
		io_service_.run();
		CATCH_ENTRY_L0("boosted_tcp_server<t_protocol_handler>::worker_thread", false);
		return true;
	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	void boosted_tcp_server<t_protocol_handler>::set_connection_filter(i_connection_filter* pfilter)
	{
		m_pfilter = pfilter;
	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	bool boosted_tcp_server<t_protocol_handler>::run_server(size_t threads_count)
	{
		m_threads_count = threads_count;
		log_space::log_singletone::set_thread_log_prefix("[NET_SERVER]");
		try
		{
			while(!m_stop_signal_sent)
			{
				// Create a pool of threads to run all of the io_services.
				std::vector<boost::shared_ptr<boost::thread> > threads;
				for (std::size_t i = 0; i < threads_count; ++i)
				{
					boost::shared_ptr<boost::thread> thread(new boost::thread(
						boost::bind(&boosted_tcp_server<t_protocol_handler>::worker_thread, this)));
					threads.push_back(thread);
				}

				// Wait for all threads in the pool to exit.
				for (std::size_t i = 0; i < threads.size(); ++i)
					threads[i]->join();
				if(!m_stop_signal_sent)
				{
					LOG_PRINT_L0("Net service stopped without stop request, restarting...");
					if(!this->init_server(m_port, m_address))
					{
						LOG_PRINT_L0("Reiniting service failed, exit.");
						return false;
					}else
					{
						LOG_PRINT_L0("Reiniting OK.");
					}
					//here we just have some problems with the listenning socket.
				}
			}
		}
		catch(const boost::system::system_error& er)
		{
			LOG_ERROR("Failed to run_server server, message: " << er.what());
			return false;
		}
		catch(...)
		{
			LOG_ERROR("Failed to run_server server, fatal error");
			return false;
		}
		return true;
	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	void boosted_tcp_server<t_protocol_handler>::send_stop_signal()
	{
		m_stop_signal_sent = true;
		TRY_ENTRY();
		io_service_.stop();
		CATCH_ENTRY_L0("boosted_tcp_server<t_protocol_handler>::send_stop_signal()", void());
	}
	//---------------------------------------------------------------------------------
	template<class t_protocol_handler>
	void boosted_tcp_server<t_protocol_handler>::handle_accept(const boost::system::error_code& e)
	{
		TRY_ENTRY();
		if (!e)
		{
			
			new_connection_->start();
			new_connection_.reset(new connection<t_protocol_handler>(io_service_, m_config, m_sockets_count, m_pfilter));
			acceptor_.async_accept(new_connection_->socket(),
				boost::bind(&boosted_tcp_server<t_protocol_handler>::handle_accept, this,
				boost::asio::placeholders::error));
		}else
		{
			LOG_ERROR("Some problems at accept: " << e.message());
		}
		CATCH_ENTRY_L0("boosted_tcp_server<t_protocol_handler>::handle_accept", void());
	}

}
}