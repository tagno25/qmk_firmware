// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#if defined(RGB_MATRIX_ENABLE)
// TODO: Should have attribute __flash. But won't compile if I add it
const is31_led g_is31_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |    R location
 *   |    |          G location
 *   |    |          |          B location
 *   |    |          |          | */
    // Re-arranged order so it matches with the physical location array
    {0,   CS9_SW8,   CS8_SW8,   CS7_SW8}, // LED 0 (ESC {L})
    {0,   CS9_SW6,   CS8_SW6,   CS7_SW6}, // LED 1 (ESC {R})
    {0,   CS9_SW4,   CS8_SW4,   CS7_SW4}, // LED 2 (F1)
    {0,   CS9_SW2,   CS8_SW2,   CS7_SW2}, // LED 3 (F2)
    {0,   CS9_SW1,   CS8_SW1,   CS7_SW1}, // LED 4 (F3)
    {0,   CS9_SW3,   CS8_SW3,   CS7_SW3}, // LED 5 (F4)
    {0,   CS9_SW5,   CS8_SW5,   CS7_SW5}, // LED 6 (F5)
    {0,   CS9_SW7,   CS8_SW7,   CS7_SW7}, // LED 7 (F6)
    {0,   CS9_SW9,   CS8_SW9,   CS7_SW9}, // LED 8 (F7)
    {1, CS9_SW2, CS8_SW2, CS7_SW2}, // LED 9 (F8)
    {1, CS9_SW3, CS8_SW3, CS7_SW3}, // LED 10 (F9)
    {1, CS9_SW4, CS8_SW4, CS7_SW4}, // LED 11 (F10)
    {1, CS9_SW1, CS8_SW1, CS7_SW1}, // LED 12 (F11 {L})
    {1, CS9_SW7, CS8_SW7, CS7_SW7}, // LED 13 (F11 {R})
    {1, CS9_SW6, CS8_SW6, CS7_SW6}, // LED 14 (F12)
    {1, CS9_SW8, CS8_SW8, CS7_SW8}, // LED 15 (Del {L})
    {1, CS9_SW9, CS8_SW9, CS7_SW9}, // LED 16 (Del {R})

    {0,   CS6_SW8,   CS5_SW8,   CS4_SW8}, // LED 17 (tilde)
    {0,   CS6_SW6,   CS5_SW6,   CS4_SW6}, // LED 18 (1)
    {0,   CS6_SW4,   CS5_SW4,   CS4_SW4}, // LED 19 (2)
    {0,   CS6_SW2,   CS5_SW2,   CS4_SW2}, // LED 20 (3)
    {0,   CS6_SW1,   CS5_SW1,   CS4_SW1}, // LED 21 (4)
    {0,   CS6_SW3,   CS5_SW3,   CS4_SW3}, // LED 22 (5)
    {0,   CS6_SW5,   CS5_SW5,   CS4_SW5}, // LED 23 (6)
    {0,   CS6_SW7,   CS5_SW7,   CS4_SW7}, // LED 24 (7)
    {0,   CS6_SW9,   CS5_SW9,   CS4_SW9}, // LED 25 (8)
    {1, CS9_SW5, CS8_SW5, CS7_SW5}, // LED 26 (9)
    {1, CS6_SW5, CS5_SW5, CS4_SW5}, // LED 27 (0)
    {1, CS6_SW7, CS5_SW7, CS4_SW7}, // LED 28 (Minus)
    {1, CS6_SW6, CS5_SW6, CS4_SW6}, // LED 29 (Equal)
    {1, CS6_SW8, CS5_SW8, CS4_SW8}, // LED 30 (BKSP {L})
    {1, CS6_SW9, CS5_SW9, CS4_SW9}, // LED 31 (BKSP {R})

    {0,   CS3_SW8,   CS2_SW8,   CS1_SW8}, // LED 32 (Tab {L})
    {0,   CS3_SW6,   CS2_SW6,   CS1_SW6}, // LED 33 (Tab {R})
    {0,   CS3_SW4,   CS2_SW4,   CS1_SW4}, // LED 34 (Q)
    {0,   CS3_SW2,   CS2_SW2,   CS1_SW2}, // LED 35 (W)
    {0,   CS3_SW1,   CS2_SW1,   CS1_SW1}, // LED 36 (E)
    {0,   CS3_SW3,   CS2_SW3,   CS1_SW3}, // LED 37 (R)
    {0,   CS3_SW5,   CS2_SW5,   CS1_SW5}, // LED 38 (T)
    {0,   CS3_SW7,   CS2_SW7,   CS1_SW7}, // LED 39 (Y)
    {0,   CS3_SW9,   CS2_SW9,   CS1_SW9}, // LED 40 (U)
    {1, CS6_SW2, CS5_SW2, CS4_SW2}, // LED 41 (I)
    {1, CS6_SW3, CS5_SW3, CS4_SW3}, // LED 42 (O)
    {1, CS6_SW4, CS5_SW4, CS4_SW4}, // LED 43 (P)
    {1, CS6_SW1, CS5_SW1, CS4_SW1}, // LED 44 (L_Bracket)
    {1, CS3_SW7, CS2_SW7, CS1_SW7}, // LED 45 (R_Bracket)
    {1, CS3_SW8, CS2_SW8, CS1_SW8}, // LED 46 (Backslash)

    {0,  CS15_SW8,  CS14_SW8,  CS13_SW8}, // LED 47 (Caps {L})
    {0,  CS15_SW6,  CS14_SW6,  CS13_SW6}, // LED 48 (Caps {C})
    {0,  CS15_SW4,  CS14_SW4,  CS13_SW4}, // LED 49 (Caps {R})
    {0,  CS15_SW2,  CS14_SW2,  CS13_SW2}, // LED 50 (A)
    {0,  CS15_SW1,  CS14_SW1,  CS13_SW1}, // LED 51 (S)
    {0,  CS15_SW3,  CS14_SW3,  CS13_SW3}, // LED 52 (D)
    {0,  CS15_SW5,  CS14_SW5,  CS13_SW5}, // LED 53 (F)
    {0,  CS15_SW7,  CS14_SW7,  CS13_SW7}, // LED 54 (G)
    {0,  CS15_SW9,  CS14_SW9,  CS13_SW9}, // LED 55 (H)
    {1, CS3_SW2, CS2_SW2, CS1_SW2}, // LED 56 (J)
    {1, CS3_SW3, CS2_SW3, CS1_SW3}, // LED 57 (K)
    {1, CS3_SW4, CS2_SW4, CS1_SW4}, // LED 58 (L)
    {1, CS3_SW1, CS2_SW1, CS1_SW1}, // LED 59 (Semicolon)
    {1, CS3_SW5, CS2_SW5, CS1_SW5}, // LED 60 (Apostrophe)
    {1, CS3_SW6, CS2_SW6, CS1_SW6}, // LED 61 (Return {L})
    {1, CS3_SW9, CS2_SW9, CS1_SW9}, // LED 62 (Return {R})

    {0,  CS12_SW6,  CS11_SW6,  CS10_SW6}, // LED 63 (L_Shift {L})
    {0,  CS12_SW4,  CS11_SW4,  CS10_SW4}, // LED 64 (L_Shift {C})
    {0,  CS12_SW2,  CS11_SW2,  CS10_SW2}, // LED 65 (L_Shift {R})
    {0,  CS12_SW1,  CS11_SW1,  CS10_SW1}, // LED 66 (Z)
    {0,  CS12_SW3,  CS11_SW3,  CS10_SW3}, // LED 67 (X)
    {0,  CS12_SW5,  CS11_SW5,  CS10_SW5}, // LED 68 (C)
    {0,  CS12_SW7,  CS11_SW7,  CS10_SW7}, // LED 69 (V)
    {0,  CS12_SW9,  CS11_SW9,  CS10_SW9}, // LED 70 (B)
    {1, CS12_SW2, CS11_SW2, CS10_SW2}, // LED 71 (N)
    {1, CS12_SW3, CS11_SW3, CS10_SW3}, // LED 72 (M)
    {1, CS12_SW4, CS11_SW4, CS10_SW4}, // LED 73 (Comma)
    {1, CS12_SW1, CS11_SW1, CS10_SW1}, // LED 74 (Period)
    {1, CS12_SW5, CS11_SW5, CS10_SW5}, // LED 75 (Slash)
    {1, CS12_SW6, CS11_SW6, CS10_SW6}, // LED 76 (R_Shift {L})
    {1, CS12_SW8, CS11_SW8, CS10_SW8}, // LED 77 (R_Shift {CL})
    {1, CS12_SW9, CS11_SW9, CS10_SW9}, // LED 78 (R_Shift {CR})
    {1, CS15_SW9, CS14_SW9, CS13_SW9}, // LED 79 (R_Shift {R})

    {1, CS12_SW7, CS11_SW7, CS10_SW7}, // LED 80 (Up_Arrow)

    {0,  CS12_SW8,  CS11_SW8,  CS10_SW8}, // LED 81 (L_Ctrl {L})
    {0,  CS18_SW1,  CS17_SW1,  CS16_SW1}, // LED 82 (L_Ctrl {R})
    {1, CS18_SW1, CS17_SW1, CS16_SW1}, // LED 83 (Fn)
    {0,  CS18_SW2,  CS17_SW2,  CS16_SW2}, // LED 84 (Super)
    {0,  CS18_SW3,  CS17_SW3,  CS16_SW3}, // LED 85 (L_Alt)
    {1, CS18_SW2, CS17_SW2, CS16_SW2}, // LED 86 (Space {LL})
    {1, CS18_SW3, CS17_SW3, CS16_SW3}, // LED 87 (Space {LC})
    {1, CS18_SW4, CS17_SW4, CS16_SW4}, // LED 88 (Space {LR})
    {1, CS15_SW2, CS14_SW2, CS13_SW2}, // LED 89 (Space {RL})
    {1, CS15_SW3, CS14_SW3, CS13_SW3}, // LED 90 (Space {RC})
    {1, CS15_SW4, CS14_SW4, CS13_SW4}, // LED 91 (Space {RR})
    {1, CS15_SW1, CS14_SW1, CS13_SW1}, // LED 92 (R_Alt)
    {1, CS15_SW5, CS14_SW5, CS13_SW5}, // LED 93 (R_Ctrl)
    {1, CS15_SW6, CS14_SW6, CS13_SW6}, // LED 94 (Left_Arrow)
    {1, CS15_SW7, CS14_SW7, CS13_SW7}, // LED 95 (Down_Arrow)
    {1, CS15_SW8, CS14_SW8, CS13_SW8}, // LED 96 (Right_Arrow)
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {    68,     16,     34,     92, NO_LED,     67,     69,     72,     74,     79,     73, NO_LED,     93,     75,     60, NO_LED, },
  {NO_LED, NO_LED, NO_LED,     85,     86,     66,     70,     71,     95,     63, NO_LED, NO_LED,     81,     80,     62,      9, },
  {NO_LED, NO_LED,     83, NO_LED,     36,      3,     54,     55,     46, NO_LED,      8, NO_LED, NO_LED,     28, NO_LED,     96, },
  {NO_LED,     84,     32, NO_LED,      5,      2,     38,     39,     42, NO_LED,      7,     10, NO_LED,     14, NO_LED, NO_LED, },
  {NO_LED, NO_LED,     17, NO_LED,     47,     51,     22,     23,     11, NO_LED,      6, NO_LED, NO_LED,     27,     29, NO_LED, },
  {NO_LED, NO_LED,     18, NO_LED,     20,     19,     21,     24,     26, NO_LED,     25, NO_LED, NO_LED,     43,     31, NO_LED, },
  {NO_LED, NO_LED, NO_LED, NO_LED,      4,     35,     37,     40,     12, NO_LED,     41,     94, NO_LED,     44,     45, NO_LED, },
  {NO_LED, NO_LED,     50, NO_LED, NO_LED,      0,     53,     56,     58, NO_LED,     57, NO_LED, NO_LED,     59,     52, NO_LED, },
}, {
  // LED Index to Physical Position
  {   0,   0 }, // LED 0 (ESC {L})
  {  16,   0 }, // LED 1 (ESC {R})
  {  32,   0 }, // LED 2 (F1)
  {  48,   0 }, // LED 3 (F2)
  {  64,   0 }, // LED 4 (F3)
  {  80,   0 }, // LED 5 (F4)
  {  96,   0 }, // LED 6 (F5)
  { 112,   0 }, // LED 7 (F6)
  { 128,   0 }, // LED 8 (F7)
  { 144,   0 }, // LED 9 (F8)
  { 160,   0 }, // LED 10 (F9)
  { 176,   0 }, // LED 11 (F10)
  { 192,   0 }, // LED 12 (F11 {L})
  { 208,   0 }, // LED 13 (F11 {R})
  { 224,   0 }, // LED 14 (F12)
  { 240,   0 }, // LED 15 (Del {L})
  { 250,   0 }, // LED 16 (Del {R})

  {   2,  10 }, // LED 17 (tilde)
  {  18,  10 }, // LED 18 (1)
  {  34,  10 }, // LED 19 (2)
  {  49,  10 }, // LED 20 (3)
  {  66,  10 }, // LED 21 (4)
  {  82,  10 }, // LED 22 (5)
  {  98,  10 }, // LED 23 (6)
  { 114,  10 }, // LED 24 (7)
  { 130,  10 }, // LED 25 (8)
  { 146,  10 }, // LED 26 (9)
  { 162,  10 }, // LED 27 (0)
  { 178,  10 }, // LED 28 (Minus)
  { 194,  10 }, // LED 29 (Equal)
  { 209,  10 }, // LED 30 (BKSP {L})
  { 222,  10 }, // LED 31 (BKSP {R})

  {   0,  22 }, // LED 32 (Tab {L})
  {  16,  22 }, // LED 33 (Tab {R})
  {  32,  22 }, // LED 34 (Q)
  {  48,  22 }, // LED 35 (W)
  {  64,  22 }, // LED 36 (E)
  {  80,  22 }, // LED 37 (R)
  {  96,  22 }, // LED 38 (T)
  { 112,  22 }, // LED 39 (Y)
  { 128,  22 }, // LED 40 (U)
  { 144,  22 }, // LED 41 (I)
  { 160,  22 }, // LED 42 (O)
  { 176,  22 }, // LED 43 (P)
  { 192,  22 }, // LED 44 (L_Bracket)
  { 208,  22 }, // LED 45 (R_Bracket)
  { 224,  22 }, // LED 46 (Backslash)

  {   0,  34 }, // LED 47 (Caps {L})
  {  16,  34 }, // LED 48 (Caps {C})
  {  32,  34 }, // LED 49 (Caps {R})
  {  48,  34 }, // LED 50 (A)
  {  64,  34 }, // LED 51 (S)
  {  80,  34 }, // LED 52 (D)
  {  96,  34 }, // LED 53 (F)
  { 112,  34 }, // LED 54 (G)
  { 128,  34 }, // LED 55 (H)
  { 144,  34 }, // LED 56 (J)
  { 160,  34 }, // LED 57 (K)
  { 176,  34 }, // LED 58 (L)
  { 192,  34 }, // LED 59 (Semicolon)
  { 208,  34 }, // LED 60 (Apostrophe)
  { 224,  34 }, // LED 61 (Return {L})
  { 240,  34 }, // LED 62 (Return {R})

  {   0,  47 }, // LED 63 (L_Shift {L})
  {  16,  47 }, // LED 64 (L_Shift {C})
  {  32,  47 }, // LED 65 (L_Shift {R})
  {  48,  47 }, // LED 66 (Z)
  {  64,  47 }, // LED 67 (X)
  {  80,  47 }, // LED 68 (C)
  {  96,  47 }, // LED 69 (V)
  { 112,  47 }, // LED 70 (B)
  { 128,  47 }, // LED 71 (N)
  { 144,  47 }, // LED 72 (M)
  { 160,  47 }, // LED 73 (Comma)
  { 176,  47 }, // LED 74 (Period)
  { 192,  47 }, // LED 75 (Slash)
  { 208,  47 }, // LED 76 (R_Shift {L})
  { 224,  47 }, // LED 77 (R_Shift {CL})
  { 240,  47 }, // LED 78 (R_Shift {CR})
  { 250,  47 }, // LED 79 (R_Shift {R})

  { 224,  58 }, // LED 80 (Up_Arrow)

  {   0,  64 }, // LED 81 (L_Ctrl {L})
  {  16,  64 }, // LED 82 (L_Ctrl {R})
  {  32,  64 }, // LED 83 (Fn)
  {  48,  64 }, // LED 84 (Super)
  {  64,  64 }, // LED 85 (L_Alt)
  {  80,  64 }, // LED 86 (Space {LL})
  {  96,  64 }, // LED 87 (Space {LC})
  { 112,  64 }, // LED 88 (Space {LR})
  { 128,  64 }, // LED 89 (Space {RL})
  { 144,  64 }, // LED 90 (Space {RC})
  { 160,  64 }, // LED 91 (Space {RR})
  { 176,  64 }, // LED 92 (R_Alt)
  { 192,  64 }, // LED 93 (R_Ctrl)
  { 208,  64 }, // LED 94 (Left_Arrow)
  { 224,  64 }, // LED 95 (Down_Arrow)
  { 240,  64 }, // LED 96 (Right_Arrow)
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4
} };
#endif
