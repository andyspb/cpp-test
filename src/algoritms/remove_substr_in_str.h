#ifndef REMOVE_SUBSTR_IN_STR_H_
#define REMOVE_SUBSTR_IN_STR_H_
//Given two strings S1 and S2.
//Delete from S2 all those characters which occur in S1
//also and finally create a clean S2 with the relevant
//characters deleted.

void algo_23() {
  printf("Test - remove substr in str:\n");

  char s1[] = "hello world : algo_23 test";
  printf("\nString is:%s", s1);
  char s2[] = "elt";
  printf("\nDelete all symbols:%s", s2);

  unsigned int i, j;
  for (i = 0, j = 0; i < strlen(s1); ++i) {
    if (!strchr(s2, s1[i])) {
      s1[j] = s1[i];
      ++j;
    }
  }

  s1[j] = '\0';
  printf("\nString is:%s\n", s1);
}


#endif  // REMOVE_SUBSTR_IN_STR_H_
