#include <emscripten/bind.h>

#include "document.h"
#include "html_video_element.h"
#include "html_source_element.h"
#include "html_image_element.h"
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

static void createImage()
{
    HTMLImageElement *image = HTMLImageElement::create();
    static EventHandler onload = [image](Event *e){
        std::cout << "callback. onload" << std::endl;
        std::cout << "width = " << image->width << std::endl;
        std::cout << "height = " << image->height << std::endl;
    };
    image->onload = &onload;
    image->src = "";
    Document::body()->appendChild(image);
}

static emscripten::val toString(intptr_t ptr)
{
    return emscripten::val(std::string((char *)ptr));
}

static EventTarget *toEventTarget(intptr_t ptr)
{
    return (EventTarget *)ptr;
}

static HTMLElement *toHTMLElement(intptr_t ptr)
{
    return (HTMLElement *)ptr;
}

EMSCRIPTEN_BINDINGS(createVideo) {
    emscripten::class_<EventTarget>("EventTarget")
        .property("_value", &EventTarget::getValue)
        .function("addEventListenerCallback", &EventTarget::addEventListenerCallback);
    emscripten::class_<HTMLElement>("HTMLElement")
        .property("_value", &HTMLElement::getValue)
        .function("onAbortCallback", &HTMLElement::onAbortCallback)
        .function("onAutoCompleteCallback", &HTMLElement::onAutoCompleteCallback)
        .function("onAutoCompleteErrorCallback", &HTMLElement::onAutoCompleteErrorCallback)
        .function("onBlurCallback", &HTMLElement::onBlurCallback)
        .function("onCancelCallback", &HTMLElement::onCancelCallback)
        .function("onCanplayCallback", &HTMLElement::onCanplayCallback)
        .function("onCanplayThroughCallback", &HTMLElement::onCanplayThroughCallback)
        .function("onChangeCallback", &HTMLElement::onChangeCallback)
        .function("onClickCallback", &HTMLElement::onClickCallback)
        .function("onCloseCallback", &HTMLElement::onCloseCallback)
        .function("onContextMenuCallback", &HTMLElement::onContextMenuCallback)
        .function("onCueChangeCallback", &HTMLElement::onCueChangeCallback)
        .function("onDoubleClickCallback", &HTMLElement::onDoubleClickCallback)
        .function("onDragCallback", &HTMLElement::onDragCallback)
        .function("onDragEndCallback", &HTMLElement::onDragEndCallback)
        .function("onDragEnterCallback", &HTMLElement::onDragEnterCallback)
        .function("onDragExitCallback", &HTMLElement::onDragExitCallback)
        .function("onDragLeaveCallback", &HTMLElement::onDragLeaveCallback)
        .function("onDragOverCallback", &HTMLElement::onDragOverCallback)
        .function("onDragStartCallback", &HTMLElement::onDragStartCallback)
        .function("onDropCallback", &HTMLElement::onDropCallback)
        .function("onDurationChangeCallback", &HTMLElement::onDurationChangeCallback)
        .function("onEmptiedCallback", &HTMLElement::onEmptiedCallback)
        .function("onEndedCallback", &HTMLElement::onEndedCallback)
        .function("onErrorCallback", &HTMLElement::onErrorCallback)
        .function("onFocusCallback", &HTMLElement::onFocusCallback)
        .function("onInputCallback", &HTMLElement::onInputCallback)
        .function("onInvalidCallback", &HTMLElement::onInvalidCallback)
        .function("onKeyDownCallback", &HTMLElement::onKeyDownCallback)
        .function("onKeyPressCallback", &HTMLElement::onKeyPressCallback)
        .function("onKeyUpCallback", &HTMLElement::onKeyUpCallback)
        .function("onLoadCallback", &HTMLElement::onLoadCallback);
    emscripten::function("createVideo", &createVideo);
    emscripten::function("createImage", &createImage);
    function("toEventTarget", &toEventTarget, emscripten::allow_raw_pointers());
    function("toHTMLElement", &toHTMLElement, emscripten::allow_raw_pointers());
    function("toString", &toString, emscripten::allow_raw_pointers());
}
