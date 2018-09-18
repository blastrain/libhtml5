#pragma once

#include "node.h"

class Element;

class CharacterData : public Node {
public:

    HTML5_PROPERTY(CharacterData, std::string, data);
    HTML5_PROPERTY(CharacterData, unsigned long, length);
    HTML5_PROPERTY_OBJECT(CharacterData, Element, nextElementSibling);
    HTML5_PROPERTY_OBJECT(CharacterData, Element, previousElementSibling);

    CharacterData(emscripten::val v);
    virtual ~CharacterData();
    static CharacterData *create(emscripten::val v);
    template<typename... Args> void after(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        after(nodes);
    };
    void after(std::vector<Node *> nodes);
    void appendData(std::string data);
    template<typename... Args> void before(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        before(nodes);
    };
    void before(std::vector<Node *> nodes);
    void deleteData(unsigned long offset, unsigned long count);
    void insertData(unsigned long offset, std::string data);
    void remove();
    template<typename... Args> void replace(Node *node, Args ...args) {
        std::vector<Node *> nodes = { args... };
        nodes.insert(nodes.begin(), node);
        replace(nodes);
    };
    void replace(std::vector<Node *> nodes);
    void replaceData(unsigned long offset, unsigned long count, std::string data);
    std::string substringData(unsigned long offset, unsigned long count);
};
