#ifndef SUBSTR_SEARCH_H_
#define SUBSTR_SEARCH_H_

#include <iostream>
namespace substr_search {

void bf(char *x, char *y, int m) {
 /* »щем до конца, вообще говор€ можно до позиции n-m */
 for(int i=0; *y!='\0'; i++, y++) {
   if(memcmp(y,x,m) == 0) {
     std::cout << "Found at position: " << i;
   }
 }
}


int test() {
  return 1;
}

}

#endif /* SUBSTR_SEARCH_H_ */
