//
// Created by Adrian Jutrowski on 01/12/2020.
//

#include <cstdlib>
#include <caf/io/all.hpp>
#include "GameController.h"
#include "../../interfaces/IActorWrapper.h"
#include "boost/di/extension/injections/lazy.hpp"
using namespace boost::di::extension;

GameController::GameController(
        caf::actor_system& system,
        Agent agent,
        const shared_ptr<IBoardController>& boardCtrl,
        const shared_ptr<IPieceController>& pieceCtrl,
        lazy<shared_ptr<IRenderer>> lazyRenderer

): ActorWrapper<GameControllerActor>(system, boardCtrl, pieceCtrl), lazyRenderer(lazyRenderer){
    auto port = system.middleman().publish(actor, 0 );
    auto healthCheckAddress = "docker.for.mac.host.internal:" + std::to_string(port.value());
    agent.registerService(
            agent::kw::id = "GameActor",
            agent::kw::name = "my-service",
            agent::kw::port = port.value(),
            agent::kw::tags = {"tcp", "super_server"},
            agent::kw::check = TcpCheck{healthCheckAddress, std::chrono::seconds(2)}
    );
}

void GameController::start() {
    auto renderer = lazyRenderer.get();

    auto self = scoped_actor{system};
    auto minX = (float)std::rand()/RAND_MAX;
    auto maxX = (float)std::rand()/RAND_MAX;
    auto minY = (float)std::rand()/RAND_MAX;
    auto maxY = (float)std::rand()/RAND_MAX;
    Rect rect{ std::min(minX, maxX),std::min(minY, maxY), std::max(minX, maxX) , std::max(minY, maxY)};
    renderer->addRect(rect);
}

void GameController::stop() {
    auto self = scoped_actor{system};
}

void GameController::tick() {
    auto self = scoped_actor{system};
}
