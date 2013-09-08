#ifndef _NET_UTILS_BASE_H_
#define _NET_UTILS_BASE_H_

namespace epee {
namespace net_utils {
struct connection_context {
  long m_remote_ip;
  int m_remote_port;
};

struct i_send_handler {
  virtual bool handle_send(const void* ptr, size_t cb)=0;
  virtual ~i_send_handler() {
  }
};
}  // namespace net_utils
}  // namespace epee

#endif //_NET_UTILS_BASE_H_
