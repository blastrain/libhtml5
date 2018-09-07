#pragma once

#include "event_target.h"
#include <string>
#include <emscripten/val.h>

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
    std::string _baseURI;
    std::vector<Node *> _childNodes;
    Node *_firstChild;
    Node *_lastChild;
    Node *_nextSibling;
    std::string _nodeName;
    unsigned short _nodeType;
    std::string _nodeValue;
    Document *_ownerDocument;
    Element *_parentElement;
    Node *_parentNode;
    Node *_previousNode;
    Node *_previousSibling;
    std::string _textContent;

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
        void operator=(std::string value) { self.setBaseURI(value); };
        operator std::string() { return self.getBaseURI(); };
    } baseURI{*this};
    struct {
        Node &self;
        void operator=(std::vector<Node *> value) { self.setChildNodes(value); };
        operator std::vector<Node *>() { return self.getChildNodes(); };
    } childNodes{*this};
    struct {
        Node &self;
        void operator=(Node *value) { self.setFirstChild(value); };
        operator Node *() { return self.getFirstChild(); };
    } firstChild{*this};
    struct {
        Node &self;
        void operator=(Node *value) { self.setLastChild(value); };
        operator Node *() { return self.getLastChild(); };
    } lastChild{*this};
    struct {
        Node &self;
        void operator=(Node *value) { self.setNextSibling(value); };
        operator Node *() { return self.getNextSibling(); };
    } nextSibling{*this};
    struct {
        Node &self;
        void operator=(std::string value) { self.setNodeName(value); };
        operator std::string() { return self.getNodeName(); };
    } nodeName{*this};
    struct {
        Node &self;
        void operator=(unsigned short value) { self.setNodeType(value); };
        operator unsigned short() { return self.getNodeType(); };
    } nodeType{*this};
    struct {
        Node &self;
        void operator=(std::string value) { self.setNodeValue(value); };
        operator std::string() { return self.getNodeValue(); };
    } nodeValue{*this};
    struct {
        Node &self;
        void operator=(Document *value) { self.setOwnerDocument(value); };
        operator Document *() { return self.getOwnerDocument(); };
    } ownerDocument{*this};
    struct {
        Node &self;
        void operator=(Element *value) { self.setParentElement(value); };
        operator Element *() { return self.getParentElement(); };
    } parentElement{*this};
    struct {
        Node &self;
        void operator=(Node *value) { self.setParentNode(value); };
        operator Node *() { return self.getParentNode(); };
    } parentNode{*this};
    struct {
        Node &self;
        void operator=(Node *value) { self.setPreviousNode(value); };
        operator Node *() { return self.getPreviousNode(); };
    } previousNode{*this};
    struct {
        Node &self;
        void operator=(Node *value) { self.setPreviousSibling(value); };
        operator Node *() { return self.getPreviousSibling(); };
    } previousSibling{*this};
    struct {
        Node &self;
        void operator=(std::string value) { self.setTextContent(value); };
        operator std::string() { return self.getTextContent(); };
    } textContent{*this};

private:
    std::string getBaseURI() const;
    void setBaseURI(std::string value);
    std::vector<Node *> getChildNodes() const;
    void setChildNodes(std::vector<Node *> value);
    Node *getFirstChild() const;
    void setFirstChild(Node *value);
    Node *getLastChild() const;
    void setLastChild(Node *value);
    Node *getNextSibling() const;
    void setNextSibling(Node *value);
    std::string getNodeName() const;
    void setNodeName(std::string value);
    unsigned short getNodeType() const;
    void setNodeType(unsigned short value);
    std::string getNodeValue() const;
    void setNodeValue(std::string value);
    Document *getOwnerDocument() const;
    void setOwnerDocument(Document *value);
    Element *getParentElement() const;
    void setParentElement(Element *value);
    Node *getParentNode() const;
    void setParentNode(Node *value);
    Node *getPreviousNode() const;
    void setPreviousNode(Node *value);
    Node *getPreviousSibling() const;
    void setPreviousSibling(Node *value);
    std::string getTextContent() const;
    void setTextContent(std::string value);
};
