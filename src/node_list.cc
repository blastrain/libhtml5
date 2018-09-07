#include "node.h"
#include "node_list.h"

NodeList::NodeList(emscripten::val v) : v(v)
{

}

NodeList::~NodeList()
{


}

NodeList *NodeList::create(emscripten::val v)
{
    return new NodeList(v);
}

Node *NodeList::item(unsigned long index)
{
    return Node::create(this->v.call<emscripten::val>("item", index));
}

unsigned long NodeList::getLength()
{
    return this->v["length"].as<unsigned long>();
}

void NodeList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}

