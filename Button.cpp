#include "Button.h"



// Display includes
#include "TS_DISCO_F746NG.h"
#include "LCD_DISCO_F746NG.h"

Button::Button(int x, int y, int w, int h, TS_DISCO_F746NG* touch, LCD_DISCO_F746NG* screen) :
    m_x(x), m_y(y), m_w(w), m_h(h),
    m_touch(touch),
    m_screen(screen)
{
    
}

void Button::setLabel(std::string label) {
    m_label = label;
}

void Button::setTextColor(uint32_t color) {
    m_screen->SetTextColor(color);
}

void Button::setBoxColor(uint32_t color) {
    m_screen->SetBackColor(color);
}

void Button::draw() {
    m_screen->DrawRect(m_x, m_y, m_w, m_h);
    
    m_screen->DisplayStringAt(m_x + (m_w / 2) - (CHAR_WIDTH * strlen(m_label.c_str()) / 2 - 1), m_y + (m_h / 2) - (CHAR_HEIGHT / 2 - 1), (uint8_t*) m_label.c_str(), LEFT_MODE);
}

bool Button::intersects(int x, int y) {
    return  x >= m_x &&
            x <= m_x + m_w &&
            y >= m_y &&
            y <= m_y + m_h;
}

void Button::onTouch(int x, int y) {

}