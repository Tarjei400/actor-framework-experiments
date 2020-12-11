//
// Created by Adrian Jutrowski on 24/11/2020.
//

#ifndef TETRIS_BOARDMOUSEEVENT_H
#define TETRIS_BOARDMOUSEEVENT_H
#include "../../interfaces/IMouseEventListener.h"


class BoardMouseEvent: public IMouseEventListener {
    std::string getName() override { return " Board mouse event";};
    void onKey(int key) override { return ;};
};


#endif //TETRIS_BOARDMOUSEEVENT_H
