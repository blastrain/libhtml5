#pragma once

#include "node.h"

class Attr;
class HTMLCollection;
class DOMTokenList;
class NodeList;
class ShadowRoot;
class PseudoElement;

class Element : public Node {
public:
    std::vector<Attr *> _attributes;
    unsigned long _childElementCount;
    HTMLCollection *_children;
    std::string _className;
    Element *_firstElementChild;
    std::string _id;
    Element *_lastElementChild;
    std::string _localName;
    std::string _namespaceURI;
    Element *_nextElementSibling;
    std::string _prefix;
    Element *_previousElementSibling;
    std::string _tagName;
    ShadowRoot *_shadowRoot;
    DOMTokenList *_classList;

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

    struct {
        Element &self;
        void operator=(unsigned long value) { self.setChildElementCount(value); };
        operator unsigned long() { return self.getChildElementCount(); };
    } childElementCount{*this};

    struct {
        Element &self;
        void operator=(HTMLCollection *value) { self.setChildren(value); };
        operator HTMLCollection *() { return self.getChildren(); };
    } children{*this};

    struct {
        Element &self;
        void operator=(std::string value) { self.setClassName(value); };
        operator std::string () { return self.getClassName(); };
    } className{*this};

    struct {
        Element &self;
        void operator=(Element *value) { self.setFirstElementChild(value); };
        operator Element *() { return self.getFirstElementChild(); };
    } firstElementChild{*this};

    struct {
        Element &self;
        void operator=(std::string value) { self.setId(value); };
        operator std::string() { return self.getId(); };
    } id{*this};

    struct {
        Element &self;
        void operator=(Element *value) { self.setLastElementChild(value); };
        operator Element *() { return self.getLastElementChild(); };
    } lastElementChild{*this};

    struct {
        Element &self;
        void operator=(std::string value) { self.setLocalName(value); };
        operator std::string() { return self.getLocalName(); };
    } localName{*this};

    struct {
        Element &self;
        void operator=(std::string value) { self.setNamespaceURI(value); };
        operator std::string() { return self.getNamespaceURI(); };
    } namespaceURI{*this};

    struct {
        Element &self;
        void operator=(Element *value) { self.setNextElementSibling(value); };
        operator Element *() { return self.getNextElementSibling(); };
    } nextElementSibling{*this};

    struct {
        Element &self;
        void operator=(std::string value) { self.setPrefix(value); };
        operator std::string() { return self.getPrefix(); };
    } prefix{*this};

    struct {
        Element &self;
        void operator=(Element *value) { self.setPreviousElementSibling(value); };
        operator Element *() { return self.getPreviousElementSibling(); };
    } previousElementSibling{*this};

    struct {
        Element &self;
        void operator=(std::string value) { self.setTagName(value); };
        operator std::string() { return self.getTagName(); };
    } tagName{*this};

    struct {
        Element &self;
        void operator=(ShadowRoot *value) { self.setShadowRoot(value); };
        operator ShadowRoot *() { return self.getShadowRoot(); };
    } shadowRoot{*this};

    struct {
        Element &self;
        void operator=(DOMTokenList *value) { self.setClassList(value); };
        operator DOMTokenList *() { return self.getClassList(); };
    } classList{*this};

private:
    std::vector<Attr *> getAttributes() const;
    void setAttributes(std::vector<Attr *> value);
    unsigned long getChildElementCount() const;
    void setChildElementCount(unsigned long value);
    HTMLCollection *getChildren() const;
    void setChildren(HTMLCollection *value);
    std::string getClassName() const;
    void setClassName(std::string value);
    Element *getFirstElementChild() const;
    void setFirstElementChild(Element *value);
    std::string getId() const;
    void setId(std::string value);
    Element *getLastElementChild() const;
    void setLastElementChild(Element *value);
    std::string getLocalName() const;
    void setLocalName(std::string value);
    std::string getNamespaceURI() const;
    void setNamespaceURI(std::string value);
    Element *getNextElementSibling() const;
    void setNextElementSibling(Element *value);
    std::string getPrefix() const;
    void setPrefix(std::string value);
    Element *getPreviousElementSibling() const;
    void setPreviousElementSibling(Element *value);
    std::string getTagName() const;
    void setTagName(std::string value);
    ShadowRoot *getShadowRoot() const;
    void setShadowRoot(ShadowRoot *value);
    DOMTokenList *getClassList() const;
    void setClassList(DOMTokenList *value);
};
