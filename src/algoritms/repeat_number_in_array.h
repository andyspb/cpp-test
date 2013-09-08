//http://sites.google.com/site/vijaytechi/interview

void repeat_number_in_array() {
  printf("Test repeat_number_in_array\n");

  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 10, 11, 12, 13 };
  int size = sizeof(arr) / sizeof(arr[0]);
  int sum = 0;
  for (int i = 0; i < size; i++) {
    printf("%2d ", arr[i]);
    sum += arr[i];
  }
  printf("\nsum=%d\n", sum);
  printf("array size = %d\n", size);

  int s = size - 1;

  printf("s=%d\n", s);

  int sum_s = (size * (size - 1)) / 2;

  printf("sum_s=%d\n", sum_s);

  printf("duplicate is %d\n", sum - sum_s);

}
