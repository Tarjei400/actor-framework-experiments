//
// Created by Adrian Jutrowski on 02/12/2020.
//

#include "LoggerAdapter.h"

void LoggerAdapter::log(Severity s, const std::string &msg) {
    for (auto& logger: loggers) {
        logger->log(s, msg);
    }
}
