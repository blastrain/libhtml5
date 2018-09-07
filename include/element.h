#pragma once

#include "node.h"

class Element : public Node {
public:

    Element(emscripten::val v);
    virtual ~Element();
    static Element *create(emscripten::val v);
    void setAttribute(std::string qualifiedName, std::string value);
};
