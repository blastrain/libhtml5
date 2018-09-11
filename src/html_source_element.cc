#include "document.h"
#include "html_source_element.h"

HTMLSourceElement::HTMLSourceElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLSourceElement::~HTMLSourceElement()
{

}

HTMLSourceElement *HTMLSourceElement::create(emscripten::val v)
{
    HTMLSourceElement *source = new HTMLSourceElement(v);
    source->autorelease();
    return source;
}

HTMLSourceElement *HTMLSourceElement::create()
{
    return dynamic_cast<HTMLSourceElement *>(Document::create()->createElement("source"));
}

std::string HTMLSourceElement::getSrc()
{
    return HTML5_PROPERTY_GET(src, std::string);
}

void HTMLSourceElement::setSrc(std::string value)
{
    this->_src = value;
    this->v.set("src", value);
}

std::string HTMLSourceElement::getType()
{
    return HTML5_PROPERTY_GET(type, std::string);
}

void HTMLSourceElement::setType(std::string value)
{
    this->_type = value;
    this->v.set("type", value);
}
