#include <emscripten/bind.h>

#include "document.h"
#include "html_video_element.h"
#include "html_source_element.h"
#include "event.h"
#include "event_target.h"
#include <iostream>
#include <emscripten/emscripten.h>

static void createVideo()
{
    HTMLVideoElement *video = HTMLVideoElement::create();
    HTMLSourceElement *source = HTMLSourceElement::create();
    source->src = "http://clips.vorwaerts-gmbh.de/VfE_html5.mp4";
    video->appendChild(source);
    static std::function<void(Event*)> f = [](Event *e){
        std::cout << "demo event fired!!!" << std::endl;
        std::cout << (std::string)e->type << std::endl;
        std::cout << e->bubbles << std::endl;
        std::cout << e->timeStamp << std::endl;
    };
    video->addEventListener("demo", &f);
    Document::body()->appendChild(video);
    Event *event = Event::create("demo");
    video->dispatchEvent(event);
}

static emscripten::val toString(intptr_t ptr)
{
    return emscripten::val(std::string((char *)ptr));
}

static EventTarget *toEventTarget(intptr_t ptr)
{
    return (EventTarget *)ptr;
}

EMSCRIPTEN_BINDINGS(createVideo) {
    emscripten::class_<EventTarget>("EventTarget")
        .property("_value", &EventTarget::getValue)
        .function("addEventListenerCallback", &EventTarget::addEventListenerCallback);
    emscripten::function("createVideo", &createVideo);
    function("toEventTarget", &toEventTarget, emscripten::allow_raw_pointers());
    function("toString", &toString, emscripten::allow_raw_pointers());
}
