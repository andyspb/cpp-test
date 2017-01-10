/*
 * perfect_hash_function.h
 *
 *  Created on: Aug 5, 2016
 *      Author: andy
 */

#ifndef SRC_HASH_PERFECT_HASH_FUNCTION_H_
#define SRC_HASH_PERFECT_HASH_FUNCTION_H_

#include <vector>
#include <list>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <string>

namespace perfect_hash_function {

typedef long long int long_int;
const int max_int = 1000000001;

// function for calculation of hash
inline int hash(long_int a_prime, long_int b_prime, int p_prime, int table_size,
                int key) {
  return (((a_prime * key + b_prime) % p_prime) % table_size);
}

// class for mini-hash table in cells of main hash-table
class Bucket {
  std::vector<int> _cells;
  int size;  // the size of mini-table should be greater then 4
  long_int hash_a;
  long_int hash_b;
  int prime;

 public:
  Bucket()
      : size(0),
        hash_a(0),
        hash_b(0),
        prime(0) {
  }
  void Initialize() {
    prime = 17;
    hash_a = std::rand() % prime;
    hash_b = 1 + std::rand() % (prime - 1);
  }

  // construct hash table from list of elements
  void Construct(std::list<int>& input) {
    if (input.empty()) {
      size = 0;
      return;
    }

    size = input.size() * input.size();
    bool flag = true;

    // while there is no collisions in table
    while (flag) {
      _cells.assign(size, max_int);
      Initialize();
      std::list<int>::iterator elem = input.begin();
      while (elem != input.end() && flag) {
        int hashKey = hash(hash_a, hash_b, prime, size, *elem);
        if (hashKey < 0)
          hashKey = -hashKey;

        // if collision then construct hash table from the begining!
        if (_cells[hashKey] != max_int) {
          flag = false;
          break;
        }
        _cells[hashKey] = *elem;
        ++elem;
      }

      if (!flag)
        flag = true;
      else
        flag = false;
    }
  }

  bool Contains(int elem) {
    if (size == 0)
      return false;
    int hashKey = hash(hash_a, hash_b, prime, size, elem);
    if (hashKey < 0)
      hashKey = -hashKey;
    if (_cells[hashKey] == elem)
      return true;
    return false;
  }
};

// class for main hash table
class FixedSet {
  int _tableSize;
  long_int _hashFuncA;
  long_int _hashFuncB;
  int _primeNumber;
  std::vector<std::list<int> > _elementsInCells;
  std::vector<Bucket> _buckets;

 public:
  FixedSet()
      : _tableSize(0),
        _hashFuncA(0),
        _hashFuncB(0),
        _primeNumber(0) {
    _primeNumber = 100013;  // the maximum prime number
    _hashFuncA = std::rand() % _primeNumber;
    _hashFuncB = 1 + std::rand() % (_primeNumber - 1);
  }

  void setTableSize(int size) {
    _tableSize = size;
    _buckets.resize(size);
  }

  void Initialize(const std::vector<int>& numbers) {
    _tableSize = numbers.size();
    _buckets.resize(numbers.size());
    _elementsInCells.resize(numbers.size());
    for (size_t i = 0; i < numbers.size(); ++i) {
      int hashKey = hash(_hashFuncA, _hashFuncB, _primeNumber, _tableSize,
                         numbers[i]);
      if (hashKey < 0)
        hashKey = -hashKey;
      _elementsInCells[hashKey].push_back(numbers[i]);
    }
    for (size_t i = 0; i < numbers.size(); ++i) {
      _buckets[i].Construct(_elementsInCells[i]);
    }
  }

  bool Contains(int number) {
    int hashKey = hash(_hashFuncA, _hashFuncB, _primeNumber, _tableSize,
                       number);
    if (hashKey < 0)
      hashKey = -hashKey;
    return _buckets[hashKey].Contains(number);
  }
};

TEST_RESULT test() {
  __SCOPE_LOG__;

  clock_t begin, end;
  double time_spent;
  std::srand(time(NULL));
  int number_elements_ = 5;

  FixedSet fs;
  begin = clock();
  std::vector<int> inputVector;
  fs.setTableSize(number_elements_);

  for (int i = 0; i < number_elements_; ++i) {
    int elemValue;
    scanf("%d", &elemValue);

    inputVector.push_back(elemValue);
  }

  fs.Initialize(inputVector);
  end = clock();
  int numberOfElementsForSearch;
  scanf("%i", &numberOfElementsForSearch);
  for (int i = 0; i < numberOfElementsForSearch; ++i) {
    int elem;
    scanf("%d", &elem);
    if (fs.Contains(elem)) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

  time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
  std::cout << time_spent << std::endl;

  RETURN_OK();
}

}  // namespace perfect_hash_function

#endif /* SRC_HASH_PERFECT_HASH_FUNCTION_H_ */
