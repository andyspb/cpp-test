#ifndef STRING_LITERAL_H_
#define STRING_LITERAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


namespace string_literal {

int test() {
	std::cout << "Test: string literal --> " << std::endl;

	const char *s1 = "abcabc";
	char s2[] = "abcabc";

	std::cout << "s1: strlen:" << strlen(s1) << " sizeof: " << sizeof(s1)
			<< std::endl;

	std::cout << "s2: strlen:" << strlen(s2) << " sizeof: " << sizeof(s2)
			<< std::endl;

	return 1;
}
}  // namespace string_literal

#endif /* STRING_LITERAL_H_ */
