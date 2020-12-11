//
// Created by Adrian Jutrowski on 10/12/2020.
//

#include "ConfigurationAdapter.h"
std::optional<std::string> ConfigurationAdapter::get(const std::string& key) {
    for( auto config: configs) {
        auto v = config->get(key);
        if(v) {
            return v;
        }
    }

    return std::nullopt;
};
