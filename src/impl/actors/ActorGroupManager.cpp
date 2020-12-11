//
// Created by Adrian Jutrowski on 06/12/2020.
//

#include "ActorGroupManager.h"
void ActorGroupManager::add(const caf::actor& actor, const std::string_view& groupName){
    auto group = system.groups().get_local(std::string(groupName));
    group->subscribe(caf::actor_cast<caf::strong_actor_ptr>(actor));
};

void ActorGroupManager::remove(const caf::actor& actor, const std::string_view& groupName){
    auto group = system.groups().get_local(std::string(groupName));
    auto ptr = caf::actor_cast<caf::strong_actor_ptr>(actor);

//    group->unsubscribe(blk);
};