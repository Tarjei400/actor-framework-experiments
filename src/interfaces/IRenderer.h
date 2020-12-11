//
// Created by Adrian Jutrowski on 06/11/2020.
//

#ifndef SERVER_IRENDERER_H
#define SERVER_IRENDERER_H
#include "./primitives.h"

class IRenderer {
public:
    virtual void renderFrame() = 0;
    virtual void addRect(const Rect& rect) = 0;
};
#endif //SERVER_IRENDERER_H
