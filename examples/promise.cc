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
        return html5::Promise::resolve("bar");
    })->then([](const std::string &value) {
        html5::window->console->log(value);
        return html5::Promise::resolve(0.0);
    });
    html5::window->console->log(promise);
}

static void fetchImageTest(const std::string &imageURL)
{
    HTML5_INIT();
    html5::fetch(imageURL)->then<html5::Response *>([](html5::Response *response) {
        return response->blob();
    })->then<html5::Blob *>([](html5::Blob *blob) {
        auto reader = html5::FileReader::create();
        reader->onload = [reader](html5::Event *event) {
            std::string data = reader->result;
            auto image = html5::HTMLImageElement::create();
            image->src = data;
            html5::window->document->body->appendChild(image);
        };
        reader->readAsDataURL(blob);
        return nullptr;
    })->catchError([]{
        html5::window->console->log("catch");
        return nullptr;
    })->finally([]{
        html5::window->console->log("finally");
        return nullptr;
    });
}

EMSCRIPTEN_BINDINGS(Promise) {
    emscripten::function("promiseTest", &promiseTest);
    emscripten::function("fetchImageTest", &fetchImageTest);
}
