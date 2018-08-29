/*
 * 1_5_perform_string_compression.h
 *
 *  Created on: 26 дек. 2014 г.
 *      Author: andy
 */

#ifndef _PERFORM_STRING_COMPRESSION_H_
#define _PERFORM_STRING_COMPRESSION_H_

namespace perform_string_compression {

char* StrCompress(char str[]) {
  char *s, *in;
  for (s = str, in = str; *s; ++s) {
    int count = 1;
    in[0] = s[0];
    ++in;
    while (s[0] == s[1]) {
      ++count;
      ++s;
    }
    if (count > 1) {
      int len = sprintf(in, "%d", count);
      in += len;
    }
  }
  in[0] = 0;
  return str;
}

int test() {
  char str[] = "AAAABBBCCCCCEEFGIIJJJKLMNNNNOOO";
  std::cout << str << std::endl;

  char* res = StrCompress(str);
  std::cout << res << std::endl;

  return 1;
}

}
#endif /* _PERFORM_STRING_COMPRESSION_H_ */
