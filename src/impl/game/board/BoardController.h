//
// Created by Adrian Jutrowski on 06/11/2020.
//

#ifndef SERVER_BOARDCONTROLLER2D_H
#define SERVER_BOARDCONTROLLER2D_H

#include "../../../interfaces/IBoardController.h"
#include "../../../interfaces/IActorWrapper.h"
#include "BoardControllerActor.h"

class BoardController : public IBoardController, public  ActorWrapper<BoardControllerActor> {
public:
    explicit BoardController(
            caf::actor_system& system
    );
};


#endif //SERVER_BOARDCONTROLLER2D_H
