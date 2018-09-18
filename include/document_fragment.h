#pragma once

#include "node.h"

class HTMLCollection;
class Element;
class NodeList;

class DocumentFragment : public Node {
public:

    HTML5_PROPERTY(DocumentFragment, unsigned long, childElementCount);
    HTML5_PROPERTY_OBJECT(DocumentFragment, HTMLCollection, children);
    HTML5_PROPERTY_OBJECT(DocumentFragment, Element, firstElementChild);
    HTML5_PROPERTY_OBJECT(DocumentFragment, Element, lastElementChild);

    DocumentFragment(emscripten::val v);
    virtual ~DocumentFragment();
    static DocumentFragment *create(emscripten::val v);
    template<typename... Args> void append(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        append(nodes);
    };
    void append(std::vector<Node *> nodes);
    Element *getElementById(std::string elementId);
    template<typename... Args> void prepend(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        prepend(nodes);
    };
    void prepend(std::vector<Node *> nodes);
    Element *query(std::string relativeSelectors);
    std::vector<Element *> queryAll(std::string relativeSelectors);
    Element *querySelector(std::string selectors);
    NodeList *querySelectorAll(std::string selectors);
};
