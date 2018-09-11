#pragma once

#include "libhtml5.h"
#include "node.h"

class Element;
class HTMLElement;

class Document : public Node {
public:
    HTMLElement *_body;

    Document(emscripten::val v);
    ~Document();
    static Document *create();
    static Document *create(emscripten::val v);
    Element *createElement(std::string localName);

    HTMLElement *getBody() const;
    void setBody(HTMLElement *value);

    struct {
        Document &self;
        void operator=(HTMLElement *value) { self.setBody(value); };
        operator HTMLElement *() { return self.getBody(); };
        HTMLElement *operator->() { return self.getBody(); };
    } body{*this};
};
