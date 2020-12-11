//
// Created by Adrian Jutrowski on 24/11/2020.
//

#ifndef TETRIS_PIECECONSTROLLER_H
#define TETRIS_PIECECONSTROLLER_H
#include "../../../interfaces/IPieceController.h"
#include "../../../interfaces/IActorWrapper.h"
#include "PieceControllerActor.h"

using namespace caf;

class PieceController: public IPieceController, public  ActorWrapper<PieceControllerActor> {
public:
    explicit PieceController(
            caf::actor_system& system
    );

    void moveUp() override;
    void moveDown() override;
    void moveLeft() override;
    void moveRight() override;
    void rotate() override;
};


#endif //TETRIS_PIECECONSTROLLER_H
