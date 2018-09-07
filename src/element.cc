#include "attr.h"
#include "dom_token_list.h"
#include "html_collection.h"
#include "node_list.h"
#include "element.h"

Element::Element(emscripten::val v) :
    Node(v)
{

}

Element::~Element()
{

}

Element *Element::create(emscripten::val v)
{
    Element *e = new Element(v);
    return e;
}

void Element::after(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        this->v.call<void>("after", node->v);
    }
}

void Element::append(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        this->v.call<void>("append", node->v);
    }
}

void Element::before(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        this->v.call<void>("before", node->v);
    }
}

std::string Element::getAttribute(std::string name)
{
    return this->v.call<std::string>("getAttribute", name);
}

std::string Element::getAttributeNS(std::string _namespace, std::string localName)
{
    return this->v.call<std::string>("getAttributeNS", _namespace, localName);
}

HTMLCollection *Element::getElementsByClassName(std::string classNames)
{
    emscripten::val v = this->v.call<emscripten::val>("getElementsByClassName", classNames);
    return HTMLCollection::create(v);
}

HTMLCollection *Element::getElementsByTagName(std::string localName)
{
    emscripten::val v = this->v.call<emscripten::val>("getElementsByTagName", localName);
    return HTMLCollection::create(v);
}

HTMLCollection *Element::getElementsByTagnameNS(std::string _namespace, std::string localName)
{
    emscripten::val v = this->v.call<emscripten::val>("getElementsByTagNameNS", _namespace, localName);
    return HTMLCollection::create(v);
}

bool Element::hasAttribute(std::string name)
{
    return this->v.call<bool>("hasAttribute", name);
}

bool Element::hasAttributeNS(std::string _namespace, std::string localName)
{
    return this->v.call<bool>("hasAttributeNS", _namespace, localName);
}

bool Element::matches(std::string selectors)
{
    return this->v.call<bool>("matches", selectors);
}

void Element::prepend(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        this->v.call<void>("prepend", node->v);
    }
}

Element *Element::query(std::string relativeSelectors)
{
    emscripten::val v = this->v.call<emscripten::val>("query", relativeSelectors);
    return Element::create(v);
}

std::vector<Element *> Element::queryAll(std::string relativeSelectors)
{
    emscripten::val arr = this->v.call<emscripten::val>("queryAll", relativeSelectors);
    std::vector<emscripten::val> elems = emscripten::vecFromJSArray<emscripten::val>(arr);
    std::vector<Element *> ret;
    for (emscripten::val &elem : elems) {
        ret.push_back(Element::create(elem));
    }
    return ret;
}

Element *Element::querySelector(std::string selectors)
{
    emscripten::val v = this->v.call<emscripten::val>("querySelector", selectors);
    return Element::create(v);
}

NodeList *Element::querySelectorAll(std::string selectors)
{
    emscripten::val v = this->v.call<emscripten::val>("querySelectorAll", selectors);
    return NodeList::create(v);
}

void Element::remove()
{
    this->v.call<void>("remove");
}

void Element::removeAttribute(std::string name)
{
    this->v.call<void>("removeAttribute", name);
}

void Element::removeAttributeNS(std::string _namespace, std::string localName)
{
    this->v.call<void>("removeAttributeNS", _namespace, localName);
}

void Element::replace(std::vector<Node *> nodes)
{
    for (Node *node : nodes) {
        this->v.call<void>("replace", node->v);
    }
}

void Element::requestFullscreen()
{
    this->v.call<void>("requestFullscreen");
}

void Element::requestPointerLock()
{
    this->v.call<void>("requestPointerLock");
}

void Element::setAttribute(std::string qualifiedName, std::string value)
{
    this->v.call<void>("setAttribute", qualifiedName, value);
}

void Element::setAttributeNS(std::string _namespace, std::string name, std::string value)
{
    this->v.call<void>("setAttributeNS", _namespace, name, value);
}

std::vector<Attr *> Element::getAttributes() const
{
    std::vector<emscripten::val> attrs = emscripten::vecFromJSArray<emscripten::val>(this->v["attributes"]);
    std::vector<Attr *> ret;
    for (emscripten::val &attr : attrs) {
        ret.push_back(Attr::create(attr));
    }
    return ret;
}

void Element::setAttributes(std::vector<Attr *> value)
{
    this->_attributes = value;
    emscripten::val arr = emscripten::val::array();
    for (size_t i = 0; i < value.size(); ++i) {
        arr.set(i, value[i]->v);
    }
    this->v.set("attributes", arr);
}

unsigned long Element::getChildElementCount() const
{
    return this->v["childElementCount"].as<unsigned long>();
}

void Element::setChildElementCount(unsigned long value)
{
    this->_childElementCount = value;
    this->v.set("childElementCount", value);
}

HTMLCollection *Element::getChildren() const
{
    return HTMLCollection::create(this->v["children"]);
}
    
void Element::setChildren(HTMLCollection *value)
{
    this->_children = value;
    this->v.set("children", value->v);
}

std::string Element::getClassName() const
{
    return this->v["className"].as<std::string>();
}

void Element::setClassName(std::string value)
{
    this->_className = value;
    this->v.set("className", value);
}

Element *Element::getFirstElementChild() const
{
    return Element::create(this->v["firstElementChild"]);
}

void Element::setFirstElementChild(Element *value)
{
    this->_firstElementChild = value;
    this->v.set("firstElementChild", value->v);
}

std::string Element::getId() const
{
    return this->v["id"].as<std::string>();
}

void Element::setId(std::string value)
{
    this->_id = value;
    this->v.set("id", value);
}

Element *Element::getLastElementChild() const
{
    return Element::create(this->v["lastElementChild"]);
}

void Element::setLastElementChild(Element *value)
{
    this->_lastElementChild = value;
    this->v.set("lastElementChild", value->v);
}

std::string Element::getLocalName() const
{
    return this->v["localName"].as<std::string>();
}

void Element::setLocalName(std::string value)
{
    this->_localName = value;
    this->v.set("localName", value);
}

std::string Element::getNamespaceURI() const
{
    return this->v["namespaceURI"].as<std::string>();
}

void Element::setNamespaceURI(std::string value)
{
    this->_namespaceURI = value;
    this->v.set("namespaceURI", value);
}

Element *Element::getNextElementSibling() const
{
    return Element::create(this->v["nextElementSibling"]);
}

void Element::setNextElementSibling(Element *value)
{
    this->_nextElementSibling = value;
    this->v.set("nextElementSibling", value->v);
}

std::string Element::getPrefix() const
{
    return this->v["prefix"].as<std::string>();
}

void Element::setPrefix(std::string value)
{
    this->_prefix = value;
    this->v.set("prefix", value);
}

Element *Element::getPreviousElementSibling() const
{
    return Element::create(this->v["previousElementSibling"]);
}

void Element::setPreviousElementSibling(Element *value)
{
    this->_previousElementSibling = value;
    this->v.set("previousElementSibling", value->v);
}

std::string Element::getTagName() const
{
    return this->v["tagName"].as<std::string>();
}

void Element::setTagName(std::string value)
{
    this->_tagName = value;
    this->v.set("tagName", value);
}

DOMTokenList *Element::getClassList() const
{
    return DOMTokenList::create(this->v["classList"]);
}

void Element::setClassList(DOMTokenList *value)
{
    this->_classList = value;
    this->v.set("classList", value->v);
}
