#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class StyleSheet;

class StyleSheetList : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(StyleSheetList, unsigned long, length);

    StyleSheetList(emscripten::val v);
    virtual ~StyleSheetList();
    static StyleSheetList *create(emscripten::val v);
    StyleSheet *item(unsigned long index);
};

NAMESPACE_HTML5_END;
