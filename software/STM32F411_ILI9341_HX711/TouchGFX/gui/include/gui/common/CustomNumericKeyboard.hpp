#ifndef NUMERIC_TGFXKEYBOARD_HPP_
#define NUMERIC_TGFXKEYBOARD_HPP_

#include <touchgfx/widgets/Keyboard.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <gui/common/NumericKeyboardLayout.hpp>
#include <fonts/ApplicationFontProvider.hpp>
#include <gui/common/NumericKeyboardKeyMapping.hpp>

using namespace touchgfx;

/**
 * An alphanumeric keyboard with backspace, space-bar and delete functionality.
 * Keyboard mappings for the keyboard are defined in gui/include/gui/common/KeyboardKeyMapping.hpp.
 * Keyboard layout for the keyboard is defined in gui/include/gui/common/KeyboardLayout.hpp.
 * Please note that the ApplicationFontProvider is initialized and set with the FontManager in main.cpp
 * The fonts and the characters used by the keyboard have to be defined in the assets/texts/texts.xlsx file.
 */
class CustomNumericKeyboard : public Container
{
public:
    CustomNumericKeyboard();
    virtual ~CustomNumericKeyboard() { }

    /*
     * Override setTouchable to also affect the keyboard object inside this
     * CustomKeyboard.
     */
    void setTouchable(bool touch);

    Unicode::UnicodeChar *getBuffer ();

    void clearBuffer();

    void setOKCallback(GenericCallback<void,void,void> * callback);

    void setEXITCallback(GenericCallback<void,void,void> * callback);

    /**
     * The keyboard which this CustomKeyboard wraps.
     */
    Keyboard keyboard;


private:

    /*
     * The size of the buffer that is used by the keyboard.
     * The size determines how much text the keyboard can contain in its textfield.
     */
    static const uint8_t BUFFER_SIZE = 8;

    /**
     * The buffer used by the keyboard for text input.
     */
    Unicode::UnicodeChar buffer[BUFFER_SIZE];

    /**
     * Callback for the backspace button.
     */
     Callback<CustomNumericKeyboard> backspacePressed;

     Callback<CustomNumericKeyboard> okPressed;

     Callback<CustomNumericKeyboard> exitPressed;

    /**
     * Callback for when keys are pressed on the keyboard.
     */
    Callback<CustomNumericKeyboard, Unicode::UnicodeChar> keyPressed;

    /*
     * Sets the correct key mappings of the keyboard according to alpha/numeric and upper-case/lower-case.
     */
    void setKeyMappingList();

    /**
     * Callback handler for the backspace button.
     */
    void backspacePressedHandler();

    void okPressedHandler();

    void exitPressedHandler();

    /**
     * Callback handler for key presses.
     * @param keyChar The UnicodeChar for the key that was pressed.
     */
    void keyPressedhandler(Unicode::UnicodeChar keyChar);



};

#endif /* TGFXKEYBOARD_HPP_ */
