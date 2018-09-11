#include "html_image_element.h"
#include <iostream>

HTMLImageElement::HTMLImageElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLImageElement::~HTMLImageElement()
{

}

HTMLImageElement *HTMLImageElement::create()
{
    HTMLImageElement *image = new HTMLImageElement(HTML5_NEW_PRIMITIVE_INSTANCE(Image));
    image->autorelease();
    return image;
}

HTMLImageElement *HTMLImageElement::create(emscripten::val v)
{
    HTMLImageElement *image = new HTMLImageElement(v);
    image->autorelease();
    return image;
}

HTMLImageElement *HTMLImageElement::create(unsigned long width, unsigned long height)
{
    auto image = new HTMLImageElement(HTML5_NEW_PRIMITIVE_INSTANCE("Image", width, height));
    image->autorelease();
    return image;
}

std::string HTMLImageElement::getAlt() const
{
    return HTML5_PROPERTY_GET(alt, std::string);
}

void HTMLImageElement::setAlt(std::string value)
{
    this->_alt = value;
    this->v.set("alt", value);
}

bool HTMLImageElement::getComplete() const
{
    return HTML5_PROPERTY_GET(complete, bool);
}

void HTMLImageElement::setComplete(bool value)
{
    this->_complete = value;
    this->v.set("complete", value);
}

std::string HTMLImageElement::getCrossOrigin() const
{
    return HTML5_PROPERTY_GET(crossOrigin, std::string);
}

void HTMLImageElement::setCrossOrigin(std::string value)
{
    this->_crossOrigin = value;
    this->v.set("crossOrigin", value);
}

unsigned long HTMLImageElement::getHeight() const
{
    return HTML5_PROPERTY_GET(height, unsigned long);
}

void HTMLImageElement::setHeight(unsigned long value)
{
    this->_height = value;
    this->v.set("height", value);
}

bool HTMLImageElement::getIsMap() const
{
    return HTML5_PROPERTY_GET(isMap, bool);
}

void HTMLImageElement::setIsMap(bool value)
{
    this->_isMap = value;
    this->v.set("isMap", value);
}

unsigned long HTMLImageElement::getNaturalHeight() const
{
    return HTML5_PROPERTY_GET(naturalHeight, unsigned long);
}

void HTMLImageElement::setNaturalHeight(unsigned long value)
{
    this->_naturalHeight = value;
    this->v.set("naturalHeight", value);
}

unsigned long HTMLImageElement::getNaturalWidth() const
{
    return HTML5_PROPERTY_GET(naturalWidth, unsigned long);
}

void HTMLImageElement::setNaturalWidth(unsigned long value)
{
    this->_naturalWidth = value;
    this->v.set("naturalWidth", value);
}

std::string HTMLImageElement::getSrc() const
{
    return HTML5_PROPERTY_GET(src, std::string);
}

void HTMLImageElement::setSrc(std::string value)
{
    this->_src = value;
    this->v.set("src", value);
}

std::string HTMLImageElement::getSrcSet() const
{
    return HTML5_PROPERTY_GET(srcset, std::string);
}

void HTMLImageElement::setSrcSet(std::string value)
{
    this->_srcset = value;
    this->v.set("srcset", value);
}

std::string HTMLImageElement::getUseMap() const
{
    return HTML5_PROPERTY_GET(useMap, std::string);
}

void HTMLImageElement::setUseMap(std::string value)
{
    this->_useMap = value;
    this->v.set("useMap", value);
}

unsigned long HTMLImageElement::getWidth() const
{
    return HTML5_PROPERTY_GET(width, unsigned long);
}

void HTMLImageElement::setWidth(unsigned long value)
{
    this->_width = value;
    this->v.set("width", value);
}
