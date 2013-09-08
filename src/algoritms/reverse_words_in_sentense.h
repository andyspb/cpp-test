//Given a const null terminated string containing a sentence,
//can you print out the words of the sentence in reverse without
//changing any data and without creating a temporary string buffer?
//Do not use any helper functions, write it all out on your own.
//(ie "The dog is fast" becomes "fast is dog The")

#include <iostream>
using namespace std;

void rev(char *l, char *r);
void ReverseWordsInSentence(char * str) {

  int length = strlen(str);
  if (length <= 1) {
    return;
  }
  char *end, *x, *y;
  end = &str[length];
  rev(str, end - 1);
  x = str - 1;
  y = str;
  while (x++ < end) {
    if (*x == '\0' || *x == ' ') {
      rev(y, x - 1);
      y = x + 1;
    }
  }
  printf("%s\n", str);
}

void rev(char *l, char *r) {
  char t;
  while (l < r) {
    t = *l;
    *l++ = *r;
    *r-- = t;
  }
}

void ReverseWordsInSentenceTest() {
  cout << endl << "Reverse words in a sentence test" << endl;
  char str[] = "The dog is fast";
  cout << str << endl;
  ReverseWordsInSentence(str);
  cout << endl;
}
