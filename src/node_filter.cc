#include "node.h"
#include "node_filter.h"

NodeFilter::NodeFilter(emscripten::val v) :
    Object(),
    v(v)
{

}

NodeFilter::~NodeFilter()
{

}

NodeFilter *NodeFilter::create(emscripten::val v)
{
    auto filter = new NodeFilter(v);
    filter->autorelease();
    return filter;
}

unsigned short NodeFilter::acceptNode(Node *node)
{
    return HTML5_CALLi(this->v, acceptNode, unsigned short, node->v);
}
