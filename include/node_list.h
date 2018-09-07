#pragma once

class Node;

class NodeList {
public:
    emscripten::val v;
    unsigned long _length;

    NodeList(emscripten::val v);
    virtual ~NodeList();
    static NodeList *create(emscripten::val v);
    Node *item(unsigned long index);

    struct {
        NodeList &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};

private:
    unsigned long getLength();
    void setLength(unsigned long value);
};
