#include <iostream>
#include <map>
#include <iterator>

using namespace std;

void StdMapTest() {
  cout << "std::map Test" << endl;

  map<int, int> imap;

  for (int i = 0; i < 10; i++) {
    imap[i] = 2 * i;
    cout << imap[i] << " ";
  }
  cout << endl;

//   for (map<int, int>::iterator i = imap.begin(); i != imap.end() ; i++)
//   {
////       imap.erase( i ); //invalid
////       imap.erase( ++i ); //invalid
//     imap.erase( i++ ); //valid
//   }

//imap.clear();
  cout << "imap size=" << imap.size() << endl;

  for (map<int, int>::iterator iter = imap.begin(); iter != imap.end();
      iter++) {
    cout << iter->first << ":" << iter->second << " ";
  }
  cout << endl;

  while (!imap.empty()) {

    map<int, int>::iterator iter = imap.begin();
    imap.erase(iter);
  }

  //for (int i = 20; i <30 ; i++)
  //{
  //    imap[i]= i+i;
  //}

  cout << "imap size=" << imap.size() << endl;

}

