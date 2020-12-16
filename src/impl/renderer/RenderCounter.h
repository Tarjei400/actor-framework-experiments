//
// Created by Adrian Jutrowski on 15/12/2020.
//

#ifndef TETRIS_RENDERCOUNTER_H
#define TETRIS_RENDERCOUNTER_H
#include "boost/di/extension/injections/lazy.hpp"
#include "../../interfaces/IRenderCounter.h"
#include <prometheus/exposer.h>
#include <prometheus/counter.h>
#include <prometheus/registry.h>

using namespace prometheus;

class RenderCounter: public IRenderCounter {
    boost::di::extension::lazy<std::shared_ptr<Registry>> registryLazy;
public:
    RenderCounter(
            const boost::di::extension::lazy<std::shared_ptr<Registry>>& registryLazy
    );

    void increment() override;
};


#endif //TETRIS_RENDERCOUNTER_H
