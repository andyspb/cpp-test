// utils.h
// author: andrey.krutogolov@gmail.com
// date:   11.04.2013


#ifndef UTILS_H_
#define UTILS_H_

// A macro to disallow the evil copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&); \
    void operator=(const TypeName&)

#endif  // UTILS_H_
