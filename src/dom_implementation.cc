#include "document.h"
#include "xml_document.h"
#include "document_type.h"
#include "dom_implementation.h"

DOMImplementation::DOMImplementation(emscripten::val v) :
    Object(),
    v(v)
{

}

DOMImplementation::~DOMImplementation()
{

}

DOMImplementation *DOMImplementation::create(emscripten::val v)
{
    auto impl = new DOMImplementation(v);
    impl->autorelease();
    return impl;
}

XMLDocument *DOMImplementation::createDocument(std::string _namespace, std::string qualifiedName, DocumentType *type)
{
    return XMLDocument::create(HTML5_CALLv(this->v, createDocument, _namespace, qualifiedName, type->v));
}

DocumentType *DOMImplementation::createDocumentType(std::string qualifiedName, std::string publicId, std::string systemId)
{
    return DocumentType::create(HTML5_CALLv(this->v, createDocumentType, qualifiedName, publicId, systemId));
}

Document *DOMImplementation::createHTMLDocument(std::string title)
{
    return Document::create(HTML5_CALLv(this->v, createHTMLDocument, title));
}

bool DOMImplementation::hasFeature()
{
    return HTML5_CALLb(this->v, hasFeature);
}
