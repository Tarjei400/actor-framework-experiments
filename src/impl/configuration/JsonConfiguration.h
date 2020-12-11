//
// Created by Adrian Jutrowski on 09/12/2020.
//

#ifndef TETRIS_JSONCONFIGURATION_H
#define TETRIS_JSONCONFIGURATION_H
#include "./IConfiguration.h"
#include <nlohmann/json.hpp>
#include <fstream>

// for convenience
using json = nlohmann::json;

class JsonConfiguration: public IConfiguration {
    json config;

public:
    JsonConfiguration() {
        std::ifstream t("config.json");
        std::string data((std::istreambuf_iterator<char>(t)),
                        std::istreambuf_iterator<char>());

        config = json::parse(data);
    }
    std::optional<std::string> get(const std::string& key) override;

};


#endif //TETRIS_JSONCONFIGURATION_H
