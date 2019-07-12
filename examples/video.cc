#include "libhtml5.h"
#include "class.h"
#include <iostream>
#include "runtime.h"

static void createVideo(std::string url)
{
    html5::HTMLVideoElement *video   = html5::HTMLVideoElement::create();
    html5::HTMLSourceElement *source = html5::HTMLSourceElement::create();
    source->src = url;
    video->appendChild(source);
    static html5::EventHandler f = [](html5::Event *e){
        std::cout << "demo event fired!!!" << std::endl;
        std::cout << (std::string)e->type << std::endl;
        std::cout << e->bubbles << std::endl;
        std::cout << e->timeStamp << std::endl;
    };
    video->addEventListener("demo", &f);
    html5::Document *document = html5::window->document;
    document->body->appendChild(video);
    html5::Event *event = html5::Event::create("demo");
    video->dispatchEvent(event);
}
