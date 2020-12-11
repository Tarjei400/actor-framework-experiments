

#ifndef SERVER_IBOARDCONTROLLER_H
#define SERVER_IBOARDCONTROLLER_H

#include <memory>
#include "IBoard.h"

class IBoardController {
    std::shared_ptr<IBoard> board;

};
#endif //SERVER_IBOARDCONTROLLER_H
