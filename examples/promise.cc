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

static void fetchTest()
{
    HTML5_INIT();
    std::string url = "http://localhost/test/free.jpg";
    html5::fetch(url)->then([](const html5::Object &_response)->html5::Promise* {
        auto response = (html5::Response *)(&_response);
        return response->blob();
    })->then([](const html5::Object &_blob)->html5::Promise* {
        auto blob = (html5::Blob *)(&_blob);
        auto reader = html5::FileReader::create();
        reader->onload = [reader](html5::Event *event) {
            std::string data = reader->result;
            auto image = html5::HTMLImageElement::create();
            image->src = data;
            html5::window->document->body->appendChild(image);
        };
        reader->readAsDataURL(blob);
        return nullptr;
    });
}

EMSCRIPTEN_BINDINGS(Promise) {
    emscripten::function("promiseTest", &promiseTest);
    emscripten::function("fetchTest", &fetchTest);
}
