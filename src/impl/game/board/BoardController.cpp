//
// Created by Adrian Jutrowski on 06/11/2020.
//

#include "BoardController.h"

BoardController::BoardController(
        caf::actor_system& system
) : ActorWrapper<BoardControllerActor>(system){

}

