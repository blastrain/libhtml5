#include "attr.h"
#include "dom_token_list.h"
#include "html_collection.h"
#include "node_list.h"
#include "element.h"
#include "html_element.h"
#include "html_image_element.h"
#include "html_video_element.h"
#include "html_source_element.h"
#include <iostream>

static std::map<std::string, std::function<Element*(emscripten::val)>> classFactories = {
    CLASS_FACTORY_MAP(HTMLElement),
    CLASS_FACTORY_MAP(HTMLImageElement),
    CLASS_FACTORY_MAP(HTMLSourceElement),
    CLASS_FACTORY_MAP(HTMLVideoElement),
};

Element::Element(emscripten::val v) :
    Node(v)
{
}

Element::~Element()
{

}

Element *Element::create(emscripten::val v)
{
#if ENABLE_EMSCRIPTEN
    std::string className = v["constructor"]["name"].as<std::string>();
    return classFactories[className](v);
#else
    Element *e = new Element(v);
    e->autorelease();
    return e;
#endif
}

void Element::after(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, after, node->v);
    }
}

void Element::append(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, append, node->v);
    }
}

void Element::before(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, before, node->v);
    }
}

std::string Element::getAttribute(std::string name)
{
    return HTML5_CALLs(this->v, getAttribute, name);
}

std::string Element::getAttributeNS(std::string _namespace, std::string localName)
{
    return HTML5_CALLs(this->v, getAttributeNS, _namespace, localName);
}

HTMLCollection *Element::getElementsByClassName(std::string classNames)
{
    return HTMLCollection::create(HTML5_CALLv(this->v, getElementsByClassName, classNames));
}

HTMLCollection *Element::getElementsByTagName(std::string localName)
{
    return HTMLCollection::create(HTML5_CALLv(this->v, getElementsByTagName, localName));
}

HTMLCollection *Element::getElementsByTagnameNS(std::string _namespace, std::string localName)
{
    return HTMLCollection::create(HTML5_CALLv(this->v, getElementsByTagNameNS, _namespace, localName));
}

bool Element::hasAttribute(std::string name)
{
    return HTML5_CALLb(this->v, hasAttribute, name);
}

bool Element::hasAttributeNS(std::string _namespace, std::string localName)
{
    return HTML5_CALLb(this->v, hasAttributeNS, _namespace, localName);
}

bool Element::matches(std::string selectors)
{
    return HTML5_CALLb(this->v, matches, selectors);
}

void Element::prepend(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, prepend, node->v);
    }
}

Element *Element::query(std::string relativeSelectors)
{
    return Element::create(HTML5_CALLv(this->v, query, relativeSelectors));
}

std::vector<Element *> Element::queryAll(std::string relativeSelectors)
{
    emscripten::val arr = HTML5_CALLv(this->v, queryAll, relativeSelectors);
    std::vector<Element *> ret;
#if ENABLE_EMSCRIPTEN
    std::vector<emscripten::val> elems = emscripten::vecFromJSArray<emscripten::val>(arr);
    for (emscripten::val &elem : elems) {
        ret.push_back(Element::create(elem));
    }
#endif
    return ret;
}

Element *Element::querySelector(std::string selectors)
{
    return Element::create(HTML5_CALLv(this->v, querySelector, selectors));
}

NodeList *Element::querySelectorAll(std::string selectors)
{
    return NodeList::create(HTML5_CALLv(this->v, querySelectorAll, selectors));
}

void Element::remove()
{
    HTML5_CALL(this->v, remove);
}

void Element::removeAttribute(std::string name)
{
    HTML5_CALL(this->v, removeAttribute, name);
}

void Element::removeAttributeNS(std::string _namespace, std::string localName)
{
    HTML5_CALL(this->v, removeAttributeNS, _namespace, localName);
}

void Element::replace(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        HTML5_CALL(this->v, replace, node->v);
    }
}

void Element::requestFullscreen()
{
    HTML5_CALL(this->v, requestFullscreen);
}

void Element::requestPointerLock()
{
    HTML5_CALL(this->v, requestPointerLock);
}

void Element::setAttribute(std::string qualifiedName, std::string value)
{
    HTML5_CALL(this->v, setAttribute, qualifiedName, value);
}

void Element::setAttributeNS(std::string _namespace, std::string name, std::string value)
{
    HTML5_CALL(this->v, setAttributeNS, _namespace, name, value);
}

std::vector<Attr *> Element::getAttributes() const
{
    std::vector<Attr *> ret;
#if ENABLE_EMSCRIPTEN
    std::vector<emscripten::val> attrs = emscripten::vecFromJSArray<emscripten::val>(this->v["attributes"]);
    for (emscripten::val &attr : attrs) {
        ret.push_back(Attr::create(attr));
    }
#endif
    return ret;
}

void Element::setAttributes(std::vector<Attr *> value)
{
#if ENABLE_EMSCRIPTEN
    this->_attributes = value;
    emscripten::val arr = emscripten::val::array();
    for (size_t i = 0; i < value.size(); ++i) {
        arr.set(i, value[i]->v);
    }
    this->v.set("attributes", arr);
#endif
}

HTML5_PROPERTY_IMPL(Element, unsigned long, childElementCount);
HTML5_PROPERTY_OBJECT_IMPL(Element, HTMLCollection, children);
HTML5_PROPERTY_IMPL(Element, std::string, className);
HTML5_PROPERTY_OBJECT_IMPL(Element, Element, firstElementChild);
HTML5_PROPERTY_IMPL(Element, std::string, id);
HTML5_PROPERTY_OBJECT_IMPL(Element, Element, lastElementChild);
HTML5_PROPERTY_IMPL(Element, std::string, localName);
HTML5_PROPERTY_IMPL(Element, std::string, namespaceURI);
HTML5_PROPERTY_OBJECT_IMPL(Element, Element, nextElementSibling);
HTML5_PROPERTY_IMPL(Element, std::string, prefix);
HTML5_PROPERTY_OBJECT_IMPL(Element, Element, previousElementSibling);
HTML5_PROPERTY_IMPL(Element, std::string, tagName);
//HTML5_PROPERTY_OBJECT_IMPL(Element, ShadowRoot, shadowRoot);
HTML5_PROPERTY_OBJECT_IMPL(Element, DOMTokenList, classList);
