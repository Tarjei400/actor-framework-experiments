#include <iostream>
#include <boost/di.hpp>
#include <caf/all.hpp>
#include <caf/io/all.hpp>
#include <glad/glad.h>
#include <boost/di/extension/injections/shared_factory.hpp>

#include "src/interfaces/CommonActorAtoms.h"
#include "src/interfaces/IBoardController.h"
#include "src/interfaces/IActorWrapper.h"
#include "src/interfaces/IRenderer.h"
#include "src/interfaces/IRenderCounter.h"
#include "src/interfaces/IWindow.h"
#include "src/interfaces/IKeyEventListener.h"
#include "src/interfaces/IWindowLoop.h"
#include "src/interfaces/IWindowController.h"
#include "src/interfaces/IPieceController.h"
#include "src/interfaces/ILogger.h"
#include "src/interfaces/IGameController.h"
#include "src/impl/game/board/BoardController.h"
#include "src/impl/renderer/GLRenderer.h"
#include "src/impl/renderer/RenderCounter.h"
#include "src/impl/windows/GlfwWindow.h"
#include "src/impl/windows/GlfwWindowController.h"
#include "src/impl/GameLoop.h"
#include "src/impl/listeners/BoardKeyListener.h"
#include "src/impl/listeners/WindowKeyListener.h"
#include "src/impl/listeners/GameKeyListener.h"
#include "src/impl/loggers/TextLogger.h"
#include "src/impl/loggers/LoggerAdapter.h"
#include "src/impl/game/pieces/PieceController.h"
#include "src/impl/game/pieces/PieceControllerActor.h"
#include "src/impl/game/GameController.h"
#include "src/impl/configuration/IConfiguration.h"
#include "src/impl/configuration/EnvConfiguration.h"
#include "src/impl/configuration/JsonConfiguration.h"
#include "src/impl/configuration/ConsulConfiguration.h"
#include "src/impl/configuration/ConfigurationAdapter.h"


using namespace boost;
#include <prometheus/counter.h>
#include <prometheus/histogram.h>
#include <prometheus/exposer.h>
#include <prometheus/registry.h>



//Board actor
//Rendering queue
//Rendering actor?

int caf_main(actor_system& system) {

// Create a consul client that uses default local endpoint `http://127.0.0.1:8500` and default data center
    Consul consul;
// We need the 'agent' endpoint for a service registration
    ConsulAgent agent(consul);
    ConsulKv kv(consul);

    // create an http server running on port 8081 TODO: Add it to di container
    prometheus::Exposer exposer{"127.0.0.1:8081"};

    auto module = di::make_injector(
            di::bind<prometheus::Registry>().in(di::singleton).to<prometheus::Registry>(),
            di::bind<actor_system>().to(system),
            di::bind<ConsulAgent>().to(agent),
            di::bind<ConsulKv>().to(kv),
            di::bind<IConfiguration>().to<ConfigurationAdapter>(),
            di::bind<IConfiguration *[]>().to<ConsulConfiguration, EnvConfiguration, JsonConfiguration>(),
            di::bind<IBoardController>().to<BoardController>(),
            di::bind<IRenderer>().in(di::singleton).to<GLRenderer>(),
            di::bind<IRenderCounter>().in(di::singleton).to<RenderCounter>(),
            di::bind<IWindow>().in(di::singleton).to<GlfwWindow>(),
            di::bind<ILogger *[]>().to<TextLogger>(),
            di::bind<ILogger>().to<LoggerAdapter>(),
            di::bind<IWindowLoop *[]>.to<GameLoop>(),
            di::bind<IWindowController>().to<GlfwWindowController>(),
            di::bind<IPieceController>().in(di::singleton).to<PieceController>(),
            di::bind<IKeyEventListener *[]>().to<BoardKeyListener, WindowKeyListener, GameKeyListener>(),
            di::bind<IGameController>().in(di::singleton).to<GameController>()
    );

    auto registry = module.create<std::shared_ptr<prometheus::Registry>>();
    exposer.RegisterCollectable(registry);
    // create a metrics registry with component=main labels applied to all its
    // metrics

//    auto& histogram_family = BuildHistogram()
//                              .Name("some_name")
//                              .Help("Additional description.")
//                              .Labels({{"key", "value"}})
//                              .Register(*registry);
//
//    auto& counter_family = BuildCounter()
//            .Name("time_running_seconds_total")
//            .Help("How many seconds is this server running?")
//            .Labels({{"label", "value"}})
//            .Register(*registry);
//
//    // add a counter to the metric family
//    auto& second_counter = counter_family.Add(
//    {{"another_label", "value"}, {"yet_another_label", "value"}}
//    );
//
//
//    std::vector<double> buckets{0.0, 100.0, 200.0, 500.0, 1000.0, 2000.0, 9999999.0};
//    auto& fps_histogram = histogram_family.Add(
//            {{"fps_label", "value"}}, buckets
//    );
//
//    for (auto i = 0; i < 10000; i++) {
//        fps_histogram.Observe((double)std::rand()/RAND_MAX*2000);
//    }
//
//    fps_histogram.Collect();
//
//    // ask the exposer to scrape the registry on incoming scrapes
//
//
//    // increment the counter by one (second)
//    second_counter.Increment();
//    second_counter.Increment();
//    second_counter.Increment();

    auto services = agent.services();

    auto logger = module.create<std::shared_ptr<ILogger>>();
    auto configuration = module.create<std::shared_ptr<IConfiguration>>();
    auto v1 = configuration->get("test");
    auto v2 = configuration->get("test2");
    auto v3 = configuration->get("test3");

    logger->log(LOG_INFO, v1.value());
    logger->log(LOG_INFO, v2.value());
    logger->log(LOG_INFO, v3.value());

    logger->log(LOG_INFO, "Bla bla");
    auto window = module.create<std::shared_ptr<IWindowController>>();
    window->start();
    logger->log(LOG_INFO, "ending");

    auto self = scoped_actor{system};
    auto group = system.groups().get_local(std::string(EXIT_GROUP_NAME));
    self->send(group, MoveRightAtom::value);
    self->send(group, QuitAtom::value);

    std::cout << "window should get destroyed" << std::endl;

    system.await_actors_before_shutdown();
    std::cout << "all killed" << std::endl;

    return 0;
}

CAF_MAIN(caf::io::middleman)