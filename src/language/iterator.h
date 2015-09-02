#ifndef LANGUAGE_ITERATOR_H
#define LANGUAGE_ITERATOR_H

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

TEST_RESULT test() {
  LOG(INFO) << "Iterator pattern test";
  const char * str = "This Is Iterator test!";
  std::cout << str;
  StringIterator iterator(str);
  hello_world(iterator);
  printf("\n");
  RETURN_OK();
}

}  // namespace _iterator

#endif  // LANGUAGE_ITERATOR_H
