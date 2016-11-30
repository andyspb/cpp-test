

namespace array2_ {

TEST_RESULT test() {
  __SCOPE_LOG__;

  int arr[10];
  int *pa = arr;

  std::vector<int> v(2000);
  std::cout << "sizeof(v)" << sizeof(v);

  int is[1] = {0};

  std::cout << "sizeof(is)" << sizeof(is);

  is[2] = 1;


  register int ri = 0;
  int * ptr = &ri;

  const int& temp = int(12);

  std::string s1 = "123";
  std::string s2 = "456";

  std::string s3_copy = s1 + s2;
  const std::string& s3_reference = s1 + s2;

  const std::string str1 = "Hello, ";
  const std::string str2 = "World!";

  const std::string& str = str1 + str2;

  RETURN_OK();
}


}  // namespace array_
