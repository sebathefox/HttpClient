/**
 * The base Button file.
 * @file Button.h
 * @author Sebastian Davaris
 * @date 21-09-2020
 */

// Includes.
#include <stdint.h>
#include <string>

#include "ITouchable.h"

// Forward declarations.
class LCD_DISCO_F746NG;
class TS_DISCO_F746NG;

/**
 * The Button Interface.
 * @author Sebastian Davaris
 * @date 21-09-2020
 */
class Button : public ITouchable {
public:
    const int CHAR_HEIGHT = 16;
    const int CHAR_WIDTH = 8;

    /**
     * Constructor
     * @param x The x-axis start position.
     * @param y The y-axis start position.
     * @param w The width of the button.
     * @param h The height of the button.
     * @param touch Pointer to the primary touch device.
     * @param screen Pointer to the primary screen interface.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    Button(int x, int y, int w, int h, TS_DISCO_F746NG* touch, LCD_DISCO_F746NG* screen);

    /**
     * Puts a label on the button.
     * @param label The string to display.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    void setLabel(std::string label);

    /**
     * Sets the text color.
     * @param color The color.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    void setTextColor(uint32_t color);

    /**
     * Sets the box color.
     * @param color The color.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    void setBoxColor(uint32_t color);

    /**
     * Draws the button onto the screen.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    void draw();

    /**
     * Validates if the passed coordinates lies within the button.
     * @param x The x coordinate.
     * @param y The y coordinate.
     * @return True if it intersects, otherwise false.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    bool intersects(int x, int y);
private:
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    
    std::string m_label;

    TS_DISCO_F746NG* m_touch;

    LCD_DISCO_F746NG* m_screen;
};