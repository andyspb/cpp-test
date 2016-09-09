/*
 * hashtable.h
 *
 *  Created on: Jul 16, 2015
 *      Author: andy
 */

#ifndef SRC_HASHCODE_HASHTABLE_H_
#define SRC_HASHTABLE_HASHTABLE_H_

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
    int hash = (key % TABLE_SIZE);
    while (table[hash] != NULL && table[hash]->getKey() != key)
      hash = (hash + 1) % TABLE_SIZE;
    if (table[hash] == NULL)
      return -1;
    else
      return table[hash]->getValue();
  }

  void put(int key, int value) {
    int hash = (key % TABLE_SIZE);
    while (table[hash] != NULL && table[hash]->getKey() != key)
      hash = (hash + 1) % TABLE_SIZE;
    if (table[hash] != NULL)
      delete table[hash];
    table[hash] = new HashEntry(key, value);
  }

  ~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
      if (table[i] != NULL)
        delete table[i];
    delete[] table;
  }
 private:
  HashEntry **table;
};
TEST_RESULT test() {
  __SCOPE_LOG__;
  HashTable table;
  table.put(1,1);
  table.put(2,2);
  table.put(3,3);
  table.put(4,4);
  table.put(5,5);
  RETURN_OK();
}

}  // namespace

#endif /* SRC_HASHCODE_HASHTABLE_H_ */
