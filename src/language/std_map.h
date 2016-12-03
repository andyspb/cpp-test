#include <iostream>
#include <map>
#include <iterator>

void StdMapTest() {
  std::cout << "std::map Test" << std::endl;

  std::map<int, int> imap;

  for (int i = 0; i < 10; i++) {
    imap[i] = 2 * i;
    std::cout << imap[i] << " ";
  }
  std::cout << std::endl;

//   for (map<int, int>::iterator i = imap.begin(); i != imap.end() ; i++)
//   {
////       imap.erase( i ); //invalid
////       imap.erase( ++i ); //invalid
//     imap.erase( i++ ); //valid
//   }

//imap.clear();
  std::cout << "imap size=" << imap.size() << std::endl;

  for (std::map<int, int>::iterator iter = imap.begin(); iter != imap.end();
      iter++) {
    std::cout << iter->first << ":" << iter->second << " ";
  }
  std::cout << std::endl;

  while (!imap.empty()) {

    std::map<int, int>::iterator iter = imap.begin();
    imap.erase(iter);
  }

  //for (int i = 20; i <30 ; i++)
  //{
  //    imap[i]= i+i;
  //}

  std::cout << "imap size=" << imap.size() << std::endl;

}

