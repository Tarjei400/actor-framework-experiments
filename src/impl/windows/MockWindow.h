//
// Created by Adrian Jutrowski on 07/11/2020.
//
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include "../../interfaces/IWindow.h"
#include "../../interfaces/IWindowLoop.h"
#include "../../interfaces/IKeyEventListener.h"

using namespace std;
#ifndef TETRIS_MOCKWINDOW_H
#define TETRIS_MOCKWINDOW_H

//Window stub to use in tests
class MockWindow : public IWindow {
    vector<shared_ptr<IKeyEventListener>> keyListeners{};
    vector<shared_ptr<IWindowLoop>> loopHandlers{};

public:
    MockWindow() = default;

    MockWindow(
            vector<shared_ptr<IKeyEventListener>> &listeners
    );
    void init() override {};
    std::string getWindowName() override { return "Mock window"; }
    void getSize(int&, int&);

    void nextWindowLoopIteration();
    void keyPress(int key);


};


#endif //TETRIS_MOCKWINDOW_H
