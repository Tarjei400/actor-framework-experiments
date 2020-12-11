//
// Created by Adrian Jutrowski on 02/12/2020.
//

#ifndef TETRIS_LOGGERADAPTER_H
#define TETRIS_LOGGERADAPTER_H
#include <memory>
#include <vector>
#include "../../interfaces/ILogger.h"

using namespace std;

class LoggerAdapter: public ILogger {

    vector<shared_ptr<ILogger>> loggers;

public:
    explicit LoggerAdapter(const vector<shared_ptr<ILogger>>& loggers): loggers(loggers) {}
    void log(Severity s, const std::string& msg) override;
};


#endif //TETRIS_LOGGERADAPTER_H
