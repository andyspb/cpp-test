//Create a C function to create a two dimensional array where:
//a[i][j] = i*j;

void CreateC2DimArray(int x, int y) {
  int ** a;
  if (x <= 0 || y <= 0) {
    printf("incorrect dimension %d x %d", x, y);
    return;
  }
  a = (int **) alloca(x * y * sizeof(int*));

  printf("sizeof(a)=%ld", sizeof(a));

  return;

  int i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      a[i][j] = i * j;
    }
  }

  //print data
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      printf("a[%d][%d]=%d ", i, j, a[i][j]);
    }
    printf("\n");
  }
  free(a);
}

void CreateC2DimInt2() {
  int a[10][20], i, j;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 20; j++) {
      a[i][j] = i * j;
    }
  }

  //print data
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 20; j++) {
      printf("a[%d][%d]=%d ", i, j, a[i][j]);
    }
    printf("\n");
  }

}

void Create2DimArrayTest() {
  cout << "Create C 2Dimensional array test" << endl;
  CreateC2DimArray(5, 10);
  cout << endl;
}
