//
// Created by Adrian Jutrowski on 06/11/2020.
//

#include "GlfwWindow.h"
#include <memory>
#include <iostream>

#define GLFW_INCLUDE_NONE
using namespace std;

GlfwWindow::GlfwWindow(
        const vector<shared_ptr<IKeyEventListener>>& listeners
):
    keyListeners(listeners)
{
   // init();
}

GlfwWindow::~GlfwWindow() {
    glfwDestroyWindow(window);

    glfwTerminate();
}
void GlfwWindow::init() {

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(640, 480, getWindowName().c_str(), NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, onKeyPressCb);
    glfwSetMouseButtonCallback(window, onMousePressCb);

}
void GlfwWindow::onMousePressCb(GLFWwindow* window, int button, int action, int mods){
    auto* obj = (GlfwWindow*)glfwGetWindowUserPointer(window);
    obj->onMousePress(button, action, mods);
}

void GlfwWindow::onKeyPressCb(GLFWwindow *window, int key, int scancode, int action, int mods) {
    auto* obj = (GlfwWindow*)glfwGetWindowUserPointer(window);
    obj->onKeyPress(key, scancode, action, mods);
}


void GlfwWindow::onKeyPress(int key, int scancode, int action, int mods) {
    for(auto listener: keyListeners) {
        listener->onKey(key);
    }
}

void GlfwWindow::onMousePress(int button, int action, int mods) {
    for(auto listener: mouseListeners) {
        listener->onKey(button);
    }
}

void GlfwWindow::getSize(int &width, int &height) {
    glfwGetFramebufferSize(window, &width, &height);
}