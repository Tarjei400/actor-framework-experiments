//
// Created by Adrian Jutrowski on 07/11/2020.
//
#include "../../interfaces/IRenderer.h"

#ifndef TETRIS_GLRENDERER_H
#define TETRIS_GLRENDERER_H
#include "../../interfaces/IWindow.h"
#include "../../interfaces/IActorWrapper.h"
#include "./GLRendererActor.h"
#include "../../../const.h"

using namespace std;


class GLRenderer: public IRenderer, public ActorWrapper<GLRendererActor> {
    caf::actor_system& system;

public:
    GLRenderer(
        caf::actor_system& system,
        ConsulAgent agent,
        const shared_ptr<IWindow>& window
    );

    void renderFrame() override;
    void addRect(const Rect& rect) override;
};


#endif //TETRIS_GLRENDERER_H
