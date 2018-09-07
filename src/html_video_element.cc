#include "document.h"
#include "html_video_element.h"

HTMLVideoElement::HTMLVideoElement(emscripten::val v) :
    HTMLMediaElement(v)
{

}

HTMLVideoElement::~HTMLVideoElement()
{

}

HTMLVideoElement *HTMLVideoElement::create(emscripten::val v)
{
    return new HTMLVideoElement(v);
}

HTMLVideoElement *HTMLVideoElement::create()
{
    return dynamic_cast<HTMLVideoElement *>(Document::createElement("video"));
}
