#pragma once

#include "libhtml5.h"

class Document;
class XMLDocument;
class DocumentType;

class DOMImplementation : public Object {
public:
    emscripten::val v;

    DOMImplementation(emscripten::val v);
    virtual ~DOMImplementation();
    static DOMImplementation *create(emscripten::val v);
    XMLDocument *createDocument(std::string _namespace, std::string qualifiedName, DocumentType *type = NULL);
    DocumentType *createDocumentType(std::string qualifiedName, std::string publicId, std::string systemId);
    Document *createHTMLDocument(std::string title = "");
    bool hasFeature();
};
