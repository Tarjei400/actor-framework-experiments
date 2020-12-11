//
// Created by Adrian Jutrowski on 01/12/2020.
//

#ifndef TETRIS_PIECECONTROLLERACTOR_H
#define TETRIS_PIECECONTROLLERACTOR_H
#include <caf/all.hpp>

using namespace caf;

using MoveUpAtom = atom_constant<atom("MoveUp")>;
using MoveDownAtom = atom_constant<atom("MoveDown")>;
using MoveLeftAtom = atom_constant<atom("MoveLeft")>;
using MoveRightAtom = atom_constant<atom("MoveRight")>;
using RotateAtom = atom_constant<atom("Rotate")>;
using RequestPositionAtom = atom_constant<atom("RequestPos")>;
using ShufflePieceAtom = atom_constant<atom("Shuffle")>;
using RequestPieceAtom = atom_constant<atom("GetPiece")>;
using StopAtom = atom_constant<atom("StopAtom")>;
using StartAtom = atom_constant<atom("StartAtom")>;

class PieceControllerActor: public caf::event_based_actor {
    int x{0};
    int y{0};

    caf::behavior unitialized;
    caf::behavior initialized;

public:
    explicit PieceControllerActor(
            caf::actor_config& config
    ): event_based_actor(config) {};

    caf::behavior make_behavior() override;
};


#endif //TETRIS_PIECECONTROLLERACTOR_H
