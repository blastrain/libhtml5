#include "libhtml5.h"
#include "class.h"

static void promiseTest()
{
    HTML5_INIT();

    auto promise = html5::Promise::create([](std::function<void(const std::string &)> resolve, std::function<void()> reject) {
        html5::window->setTimeout([resolve](){ resolve("foo"); }, 300);
    });
    promise->then([](const std::string &value) {
        html5::window->console->log(value);
    });
    html5::window->console->log(promise);
}

EMSCRIPTEN_BINDINGS(Promise) {
    emscripten::function("promiseTest", &promiseTest);
}
