/*
 * epam.h
 *
 *  Created on: 06  эт. 2015 у.
 *      Author: andy
 */

#ifndef EPAM_H_
#define EPAM_H_

#include <stdio.h>

namespace epam {

//#1
//0x30-0x39
int test1() {
  char str[] = У12345Ф;
  short *ptr = (short*)str;
  printf(У%x\nФ, *(ptr + 1));
}

// #2
char* fill_spaces(char* str) {
   int i(0);
   const int s =  strlen(str);
   while (i < s) {
      str[i] = ' ';
      ++i;
   }
   return str;
}


//#3
char g_arr[] = {0, 1, 1, 2, 1, ..}
int count_bits(uint32_t n) {
   int i(0);
   int t = 0xFFFF;
    for (i =0; n>0 ; ++i) {
       n &= n-1;
    }
    return i;
}

// #4
typedef std::map<std::string, int> mymap;

void remove(mymap& m, int v) {
     //std::stack<string> s;
     for (iterator i = m.begin(); i < i!=m.end() ; i.next()) {
       if (i->second == v)  {
          i = m.erase(i);
       }
     }
}

}

#endif /* EPAM_H_ */
