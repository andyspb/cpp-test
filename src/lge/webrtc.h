/*
 * test.h
 *
 *  Created on: Dec 29, 2015
 *      Author: andy
 */

#ifndef SRC_LGE_WEBRTC_H_
#define SRC_LGE_WEBRTC_H_

#include <iostream>

namespace webrtc {

TEST_RESULT test() {

  std::string str =
      "nm=audio 9 RTP\/SAVPF 103 126\r\nc=IN IP4 0.0.0.0\r\na=rtcp:9 IN IP4 0.0.0.0\r\na=ice-ufrag:8J0epX4yFusINNaN\r";


  std::cout << "str=" << str << '\n';


  std::string from = "\\/";
  std::string to = "/";

  size_t pos = 0;
  while ((pos = str.find(from, pos)) != std::string::npos) {
    str.replace(pos, from.length(), to);
    pos += to.length();
  }

  std::cout << "str=" << str << '\n';

  RETURN_OK();
}

}  // namespace lge

#endif /* SRC_LGE_WEBRTC_H_ */
