/*
 * map.h
 *
 *  Created on: 29 θώνÿ 2015 γ.
 *      Author: andy
 */

#ifndef SRC_LANGUAGE_HASH_MAP_H_
#define SRC_LANGUAGE_HASH_MAP_H_

namespace hashmap {

#define TABLE_SIZE 100

// Default hash function class
template<typename K>
struct KeyHash {
  unsigned long operator()(const K& key) const {
    return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
  }
};

template<typename K, typename V>
class HashNode {
 public:
  HashNode(const K& key, const V& value)
      : key_(key),
        value_(0),
        next_(0) {
  }

  K getKey() const {
    return key_;
  }

  V getValue() const {
    return value_;
  }

  void setValue(const V& value) {
    value_ = value;
  }

  HashNode *getNext() const {
    return next_;
  }

  void setNext(HashNode *next) {
    next_ = next;
  }
 private:
  K key_;
  V value_;
  HashNode* next_;  // next bucket with the same key
};

class HashMap {

};

int test() {
  return 1;
}

}  // namespace hashmap

#endif /* SRC_LANGUAGE_HASH_MAP_H_ */
