#include <gui/common/CustomNumericKeyboard.hpp>
#include <string.h>
#include "touchgfx/Color.hpp"

static const int KEYBOARD_WIDTH_NUMERIC = 124;
static const int KEYBOARD_HEIGTH_NUMERIC = 192;
static const int KEYBOARD_X_POSITION_NUMERIC = 0 * 12;
static const int KEYBOARD_Y_POSITION_NUMERIC = 0 * 315;

CustomNumericKeyboard::CustomNumericKeyboard() : keyboard(),
    backspacePressed(this, &CustomNumericKeyboard::backspacePressedHandler),
    keyPressed(this, &CustomNumericKeyboard::keyPressedhandler)
{
    //Set the callbacks for the callback areas of the keyboard and set its layout.
	layoutNumeric.callbackAreaArray[0].callback = &backspacePressed;

    keyboard.setLayout(&layoutNumeric);
    keyboard.setKeyListener(keyPressed);
    keyboard.setPosition(KEYBOARD_X_POSITION_NUMERIC, KEYBOARD_Y_POSITION_NUMERIC, KEYBOARD_WIDTH_NUMERIC, KEYBOARD_HEIGTH_NUMERIC);

    keyboard.setTextIndentation();
    memset(buffer, 0, sizeof(buffer));
    keyboard.setBuffer(buffer, BUFFER_SIZE);

    setKeyMappingList();

    add(keyboard);
}

void CustomNumericKeyboard::setKeyMappingList()
{ 
    keyboard.setKeymappingList(&keyMappingListNumeric); // R
    invalidate();
}

void CustomNumericKeyboard::backspacePressedHandler()
{
    uint16_t pos = keyboard.getBufferPosition();
    if (pos > 0)
    {
        //Delete the previous entry in the buffer and decrement the position.
        // buffer[pos - 1] = 0;
        keyboard.getBuffer()[pos - 1] = 0;
        keyboard.setBufferPosition(pos - 1);
    }
    invalidate();
}


void CustomNumericKeyboard::keyPressedhandler(Unicode::UnicodeChar keyChar)
{
	setKeyMappingList(); // R
    invalidate();
}

void CustomNumericKeyboard::setTouchable(bool touch)
{
    Container::setTouchable(touch);
    keyboard.setTouchable(touch);
}

void CustomNumericKeyboard::clearBuffer()
{
    memset(buffer, 0, sizeof(buffer));
    keyboard.setBuffer(buffer, BUFFER_SIZE);

    setKeyMappingList();
}

Unicode:: UnicodeChar* CustomNumericKeyboard::getBuffer ()
{
	return keyboard.getBuffer();
}
