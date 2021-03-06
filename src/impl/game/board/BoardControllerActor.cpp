//
// Created by Adrian Jutrowski on 01/12/2020.
//

#include "BoardControllerActor.h"
#include "../../../interfaces/CommonActorAtoms.h";

caf::behavior BoardControllerActor::make_behavior() {

    initialized.assign(
            [this]( QuitAtom) {
                std::cout << "Actor received quit message" << std::endl;
                quit();
            }

    );

    return initialized;
}