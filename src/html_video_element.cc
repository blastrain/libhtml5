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
    HTMLVideoElement *video = new HTMLVideoElement(v);
    video->autorelease();
    return video;
}

HTMLVideoElement *HTMLVideoElement::create()
{
    return dynamic_cast<HTMLVideoElement *>(Document::create()->createElement("video"));
}

HTML5_PROPERTY_IMPL(HTMLVideoElement, double, height);
HTML5_PROPERTY_IMPL(HTMLVideoElement, std::string, poster);
HTML5_PROPERTY_IMPL(HTMLVideoElement, double, videoHeight);
HTML5_PROPERTY_IMPL(HTMLVideoElement, double, videoWidth);
HTML5_PROPERTY_IMPL(HTMLVideoElement, double, width);
