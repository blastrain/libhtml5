#include "document.h"
#include "element.h"
#include "node.h"

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

std::string Node::getBaseURI() const
{
    return HTML5_PROPERTY_GET(baseURI, std::string);
}

void Node::setBaseURI(std::string value)
{
    this->_baseURI = value;
    this->v.set("baseURI", value);
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

Node *Node::getFirstChild() const
{
    return HTML5_PROPERTY_GET(firstChild, Node);
}

void Node::setFirstChild(Node *value)
{
    this->_firstChild = value;
    this->v.set("firstChild", value->v);
}

Node *Node::getLastChild() const
{
    return HTML5_PROPERTY_GET(lastChild, Node);
}

void Node::setLastChild(Node *value)
{
    this->_lastChild = value;
    this->v.set("lastChild", value->v);
}

Node *Node::getNextSibling() const
{
    return HTML5_PROPERTY_GET(nextSibling, Node);
}

void Node::setNextSibling(Node *value)
{
    this->_nextSibling = value;
    this->v.set("nextSibling", value->v);
}


std::string Node::getNodeName() const
{
    return HTML5_PROPERTY_GET(nodeName, std::string);
}

void Node::setNodeName(std::string value)
{
    this->_nodeName = value;
    this->v.set("nodeName", value);
}

unsigned short Node::getNodeType() const
{
    return HTML5_PROPERTY_GET(nodeType, unsigned short);
}

void Node::setNodeType(unsigned short value)
{
    this->_nodeType = value;
    this->v.set("nodeType", value);
}

std::string Node::getNodeValue() const
{
    return HTML5_PROPERTY_GET(nodeValue, std::string);
}

void Node::setNodeValue(std::string value)
{
    this->_nodeValue = value;
    this->v.set("nodeValue", value);
}

Document *Node::getOwnerDocument() const
{
    return HTML5_PROPERTY_GET(ownerDocument, Document);
}

void Node::setOwnerDocument(Document *value)
{
    this->_ownerDocument = value;
    this->v.set("ownerDocument", value->v);
}

Element *Node::getParentElement() const
{
    return HTML5_PROPERTY_GET(parentElement, Element);
}

void Node::setParentElement(Element *value)
{
    this->_parentElement = value;
    this->v.set("parentElement", value->v);
}

Node *Node::getParentNode() const
{
    return HTML5_PROPERTY_GET(parentNode, Node);
}

void Node::setParentNode(Node *value)
{
    this->_parentNode = value;
    this->v.set("parentNode", value->v);
}

Node *Node::getPreviousNode() const
{
    return HTML5_PROPERTY_GET(previousNode, Node);
}

void Node::setPreviousNode(Node *value)
{
    this->_previousNode = value;
    this->v.set("previousNode", value->v);
}

Node *Node::getPreviousSibling() const
{
    return HTML5_PROPERTY_GET(previousNode, Node);
}

void Node::setPreviousSibling(Node *value)
{
    this->_previousSibling = value;
    this->v.set("previousSibling", value->v);
}

std::string Node::getTextContent() const
{
    return HTML5_PROPERTY_GET(textContent, std::string);
}

void Node::setTextContent(std::string value)
{
    this->_textContent = value;
    this->v.set("textContent", value);
}
