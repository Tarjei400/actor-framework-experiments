//
// Created by Adrian Jutrowski on 01/12/2020.
//

#include "GameKeyListener.h"
#include <GLFW/glfw3.h>
#include "../../interfaces/primitives.h"

GameKeyListener::GameKeyListener(const std::shared_ptr<IGameController>& ctrl): ctrl(ctrl) {

}

void GameKeyListener::onKey(int key) {
    switch(key) {
        case GLFW_KEY_ESCAPE: {

        }
        case GLFW_KEY_ENTER: {
            //test buffer
            ctrl->start();
        }
    }
}