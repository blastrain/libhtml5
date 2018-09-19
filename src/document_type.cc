#include "node.h"
#include "document_type.h"

USING_NAMESPACE_HTML5;

DocumentType::DocumentType(emscripten::val v) :
    Object(),
    v(v)
{

}

DocumentType::~DocumentType()
{

}

DocumentType *DocumentType::create(emscripten::val v)
{
    auto type = new DocumentType(v);
    type->autorelease();
    return type;
}

void DocumentType::after(std::vector<Node *> nodes)
{
    for (size_t i = 0; i < nodes.size(); ++i) {
        HTML5_CALL(this->v, after, nodes[i]->v);
    }
}

void DocumentType::before(std::vector<Node *> nodes)
{
    for (size_t i = 0; i < nodes.size(); ++i) {
        HTML5_CALL(this->v, before, nodes[i]->v);
    }
}

void DocumentType::replace(std::vector<Node *> nodes)
{
    for (size_t i = 0; i < nodes.size(); ++i) {
        HTML5_CALL(this->v, replace, nodes[i]->v);
    }
}

void DocumentType::remove()
{
    HTML5_CALL(this->v, remove);
}

HTML5_PROPERTY_IMPL(DocumentType, std::string, name);
HTML5_PROPERTY_IMPL(DocumentType, std::string, publicId);
HTML5_PROPERTY_IMPL(DocumentType, std::string, systemId);
