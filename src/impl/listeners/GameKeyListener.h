//
// Created by Adrian Jutrowski on 01/12/2020.
//

#ifndef TETRIS_GAMEKEYLISTENER_H
#define TETRIS_GAMEKEYLISTENER_H
#include "../../interfaces/IKeyEventListener.h"
#include "../../interfaces/IGameController.h"
#include <memory>


class GameKeyListener: public IKeyEventListener {

    std::shared_ptr<IGameController> ctrl;

public:
    std::string getName() override { return " window";};

    explicit GameKeyListener(const std::shared_ptr<IGameController>& ctrl);
    void onKey(int key) override;
};


#endif //TETRIS_GAMEKEYLISTENER_H
