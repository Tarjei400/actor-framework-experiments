//
// Created by Adrian Jutrowski on 06/11/2020.
//

#ifndef TETRIS_IBOARDKEYLISTENER_H
#define TETRIS_IBOARDKEYLISTENER_H
#include <string>

class IKeyEventListener {
public:
    virtual std::string getName() = 0;
    virtual void onKey(int key) = 0;

};
#endif //TETRIS_IBOARDKEYLISTENER_H
