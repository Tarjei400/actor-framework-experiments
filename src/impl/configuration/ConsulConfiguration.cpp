//
// Created by Adrian Jutrowski on 09/12/2020.
//

#include "ConsulConfiguration.h"
std::optional<std::string> ConsulConfiguration::get(const std::string& key) {
    auto response = kv.item(key);
    return response.valid() ? std::optional<std::string>(response.value) : std::nullopt;
};