//
// Created by Adrian Jutrowski on 09/12/2020.
//

#include "EnvConfiguration.h"

std::optional<std::string> EnvConfiguration::get(const std::string& key) {
    char* value = std::getenv(key.c_str());
    return value ? std::optional<std::string>{value} : std::nullopt;
};