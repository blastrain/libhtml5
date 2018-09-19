#pragma once

#include "libhtml5.h"
#include "event_target.h"

class Document;
class Element;

class Node : public EventTarget {
public:
    enum {
        ELEMENT_NODE                = 1,
        ATTIBUTE_NODE               = 2,
        TEXT_NODE                   = 3,
        CDATA_SECTION_NODE          = 4,
        ENTITY_REFERENCE_NODE       = 5,
        ENTITY_NODE                 = 6,
        PROCESSING_INSTRUCTION_NODE = 7,
        COMMENT_NODE                = 8,
        DOCUMENT_NODE               = 9,
        DOCUMENT_TYPE_NODE          = 10,
        DOCUMENT_FRAGMENT_NODE      = 11,
        NOTATION_NODE               = 12,
        DOCUMENT_POSITION_DISCONNECTED = 0x01,
        DOCUMENT_POSITION_PRECEDING    = 0x02,
        DOCUMENT_POSITION_FOLLOWING    = 0x04,
        DOCUMENT_POSITION_CONTAINS     = 0x08,
        DOCUMENT_POSITION_CONTAINED_BY = 0x10,
        DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x20,
    };

    HTML5_PROPERTY(Node, std::string, baseURI);
    std::vector<Node *> _childNodes;
    HTML5_PROPERTY_OBJECT(Node, Node, firstChild);
    HTML5_PROPERTY_OBJECT(Node, Node, lastChild);
    HTML5_PROPERTY_OBJECT(Node, Node, nextSibling);
    HTML5_PROPERTY(Node, std::string, nodeName);
    HTML5_PROPERTY(Node, unsigned short, nodeType);
    HTML5_PROPERTY(Node, std::string, nodeValue);
    HTML5_PROPERTY_OBJECT(Node, Document, ownerDocument);
    HTML5_PROPERTY_OBJECT(Node, Element, parentElement);
    HTML5_PROPERTY_OBJECT(Node, Node, parentNode);
    HTML5_PROPERTY_OBJECT(Node, Node, previousNode);
    HTML5_PROPERTY_OBJECT(Node, Node, previousSibling);
    HTML5_PROPERTY(Node, std::string, textContent);

    Node(emscripten::val v);
    virtual ~Node();
    static Node *create(emscripten::val v);
    Node *appendChild(Node *node);
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

    struct {
        Node &self;
        void operator=(std::vector<Node *> value) { self.setChildNodes(value); };
        operator std::vector<Node *>() { return self.getChildNodes(); };
    } childNodes{*this};

private:
    std::vector<Node *> getChildNodes() const;
    void setChildNodes(std::vector<Node *> value);
};
