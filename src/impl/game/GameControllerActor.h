//
// Created by Adrian Jutrowski on 01/12/2020.
//

#ifndef TETRIS_GAMECONTROLLERACTOR_H
#define TETRIS_GAMECONTROLLERACTOR_H

#include <caf/all.hpp>
#include "../../interfaces/IPieceController.h"
#include "../../interfaces/IBoardController.h"

using namespace caf;
using namespace std;


class GameControllerActor: public event_based_actor {
    caf::behavior unitialized;
    caf::behavior initialized;

public:
    GameControllerActor(
        actor_config& config,
        const shared_ptr<IBoardController>& boardCtrl,
        const shared_ptr<IPieceController>& pieceCtrl
    ): event_based_actor(config) {};

    caf::behavior make_behavior();

};


#endif //TETRIS_GAMECONTROLLERACTOR_H
