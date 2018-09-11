#include "html_element.h"
#include "html_video_element.h"
#include "html_source_element.h"
#include "document.h"
#include <iostream>

Document::Document(emscripten::val v) :
    Node(v)
{

}

Document::~Document()
{

}

Document *Document::create()
{
    Document *doc = new Document(HTML5_STATIC_PRIMITIVE_INSTANCE(document));
    doc->autorelease();
    return doc;
}

Document *Document::create(emscripten::val v)
{
    Document *doc = new Document(v);
    doc->autorelease();
    return doc;
}

Element *Document::createElement(std::string localName)
{
    return Element::create(HTML5_CALLv(this->v, createElement, localName));
}

HTMLElement *Document::getBody() const
{
    return HTML5_PROPERTY_GET(body, HTMLElement);
}

void Document::setBody(HTMLElement *value)
{
    this->_body = value;
    this->v.set("body", value->v);
}
