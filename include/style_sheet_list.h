#pragma once

#include "libhtml5.h"
#include "style_sheet.h"

NAMESPACE_HTML5_BEGIN;

class StyleSheetList;

class StyleSheetIterator {
public:
    StyleSheetIterator(StyleSheetList *list, unsigned long index = 0);
    virtual ~StyleSheetIterator();
    StyleSheet *operator*();
    StyleSheetIterator& operator++();
    bool operator!=(const StyleSheetIterator& v);

private:
    unsigned long _index;
    StyleSheetList *_list;
};

class StyleSheetList : public Object {
public:

    HTML5_PROPERTY(StyleSheetList, unsigned long, length);

    StyleSheetList(emscripten::val v);
    virtual ~StyleSheetList();
    static StyleSheetList *create(emscripten::val v);
    StyleSheet *item(unsigned long index);
    StyleSheetIterator begin() {
        return StyleSheetIterator(this);
    };
    StyleSheetIterator end() {
        return StyleSheetIterator(this, this->length);
    };
};

NAMESPACE_HTML5_END;
