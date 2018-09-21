#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class Node;

class NodeFilter : public Object {
public:

    enum {
        FILTER_ACCEPT = 1,
        FILTER_REJECT = 2,
        FILTER_SKIP   = 3,
        SHOW_ALL = 0xFFFFFFFF,
        SHOW_ATTRIBUTE = 0x2,
        SHOW_CDATA_SECTION = 0x8,
        SHOW_COMMENT = 0x80,
        SHOW_DOCUMENT = 0x100,
        SHOW_DOCUMENT_FRAGMENT = 0x400,
        SHOW_DOCUMENT_TYPE = 0x200,
        SHOW_ELEMENT = 0x1,
        SHOW_ENTITY = 0x20,
        SHOW_ENTITY_REFERENCE = 0x10,
        SHOW_NOTATION = 0x800,
        SHOW_PROCESSING_INSTRUCTION = 0x40,
        SHOW_TEXT = 0x4,
    };

    NodeFilter(emscripten::val v);
    virtual ~NodeFilter();
    static NodeFilter *create(emscripten::val v);
    unsigned short acceptNode(Node *node);
};

NAMESPACE_HTML5_END;
