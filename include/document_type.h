#pragma once

#include "libhtml5.h"

class Node;

class DocumentType : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(DocumentType, std::string, name);
    HTML5_PROPERTY(DocumentType, std::string, publicId);
    HTML5_PROPERTY(DocumentType, std::string, systemId);

    DocumentType(emscripten::val v);
    virtual ~DocumentType();
    static DocumentType *create(emscripten::val v);
    template<typename... Args> void after(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        after(nodes);
    };
    void after(std::vector<Node *> nodes);
    template<typename... Args> void before(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        before(nodes);
    };
    void before(std::vector<Node *> nodes);
    template<typename... Args> void replace(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        replace(nodes);
    };
    void replace(std::vector<Node *> nodes);
    void remove();
};
