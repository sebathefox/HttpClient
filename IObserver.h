/**
 * The IObserver interface file.
 * @file IObserver.h
 * @author Sebastian Davaris
 * @date 22-09-2020
 */

#ifndef HTTPCLIENT_IOBSERVER_H
#define HTTPCLIENT_IOBSERVER_H

/**
 *
 */
class IObserver {
public:
    virtual void update(NumericKeyboardState state) = 0;
};


#endif //HTTPCLIENT_IOBSERVER_H
