#pragma once

#include "libhtml5.h"
#include "style_sheet.h"

NAMESPACE_HTML5_BEGIN;

class StyleSheetList : public Object {
public:

    HTML5_PROPERTY(StyleSheetList, unsigned long, length);
    HTML5_DEFINE_ITERATOR(StyleSheetList, StyleSheet);

    StyleSheetList(emscripten::val v);
    virtual ~StyleSheetList();
    static StyleSheetList *create(emscripten::val v);
    StyleSheet *item(unsigned long index);
};

NAMESPACE_HTML5_END;
