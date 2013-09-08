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



#ifndef  _ABSTRACT_TCP_SERVER2_H_ 
#define _ABSTRACT_TCP_SERVER2_H_ 


#include <boost/asio.hpp>
#include <string>
#include <vector>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/interprocess/detail/atomic.hpp>
#include "net_utils_base.h"

namespace epee
{
namespace net_utils
{

	struct i_connection_filter
	{
		virtual bool is_remote_ip_allowed(boost::uint32_t adress)=0;
	};
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	/// Represents a single connection from a client.

	template<class t_protocol_handler>
	class connection
		: public boost::enable_shared_from_this<connection<t_protocol_handler> >,
		private boost::noncopyable, 
		public i_send_handler
	{
	public:
		/// Construct a connection with the given io_service.
		explicit connection(boost::asio::io_service& io_service,
			typename t_protocol_handler::config_type& config, volatile boost::uint32_t& sock_count, i_connection_filter * &pfilter);

		~connection();
		/// Get the socket associated with the connection.
		boost::asio::ip::tcp::socket& socket();

		/// Start the first asynchronous operation for the connection.
		void start();

	private:
		//----------------- i_send_handler ---------------------
		virtual bool handle_send(const void* ptr, size_t cb);
		virtual bool que_shutdown_connection();
		//------------------------------------------------------

		/// Handle completion of a read operation.
		void handle_read(const boost::system::error_code& e,
			std::size_t bytes_transferred);

		/// Handle completion of a write operation.
		void handle_write(const boost::system::error_code& e);

		/// Strand to ensure the connection's handlers are not called concurrently.
		boost::asio::io_service::strand strand_;

		/// Socket for the connection.
		boost::asio::ip::tcp::socket socket_;



		/// Buffer for incoming data.
		boost::array<char, 8192> buffer_;


		net_utils::connection_context context;
		volatile boost::uint32_t m_want_close_connection;
		volatile boost::uint32_t m_assync_send_count;
		volatile boost::uint32_t m_last_send_op_success;
		volatile boost::uint32_t m_was_shutdown;
		critical_section m_send_que_lock;
		std::list<std::string> m_send_que;
		volatile boost::uint32_t& m_ref_sockets_count;
		i_connection_filter* &m_pfilter;

		//thios should be the las t one, becouse it could be wait on destructor, while other activities possible on other threads
		t_protocol_handler m_protocol_handler;
		//typename t_protocol_handler::config_type m_dummy_config;

	};



	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	template<class t_protocol_handler>
	class boosted_tcp_server
		: private boost::noncopyable
	{
	public:
		typedef boost::shared_ptr<connection<t_protocol_handler> > connection_ptr;
		/// Construct the server to listen on the specified TCP address and port, and
		/// serve up files from the given directory.
		explicit boosted_tcp_server();

		bool init_server(int port, const std::string address = "0.0.0.0");
		bool init_server(const std::string port,  const std::string& address = "0.0.0.0");

		/// Run the server's io_service loop.
		bool run_server(size_t threads_count);

		/// Run the server's io_service loop.
		bool worker_thread();

		/// Stop the server.
		void send_stop_signal();

		bool deinit_server(){return true;}

		size_t get_threads_count(){return m_threads_count;}

		void set_connection_filter(i_connection_filter* pfilter);


		typename t_protocol_handler::config_type& get_config_object(){return m_config;}

	protected:
		int m_port;
		typename t_protocol_handler::config_type m_config;
	private:
		/// Handle completion of an asynchronous accept operation.
		void handle_accept(const boost::system::error_code& e);

		/// The io_service used to perform asynchronous operations.
		boost::asio::io_service io_service_;

		/// Acceptor used to listen for incoming connections.
		boost::asio::ip::tcp::acceptor acceptor_;

		/// The next connection to be accepted.
		connection_ptr new_connection_;
		volatile bool m_stop_signal_sent;
		volatile boost::uint32_t m_sockets_count;
		std::string m_address;
		size_t m_threads_count;
		i_connection_filter* m_pfilter;
	protected:

	};
}
}

#include "abstract_tcp_server2.inl"

#endif