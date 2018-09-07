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
    return node;
}

Node *Node::appendChild(Node *node)
{
    emscripten::val v = this->v.call<emscripten::val>("appendChild", node->v);
    return Node::create(v);
}

Node *Node::cloneNode(bool deep)
{
    emscripten::val v = this->v.call<emscripten::val>("cloneNode", deep);
    return Node::create(v);
}

unsigned short Node::compareDocumentPosition(Node *other)
{
    return this->v.call<unsigned short>("compareDocumentPosition", other->v);
}

bool Node::contains(Node *other)
{
    return this->v.call<bool>("contains", other->v);
}
   
bool Node::hasChildNodes()
{
    return this->v.call<bool>("hasChildNodes");
}

Node *Node::insertBefore(Node *node, Node *child)
{
    emscripten::val v = this->v.call<emscripten::val>("insertBefore", node->v, child->v);
    return Node::create(v);
}

bool Node::isDefaultNamespace(std::string _namespace)
{
    return this->v.call<bool>("isDefaultNamespace", _namespace);
}

bool Node::isEqualNode(Node *node)
{
    return this->v.call<bool>("isEqualNode", node->v);
}

std::string Node::lookupNamespaceURI(std::string prefix)
{
    return this->v.call<std::string>("lookupNamespaceURI", prefix);
}

std::string Node::lookupPrefix(std::string prefix)
{
    return this->v.call<std::string>("lookupPrefix", prefix);
}

void Node::normalize()
{
    this->v.call<void>("normalize");
}

Node *Node::removeChild(Node *node)
{
    emscripten::val v = this->v.call<emscripten::val>("removeChild", node->v);
    return Node::create(v);
}

Node *Node::replaceChild(Node *node, Node *child)
{
    emscripten::val v = this->v.call<emscripten::val>("replaceChild", node->v, child->v);
    return Node::create(v);
}

std::string Node::getBaseURI() const
{
    return this->v["baseURI"].as<std::string>();
}

void Node::setBaseURI(std::string value)
{
    this->_baseURI = value;
    this->v.set("baseURI", value);
}

std::vector<Node *> Node::getChildNodes() const
{
    std::vector<emscripten::val> nodes = emscripten::vecFromJSArray<emscripten::val>(this->v["childNodes"]);
    std::vector<Node *> ret;
    for (auto &n : nodes) {
        ret.push_back(Node::create(n));
    }
    return ret;
}

void Node::setChildNodes(std::vector<Node *> value)
{
    this->_childNodes = value;
    emscripten::val arr = emscripten::val::array();
    for (size_t i = 0; i < value.size(); ++i) {
        arr.set(i, value[i]->v);
    }
    this->v.set("childNodes", arr);
}

Node *Node::getFirstChild() const
{
    return Node::create(this->v["firstChild"]);
}

void Node::setFirstChild(Node *value)
{
    this->_firstChild = value;
    this->v.set("firstChild", value->v);
}

Node *Node::getLastChild() const
{
    return Node::create(this->v["lastChild"]);
}

void Node::setLastChild(Node *value)
{
    this->_lastChild = value;
    this->v.set("lastChild", value->v);
}

Node *Node::getNextSibling() const
{
    return Node::create(this->v["nextSibling"]);
}

void Node::setNextSibling(Node *value)
{
    this->_nextSibling = value;
    this->v.set("nextSibling", value->v);
}


std::string Node::getNodeName() const
{
    return this->v["nodeName"].as<std::string>();
}


void Node::setNodeName(std::string value)
{
    this->_nodeName = value;
    this->v.set("nodeName", value);
}

unsigned short Node::getNodeType() const
{
    return this->v["nodeType"].as<unsigned short>();
}


void Node::setNodeType(unsigned short value)
{
    this->_nodeType = value;
    this->v.set("nodeType", value);
}

std::string Node::getNodeValue() const
{
    return this->v["nodeValue"].as<std::string>();
}

void Node::setNodeValue(std::string value)
{
    this->_nodeValue = value;
    this->v.set("nodeValue", value);
}

Document *Node::getOwnerDocument() const
{
    return Document::create(this->v["ownerDocument"]);
}

void Node::setOwnerDocument(Document *value)
{
    this->_ownerDocument = value;
    this->v.set("ownerDocument", value->v);
}

Element *Node::getParentElement() const
{
    return Element::create(this->v["parentElement"]);
}

void Node::setParentElement(Element *value)
{
    this->_parentElement = value;
    this->v.set("parentElement", value->v);
}

Node *Node::getParentNode() const
{
    return Node::create(this->v["parentNode"]);
}

void Node::setParentNode(Node *value)
{
    this->_parentNode = value;
    this->v.set("parentNode", value->v);
}

Node *Node::getPreviousNode() const
{
    return Node::create(this->v["previousNode"]);
}

void Node::setPreviousNode(Node *value)
{
    this->_previousNode = value;
    this->v.set("previousNode", value->v);
}

Node *Node::getPreviousSibling() const
{
    return Node::create(this->v["previousNode"]);
}

void Node::setPreviousSibling(Node *value)
{
    this->_previousSibling = value;
    this->v.set("previousSibling", value->v);
}

std::string Node::getTextContent() const
{
    return this->v["textContent"].as<std::string>();
}

void Node::setTextContent(std::string value)
{
    this->_textContent = value;
    this->v.set("textContent", value);
}
