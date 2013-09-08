void algo_ownsizeof() {
  printf("algo tests own sizeof function|n");

  int p = 0;
#pragma warning(disable: 4312)
#pragma warning(disable: 4311)
  p = (int) (char*) ((short*) p + 1);

  printf("size of int =%d\n", p);
}
