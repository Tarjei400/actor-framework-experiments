//
// Created by Adrian Jutrowski on 10/12/2020.
//

#ifndef TETRIS_CONFIGURATIONADAPTER_H
#define TETRIS_CONFIGURATIONADAPTER_H
#include "./IConfiguration.h"
#include <vector>
#include <memory>

class ConfigurationAdapter: public IConfiguration {
    std::vector<std::shared_ptr<IConfiguration>> configs;

public:
    ConfigurationAdapter(std::vector<std::shared_ptr<IConfiguration>> configs): configs(configs) {}
    std::optional<std::string> get(const std::string& key) override;

};


#endif //TETRIS_CONFIGURATIONADAPTER_H
