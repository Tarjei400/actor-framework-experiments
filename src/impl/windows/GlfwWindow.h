//
// Created by Adrian Jutrowski on 06/11/2020.
//

#ifndef TETRIS_GLFWWINDOW_H
#define TETRIS_GLFWWINDOW_H
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include "../../interfaces/IWindow.h"
#include "../../interfaces/IRenderer.h"
#include "../../interfaces/IWindowLoop.h"
#include "../../interfaces/IKeyEventListener.h"
#include "../../interfaces/IMouseEventListener.h"

using namespace std;

class GlfwWindow: public IWindow {

    /**
     * Glfw window hook
     */
    GLFWwindow* window;
    vector<shared_ptr<IKeyEventListener>> keyListeners{};
    vector<shared_ptr<IMouseEventListener>> mouseListeners{};

public :
    GlfwWindow() = default;

    explicit GlfwWindow(
        const vector<shared_ptr<IKeyEventListener>> &listeners
    );

    ~GlfwWindow();

    void init() override;
    std::string getWindowName() override { return "Glfw Default"; }

    void getSize(int&, int&) override;
    void* getWindowHook() override { return (void*)window; }

    void onKeyPress(int key, int scancode, int action, int mods);
    void onMousePress(int button, int action, int mods);

    static void onKeyPressCb(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void onMousePressCb(GLFWwindow* window, int button, int action, int mods);

};


#endif //TETRIS_GLFWWINDOW_H
