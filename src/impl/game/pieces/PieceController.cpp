//
// Created by Adrian Jutrowski on 24/11/2020.
//

#include "PieceController.h"

using namespace caf;

PieceController::PieceController(
        caf::actor_system& system
) : ActorWrapper<PieceControllerActor>(system){

}


void PieceController::moveRight() {
    auto self = scoped_actor{system};
    self->send(actor, MoveRightAtom ::value);
}

void PieceController::moveUp() {
    auto self = scoped_actor{system};
    self->send(actor, MoveLeftAtom::value);
}

void PieceController::moveDown() {
    auto self = scoped_actor{system};
    self->send(actor, MoveDownAtom::value);
}

void PieceController::moveLeft() {
    auto self = scoped_actor{system};
    self->send(actor, MoveLeftAtom::value);
}

void PieceController::rotate() {
    auto self = scoped_actor{system};
    self->send(actor, RotateAtom::value);
}


