//
// Created by Adrian Jutrowski on 06/11/2020.
//

#include "BoardKeyListener.h"
#include <GLFW/glfw3.h>
#include <iostream>

void BoardKeyListener::onKey(int key) {
    switch(key) {
        case GLFW_KEY_DOWN: {
            ctrl->moveDown();
            break;
        }
        case GLFW_KEY_UP: {
            ctrl->moveUp();
            break;
        }
        case GLFW_KEY_RIGHT: {
            ctrl->moveRight();
            break;
        }
        case GLFW_KEY_LEFT: {
            ctrl->moveLeft();
            break;
        }
        case GLFW_KEY_SPACE: {
            ctrl->rotate();
        }

        default: {
           return;
        }

    }
}