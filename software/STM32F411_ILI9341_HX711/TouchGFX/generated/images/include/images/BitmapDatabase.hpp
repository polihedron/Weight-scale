// Generated by imageconverter. Please, do not edit!

#ifndef TOUCHGFX_BITMAPDATABASE_HPP
#define TOUCHGFX_BITMAPDATABASE_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/Bitmap.hpp>

const uint16_t BITMAP_BACK_BLACK_ID = 0;
const uint16_t BITMAP_BACK_WHITE_ID = 1;
const uint16_t BITMAP_KEYBOARD_BACKGROUND_ID = 2;
const uint16_t BITMAP_KEYBOARD_KEY_DELETE_HIGHLIGHTED_ID = 3;
const uint16_t BITMAP_KEYBOARD_KEY_EXIT_ID = 4;
const uint16_t BITMAP_KEYBOARD_KEY_EXIT_HIGHLIGHTED_ID = 5;
const uint16_t BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID = 6;
const uint16_t BITMAP_KEYBOARD_KEY_OK_ID = 7;
const uint16_t BITMAP_KEYBOARD_KEY_OK_HIGHLIGHTED_ID = 8;
const uint16_t BITMAP_RESET_BLACK_ID = 9;
const uint16_t BITMAP_RESET_WHITE_ID = 10;
const uint16_t BITMAP_SAVE_BLACK60_ID = 11;
const uint16_t BITMAP_SAVE_WHITE60_ID = 12;
const uint16_t BITMAP_SETTINGS_BLACK_ID = 13;
const uint16_t BITMAP_SETTINGS_WHITE_ID = 14;

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance();
uint16_t getInstanceSize();
} // namespace BitmapDatabase

#endif // TOUCHGFX_BITMAPDATABASE_HPP
