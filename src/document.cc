#include "html_element.h"
#include "html_video_element.h"
#include "html_source_element.h"
#include "document.h"

Document::Document(emscripten::val v) :
    Node(v)
{

}

Document::~Document()
{

}

Document *Document::create()
{
    Document *doc = new Document(HTML5_STATIC_PRIMITIVE_INSTANCE(Document));
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

HTMLElement *Document::body()
{
    return HTMLElement::create(HTML5_CALLv(this->v, body));
}
