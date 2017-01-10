/*
 * hash_functions_collection.h
 *
 *  Created on: 10 џэт. 2017 у.
 *      Author: andy
 */

#ifndef SRC_HASH_HASH_FUNCTIONS_COLLECTION_H_
#define SRC_HASH_HASH_FUNCTIONS_COLLECTION_H_


namespace hash_functions_collection {


inline ULONG hashFunc( ULONG i ) {
// see http://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
//return  ( ( 2166136261UL ^ i ) * 16777619 );              // VERY BAD
//return  ( 2166136261UL ^ (i * 16777619) );                // VERY BAD
//return ((i >> 16)^i);                                     // NOT WORKING
//return ( i * 2654435761 >> 16 );                          // Knuth's multiplicative method // GOOD
return ( i * 2654435761 >> 8 );                             // GOOD, even better than Knuth for map size 2^16 ( 65536 fields )
//return ( i * 2654435761 >> 16 ) ^ i;                      // REASONABLY GOOD but worse than pure Knuth
//i = ((i >> 16) ^ i) * 0x45d9f3b; i = ((i >> 16) ^ i) * 0x45d9f3b; return  ((i >> 16) ^ i);                                        // REASONABLY GOOD but worse than pure Knuth
//i = ((i >> 16) ^ i) * 0x45d9f3b; return  ((i >> 16) ^ i); // LESS GOOD
//i = ((i >> 16) ^ i) * 0x3335b369; i = ((i >> 16) ^ i) * 0x3335b369; return  ((i >> 16) ^ i);                                        // LESS GOOD
};

unsigned int hash(unsigned int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

// Knuth's multiplicative method:
int knuth_hash_function(int i) {
  return (i*2654435761) % (2^32);
}

int k_hash(int v)
{
    v *= 2654435761;
    return v >> 32;
}
uint32_t k__hash(uint32_t v)
{
    return v * (2654435761);
}

}


#endif /* SRC_HASH_HASH_FUNCTIONS_COLLECTION_H_ */
