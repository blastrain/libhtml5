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
    NodeList *nl = new NodeList(v);
    nl->autorelease();
    return nl;
}

Node *NodeList::item(unsigned long index)
{
    return Node::create(HTML5_CALLv(this->v, item, index));
}

unsigned long NodeList::getLength()
{
    return HTML5_PROPERTY_GET(length, unsigned long);
}

void NodeList::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}

