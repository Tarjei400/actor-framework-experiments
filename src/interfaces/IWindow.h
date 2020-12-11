//
// Created by Adrian Jutrowski on 06/11/2020.
//

#ifndef SERVER_IWINDOW_H
#define SERVER_IWINDOW_H
#include <string>

class IWindow {
public:
    virtual std::string getWindowName() = 0;
    virtual void init() = 0;
    virtual void* getWindowHook() = 0;
    virtual void getSize(int& w, int& h) = 0;

};

#endif //SERVER_IWINDOW_H
