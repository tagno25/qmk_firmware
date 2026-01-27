// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#if defined(RGB_MATRIX_ENABLE)
const is31_led g_is31_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |   R location
 *   |   |         G location
 *   |   |         |         B location
 *   |   |         |         | */
    // Re-arranged in LED ID order so it matches with the physical location array
    {0,  CS6_SW3,  CS5_SW3,  CS4_SW3}, // LED 0  (A)
    {0,  CS3_SW3,  CS2_SW3,  CS1_SW3}, // LED 1  (B)
    {0, CS18_SW3, CS17_SW3, CS16_SW3}, // LED 2  (C)
    {0, CS15_SW3, CS14_SW3, CS13_SW3}, // LED 3  (D)

    {0,  CS6_SW1,  CS5_SW1,  CS4_SW1}, // LED 4  (E)
    {0,  CS3_SW1,  CS2_SW1,  CS1_SW1}, // LED 5  (F)
    {0, CS18_SW1, CS17_SW1, CS16_SW1}, // LED 6  (G)
    {0, CS15_SW1, CS14_SW1, CS13_SW1}, // LED 7  (H)

    {0,  CS6_SW2,  CS5_SW2,  CS4_SW2}, // LED 8  (I)
    {0,  CS3_SW2,  CS2_SW2,  CS1_SW2}, // LED 9  (J)
    {0, CS18_SW2, CS17_SW2, CS16_SW2}, // LED 10 (K)
    {0, CS15_SW2, CS14_SW2, CS13_SW2}, // LED 11 (L)

    {0,  CS6_SW4,  CS5_SW4,  CS4_SW4}, // LED 12 (M)
    {0,  CS3_SW4,  CS2_SW4,  CS1_SW4}, // LED 13 (N)
    {0, CS18_SW4, CS17_SW4, CS16_SW4}, // LED 14 (O)
    {0, CS15_SW4, CS14_SW4, CS13_SW4}, // LED 15 (P)

    {0,  CS9_SW2,  CS8_SW2,  CS7_SW2}, // LED 16 (Q)
    {0,  CS9_SW4,  CS8_SW4,  CS7_SW4}, // LED 17 (R)
    {0, CS12_SW4, CS11_SW4, CS10_SW4}, // LED 18 (S)
    {0, CS12_SW2, CS11_SW2, CS10_SW2}, // LED 19 (T)

    {0,  CS9_SW1,  CS8_SW1,  CS7_SW1}, // LED 20 (U)
    {0,  CS9_SW3,  CS8_SW3,  CS7_SW3}, // LED 21 (V)
    {0, CS12_SW3, CS11_SW3, CS10_SW3}, // LED 22 (W)
    {0, CS12_SW1, CS11_SW1, CS10_SW1}, // LED 23 (X)
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {     4,      8,     12,     16,      5,      9,      13,      17, },
  {    20,      6,     10,     14,     18,     22,       7,      15, },
  {    23,      0,      1, NO_LED,      3,     11,      19,      21, },
  {NO_LED, NO_LED, NO_LED, NO_LED,      2, NO_LED,  NO_LED,  NO_LED, },
}, {
  // LED Index to Physical Position
  {   0,   0 }, // LED 0  (A)
  {  73,   0 }, // LED 1  (B)
  { 150,   0 }, // LED 2  (C)
  { 223,   0 }, // LED 3  (D)
  {   0,  10 }, // LED 4  (E)
  {  73,  10 }, // LED 5  (F)
  { 150,  10 }, // LED 6  (G)
  { 223,  10 }, // LED 7  (H)
  {   0,  24 }, // LED 8  (I)
  {  73,  24 }, // LED 9  (J)
  { 150,  24 }, // LED 10 (K)
  { 223,  24 }, // LED 11 (L)
  {   0,  37 }, // LED 12 (M)
  {  73,  37 }, // LED 13 (N)
  { 150,  37 }, // LED 14 (O)
  { 223,  37 }, // LED 15 (P)
  {   0,  50 }, // LED 16 (Q)
  {  73,  50 }, // LED 17 (R)
  { 150,  50 }, // LED 18 (S)
  { 223,  50 }, // LED 19 (T)
  {   0,  64 }, // LED 20 (U)
  {  73,  64 }, // LED 21 (V)
  { 150,  64 }, // LED 22 (W)
  { 223,  64 }, // LED 23 (X)
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4
} };
#endif

