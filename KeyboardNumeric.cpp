/**
 * Contains the class implementation for the numeric keyboard.
 * @file KeyboardNumeric.h
 * @author Sebastian Davaris
 * @date 21-09-2020
 */

#include "KeyboardNumeric.h"

#include <iostream>
#include <sstream>

// Display includes
#include "TS_DISCO_F746NG.h"
#include "LCD_DISCO_F746NG.h"

KeyboardNumeric::KeyboardNumeric(int x, int y, LCD_DISCO_F746NG* screen, TS_DISCO_F746NG* touch) :
    m_x(x),
    m_y(y),
    m_screen(screen),
    m_touch(touch)
{
    const int size = 48;
    int row = 0;
    int col = 0;

    for(int i = 0; i < 9; i++) {
        if(i % 3 == 0 && i != 0) {
            row++;
            col = 0;
        }

        m_buttons.push_back(Button(0 + (col * size), 0 + (row * size), size, size, m_touch, m_screen));
        m_buttons[i].setLabel(static_cast<ostringstream*>( &(ostringstream() << (i + 1)) )->str());

        col++;
    }

    m_buttons.push_back(Button(0 + (0 * size), 0 + (3 * size), size, size, m_touch, m_screen));
    m_buttons[9].setLabel("*");

    m_buttons.push_back(Button(0 + (1 * size), 0 + (3 * size), size, size, m_touch, m_screen));
    m_buttons[10].setLabel("0");

    m_buttons.push_back(Button(0 + (2 * size), 0 + (3 * size), size, size, m_touch, m_screen));
    m_buttons[11].setLabel("#");
}

void KeyboardNumeric::draw() {
    for (int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i].draw();

    }
}

int KeyboardNumeric::poll() const {

    TS_StateTypeDef state;

    m_touch->GetState(&state);

//    printf("YEET");

    if(!state.touchDetected) {

        return 0;
    }

    for (int i = 0; i < m_buttons.size(); i++) {
//        ITouchable& btn = static_cast<ITouchable>(m_buttons[i]);

        if(m_buttons[i].intersects(state.touchX[0], state.touchY[0])) {
            m_buttons[i].notify();
        }
    }

    return 0;
}

//Button& KeyboardNumeric::operator [] (int i) {
//    return &(m_buttons[i]);
//}

//NumericKeyboardState KeyboardNumeric::getPressedKey() const {
//    return
//}
//
//void KeyboardNumeric::update(NumericKeyboardState state) {
//    m_screen.DisplayStringAt(0, LINE(1), (uint8_t *)"YEET: " + state.button.getLabel(), CENTER_MODE);
//}

Button& KeyboardNumeric::getButton(int index) {
    return m_buttons[index];
}