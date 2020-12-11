//
// Created by Adrian Jutrowski on 06/12/2020.
//

#ifndef TETRIS_IACTORGROUPMANAGER_H
#define TETRIS_IACTORGROUPMANAGER_H
#include <string>
#include <caf/all.hpp>

class IActorGroupManager {
public:
    virtual void add(const caf::actor& actor, const std::string_view& groupName) = 0;
    virtual void remove(const caf::actor& actor, const std::string_view& groupName) = 0;


};
#endif //TETRIS_IACTORGROUPMANAGER_H
