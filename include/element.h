#pragma once

#include "node.h"

class Element : public Node {
public:

    Element(emscripten::val v);
    virtual ~Element();
    void setAttribute(std::string qualifiedName, std::string value);
};
