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

double HTMLVideoElement::getHeight() const
{
    return HTML5_PROPERTY_GET(height, double);
}

void HTMLVideoElement::setHeight(double value)
{
    this->_height = value;
    this->v.set("height", value);
}

std::string HTMLVideoElement::getPoster() const
{
    return HTML5_PROPERTY_GET(poster, std::string);
}

void HTMLVideoElement::setPoster(std::string value)
{
    this->_poster = value;
    this->v.set("poster", value);
}

double HTMLVideoElement::getVideoHeight() const
{
    return HTML5_PROPERTY_GET(videoHeight, double);
}

void HTMLVideoElement::setVideoHeight(double value)
{
    this->_videoHeight = value;
    this->v.set("videoHeight", value);
}

double HTMLVideoElement::getVideoWidth() const
{
    return HTML5_PROPERTY_GET(videoWidth, double);
}

void HTMLVideoElement::setVideoWidth(double value)
{
    this->_videoWidth = value;
    this->v.set("videoWidth", value);
}

double HTMLVideoElement::getWidth() const
{
    return HTML5_PROPERTY_GET(width, double);
}

void HTMLVideoElement::setWidth(double value)
{
    this->_width = value;
    this->v.set("width", value);
}
