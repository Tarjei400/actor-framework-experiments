//
// Created by Adrian Jutrowski on 07/11/2020.
//

#include "MockWindow.h"


MockWindow::MockWindow( vector<shared_ptr<IKeyEventListener>>& listeners ): keyListeners(listeners)  {

}

void MockWindow::keyPress(int key) {
    for(const auto& keyListener: keyListeners) {
        keyListener->onKey(key);
    }
}

void MockWindow::nextWindowLoopIteration() {
    for(const auto& loopHandler: loopHandlers) {
        loopHandler->execute();
    }
}

void MockWindow::getSize(int &width, int &height) {
    height = 100;
    width = 100;
}