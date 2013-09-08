// Copyright (c) 2006-2013, Andrey N. Sabelnikov, www.sabelnikov.net
// All rights reserved.
//
#ifndef MISC_LANGUAGE_H
#define MISC_LANGUAGE_H

#include <limits>

namespace epee {
#define STD_TRY_BEGIN() try {

#define STD_TRY_CATCH(where_, ret_val) \
	} \
	catch (const std::exception  &e) \
	{ \
		LOG_ERROR("EXCEPTION: " << where_  << ", mes: "<< e.what());  \
		return ret_val; \
	} \
	catch (...) \
	{ \
		LOG_ERROR("EXCEPTION: " << where_ ); \
		return ret_val; \
	}

namespace misc_utils {
template<typename t_type>
t_type get_max_t_val(t_type t) {
  return std::numeric_limits<t_type>::max();
}

template<typename t_iterator>
t_iterator move_it_forward(t_iterator it, size_t count) {
  while (count--)
    it++;
  return it;
}

// TEMPLATE STRUCT less
template<class _Ty>
struct less_as_pod : public std::binary_function<_Ty, _Ty, bool> {  // functor for operator<
  bool operator()(const _Ty& _Left, const _Ty& _Right) const {  // apply operator< to operands
    return memcmp(&_Left, &_Right, sizeof(_Left)) > 0 ? false : true;
  }
};

inline
bool sleep_no_w(long ms) {
  boost::this_thread::sleep(
      boost::get_system_time()
          + boost::posix_time::milliseconds(std::max<long>(ms, 0)));

  return true;
}
}  // namespace misc_utils
}  // namespace epee

#endif MISC_LANGUAGE_H
