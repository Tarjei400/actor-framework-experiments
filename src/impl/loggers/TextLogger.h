//
// Created by Adrian Jutrowski on 02/12/2020.
//

#ifndef TETRIS_TEXTLOGGER_H
#define TETRIS_TEXTLOGGER_H
#include "../../interfaces/ILogger.h"


class TextLogger: public ILogger {
public:
    void log(Severity s, const std::string& msg) override;
};


#endif //TETRIS_TEXTLOGGER_H
