//
// Created by Adrian Jutrowski on 01/12/2020.
//

#ifndef TETRIS_IPIECECONTROLLER_H
#define TETRIS_IPIECECONTROLLER_H

class IPieceController {
public:
    virtual void moveUp() = 0;
    virtual void moveDown() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void rotate() = 0;

};
#endif //TETRIS_IPIECECONTROLLER_H
