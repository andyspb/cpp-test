/*
 * 5_7_find_missing_int.h
 *
 *  Created on: 23  эт. 2015 у.
 *      Author: andy
 */

#ifndef _FIND_MISSING_INT_H_
#define _FIND_MISSING_INT_H_

//  You may have seen a very similar sounding problem: Given a list of numbers from 0
//  to n, with exactly one number removed, find the missing number. This problem can
//  be solved by simply adding the list of numbers and comparing it to the actual sum of
//  0 through n, which is n * (n + 1) / 2.The difference will be the missing number.

namespace find_missing_int {

public int findMissing(ArrayList<BrtInteger> array) {
  2 I* Start from the least significant bit, and work our way up */
  3 return findMissing(array, 0);
  4}
5
6 public int findMissing(ArrayList<Bit!nteger> input, int column) {
  if (column >= BitInteger.INTEGER_SIZE) {  // We're done!
    5 return 0;
    9}
  10 ArrayList<BitInteger> oneBits =
  254 Cracking the Coding Interview I Solutions to Bit Manipulation
  Solutions to Chapter 5 | Bit Manipulation
  new ArrayList<BitInteger>(input.size()/2);
  12 ArrayList<BitInteger> zeroBits =
  13 new ArrayList<BitInteger>(input.size()/2);
  14
  15 -For (Bitlnteger t : input) {
    16 if (t.fetch(column) == 0) {
      17 zeroBits.add(t);
      18} else {
      19 oneBits.add(t);
      20}
    21}
  if (zeroBits. sizeQ <= oneBits. size()) {
    int v = findMissing(zeroBits, column + 1);
    24 return (v л 1) | 0;
    25} else {
    26 int v = findMissing(.oneBits, column + 1);
    27 return (v л 1) | 1;
    28}
  29}

}
  // namespace find_missing_int

#endif /* 5_7_FIND_MISSING_INT_H_ */
