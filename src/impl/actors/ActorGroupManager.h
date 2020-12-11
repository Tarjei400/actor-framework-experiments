//
// Created by Adrian Jutrowski on 06/12/2020.
//

#ifndef TETRIS_ACTORGROUPMANAGER_H
#define TETRIS_ACTORGROUPMANAGER_H
#include "../../interfaces/IActorGroupManager.h"


class ActorGroupManager: public IActorGroupManager {
    caf::actor_system& system;
public:
    ActorGroupManager(caf::actor_system& system): system(system) {}

    void add(const caf::actor& actor, const std::string_view& groupName) override;
    void remove(const caf::actor& actor, const std::string_view& groupName) override;

};


#endif //TETRIS_ACTORGROUPMANAGER_H
