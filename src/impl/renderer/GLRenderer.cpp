//
// Created by Adrian Jutrowski on 07/11/2020.
//

#include "GLRenderer.h"
#include <chrono>
#include <caf/io/all.hpp>


GLRenderer::GLRenderer(
        caf::actor_system& system,
        Agent agent,
        const shared_ptr<IWindow>& window,
        const shared_ptr<IRenderCounter> counter
) : ActorWrapper<GLRendererActor>(system, window, counter), system(system){
    auto port = system.middleman().publish(actor, 0 );
    auto healthCheckAddress = "docker.for.mac.host.internal:" + std::to_string(port.value());
    agent.registerService(
            agent::kw::id = "RendererActor",
            agent::kw::name = "my-service",
            agent::kw::port = port.value(),
            agent::kw::tags = {"tcp", "super_server"},
            agent::kw::check = TcpCheck{healthCheckAddress, std::chrono::seconds(2)}
    );
}

void GLRenderer::renderFrame() {
    self->send(actor, RenderAtom::value);
}

void GLRenderer::addRect(const Rect& rect) {
    self->send(actor, AddRectAtom::value, rect);
}