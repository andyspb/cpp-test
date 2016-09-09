/*
 * camera.h
 *
 *  Created on: 4 сент. 2016 г.
 *      Author: andy
 */

#ifndef SRC_LGE_CAMERA_H_
#define SRC_LGE_CAMERA_H_

#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef _WIN32
#include <direct.h>
#endif // _WIN32


namespace camera {
#ifdef __GNUC__

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
#if defined(_WIN32)
        mkdir(camera_dump_path);
#else
        mkdir(camera_dump_path, 0700);
#endif

    }
    int size = strlen(camera_dump_path)+strlen(dir)+sizeof(char);
    char dir_dump_path[size];
    memset(dir_dump_path, 0, size);
    strcpy(dir_dump_path, camera_dump_path);
    std::cout << "dump_path:" << dir_dump_path << std::endl;
    strcat(dir_dump_path, dir);
    std::cout << "dump_path:" << dir_dump_path << std::endl;

    if (stat(dir_dump_path, &st) == -1) {

#if defined(_WIN32)
      mkdir(dir_dump_path);
#else
        mkdir(dir_dump_path, 0700);
#endif
    }

    size = strlen(dir_dump_path)+strlen(file)+32;
    char file_dump_path[size];
    memset(file_dump_path, 0, size);

    sprintf (file_dump_path, file, dir_dump_path, counter++);
    std::cout << "filename:" << file_dump_path << std::endl;
    strcpy(out, file_dump_path);
}
#endif

TEST_RESULT test() {
  __SCOPE_LOG__;
#ifdef __GNUC__

  //  char out[256] = {0};
  //
  //  prepare_path(out, pathDecIn, videofileDecIn, iCounterDecIn);
  //  prepare_path(out, pathDecIn, videofileDecIn, iCounterDecIn);
  //  prepare_path(out, pathDecIn, videofileDecIn, iCounterDecIn);
  //  prepare_path(out, pathDecIn, videofileDecIn, iCounterDecIn);
  //
  //  std::cout << "out:" << out << std::endl;
#endif
  RETURN_OK();

}

}  // namespace camera


#endif /* SRC_LGE_CAMERA_H_ */
