/**
 * Contains the class definition for the numeric keyboard.
 * @file KeyboardNumeric.h
 * @author Sebastian Davaris
 * @date 21-09-2020
 */

#ifndef HTTPCLIENT_KEYBOARDNUMERIC_H
#define HTTPCLIENT_KEYBOARDNUMERIC_H

#include "Button.h"

#include <vector>

// Forward declarations.
class LCD_DISCO_F746NG;
class TS_DISCO_F746NG;

struct NumericKeyboardState {

};

/**
 * The numeric keyboard base class.
 * @brief Used for getting numbers from users.
 * @class KeyboardNumeric
 * @author Sebastian Davaris
 * @date 21-09-2020
 */
class KeyboardNumeric {
public:
    /**
     * Constructor
     * @param x The x-axis position.
     * @param y The y-axis position.
     * @param screen Pointer to the main screen device.
     * @param touch Pointer to the main touch device.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    KeyboardNumeric(int x, int y, LCD_DISCO_F746NG* screen, TS_DISCO_F746NG* touch);

    /**
     * Draws the contents to the screen.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    void draw();

    /**
     * Polls the current state from the numeric keyboard.
     * @param outState The state output.
     * @return Zero when successful otherwise positive.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    //int poll(NumericKeyboardState& outState) const;
private:

    int m_x;
    int m_y;

    LCD_DISCO_F746NG* m_screen;
    TS_DISCO_F746NG* m_touch;

    std::vector<Button> m_buttons;
};


#endif //HTTPCLIENT_KEYBOARDNUMERIC_H
