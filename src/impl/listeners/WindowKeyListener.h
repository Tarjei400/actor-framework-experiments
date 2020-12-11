//
// Created by Adrian Jutrowski on 06/11/2020.
//

#ifndef TETRIS_WINDOWKEYLISTENER_H
#define TETRIS_WINDOWKEYLISTENER_H
#include "../../interfaces/IKeyEventListener.h"


class WindowKeyListener : public IKeyEventListener {
public:
    std::string getName() override { return " window";};
    void onKey(int key) override { return ;};

};


#endif //TETRIS_WINDOWKEYLISTENER_H
