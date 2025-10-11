// vim: set ts=2 sw=2:
/*
*****************************************************************************
*
*    Copyright (C) 2025 David Latham
*
*    This library is free software; you can redistribute it and/or
*    modify it under the terms of the GNU Lesser General Public
*    License as published by the Free Software Foundation; either
*    version 2.1 of the License, or (at your option) any later version.
*
*    This library is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    Lesser General Public License for more details.
*
*    You should have received a copy of the GNU Lesser General Public
*    License along with this library; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
*    USA
*
* https://github.com/linuxplayground/z80-compiler-kit-libcpm
*
*****************************************************************************
*/

/*
 * These are the course and fine register values for the 3 tone channels.
 * The indexes of the array are the piano key numbers.
 *
 * The play_note_function takes the index for the note you want to play and
 * selects the register values from these arrays.
 *
 * The worksheet for these values is in the docs directory.
 */

#ifndef _AYNOTES_H
#define _AYNOTES_H

/*
 * These are the course and fine register values for the 3 tone channels.
 * The indexes of the array are the piano key numbers.
 *
 * The play_note_function takes the index for the note you want to play and
 * selects the register values from these arrays.
 *
 * The worksheet for these values is in the docs directory.
 */


unsigned char notes_course[89] = {
   0x00 // 0 
  ,0x0F // 1  A0
  ,0x0F // 2  A0#
  ,0x0E // 3  B0
  ,0x0D // 4  C1
  ,0x0C // 5  C1#
  ,0x0B // 6  D1
  ,0x0B // 7  D1#
  ,0x0A // 8  E1
  ,0x0A // 9  F1
  ,0x09 // 10 F1#
  ,0x08 // 11 G1
  ,0x08 // 12 G1#
  ,0x07 // 13 A1
  ,0x07 // 14 A1#
  ,0x07 // 15 B1
  ,0x06 // 16 C2
  ,0x06 // 17 C2#
  ,0x05 // 18 D2
  ,0x05 // 19 D2#
  ,0x05 // 20 E2
  ,0x05 // 21 F2
  ,0x04 // 22 F2#
  ,0x04 // 23 G2
  ,0x04 // 24 G2#
  ,0x03 // 25 A2
  ,0x03 // 26 A2#
  ,0x03 // 27 B2
  ,0x03 // 28 C3
  ,0x03 // 29 C3#
  ,0x02 // 30 D3
  ,0x02 // 31 D3#
  ,0x02 // 32 E3
  ,0x02 // 33 F3
  ,0x02 // 34 F3#
  ,0x02 // 35 G3
  ,0x02 // 36 G3#
  ,0x01 // 37 A3
  ,0x01 // 38 A3#
  ,0x01 // 39 B3
  ,0x01 // 40 C4
  ,0x01 // 41 C4#
  ,0x01 // 42 D4
  ,0x01 // 43 D4#
  ,0x01 // 44 E4
  ,0x01 // 45 F4
  ,0x01 // 46 F4#
  ,0x01 // 47 G4
  ,0x01 // 48 G4#
  ,0x00 // 49 A4
  ,0x00 // 50 A4#
  ,0x00 // 51 B4
  ,0x00 // 52 C5
  ,0x00 // 53 C5#
  ,0x00 // 54 D5
  ,0x00 // 55 D5#
  ,0x00 // 56 E5
  ,0x00 // 57 F5
  ,0x00 // 58 F5#
  ,0x00 // 59 G5
  ,0x00 // 60 G5#
  ,0x00 // 61 A5
  ,0x00 // 62 A5#
  ,0x00 // 63 B5
  ,0x00 // 64 C6
  ,0x00 // 65 C6#
  ,0x00 // 66 D6
  ,0x00 // 67 D6#
  ,0x00 // 68 E6
  ,0x00 // 69 F6
  ,0x00 // 70 F6#
  ,0x00 // 71 G6
  ,0x00 // 72 G6#
  ,0x00 // 73 A6
  ,0x00 // 74 A6#
  ,0x00 // 75 B6
  ,0x00 // 76 C7
  ,0x00 // 77 C7#
  ,0x00 // 78 D7
  ,0x00 // 79 D7#
  ,0x00 // 80 E7
  ,0x00 // 81 F7
  ,0x00 // 82 F7#
  ,0x00 // 83 G7
  ,0x00 // 84 G7#
  ,0x00 // 85 A7
  ,0x00 // 86 A7#
  ,0x00 // 87 B7
  ,0x00 // 88 C8
};

unsigned char notes_fine[89] = {
   0x00
  ,0xEC //1 A0
  ,0x07 //2 A0#
  ,0x2F //3 B0
  ,0x64 //4 C1
  ,0xA3 //5 C1#
  ,0xEE //6 D1
  ,0x42 //7 D1#
  ,0xA0 //8 E1
  ,0x08 //9 F1
  ,0x77 //10  F1#
  ,0xEF //11  G1
  ,0x6F //12  G1#
  ,0xF6 //13  A1
  ,0x83 //14  A1#
  ,0x17 //15  B1
  ,0xB2 //16  C2
  ,0x51 //17  C2#
  ,0xF7 //18  D2
  ,0xA1 //19  D2#
  ,0x50 //20  E2
  ,0x04 //21  F2
  ,0xBB //22  F2#
  ,0x77 //23  G2
  ,0x37 //24  G2#
  ,0xFB //25  A2
  ,0xC1 //26  A2#
  ,0x8B //27  B2
  ,0x59 //28  C3
  ,0x28 //29  C3#
  ,0xFB //30  D3
  ,0xD0 //31  D3#
  ,0xA8 //32  E3
  ,0x82 //33  F3
  ,0x5D //34  F3#
  ,0x3B //35  G3
  ,0x1B //36  G3#
  ,0xFD //37  A3
  ,0xE0 //38  A3#
  ,0xC5 //39  B3
  ,0xAC //40  C4
  ,0x94 //41  C4#
  ,0x7D //42  D4
  ,0x68 //43  D4#
  ,0x54 //44  E4
  ,0x41 //45  F4
  ,0x2E //46  F4#
  ,0x1D //47  G4
  ,0x0D //48  G4#
  ,0xFE //49  A4
  ,0xF0 //50  A4#
  ,0xE2 //51  B4
  ,0xD6 //52  C5
  ,0xCA //53  C5#
  ,0xBE //54  D5
  ,0xB4 //55  D5#
  ,0xAA //56  E5
  ,0xA0 //57  F5
  ,0x97 //58  F5#
  ,0x8E //59  G5
  ,0x86 //60  G5#
  ,0x7F //61  A5
  ,0x78 //62  A5#
  ,0x71 //63  B5
  ,0x6B //64  C6
  ,0x65 //65  C6#
  ,0x5F //66  D6
  ,0x5A //67  D6#
  ,0x55 //68  E6
  ,0x50 //69  F6
  ,0x4B //70  F6#
  ,0x47 //71  G6
  ,0x43 //72  G6#
  ,0x3F //73  A6
  ,0x3C //74  A6#
  ,0x38 //75  B6
  ,0x35 //76  C7
  ,0x32 //77  C7#
  ,0x2F //78  D7
  ,0x2D //79  D7#
  ,0x2A //80  E7
  ,0x28 //81  F7
  ,0x25 //82  F7#
  ,0x23 //83  G7
  ,0x21 //84  G7#
  ,0x1F //85  A7
  ,0x1E //86  A7#
  ,0x1C //87  B7
  ,0x1A //88  C8
};

#endif //_AYNOTES_H
