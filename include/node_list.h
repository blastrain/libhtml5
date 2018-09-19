#pragma once

#include "object.h"

class Node;

class NodeList : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(NodeList, unsigned long, length);

    NodeList(emscripten::val v);
    virtual ~NodeList();
    static NodeList *create(emscripten::val v);
    Node *item(unsigned long index);
};
