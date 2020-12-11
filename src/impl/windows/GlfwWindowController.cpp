//
// Created by Adrian Jutrowski on 07/11/2020.
//

#include "GlfwWindowController.h"
#include <GLFW/glfw3.h>
#include <unistd.h>

GlfwWindowController::GlfwWindowController(
        boost::di::extension::lazy<shared_ptr<IWindow>> lazyWindow,
        boost::di::extension::lazy<shared_ptr<IRenderer>> lazyRenderer,
        const vector<shared_ptr<IWindowLoop>>& loopHandlers
):
   loopHandlers(loopHandlers), lazyWindow(lazyWindow), lazyRenderer(lazyRenderer)
{

}

void GlfwWindowController::start() {
   auto window = lazyWindow.get();
   auto renderer = lazyRenderer.get();

    window->init();
    GLFWwindow* windowHook = (GLFWwindow*)window->getWindowHook();

    while (!glfwWindowShouldClose(windowHook))
    {

        renderer->renderFrame();
        for(const auto& loopHandler: loopHandlers) {
            loopHandler->execute();
        }
        //glfwSwapBuffers(windowHook);
        glfwPollEvents();
        usleep(1000000);
    }

}