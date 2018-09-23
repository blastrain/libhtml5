#pragma once

#include "libhtml5.h"
#include "style_sheet.h"

NAMESPACE_HTML5_BEGIN;

class StyleSheetList : public Object {
public:

    HTML5_PROPERTY(StyleSheetList, unsigned long, length);

    StyleSheetList(emscripten::val v);
    virtual ~StyleSheetList();
    static StyleSheetList *create(emscripten::val v);
    StyleSheet *item(unsigned long index);

    class iterator {
    public:
        iterator(StyleSheetList *list, unsigned long index = 0) :
            _list(list),
            _index(index){};
        virtual ~iterator() {};
        StyleSheet *operator*() { return this->_list->item(this->_index); };
        iterator& operator++() {
            this->_index++;
            return *this;
        };
        bool operator!=(const iterator& v) { return this->_index != v._index; };

    private:
        unsigned long _index;
        StyleSheetList *_list;
    };

    iterator begin() { return iterator(this); };
    iterator end() { return iterator(this, this->length); };
};

NAMESPACE_HTML5_END;
