//
// Created by Adrian Jutrowski on 01/12/2020.
//

#ifndef TETRIS_PRIMITIVES_H
#define TETRIS_PRIMITIVES_H
#include <vector>
#include <caf/all.hpp>


struct Position {
    float x, y;
};

struct Rect {
    Position topLeftCorner;
    Position bottonRightCorner;
};



struct Color {
    float r, g, b;
};

struct Vertex
{
    Position pos;
    float r, g, b;
};

using VertexBuffer = std::vector<Vertex>;


CAF_ALLOW_UNSAFE_MESSAGE_TYPE(Position);
CAF_ALLOW_UNSAFE_MESSAGE_TYPE(Rect);

#endif //TETRIS_PRIMITIVES_H
