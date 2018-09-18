#include "node.h"
#include "node_filter.h"
#include "tree_walker.h"

TreeWalker::TreeWalker(emscripten::val v) :
    Object(),
    v(v)
{

}

TreeWalker::~TreeWalker()
{

}

TreeWalker *TreeWalker::create(emscripten::val v)
{
    auto walker = new TreeWalker(v);
    walker->autorelease();
    return walker;
}

Node *TreeWalker::firstChild()
{
    return Node::create(HTML5_CALLv(this->v, firstChild));
}

Node *TreeWalker::lastChild()
{
    return Node::create(HTML5_CALLv(this->v, lastChild));
}

Node *TreeWalker::nextNode()
{
    return Node::create(HTML5_CALLv(this->v, nextNode));
}

Node *TreeWalker::nextSibling()
{
    return Node::create(HTML5_CALLv(this->v, nextSibling));
}

Node *TreeWalker::parentNode()
{
    return Node::create(HTML5_CALLv(this->v, parentNode));
}

Node *TreeWalker::previousNode()
{
    return Node::create(HTML5_CALLv(this->v, previousNode));
}

Node *TreeWalker::previousSibling()
{
    return Node::create(HTML5_CALLv(this->v, previousSibling));
}

HTML5_PROPERTY_OBJECT_IMPL(TreeWalker, Node, currentNode);
HTML5_PROPERTY_OBJECT_IMPL(TreeWalker, NodeFilter, filter);
HTML5_PROPERTY_OBJECT_IMPL(TreeWalker, Node, root);
HTML5_PROPERTY_IMPL(TreeWalker, unsigned long, whatToShow);
