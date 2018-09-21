#pragma once

#include "object.h"

NAMESPACE_HTML5_BEGIN;

class Node;

class NodeList : public Object {
public:

    HTML5_PROPERTY(NodeList, unsigned long, length);

    NodeList(emscripten::val v);
    virtual ~NodeList();
    static NodeList *create(emscripten::val v);
    Node *item(unsigned long index);
};

NAMESPACE_HTML5_END;
