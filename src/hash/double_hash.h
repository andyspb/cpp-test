/*
 * double_hash.h
 *
 *  Created on: Feb 18, 2018
 *      Author: andy
 */

#ifndef SRC_HASH_DOUBLE_HASH_H_
#define SRC_HASH_DOUBLE_HASH_H_

// Hash table size
#define HASH_TABLE_SIZE 13
// Used in second hash function.
#define PRIME 7

namespace double_hash {

class DoubleHash {
  int *hashTable;
  int curr_size;

 public:
  bool isFull() {
    return (curr_size == HASH_TABLE_SIZE);
  }

  int hash1(int key) {
    return (key % HASH_TABLE_SIZE);
  }

  int hash2(int key) {
    return (PRIME - (key % PRIME));
  }

  DoubleHash() {
    hashTable = new int[HASH_TABLE_SIZE];
    curr_size = 0;
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
      hashTable[i] = -1;
  }

  void insertHash(int key) {
    if (isFull())
      return;

    int index = hash1(key);
    std::cout << " hash1:" << index << " " << std::endl;

    // if collision occurs
    if (hashTable[index] != -1) {
      std::cout << " Collision!!!\n";
      // get index2 from second hash
      int index2 = hash2(key);
      std::cout << " hash2:" << index2 << " " << std::endl;

      int i = 1;
      while (true) {
        int newIndex = (index + i * index2) % HASH_TABLE_SIZE;
        std::cout << " newIndex:" << newIndex << " " << std::endl;

        if (hashTable[newIndex] == -1) {
          hashTable[newIndex] = key;
          break;
        }
        ++i;
      }
    }

    // if no collision occurs
    else
      hashTable[index] = key;
    curr_size++;
  }

  // function to display the hash table
  void displayHash() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
      if (hashTable[i] != -1)
        std::cout << i << " --> " << hashTable[i] << std::endl;
      else
        std::cout << i << std::endl;
    }
  }
};

int test() {

  int a[] = { 19, 27, 36, 10, 64 };
  int n = sizeof(a) / sizeof(a[0]);

  // inserting keys into hash table
  DoubleHash h;
  for (int i = 0; i < n; ++i) {
    std::cout << a[i];
    h.insertHash(a[i]);
  }

  std::cout << "Hashing done.\n";

  // display the hash Table
  h.displayHash();
  return 1;
}

}  // namespace double_hash

#endif /* SRC_HASH_DOUBLE_HASH_H_ */
