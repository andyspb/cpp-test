/*
 * blum_filter.h
 *
 *  Created on: Apr 14, 2016
 *      Author: andy
 */

#ifndef SRC_ALGORITMS_BLUM_FILTER_H_
#define SRC_ALGORITMS_BLUM_FILTER_H_

#include <vector>
#include <array>
#include <stdint.h>

namespace blum_filter {

void MurmurHash3_x64_128(const uint8_t *data, std::size_t len,
                         void*, void*) {

}

::std::array<uint64_t, 2> hash(const uint8_t *data,
                             std::size_t len) {
  std::array<uint64_t, 2> hashValue;
  MurmurHash3_x64_128(data, len, 0, hashValue.data());

  return hashValue;
}

inline uint64_t nthHash(uint8_t n,
                        uint64_t hashA,
                        uint64_t hashB,
                        uint64_t filterSize) {
    return (hashA + n * hashB) % filterSize;
}

struct BloomFilter {
  BloomFilter(uint64_t size, uint8_t numHashes);

  void add(const uint8_t *data, std::size_t len) {
    auto hashValues = hash(data, len);

      for (int n = 0; n < m_numHashes; n++) {
          m_bits[nthHash(n, hashValues[0], hashValues[1], m_size)] = true;
      }
  }

  bool possiblyContains(const uint8_t *data, std::size_t len) const {
    auto hashValues = hash(data, len);

      for (int n = 0; n < m_numHashes; n++) {
          if (!m_bits[nthHash(n, hashValues[0], hashValues[1], m_size)]) {
              return false;
          }
      }

      return true;
  }

private:
  uint64_t m_size;
  uint8_t m_numHashes;
  std::vector<bool> m_bits;
};

}


#endif /* SRC_ALGORITMS_BLUM_FILTER_H_ */
