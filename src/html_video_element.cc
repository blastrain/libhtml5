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

double HTMLVideoElement::getHeight() const
{
    return this->v["height"].as<double>();
}

void HTMLVideoElement::setHeight(double value)
{
    this->_height = value;
    this->v.set("height", value);
}

std::string HTMLVideoElement::getPoster() const
{
    return this->v["poster"].as<std::string>();
}

void HTMLVideoElement::setPoster(std::string value)
{
    this->_poster = value;
    this->v.set("poster", value);
}

double HTMLVideoElement::getVideoHeight() const
{
    return this->v["videoHeight"].as<double>();
}

void HTMLVideoElement::setVideoHeight(double value)
{
    this->_videoHeight = value;
    this->v.set("videoHeight", value);
}

double HTMLVideoElement::getVideoWidth() const
{
    return this->v["videoWidth"].as<double>();
}

void HTMLVideoElement::setVideoWidth(double value)
{
    this->_videoWidth = value;
    this->v.set("videoWidth", value);
}

double HTMLVideoElement::getWidth() const
{
    return this->v["width"].as<double>();
}

void HTMLVideoElement::setWidth(double value)
{
    this->_width = value;
    this->v.set("width", value);
}
