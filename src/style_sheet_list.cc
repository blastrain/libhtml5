#include "style_sheet.h"
#include "style_sheet_list.h"

USING_NAMESPACE_HTML5;

StyleSheetIterator::StyleSheetIterator(StyleSheetList *list, unsigned long index) :
    _list(list),
    _index(index)
{
};

StyleSheetIterator::~StyleSheetIterator()
{

};

StyleSheet *StyleSheetIterator::operator*()
{
    return (this->_list->item(this->_index));
};

StyleSheetIterator& StyleSheetIterator::operator++()
{
    this->_index++; return *this;
};

bool StyleSheetIterator::operator!=(const StyleSheetIterator& v)
{
    return this->_index != v._index;
};

StyleSheetList::StyleSheetList(emscripten::val v) :
    Object(v)
{

}

StyleSheetList::~StyleSheetList()
{

}

StyleSheetList *StyleSheetList::create(emscripten::val v)
{
    auto list = new StyleSheetList(v);
    list->autorelease();
    return list;
}

StyleSheet *StyleSheetList::item(unsigned long index)
{
    return StyleSheet::create(HTML5_CALLv(this->v, item, index));
}

HTML5_PROPERTY_IMPL(StyleSheetList, unsigned long, length);
