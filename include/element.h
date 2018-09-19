#pragma once

#include "node.h"

NAMESPACE_HTML5_BEGIN;

class Attr;
class HTMLCollection;
class DOMTokenList;
class NodeList;
class ShadowRoot;
class PseudoElement;

class Element : public Node {
public:

    std::vector<Attr *> _attributes;
    HTML5_PROPERTY(Element, unsigned long, childElementCount);
    HTML5_PROPERTY_OBJECT(Element, HTMLCollection, children);
    HTML5_PROPERTY(Element, std::string, className);
    HTML5_PROPERTY_OBJECT(Element, Element, firstElementChild);
    HTML5_PROPERTY(Element, std::string, id);
    HTML5_PROPERTY_OBJECT(Element, Element, lastElementChild);
    HTML5_PROPERTY(Element, std::string, localName);
    HTML5_PROPERTY(Element, std::string, namespaceURI);
    HTML5_PROPERTY_OBJECT(Element, Element, nextElementSibling);
    HTML5_PROPERTY(Element, std::string, prefix);
    HTML5_PROPERTY_OBJECT(Element, Element, previousElementSibling);
    HTML5_PROPERTY(Element, std::string, tagName);
    HTML5_PROPERTY_OBJECT(Element, ShadowRoot, shadowRoot);
    HTML5_PROPERTY_OBJECT(Element, DOMTokenList, classList);

    Element(emscripten::val v);
    virtual ~Element();
    static Element *create(emscripten::val v);
    template<typename... Args> void after(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        after(nodes);
    };
    void after(std::vector<Node *> nodes);
    template<typename... Args> void append(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        append(nodes);
    };
    void append(std::vector<Node *> nodes);
    template<typename... Args> void before(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        before(nodes);
    };
    void before(std::vector<Node *> nodes);
    ShadowRoot *createShadowRoot();
    std::string getAttribute(std::string name);
    std::string getAttributeNS(std::string _namespace, std::string localName);
    HTMLCollection *getElementsByClassName(std::string classNames);
    HTMLCollection *getElementsByTagName(std::string localName);
    HTMLCollection *getElementsByTagnameNS(std::string _namespace, std::string localName);
    bool hasAttribute(std::string name);
    bool hasAttributeNS(std::string _namespace, std::string localName);
    bool matches(std::string selectors);
    template<typename... Args> void prepend(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        prepend(nodes);
    };
    void prepend(std::vector<Node *> nodes);
    PseudoElement *pseudo(std::string pseudoElt);
    Element *query(std::string relativeSelectors);
    std::vector<Element *> queryAll(std::string relativeSelectors);
    Element *querySelector(std::string selectors);
    NodeList *querySelectorAll(std::string selectors);
    void remove();
    void removeAttribute(std::string name);
    void removeAttributeNS(std::string _namespace, std::string localName);
    template<typename... Args> void replace(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        replace(nodes);
    };
    void replace(std::vector<Node *> nodes);
    void requestFullscreen();
    void requestPointerLock();
    void setAttribute(std::string qualifiedName, std::string value);
    void setAttributeNS(std::string _namespace, std::string name, std::string value);

    struct {
        Element &self;
        void operator=(std::vector<Attr *> value) { self.setAttributes(value); };
        operator std::vector<Attr *>() { return self.getAttributes(); };
    } attributes{*this};

private:
    std::vector<Attr *> getAttributes() const;
    void setAttributes(std::vector<Attr *> value);
};

NAMESPACE_HTML5_END;
