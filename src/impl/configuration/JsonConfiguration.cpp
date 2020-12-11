//
// Created by Adrian Jutrowski on 09/12/2020.
//

#include "JsonConfiguration.h"
std::optional<std::string> JsonConfiguration::get(const std::string& key) {
    try{
        auto v = config.at(key);
        return v.get<std::string>();

    }catch ( ... ) {
        return std::nullopt;
    }
};