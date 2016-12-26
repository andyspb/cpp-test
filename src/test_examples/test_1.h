//  test.h
//  author: andrey.krutogolov@gmail.com
//  date:   10.03.2013

#ifndef TEST1_H_
#define TEST1_H_

#include <stdio.h>
#include <assert.h>


namespace leap_1 {

//typedef int[] IntArray;

typedef struct {
  char* alias; /* '\0'-terminated C string */
  int specific_id;
} aliasID;

int GetNumberOfAliases(void) {
  return 4;
}

aliasID * GetNextAlias(void) {
  return new aliasID();
}

int* GetSomeIDs(aliasID** aID, int *numOfAliases) {
  int i(0), num(GetNumberOfAliases());
  int* ids((int*) malloc(num * sizeof(int)));
  /*
   The ids are defined here
   In test it does not matter what we want to do
   assign ids or get ids from aliases,
   i cant see in the task's context.
   for example suppose we get ids from aliases
   */
  for (; i < num; ++i) {
    aID[i] = GetNextAlias();
    ids[i] = aID[i]->specific_id;
  }
  *numOfAliases = num;
  return ids;
}

void ProcessIDs() {
  int i(0), aliasesNum;
  /* we should allocate some buff for aliases
   let say 1024 * alias size
   for real life we shall know reqs
   */
  aliasID** alias_ids = (aliasID**) malloc(sizeof(aliasID*) * 1024);
  int* some_ids(GetSomeIDs(alias_ids, &aliasesNum));
  if (some_ids) {
    /* print out ids */
    for (; i < aliasesNum; ++i) {
      printf("%d\n", some_ids[i]);
    }
    /* print out alias nodes */
    for (i = 0; i < aliasesNum; ++i) {
      printf("alias_ids[%d]: string=%s  specific_id=%d\n", i,
             alias_ids[i]->alias, alias_ids[i]->specific_id);
    }

    // release memory
    free(some_ids);
  }

  for (i = 0; i < aliasesNum; ++i) {
    free(alias_ids[i]->alias);
    free(alias_ids[i]);
  }
  free(alias_ids);
}

/* we want to use �theFirst� and  �r� here*/

/*-------- GetSomeIDs-----*/
int * GetSomeIDs() {
  static int ids[8];
  /* The ids are defined here */
  int size = static_cast<int>(sizeof(ids) / sizeof(ids[0]));
  for (int i = 0; i < size; ++i) {
    ids[i] = i + 1;
  }
  return ids;
}

int* ReorderIDs(int *someIDs) {
  return NULL;
}

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
  int theFirst;

  int *someIDs, *r;
  someIDs = GetSomeIDs(); /* defined below */
  theFirst = someIDs[0];

//  int ids2[] = GetSomeIDsArr();

  printf("theFirst=%d\n", theFirst);
  r = ReorderIDs(someIDs);

  int theSecond = someIDs[1];
  printf("theSecond=%d\n", theSecond);

  someIDs = 0;
  r = 0;

  //assert(!r);
  RETURN_OK();
}

}  // namespace test_1

#endif  // TEST1_H_
