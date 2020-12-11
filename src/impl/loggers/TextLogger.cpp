//
// Created by Adrian Jutrowski on 02/12/2020.
//

#include "TextLogger.h"
#include <iostream>

void TextLogger::log(Severity s, const std::string &msg) {
    std::cout << msg << std::endl;
}