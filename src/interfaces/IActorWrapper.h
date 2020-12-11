//
// Created by Adrian Jutrowski on 08/11/2020.
//

#ifndef TETRIS_IACTORWRAPPER_H
#define TETRIS_IACTORWRAPPER_H
#include <caf/all.hpp>

class IActorWrapper {
public:
    IActorWrapper() = default;

    virtual caf::actor getActor() = 0;
};


constexpr std::string_view EXIT_GROUP_NAME = "exit events";

template<class T>
class ActorWrapper: public IActorWrapper {
protected:
    caf::actor actor;
    caf::actor_system& system;
    caf::scoped_actor self;
public:

    ActorWrapper() = default;
    ~ActorWrapper() {

    }
    template<class ...Ts>
    explicit ActorWrapper( caf::actor_system& system, Ts ...args): system(system), self(caf::scoped_actor{system}) {
        actor = self->spawn<T>(std::forward<Ts>(args)...);
        auto group = system.groups().get_local(std::string(EXIT_GROUP_NAME));
        group->subscribe( caf::actor_cast<caf::strong_actor_ptr>(actor));
    }

    caf::actor getActor() override {
       return actor;
    }
};
#endif //TETRIS_IACTORWRAPPER_H
