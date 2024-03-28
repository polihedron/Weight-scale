#ifndef NUMERIC_KEYBOARD_LAYOUT
#define NUMERIC_KEYBOARD_LAYOUT

#include <touchgfx/widgets/Keyboard.hpp>
#include <touchgfx/hal/Types.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include "BitmapDatabase.hpp"

using namespace touchgfx;

static const int SPACE_Y_BETWEEN_KEYS_NUMERIC = 6;

static const int KEY_WIDTH_NUMERIC  = 26;
static const int KEY_HEIGHT_NUMERIC = 38;

static const int KEY_ROW_1_Y_NUMERIC = 57;
static const int KEY_ROW_2_Y_NUMERIC = KEY_ROW_1_Y_NUMERIC + SPACE_Y_BETWEEN_KEYS_NUMERIC + KEY_HEIGHT_NUMERIC;
static const int KEY_ROW_3_Y_NUMERIC = KEY_ROW_2_Y_NUMERIC + SPACE_Y_BETWEEN_KEYS_NUMERIC + KEY_HEIGHT_NUMERIC;
static const int KEY_ROW_4_Y_NUMERIC = KEY_ROW_3_Y_NUMERIC + SPACE_Y_BETWEEN_KEYS_NUMERIC + KEY_HEIGHT_NUMERIC;

static const int KEY_ROW_1_X_NUMERIC = 9;
static const int KEY_ROW_1_X_KEY_DISTANCE_NUMERIC = 27;

static const int KEY_ROW_2_X_NUMERIC = KEY_ROW_1_X_NUMERIC;
static const int KEY_ROW_2_X_KEY_DISTANCE_NUMERIC = KEY_ROW_1_X_KEY_DISTANCE_NUMERIC;

static const int KEY_ROW_3_X_NUMERIC = KEY_ROW_1_X_NUMERIC;
static const int KEY_ROW_3_X_KEY_DISTANCE_NUMERIC = KEY_ROW_1_X_KEY_DISTANCE_NUMERIC;

static const int BACKSPACE_X_NUMERIC = KEY_ROW_3_X_NUMERIC + KEY_ROW_1_X_KEY_DISTANCE_NUMERIC*2;


/**
 * Array specifying the keys used in the CustomKeyboard.
 */
static const Keyboard::Key keyArrayNumeric[10] =
{
    { 1, Rect(KEY_ROW_1_X_NUMERIC                                       ,                 	KEY_ROW_1_Y_NUMERIC,	KEY_WIDTH_NUMERIC, 			KEY_HEIGHT_NUMERIC), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 2, Rect(KEY_ROW_1_X_NUMERIC + KEY_ROW_1_X_KEY_DISTANCE_NUMERIC    ,      				KEY_ROW_1_Y_NUMERIC, 	KEY_WIDTH_NUMERIC, 			KEY_HEIGHT_NUMERIC), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 3, Rect(KEY_ROW_1_X_NUMERIC + KEY_ROW_1_X_KEY_DISTANCE_NUMERIC * 2,  					KEY_ROW_1_Y_NUMERIC, 	KEY_WIDTH_NUMERIC, 			KEY_HEIGHT_NUMERIC), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 4, Rect(KEY_ROW_1_X_NUMERIC + KEY_ROW_1_X_KEY_DISTANCE_NUMERIC * 3,					KEY_ROW_1_Y_NUMERIC,	KEY_WIDTH_NUMERIC, 			KEY_HEIGHT_NUMERIC), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 5, Rect(KEY_ROW_2_X_NUMERIC 									    ,	   				KEY_ROW_2_Y_NUMERIC, 	KEY_WIDTH_NUMERIC, 			KEY_HEIGHT_NUMERIC), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 6, Rect(KEY_ROW_2_X_NUMERIC + KEY_ROW_1_X_KEY_DISTANCE_NUMERIC    ,   				KEY_ROW_2_Y_NUMERIC,	KEY_WIDTH_NUMERIC, 			KEY_HEIGHT_NUMERIC), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 7, Rect(KEY_ROW_2_X_NUMERIC + KEY_ROW_1_X_KEY_DISTANCE_NUMERIC * 2,  					KEY_ROW_2_Y_NUMERIC,	KEY_WIDTH_NUMERIC, 			KEY_HEIGHT_NUMERIC), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 8, Rect(KEY_ROW_2_X_NUMERIC + KEY_ROW_1_X_KEY_DISTANCE_NUMERIC * 3, 					KEY_ROW_2_Y_NUMERIC,	KEY_WIDTH_NUMERIC, 			KEY_HEIGHT_NUMERIC), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    { 9, Rect(KEY_ROW_3_X_NUMERIC 										, 					KEY_ROW_3_Y_NUMERIC, 	KEY_WIDTH_NUMERIC,			KEY_HEIGHT_NUMERIC), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
    {10, Rect(KEY_ROW_3_X_NUMERIC + KEY_ROW_1_X_KEY_DISTANCE_NUMERIC    ,  					KEY_ROW_3_Y_NUMERIC, 	KEY_WIDTH_NUMERIC,			KEY_HEIGHT_NUMERIC), BITMAP_KEYBOARD_KEY_HIGHLIGHTED_ID},
};

/**
 * Callback areas for the special buttons on the CustomKeyboard.
 */
 static Keyboard::CallbackArea callbackAreasNumeric[1] =
{
    {Rect(BACKSPACE_X_NUMERIC,  KEY_ROW_3_Y_NUMERIC,KEY_WIDTH_NUMERIC*2 , KEY_HEIGHT_NUMERIC), 0, BITMAP_KEYBOARD_KEY_DELETE_HIGHLIGHTED_ID },   // backspace
		};

/**
 * The layout for the CustomKeyboard.
 */
static const Keyboard::Layout layoutNumeric =
{
    BITMAP_KEYBOARD_BACKGROUND_ID,
    keyArrayNumeric,
	10,
    callbackAreasNumeric,
    1,
    Rect(0, 14, 118, 50),
    TypedText(T_ENTEREDTEXT),
#if !defined(USE_BPP) || USE_BPP==16
    0xFFFFFF,
#elif USE_BPP==24
	0xFFFFFF,
#elif USE_BPP==4
    0xF,
#elif USE_BPP==2
    0xF,
#else
#error Unknown USE_BPP
#endif
    Typography::KEYBOARDNUMERIC,
#if !defined(USE_BPP) || USE_BPP==16
	0,
#elif USE_BPP==24
	0,
#endif
};

#endif