#include "xml_document.h"

XMLDocument::XMLDocument(emscripten::val v) :
    Document(v)
{

}

XMLDocument::~XMLDocument()
{

}

XMLDocument *XMLDocument::create(emscripten::val v)
{
    auto doc = new XMLDocument(v);
    doc->autorelease();
    return doc;
}

bool XMLDocument::load(std::string url)
{
    return HTML5_CALLb(this->v, load, url);
}
