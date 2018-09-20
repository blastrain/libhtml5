#include "node.h"
#include "document_fragment.h"
#include "range.h"

USING_NAMESPACE_HTML5;

Range::Range(emscripten::val v) :
    Object(v)
{

}

Range::~Range()
{

}

Range *Range::create(emscripten::val v)
{
    auto range = new Range(v);
    range->autorelease();
    return range;
}

DocumentFragment *Range::cloneContents()
{
    return DocumentFragment::create(HTML5_CALLv(this->v, cloneContents));
}

Range *Range::cloneRange()
{
    return Range::create(HTML5_CALLv(this->v, cloneRange));
}

void Range::collapse(bool toStart)
{
    HTML5_CALL(this->v, collapse, toStart);
}

short Range::compareBoundaryPoints(unsigned short how, Range *sourceRange)
{
    return HTML5_CALLi(this->v, compareBoundaryPoints, short, how, sourceRange->v);
}

short Range::comparePoint(Node *node, unsigned long offset)
{
    return HTML5_CALLi(this->v, comparePoint, short, node->v, offset);
}

void Range::deleteContents()
{
    HTML5_CALL(this->v, deleteContents);
}

void Range::detach()
{
    HTML5_CALL(this->v, detach);
}

DocumentFragment *Range::extractContents()
{
    return DocumentFragment::create(HTML5_CALLv(this->v, extractContents));
}

void Range::insertNode(Node *node)
{
    HTML5_CALL(this->v, insertNode, node->v);
}

bool Range::intersectsNode(Node *node)
{
    return HTML5_CALLb(this->v, intersectsNode, node->v);
}

bool Range::isPointInRange(Node *node, unsigned long offset)
{
    return HTML5_CALLb(this->v, isPointInRange, node->v, offset);
}

void Range::selectNode(Node *node)
{
    HTML5_CALL(this->v, selectNode, node->v);
}

void Range::selectNodeContents(Node *node)
{
    HTML5_CALL(this->v, selectNodeContents, node->v);
}

void Range::setEnd(Node *node, unsigned long offset)
{
    HTML5_CALL(this->v, setEnd, node->v, offset);
}

void Range::setEndAfter(Node *node)
{
    HTML5_CALL(this->v, setEndAfter, node->v);
}

void Range::setEndBefore(Node *node)
{
    HTML5_CALL(this->v, setEndBefore, node->v);
}

void Range::setStart(Node *node, unsigned long offset)
{
    HTML5_CALL(this->v, setStart, node->v, offset);
}

void Range::setStartAfter(Node *node)
{
    HTML5_CALL(this->v, setStartAfter, node->v);
}

void Range::setStartBefore(Node *node)
{
    HTML5_CALL(this->v, setStartBefore, node->v);
}

void Range::surroundContents(Node *newParent)
{
    HTML5_CALL(this->v, surroundContents, newParent->v);
}

HTML5_PROPERTY_IMPL(Range, bool, collapsed);
HTML5_PROPERTY_OBJECT_IMPL(Range, Node, commonAncestorContainer);
HTML5_PROPERTY_OBJECT_IMPL(Range, Node, endContainer);
HTML5_PROPERTY_IMPL(Range, unsigned long, endOffset);
HTML5_PROPERTY_OBJECT_IMPL(Range, Node, startContainer);
HTML5_PROPERTY_IMPL(Range, unsigned long, startOffset);
