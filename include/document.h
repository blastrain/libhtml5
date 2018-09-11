#pragma once

#include "libhtml5.h"
#include "node.h"

class Element;
class HTMLElement;

class Document : public Node {
public:

    Document(emscripten::val v);
    ~Document();
    static Document *create();
    static Document *create(emscripten::val v);
    Element *createElement(std::string localName);
    HTMLElement *body();
};
