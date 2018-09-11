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
    return dynamic_cast<HTMLSourceElement *>(Document::createElement("source"));
}

std::string HTMLSourceElement::getSrc()
{
    return this->v["src"].as<std::string>();
}

void HTMLSourceElement::setSrc(std::string value)
{
    this->_src = value;
    this->v.set("src", emscripten::val(value));
}

std::string HTMLSourceElement::getType()
{
    return this->v["type"].as<std::string>();
}

void HTMLSourceElement::setType(std::string value)
{
    this->_type = value;
    this->v.set("type", emscripten::val(value));
}
