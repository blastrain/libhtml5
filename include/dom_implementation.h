#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class Document;
class XMLDocument;
class DocumentType;

class DOMImplementation : public Object {
public:

    DOMImplementation(emscripten::val v);
    virtual ~DOMImplementation();
    static DOMImplementation *create(emscripten::val v);
    XMLDocument *createDocument(std::string _namespace, std::string qualifiedName, DocumentType *type = NULL);
    DocumentType *createDocumentType(std::string qualifiedName, std::string publicId, std::string systemId);
    std::unique_ptr<Document> createHTMLDocument(std::string title = "");
    bool hasFeature();
};

NAMESPACE_HTML5_END;
