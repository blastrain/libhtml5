#pragma once

#include "html_collection.h"

class HTMLPropertiesCollection : public HTMLCollection {
public:

    HTMLPropertiesCollection(emscripten::val v);
    virtual ~HTMLPropertiesCollection();
    static HTMLPropertiesCollection *create(emscripten::val v);
};
