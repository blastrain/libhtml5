#include "node.h"

Node::Node(emscripten::val v) :
    EventTarget(v)
{

}

Node::~Node()
{

}

Node *Node::create(emscripten::val v)
{
    Node *node = new Node(v);
    return node;
}

Node *Node::appendChild(Node *node)
{
    return Node::create(this->v.call<emscripten::val>("appendChild", node->v));
}
