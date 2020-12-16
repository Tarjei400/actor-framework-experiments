//
// Created by Adrian Jutrowski on 15/12/2020.
//

#include "RenderCounter.h"


RenderCounter::RenderCounter(
        const boost::di::extension::lazy<std::shared_ptr<Registry>>& registryLazy
): registryLazy(registryLazy) {

}

void RenderCounter::increment(){
    auto registry = registryLazy.get();

    auto& counter_family = BuildCounter()
            .Name("renders_count")
            .Help("How many renders were done when app is running?")
            .Labels({{"label", "value"}})
            .Register(*registry);


    auto& counter = counter_family.Add(
            {{"another_label", "value"}, {"yet_another_label", "value"}}
    );

    counter.Increment();
}