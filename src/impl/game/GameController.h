//
// Created by Adrian Jutrowski on 01/12/2020.
//

#ifndef TETRIS_GAMECONTROLLER_H
#define TETRIS_GAMECONTROLLER_H

#include "../../interfaces/IBoardController.h"
#include "../../interfaces/IPieceController.h"
#include "../../interfaces/IGameController.h"
#include "../../interfaces/IActorWrapper.h"
#include "../../interfaces/IRenderer.h"
#include "GameControllerActor.h"
#include "boost/di/extension/injections/lazy.hpp"
#include "../../../const.h"

using namespace std;
class GameController: public IGameController, public ActorWrapper<GameControllerActor> {

    shared_ptr<IBoardController> boardCtrl;
    shared_ptr<IBoardController> pieceCtrl;
    boost::di::extension::lazy<shared_ptr<IRenderer>> lazyRenderer;

public:
    explicit GameController(
            caf::actor_system& system,
            ConsulAgent agent,
            const shared_ptr<IBoardController>& boardCtrl,
            const shared_ptr<IPieceController>& pieceCtrl,
            boost::di::extension::lazy<shared_ptr<IRenderer>> lazyRenderer
    );

    void start();
    void stop();
    void tick();

};


#endif //TETRIS_GAMECONTROLLER_H
