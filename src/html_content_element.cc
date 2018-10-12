#include "html_content_element.h"
#include "node_list.h"

USING_NAMESPACE_HTML5;

HTMLContentElement::HTMLContentElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLContentElement::~HTMLContentElement()
{

}

HTMLContentElement *HTMLContentElement::create(emscripten::val v)
{
    HTMLContentElement *content = new HTMLContentElement(v);
    content->autorelease();
    return content;
}

NodeList *HTMLContentElement::getDistributedNodes()
{
    return NodeList::create(HTML5_CALLv(this->v, getDistributedNodes));
}

HTML5_PROPERTY_IMPL(HTMLContentElement, bool, resetStyleInheritance);
HTML5_PROPERTY_IMPL(HTMLContentElement, std::string, select);
