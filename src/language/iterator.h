#ifndef ITERATOR_H
#define ITERATOR_H

namespace _iterator {
class StringIterator {
  const char *position, *end;
 public:
  StringIterator(const char * str)
      :
          position(str),
          end(str + strlen(str)) {
  }
  bool at_end() const {
    return position == end;
  }
  void next() {
    ++position;
  }
  bool hasNext() const {
    return position < end;
  }
  char get_char() const {
    return *position;
  }
};

void hello_world(StringIterator & iterator) {
  StringIterator i = iterator;
  while (i.hasNext()) {
    std::cout << "." << i.get_char() << ".";
    i.next();
  }

}

int test() {
  printf("Iterator pattern test\n");
  const char * str = "This Is Iterator test!\n";
  std::cout << str;
  StringIterator iterator(str);
  hello_world(iterator);
  printf("\n");
  return 0;
}

}  // namespace _iterator

#endif  // ITERATOR_H
