//
// Created by Adrian Jutrowski on 01/12/2020.
//

#ifndef TETRIS_IGAMECONTROLLER_H
#define TETRIS_IGAMECONTROLLER_H



class IGameController {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void tick() = 0;
};

#endif //TETRIS_IGAMECONTROLLER_H