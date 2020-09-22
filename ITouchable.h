/**
 * Interface file.
 * @file ITouchable.h
 * @author Sebastian Davaris
 * @date 21-09-2020
 */

#ifndef HTTPCLIENT_ITOUCHABLE_H
#define HTTPCLIENT_ITOUCHABLE_H

#include <list>

class IObserver;

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
    virtual void onTouch(int x, int y) = 0;

    virtual bool pressed() const = 0;

    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual void notify() = 0;

protected:
    bool m_pressed;

    std::list<IObserver*> m_observers;
};


#endif //HTTPCLIENT_ITOUCHABLE_H
