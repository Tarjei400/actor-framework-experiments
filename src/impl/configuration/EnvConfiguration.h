//
// Created by Adrian Jutrowski on 09/12/2020.
//

#ifndef TETRIS_ENVCONFIGURATION_H
#define TETRIS_ENVCONFIGURATION_H
#include "./IConfiguration.h"


class EnvConfiguration: public IConfiguration {
public:
    std::optional<std::string> get(const std::string& key) override;
};


#endif //TETRIS_ENVCONFIGURATION_H
