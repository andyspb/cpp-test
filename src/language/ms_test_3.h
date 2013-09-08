char * ms_itoa(int value, char *str, int base = 10);

void ms_itoa_test() {
  char * str = NULL;
  printf("ms_itoa(0) result = :%s\n", ms_itoa(0, str));
  printf("ms_itoa(-1) result = :%s\n", ms_itoa(-1, str));
  printf("ms_itoa(1234) result = :%s\n", ms_itoa(1234, str));
}

char * ms_itoa(int value, char * str, int base) {
  if (value == 0) {
    str = (char *) malloc(2 * sizeof(char));
    *str = '0';
    *(str + 1) = '\0';
    return str;
  } else {
    bool negative = (value < 0);

    char buff[256];
    buff[0] = '\0';
    if (negative) {
      value *= -1;
    }

    int i = 0;

    while (value != 0) {
      buff[++i] = value % 10 + char('0');
      value = value / 10;
    }

    if (negative) {
      buff[++i] = '-';
    }

    //revert string
    int m = i >> 1;
    for (int j = 0; j <= m; j++) {
      char ch = buff[j];
      buff[j] = buff[i - j];
      buff[i - j] = ch;
    }
    str = (char *) malloc((i + 1) * sizeof(char));
    memset(str, 0, (i + 1) * sizeof(char));
    printf("i=%d sizeof(str)=%d\n", i, (i + 1) * sizeof(char));
    memcpy(str, buff, (i + 1) * sizeof(char));
    return str;
  }
  return 0;
}
