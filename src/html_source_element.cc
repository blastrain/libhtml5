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

HTML5_PROPERTY_IMPL(HTMLSourceElement, std::string, src);
HTML5_PROPERTY_IMPL(HTMLSourceElement, std::string, type);
