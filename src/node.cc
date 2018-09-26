#include "document.h"
#include "element.h"
#include "node.h"

USING_NAMESPACE_HTML5;

Node::Node(emscripten::val v) :
    EventTarget(v)
{

}

Node::~Node()
{

}

Node *Node::create(emscripten::val v)
{
    Node *node = new Node(v);
    node->autorelease();
    return node;
}

Node *Node::appendChild(Node *node)
{
    return Node::create(HTML5_CALLv(this->v, appendChild, node->v));
}

Node *Node::cloneNode(bool deep)
{
    return Node::create(HTML5_CALLv(this->v, cloneNode, deep));
}

unsigned short Node::compareDocumentPosition(Node *other)
{
    return HTML5_CALLi(this->v, compareDocumentPosition, unsigned short, other->v);
}

bool Node::contains(Node *other)
{
    return HTML5_CALLb(this->v, contains, other->v);
}
   
bool Node::hasChildNodes()
{
    return HTML5_CALLb(this->v, hasChildNodes); 
}

Node *Node::insertBefore(Node *node, Node *child)
{
    return Node::create(HTML5_CALLv(this->v, insertBefore, node->v, child->v));
}

bool Node::isDefaultNamespace(std::string _namespace)
{
    return HTML5_CALLb(this->v, isDefaultNamespace, _namespace);
}

bool Node::isEqualNode(Node *node)
{
    return HTML5_CALLb(this->v, isEqualNode, node->v);
}

std::string Node::lookupNamespaceURI(std::string prefix)
{
    return HTML5_CALLs(this->v, lookupNamespaceURI, prefix);
}

std::string Node::lookupPrefix(std::string prefix)
{
    return HTML5_CALLs(this->v, lookupPrefix, prefix);
}

void Node::normalize()
{
    HTML5_CALL(this->v, normalize);
}

Node *Node::removeChild(Node *node)
{
    return Node::create(HTML5_CALLv(this->v, removeChild, node->v));
}

Node *Node::replaceChild(Node *node, Node *child)
{
    return Node::create(HTML5_CALLv(this->v, replaceChild, node->v, child->v));
}

std::vector<Node *> Node::getChildNodes() const
{
#if ENABLE_EMSCRIPTEN
    std::vector<emscripten::val> nodes = emscripten::vecFromJSArray<emscripten::val>(this->v["childNodes"]);
    std::vector<Node *> ret;
    for (auto &n : nodes) {
        ret.push_back(Node::create(n));
    }
    return ret;
#else
    return this->_childNodes;
#endif
}

void Node::setChildNodes(std::vector<Node *> value)
{
    this->_childNodes = value;
#if ENABLE_EMSCRIPTEN
    emscripten::val arr = emscripten::val::array();
    for (size_t i = 0; i < value.size(); ++i) {
        arr.set(i, value[i]->v);
    }
    this->v.set("childNodes", arr);
#endif
}

HTML5_PROPERTY_IMPL(Node, std::string, baseURI);
HTML5_PROPERTY_OBJECT_IMPL(Node, Node, firstChild);
HTML5_PROPERTY_IMPL(Node, std::string, innerText);
HTML5_PROPERTY_OBJECT_IMPL(Node, Node, lastChild);
HTML5_PROPERTY_OBJECT_IMPL(Node, Node, nextSibling);
HTML5_PROPERTY_IMPL(Node, std::string, nodeName);
HTML5_PROPERTY_IMPL(Node, unsigned short, nodeType);
HTML5_PROPERTY_IMPL(Node, std::string, nodeValue);
HTML5_PROPERTY_OBJECT_IMPL(Node, Document, ownerDocument);
HTML5_PROPERTY_OBJECT_IMPL(Node, Element, parentElement);
HTML5_PROPERTY_OBJECT_IMPL(Node, Node, parentNode);
HTML5_PROPERTY_OBJECT_IMPL(Node, Node, previousNode);
HTML5_PROPERTY_OBJECT_IMPL(Node, Node, previousSibling);
HTML5_PROPERTY_IMPL(Node, std::string, textContent);
