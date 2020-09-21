//
// Created by sebastian on 21/09/2020.
//

#include "KeyboardNumeric.h"

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

        m_buttons.push_back(Button(0 + (col * size), 0 + (row * size), size, size, &m_touch, &m_screen));
        m_buttons[i].setLabel(static_cast<ostringstream*>( &(ostringstream() << (i + 1)) )->str());

        col++;
    }

    m_buttons.push_back(Button(0 + (0 * size), 0 + (3 * size), size, size, &ts, &lcd));
    m_buttons[9].setLabel("*");

    m_buttons.push_back(Button(0 + (1 * size), 0 + (3 * size), size, size, &ts, &lcd));
    m_buttons[9].setLabel("0");

    m_buttons.push_back(Button(0 + (2 * size), 0 + (3 * size), size, size, &ts, &lcd));
    m_buttons[9].setLabel("#");
}

void KeyboardNumeric::draw() {
    for (Button button : m_buttons) {
        button.draw();
    }
}