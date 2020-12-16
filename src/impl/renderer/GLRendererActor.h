//
// Created by Adrian Jutrowski on 08/11/2020.
//

#ifndef TETRIS_GLRENDERERACTOR_H
#define TETRIS_GLRENDERERACTOR_H
#include <memory>
#include <array>
#include <glad/glad.h>
#include <caf/all.hpp>
#include "../../interfaces/IWindow.h"
#include "../../interfaces/IRenderCounter.h"
#include "../../interfaces/primitives.h"


using namespace std;
using namespace caf;

using RenderAtom = atom_constant<atom("Write")>;
using AddRectAtom = atom_constant<atom("AddRect")>;


static Vertex vertices[6] =
{
        { -0.6f, -0.4f, 1.f, 0.f, 0.f },
        {  0.6f, -0.4f, 0.f, 1.f, 0.f },
        {   0.f,  0.6f, 0.f, 0.f, 1.f },

        { -0.9f, -0.9f, 1.f, 0.f, 0.f },
        {  0.2f, -0.6, 0.f, 1.f, 0.f },
        {   -0.1f,  -0.1f, 0.f, 0.f, 1.f }
};

static const char* vertex_shader_text =
        "#version 110\n"
        "uniform mat4 MVP;\n"
        "attribute vec3 vCol;\n"
        "attribute vec2 vPos;\n"
        "varying vec3 color;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
        "    color = vCol;\n"
        "}\n";

static const char* fragment_shader_text =
        "#version 110\n"
        "varying vec3 color;\n"
        "void main()\n"
        "{\n"
        "    gl_FragColor = vec4(color, 1.0);\n"
        "}\n";


class GLRendererActor : public event_based_actor {
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;

    shared_ptr<IWindow> window;
    shared_ptr<IRenderCounter> counter;

    vector<Vertex> vertexBuffer{{
    { -0.6f, -0.4f, 1.f, 0.f, 0.f },
    {  0.6f, -0.4f, 0.f, 1.f, 0.f },
    {   0.f,  0.6f, 0.f, 0.f, 1.f },

    { -0.9f, -0.9f, 1.f, 0.f, 0.f },
    {  0.2f, -0.6, 0.f, 1.f, 0.f },
    {   -0.1f,  -0.1f, 0.f, 0.f, 1.f }
    }};

public:

    GLRendererActor(
            actor_config& config,
            const shared_ptr<IWindow>& window,
            const shared_ptr<IRenderCounter> counter
    ): event_based_actor(config), window(window), counter(counter) {

    };
protected:


    caf::behavior unitialized;
    caf::behavior initialized;
    caf::behavior stopped;

    caf::behavior make_behavior() override;

};


#endif //TETRIS_GLRENDERERACTOR_H
