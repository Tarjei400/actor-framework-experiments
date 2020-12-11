//
// Created by Adrian Jutrowski on 10/12/2020.
//

#ifndef TETRIS_ICONFIGURATION_H
#define TETRIS_ICONFIGURATION_H
#include<string>
#include<optional>

class IConfiguration {
public:
    virtual std::optional<std::string> get(const std::string& key) = 0;

};
#endif //TETRIS_ICONFIGURATION_H
