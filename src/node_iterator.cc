#include "node.h"
#include "node_filter.h"
#include "node_iterator.h"

USING_NAMESPACE_HTML5;

NodeIterator::NodeIterator(emscripten::val v) :
    Object(),
    v(v)
{

}

NodeIterator::~NodeIterator()
{

}

NodeIterator *NodeIterator::create(emscripten::val v)
{
    auto iter = new NodeIterator(v);
    iter->autorelease();
    return iter;
}

void NodeIterator::detach()
{
    HTML5_CALL(this->v, detach);
}

Node *NodeIterator::nextNode()
{
    return Node::create(HTML5_CALLv(this->v, nextNode));
}

Node *NodeIterator::previousNode()
{
    return Node::create(HTML5_CALLv(this->v, previousNode));
}

HTML5_PROPERTY_OBJECT_IMPL(NodeIterator, NodeFilter, filter);
HTML5_PROPERTY_IMPL(NodeIterator, bool, pointerBeforeReferenceNode);
HTML5_PROPERTY_OBJECT_IMPL(NodeIterator, Node, referenceNode);
HTML5_PROPERTY_OBJECT_IMPL(NodeIterator, Node, root);
HTML5_PROPERTY_IMPL(NodeIterator, unsigned long, whatsToShow);
