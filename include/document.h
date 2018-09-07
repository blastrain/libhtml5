#pragma once

#include "node.h"
#include <string>

class Element;
class HTMLElement;

class Document : public Node {
public:

    Document();
    ~Document();

    static Element *createElement(std::string localName);
    static HTMLElement *body();

private:
    static emscripten::val _document();
};
