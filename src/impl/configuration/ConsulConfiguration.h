//
// Created by Adrian Jutrowski on 09/12/2020.
//

#ifndef TETRIS_CONSULCONFIGURATION_H
#define TETRIS_CONSULCONFIGURATION_H
#include "IConfiguration.h"
#include "../../interfaces/IActorWrapper.h"
#include "../../../const.h"


class ConsulConfiguration: public IConfiguration {
    ConsulKv& kv;
public:
    explicit ConsulConfiguration(ConsulKv& kv): kv(kv) {};
    std::optional<std::string> get(const std::string& key) override;
};


#endif //TETRIS_CONSULCONFIGURATION_H
