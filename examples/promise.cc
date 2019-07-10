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
        auto response = dynamic_cast<html5::Response *>(const_cast<html5::Object *>(&_response));
        return response->blob();
    })->then([](const html5::Object &_blob)->html5::Promise* {
        auto blob = dynamic_cast<html5::Blob *>(const_cast<html5::Object *>(&_blob));
        auto reader = html5::FileReader::create();
        reader->onload = [reader](html5::Event *event) {
            auto data = reader->result;
            auto image = html5::HTMLImageElement::create();
            image->src = data;
            html5::window->document->appendChild(image);
        };
        reader->readAsDataURL(blob);
        return nullptr;
    });
}

EMSCRIPTEN_BINDINGS(Promise) {
    emscripten::function("promiseTest", &promiseTest);
    emscripten::function("fetchTest", &fetchTest);
}
