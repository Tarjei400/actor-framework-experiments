//
// Created by Adrian Jutrowski on 01/12/2020.
//

#ifndef TETRIS_BOARDCONTROLLERACTOR_H
#define TETRIS_BOARDCONTROLLERACTOR_H
#include <caf/all.hpp>

using namespace caf;


class BoardControllerActor: public event_based_actor {
    caf::behavior unitialized;
    caf::behavior initialized;
public:
    explicit BoardControllerActor(
            caf::actor_config& config
    ): event_based_actor(config) {};
    caf::behavior make_behavior();

};


#endif //TETRIS_BOARDCONTROLLERACTOR_H
