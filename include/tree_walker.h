#pragma once

#include "libhtml5.h"

class Node;
class NodeFilter;

class TreeWalker : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY_OBJECT(TreeWalker, Node, currentNode);
    HTML5_PROPERTY_OBJECT(TreeWalker, NodeFilter, filter);
    HTML5_PROPERTY_OBJECT(TreeWalker, Node, root);
    HTML5_PROPERTY(TreeWalker, unsigned long, whatToShow);

    TreeWalker(emscripten::val v);
    virtual ~TreeWalker();
    static TreeWalker *create(emscripten::val v);
    Node *firstChild();
    Node *lastChild();
    Node *nextNode();
    Node *nextSibling();
    Node *parentNode();
    Node *previousNode();
    Node *previousSibling();
};
