//
// Created by Adrian Jutrowski on 01/12/2020.
//

#include "PieceControllerActor.h"
#include "../../../interfaces/CommonActorAtoms.h"
caf::behavior PieceControllerActor::make_behavior() {

    initialized.assign(
        [this](MoveUpAtom) {
            y--;
            std::cout << "/\\ " << std::endl;

        },
        [this](MoveDownAtom) {
            y++;
            std::cout << "\\/ " << std::endl;

        },
        [this](MoveLeftAtom) {
            x--;
            std::cout << "<<" << std::endl;

        },
        [this](MoveRightAtom) {
            x++;
            std::cout << ">>" << std::endl;

        },
        [this](RotateAtom) {
            std::cout << "Not implemented rotation" << std::endl;
        },
        [this](RequestPositionAtom) {
            std::cout << "Not implemented rotation" << std::endl;
            return x;
        },
        [this]( QuitAtom) {
            std::cout << "Actor received quit message" << std::endl;
            quit();
        }

    );

    return initialized;
}