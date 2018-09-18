#include "element.h"
#include "node_list.h"
#include "html_collection.h"
#include "document_fragment.h"

DocumentFragment::DocumentFragment(emscripten::val v) :
    Node(v)
{

}

DocumentFragment::~DocumentFragment()
{

}

DocumentFragment *DocumentFragment::create(emscripten::val v)
{
    auto frag = new DocumentFragment(v);
    frag->autorelease();
    return frag;
}

void DocumentFragment::append(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, append, node->v);
    }
}

Element *DocumentFragment::getElementById(std::string elementId)
{
    return Element::create(HTML5_CALLv(this->v, getElementById, elementId));
}

void DocumentFragment::prepend(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, prepend, node->v);
    }
}

Element *DocumentFragment::query(std::string relativeSelectors)
{
    return Element::create(HTML5_CALLv(this->v, query, relativeSelectors));
}

std::vector<Element *> DocumentFragment::queryAll(std::string relativeSelectors)
{
    return toObjectArray<Element>(HTML5_CALLv(this->v, queryAll, relativeSelectors));
}

Element *DocumentFragment::querySelector(std::string selectors)
{
    return Element::create(HTML5_CALLv(this->v, querySelector, selectors));
}

NodeList *DocumentFragment::querySelectorAll(std::string selectors)
{
    return NodeList::create(HTML5_CALLv(this->v, querySelectorAll, selectors));
}

HTML5_PROPERTY_IMPL(DocumentFragment, unsigned long, childElementCount);
HTML5_PROPERTY_OBJECT_IMPL(DocumentFragment, HTMLCollection, children);
HTML5_PROPERTY_OBJECT_IMPL(DocumentFragment, Element, firstElementChild);
HTML5_PROPERTY_OBJECT_IMPL(DocumentFragment, Element, lastElementChild);
