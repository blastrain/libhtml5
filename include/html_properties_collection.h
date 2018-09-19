#pragma once

#include "html_collection.h"

NAMESPACE_HTML5_BEGIN;

class HTMLPropertiesCollection : public HTMLCollection {
public:

    HTMLPropertiesCollection(emscripten::val v);
    virtual ~HTMLPropertiesCollection();
    static HTMLPropertiesCollection *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
