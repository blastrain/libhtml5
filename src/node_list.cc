#include "node.h"
#include "node_list.h"

USING_NAMESPACE_HTML5;

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

HTML5_PROPERTY_IMPL(NodeList, unsigned long, length);
