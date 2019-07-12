#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class Node;
class DocumentFragment;

class Range : public Object {
public:

    enum {
        START_TO_START = 0,
        START_TO_END   = 1,
        END_TO_END     = 2,
        END_TO_START   = 3,
    };

    HTML5_PROPERTY(Range, bool, collapsed);
    HTML5_PROPERTY_OBJECT(Range, Node, commonAncestorContainer);
    HTML5_PROPERTY_OBJECT(Range, Node, endContainer);
    HTML5_PROPERTY(Range, unsigned long, endOffset);
    HTML5_PROPERTY_OBJECT(Range, Node, startContainer);
    HTML5_PROPERTY(Range, unsigned long, startOffset);

    Range(emscripten::val v);
    virtual ~Range();
    static Range *create(emscripten::val v);
    DocumentFragment *cloneContents();
    Range *cloneRange();
    void collapse(bool toStart);
    short compareBoundaryPoints(unsigned short how, Range *sourceRange);
    short comparePoint(Node *node, unsigned long offset);
    void deleteContents();
    void detach();
    DocumentFragment *extractContents();
    void insertNode(Node *node);
    bool intersectsNode(Node *node);
    bool isPointInRange(Node *node, unsigned long offset);
    void selectNode(Node *node);
    void selectNodeContents(Node *node);
    void setEnd(Node *node, unsigned long offset);
    void setEndAfter(Node *node);
    void setEndBefore(Node *node);
    void setStart(Node *node, unsigned long offset);
    void setStartAfter(Node *node);
    void setStartBefore(Node *node);
    void surroundContents(Node *newParent);
};

NAMESPACE_HTML5_END;
