//
// Created by Adrian Jutrowski on 07/11/2020.
//

#ifndef TETRIS_GLFWWINDOWHANDLER_H
#define TETRIS_GLFWWINDOWHANDLER_H
#include <vector>
#include "boost/di/extension/injections/lazy.hpp"
#include "../../interfaces/IRenderer.h"
#include "../../interfaces/IWindow.h"
#include "../../interfaces/IWindowLoop.h"
#include "../../interfaces/IWindowController.h"

using namespace std;

class GlfwWindowController: public IWindowController {

    vector<shared_ptr<IWindowLoop>> loopHandlers{};
    boost::di::extension::lazy<shared_ptr<IWindow>> lazyWindow;
    boost::di::extension::lazy<shared_ptr<IRenderer>> lazyRenderer;

public:
    explicit GlfwWindowController(
        boost::di::extension::lazy<shared_ptr<IWindow>> lazyWindow,
        boost::di::extension::lazy<shared_ptr<IRenderer>> lazyRenderer,
        const vector<shared_ptr<IWindowLoop>>& loopHandlers
    );

    ~GlfwWindowController() {
        std::cout << "Sontroller destroyed"  << std::endl;
    }
    void start() override;
};


#endif //TETRIS_GLFWWINDOWHANDLER_H
