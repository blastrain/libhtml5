#include "libhtml5.h"
#include "class.h"
#include <iostream>

static void createVideo()
{
    HTMLVideoElement *video = HTMLVideoElement::create();
    HTMLSourceElement *source = HTMLSourceElement::create();
    source->src = "http://clips.vorwaerts-gmbh.de/VfE_html5.mp4";
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

static void createImage(std::string url)
{
    HTMLImageElement *image = HTMLImageElement::create();
    static EventHandler onload = [image](Event *e){
        std::cout << "callback. onload" << std::endl;
        std::cout << "width = " << image->width << std::endl;
        std::cout << "height = " << image->height << std::endl;
        std::cout << "naturalWidth = " << image->naturalWidth << std::endl;
        std::cout << "naturalHeight = " << image->naturalHeight << std::endl;
    };
    image->onload = &onload;
    image->src = url;
    document->body->appendChild(image);
}

EMSCRIPTEN_BINDINGS(html5example) {
    emscripten::function("createVideo", &createVideo);
    emscripten::function("createImage", &createImage);
}
