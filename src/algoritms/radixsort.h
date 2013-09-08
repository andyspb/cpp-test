#ifndef _ALGO_RADIX_SORT_H_
#define  _ALGO_RADIX_SORT_H_

#include <iostream>

namespace radix_sort {

slist *radix_list(slist *l, int t);

void algo_radixsort() {
  printf("radix sort test:\n");

  slist * list = new slist();
  list->val = 0;
  list->next = 0;
  slist * sl = list;
  for (int i = 1; i < 100; i++) {
    sl->next = new slist();
    sl->next->next = 0;
    sl->next->val = (i * 789) % 100;
    sl = sl->next;
  }
  sl = list;
  while (sl) {
    printf(" %ld", sl->val);
    sl = sl->next;
  }
  printf("\n\n");

  list = radix_list(list, 2);
  sl = list;
  while (sl) {
    printf(" %ld", sl->val);
    sl = sl->next;
  }
  printf("\n");

}

slist *radix_list(slist *l, int t) {
  int i, j, d, m = 1;
  slist *temp, *out, *head[10], *tail[10];
  out = l;

  for (j = 1; j <= t; j++) {
    for (i = 0; i <= 9; i++)
      head[i] = (tail[i] = NULL);

    while (l != NULL) {
      d = ((int) (l->val / m)) % (int) 10;
      temp = tail[d];
      if (head[d] == NULL)
        head[d] = l;
      else
        temp->next = l;
      temp = tail[d] = l;
      l = l->next;
      temp->next = NULL;
    }
    for (i = 0; i <= 9; i++)
      if (head[i] != NULL)
        break;
    l = head[i];
    temp = tail[i];
    for (d = i + 1; d <= 9; d++) {
      if (head[d] != NULL) {
        temp->next = head[d];
        temp = tail[d];
      }
    }
    m *= 10;
  }
  return (out);
}

} // namespace radix_sort

#endif _ALGO_RADIX_SORT_H_
