/*
 * 5_8_drawHorizontalLine.h
 *
 *  Created on: 23 џэт. 2015 у.
 *      Author: andy
 */

#ifndef _DRAWHORIZONTALLINE_H_
#define _DRAWHORIZONTALLINE_H_

//  A monochrome screen is stored as a single array of bytes, allowing eight consecutive
//  pixels to be stored in one byte. The screen has width w, where w is divisible
//  by 8 (that is, no byte will be split across rows). The height of the screen, of course,
//  can be derived from the length of the array and the width. Implement a function
//  drawHorizontalLine(byte[] screen, int width, intxl, intx2, inty) which draws a horizontal
//  line from (x 1, y) to (x2, y).

namespace draw_horizontal_line {


void drawLine(byte[] screen, int width, int xl, int x2, int y) {
2 int start_offset = xl % 8;
3 int first_full_byte = xl / 8;
4 if (start_offset != 0) {
5 first_full_byte++;
6 }
7
8 int end_offset = x2 % 8;
CrackingTheCodinglnterview.com 255
Solutions to Chapter 5 | Bit Manipulation
9 int last_full_byte = x2 / 8;
10 if (end_offset != 7) {
11 last_full_byte--;
12 }
13
14 // Set full bytes
15 for (int b = first_full_byte; b <= last_full_byte; b++) {
16 screen[(width / 8) * y + b] = (byte) 0xFF;
17 }
18
19 // Create masks for start and end of line
20 byte start_mask = (byte) (0xFF Л start_offset);
21 byte endjnask = (byte) ~(0xFF Л (end_offset +1));
22
23 // Set start and end of line
24 if ((xl / 8) == (x2 / 8)) { // xl and x2 are in the same byte
25 byte mask = (byte) (start_mask & endjnask);
26 screen[(width / 8) * y + (xl / 8)] |= mask;
27 } else {
28 if (start_offset != 0) {
29 int bytejiumber = (width / 8) * y + first_full_byte - 1;
30 screen[byte_number] |= start_mask;
31 }
if (end_offset != 7) {
33 int byte_number = (width / 8) * y + last_full_byte + 1;
34 screen[byte_number] |= endjnask;
35 }
36 }
37 }

}  // namespace draw_horizontal_line



#endif /* 5_8_DRAWHORIZONTALLINE_H_ */
