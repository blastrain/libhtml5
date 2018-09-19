#include "libhtml5.h"
#include "class.h"
#include <iostream>

static void createVideo(std::string url)
{
    HTML5_INIT();
    HTMLVideoElement *video = HTMLVideoElement::create();
    HTMLSourceElement *source = HTMLSourceElement::create();
    source->src = url;
    video->appendChild(source);
    static EventHandler f = [](Event *e){
        std::cout << "demo event fired!!!" << std::endl;
        std::cout << (std::string)e->type << std::endl;
        std::cout << e->bubbles << std::endl;
        std::cout << e->timeStamp << std::endl;
    };
    video->addEventListener("demo", &f);
    document->body->appendChild(video);
    Event *event = Event::create("demo");
    video->dispatchEvent(event);
}

EMSCRIPTEN_BINDINGS(video) {
    emscripten::function("createVideo", &createVideo);
}
