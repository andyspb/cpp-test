#include "test.h"


#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

const char camera_dump [] = "CAMERA_DUMP";
const char pathDecIn [] = "/dump_vp8_dec_in";
const char videofileDecIn [] = "%s/vp8_%05d.chunk";
int iCounterDecIn = 12345;


void prepare_path(char* out, const char* dir, const char* file, int& counter)
{
    FILE*  fd = NULL;
    char* camera_dump_path = getenv(camera_dump);
    if (!camera_dump_path) {
        std::cout << "dump_dir:NULL" << std::endl;

        return;
    }

    std::cout << "dump_dir:" <<camera_dump_path << std::endl;
    std::cout << "path:" << dir << std::endl;
    std::cout << "file:" << file << std::endl;


    struct stat st = { 0 };
    if (stat(camera_dump_path, &st) == -1) {
        mkdir(camera_dump_path, 0700);
    }
    int size = strlen(camera_dump_path)+strlen(dir)+sizeof(char);
    char dir_dump_path[size];
    memset(dir_dump_path, 0, size);
    strcpy(dir_dump_path, camera_dump_path);
    std::cout << "dump_path:" << dir_dump_path << std::endl;
    strcat(dir_dump_path, dir);
    std::cout << "dump_path:" << dir_dump_path << std::endl;

    if (stat(dir_dump_path, &st) == -1) {
        mkdir(dir_dump_path, 0700);
    }

    size = strlen(dir_dump_path)+strlen(file)+32;
    char file_dump_path[size];
    memset(file_dump_path, 0, size);

    sprintf (file_dump_path, file, dir_dump_path, counter++);
    std::cout << "filename:" << file_dump_path << std::endl;
    strcpy(out, file_dump_path);
}


int main(int argc, char **argv) {
  __SCOPE_LOG__;

//  char out[256] = {0};
//
//  prepare_path(out, pathDecIn, videofileDecIn, iCounterDecIn);
//  prepare_path(out, pathDecIn, videofileDecIn, iCounterDecIn);
//  prepare_path(out, pathDecIn, videofileDecIn, iCounterDecIn);
//  prepare_path(out, pathDecIn, videofileDecIn, iCounterDecIn);
//
//  std::cout << "out:" << out << std::endl;


//    assert(algorithms::test());
//  assert(array_::test());
//    assert(array_::test());
//  assert(binary_tree::test());
//  assert(bits::test());
//  assert(blockchain::test());
    assert(cpp1x::test());
//  assert(cci4::test());
//  assert(cci5::test());
//  assert(diff::test());
//  assert(exceptions::test());
//  assert(facebook::test());
//  assert(functors::test());
//  assert(google_2::test());
//  assert(hashtable::test());
//  assert(hashcodes::test());
//  assert(hashmap::test());
//  assert(http::test());
//  assert(lambda::test());
//  assert(language::test());
//  assert(last_1::test());
//  assert(lock_free::test());

  assert(logger::test());

  //  assert(lge::test());
//  assert(mem_test::test());
//  assert(moto::test());
//  assert(quiz::test());
//  assert(overloading::test());
//  assert(patterns::test());
//  assert(serialization::test());
//  assert(smart_ptr_::test());
//  assert(spb::test());
//  assert(sqllite::test());
//  assert(sqrt_::test());
//  assert(stackoverflow::test());
//  assert(static_::test());
//  assert(stl::test());
//  assert(threads::test());
//  assert(templates::test());
//  assert(teramind::test());
//  assert(tests::test());
//  assert(terramind::test());
//  assert(virtuals::test());
//  assert(clock_::test());
//  assert(cpp1x::test());
//  assert(threads::test());
//  assert(futures::test());
//  assert(epam::test() );
//  assert(ms::test() );
//  assert(google_2::test());
//  assert(alignment::test());

//  assert(yandex::test());

//  int arr[10];
//  int *pa = arr;

//  std::vector<int> v(2000);
//  std::cout << "sizeof(v)" << sizeof(v);

//  int is[1];
//  is[2] = 1;


//  register int ri = 0;
//  int * ptr = &ri;

//  const int& temp = int(12);
//
//  std::string s1 = "123";
//  std::string s2 = "456";
//
//  std::string s3_copy = s1 + s2;
//  const std::string& s3_reference = s1 + s2;
//
//  const std::string str1 = "Hello, ";
//  const std::string str2 = "World!";
//
//  const std::string& str = str1 + str2;
  return 0;
}

