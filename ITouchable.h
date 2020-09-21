/**
 * Interface file.
 * @file ITouchable.h
 * @author Sebastian Davaris
 * @date 21-09-2020
 */

#ifndef HTTPCLIENT_ITOUCHABLE_H
#define HTTPCLIENT_ITOUCHABLE_H

/**
 * Itouchable event interface.
 * @class ITouchable
 * @author Sebastian Davaris
 * @date 21-09-2020
 */
class ITouchable {
public:
    /**
     * Called when a touch event is detected.
     * @param x The x position of the click.
     * @param y The y position of the click.
     * @author Sebastian Davaris
     * @date 21-09-2020
     */
    void onTouch(int x, int y) = 0;
};


#endif //HTTPCLIENT_ITOUCHABLE_H
