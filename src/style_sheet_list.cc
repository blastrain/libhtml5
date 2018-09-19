#include "style_sheet.h"
#include "style_sheet_list.h"

USING_NAMESPACE_HTML5;

StyleSheetList::StyleSheetList(emscripten::val v) :
    Object(),
    v(v)
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
