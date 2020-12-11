//
// Created by Adrian Jutrowski on 08/11/2020.
//

#include "GLRendererActor.h"
#include "../../interfaces/CommonActorAtoms.h"
#include <GLFW/glfw3.h>
#include "linmath.h"

caf::behavior GLRendererActor::make_behavior() {

    unitialized.assign(
        [this](RenderAtom) {
            auto windowHook = (GLFWwindow*)window->getWindowHook();
            glfwMakeContextCurrent(windowHook);
            glfwSwapBuffers(windowHook);
            gladLoadGL();
            glfwSwapInterval(1);


            glGenBuffers(1, &vertex_buffer);
            glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
            glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*vertexBuffer.size(), vertexBuffer.data(), GL_STATIC_DRAW);

            vertex_shader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex_shader, 1, &vertex_shader_text, nullptr);
            glCompileShader(vertex_shader);

            fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment_shader, 1, &fragment_shader_text, nullptr);
            glCompileShader(fragment_shader);

            program = glCreateProgram();
            glAttachShader(program, vertex_shader);
            glAttachShader(program, fragment_shader);
            glLinkProgram(program);

            mvp_location = glGetUniformLocation(program, "MVP");
            vpos_location = glGetAttribLocation(program, "vPos");
            vcol_location = glGetAttribLocation(program, "vCol");

            glEnableVertexAttribArray(vpos_location);
            glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                                  sizeof(vertices[0]), (void*) 0);
            glEnableVertexAttribArray(vcol_location);
            glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                                  sizeof(vertices[0]), (void*) (sizeof(float) * 2));

            become(initialized);
    });

    initialized.assign(
        [this](RenderAtom) {
            auto* windowHook = (GLFWwindow*)window->getWindowHook();

            if (glfwWindowShouldClose(windowHook))
                return;

            glfwMakeContextCurrent(windowHook);

            float ratio;
            int width, height;
            mat4x4 m, p, mvp;

            window->getSize( width, height);
            ratio = width / (float) height;

            glViewport(0, 0, width, height);
            glClear(GL_COLOR_BUFFER_BIT);

            glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vector<Vertex>) + sizeof(Vertex)*vertexBuffer.size(), vertexBuffer.data(), GL_DYNAMIC_DRAW);

            auto time = (float)glfwGetTime()/10.0f;
            mat4x4_identity(m);
            mat4x4_rotate_Z(m, m, time);
            mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
            mat4x4_mul(mvp, p, m);

            glUseProgram(program);
            glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*) mvp);
            glDrawArrays(GL_TRIANGLES, 0, vertexBuffer.size() - 1);

            //vertexBuffer.clear();
            glfwSwapBuffers(windowHook);

        }, [this](AddRectAtom, const Rect& rect) {
            vertexBuffer.push_back({rect.bottonRightCorner.x, rect.bottonRightCorner.y, 1 ,0 ,0});
            vertexBuffer.push_back({rect.bottonRightCorner.x, rect.topLeftCorner.y, 1 ,1 ,0});
            vertexBuffer.push_back({rect.topLeftCorner.x, rect.bottonRightCorner.y, 1 ,0 ,0});
            vertexBuffer.push_back({rect.topLeftCorner.x, rect.bottonRightCorner.y, 1 ,0 ,0});
            vertexBuffer.push_back({rect.topLeftCorner.x, rect.topLeftCorner.y, 1 ,0 ,0});
            vertexBuffer.push_back({rect.bottonRightCorner.x, rect.topLeftCorner.y, 1 ,0 ,0});

        },
        [this]( QuitAtom) {
            std::cout << "Actor received quit message" << std::endl;
            become(stopped);
            quit();
        }
    );

    return unitialized;

}