/*
 * hashtable.h
 *
 *  Created on: Jul 16, 2015
 *      Author: andy
 */

#ifndef SRC_HASHCODE_HASHTABLE_H_
#define SRC_HASHTABLE_HASHTABLE_H_

#include "hash_functions_collection.h"

namespace hash_table {

class HashEntry {
 public:
  HashEntry(int key, int value) {
    this->key = key;
    this->value = value;
  }
  ~HashEntry() {
  }

  int getKey() {
    return key;
  }

  int getValue() {
    return value;

  }
 private:
  int key;
  int value;
};

const int TABLE_SIZE = 128;

class HashTable {
 public:
  HashTable() {
    table = new HashEntry*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
      table[i] = NULL;
  }

  int get(int key) {
//    int hash = (key % TABLE_SIZE);
    int hash = hash_functions_collection::knuth_hash_function(key);
    LOG(INFO) << "hash=" << hash;
    LOG(INFO) << "table[hash] =" << table[hash] << " table[hash]->getKey()="
        << table[hash]->getKey();

    while (table[hash] != NULL && table[hash]->getKey() != key) {
      LOG(INFO) << "table[hash] =" << table[hash] << " table[hash]->getKey()="
          << table[hash]->getKey();
      hash = (hash + 1) % TABLE_SIZE;
    }
    if (table[hash] == NULL)
      return -1;
    else
      return table[hash]->getValue();
  }

  void put(int key, int value) {
    //int hash = (key % TABLE_SIZE);
    int hash = hash_functions_collection::knuth_hash_function(key);
    LOG(INFO) << "hash=" << hash;
    while (table[hash] != NULL && table[hash]->getKey() != key)
      hash = (hash + 1) % TABLE_SIZE;
    if (table[hash] != NULL)
      delete table[hash];
    table[hash] = new HashEntry(key, value);
    LOG(INFO) << "hash: " << hash;
  }

  ~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
      if (table[i] != NULL)
        delete table[i];
    delete[] table;
  }

  int size() {
    int counter = 0;
    for (int i = 0; i < TABLE_SIZE; ++i)
      if (table[i] != NULL) {
        ++counter;
      }
    return counter;
  }
 private:
  HashEntry **table;
};
TEST_RESULT test() {
  __SCOPE_LOG__;
  HashTable table;
  constexpr int kMax = 10;
  for (int i = 1; i < kMax; ++i) {
    int value = (i * 100) + (i * 10) + i;
    LOG(INFO) << "table.put(" << i << ", " << value << ")";
    table.put(i, value);
  }

  int size = table.size();
  LOG(INFO) << "table.size()=" << size;

  for (int i = 1; i < kMax; ++i) {
    int value = table.get(i);
    LOG(INFO) << "table.get(" << i << ") =" << value;
  }

  RETURN_OK();
}

}  // namespace

#endif /* SRC_HASHCODE_HASHTABLE_H_ */
