#pragma once

#include "event_target.h"
#include <string>
#include <emscripten/val.h>

class Document;
class Element;

class Node : public EventTarget {
public:
    std::string baseURI;
    Node *firstChild;
    Node *lastChild;
    Node *nextSibling;
    std::string nodeName;
    unsigned short nodeType;
    std::string nodeValue;
    Document *ownerDocument;
    Element *parentElement;
    Node *parentNode;
    Node *previousNode;
    std::string textContent;

    Node(emscripten::val v);
    virtual ~Node();
    static Node *create(emscripten::val v);
    Node *appendChild(Node *node);
    /*
    Node *cloneNode(bool deep = false);
    unsigned short compareDocumentPosition(Node *other);
    bool contains(Node *other);
    bool hasChildNodes();
    Node *insertBefore(Node *node, Node *child);
    bool isDefaultNamespace(std::string _namespace);
    bool isEqualNode(Node *node);
    std::string lookupNamespaceURI(std::string prefix);
    std::string lookupPrefix(std::string prefix);
    void normalize();
    Node *removeChild(Node *node);
    Node *replaceChild(Node *node, Node *child);
    */
};
