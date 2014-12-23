#ifndef TEST_H_
#define TEST_H_

#ifdef __linux__
  //linux code goes here
  #pragma GCC diagnostic ignored "-Wunused-variable"
  #pragma GCC diagnostic ignored "-Wuninitialized"
  #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
  #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif _WIN32
  // windows code goes here
#else
  // something else
#endif


#endif /* TEST_H_ */
