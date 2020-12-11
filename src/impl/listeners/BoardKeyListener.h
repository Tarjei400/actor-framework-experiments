//
// Created by Adrian Jutrowski on 06/11/2020.
//

#ifndef TETRIS_BOARDKEYLISTENER_H
#define TETRIS_BOARDKEYLISTENER_H
#include "../../interfaces/IKeyEventListener.h"
#include "../../interfaces/IPieceController.h"


class BoardKeyListener : public IKeyEventListener {

    std::shared_ptr<IPieceController> ctrl{nullptr};

public:
     explicit BoardKeyListener(const std::shared_ptr<IPieceController>& ctrl): ctrl(ctrl) {}

     std::string getName() override { return " Board";};
     void onKey(int key) override;

};


#endif //TETRIS_BOARDKEYLISTENER_H
