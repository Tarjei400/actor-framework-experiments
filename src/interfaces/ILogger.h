//
// Created by Adrian Jutrowski on 02/12/2020.
//

#ifndef TETRIS_ILOGGER_H
#define TETRIS_ILOGGER_H
#include <string>

enum Severity {
    LOG_VERBOSE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
};

class ILogger {
public:
    virtual void log(Severity severity, const std::string& message ) = 0;
};

class ILoggerMain: public ILogger {

};

#endif //TETRIS_ILOGGER_H
