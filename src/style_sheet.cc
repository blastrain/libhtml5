#include "media_list.h"
#include "element.h"
#include "style_sheet.h"

StyleSheet::StyleSheet(emscripten::val v) : v(v)
{

}

StyleSheet::~StyleSheet()
{

}

StyleSheet *StyleSheet::create(emscripten::val v)
{
    StyleSheet *sheet = new StyleSheet(v);
    sheet->autorelease();
    return sheet;
}

HTML5_PROPERTY_IMPL(StyleSheet, bool, disabled);
HTML5_PROPERTY_IMPL(StyleSheet, std::string, href);
HTML5_PROPERTY_OBJECT_IMPL(StyleSheet, MediaList, media);
HTML5_PROPERTY_OBJECT_IMPL(StyleSheet, Element, ownerNode);
HTML5_PROPERTY_OBJECT_IMPL(StyleSheet, StyleSheet, parentStyleSheet);
HTML5_PROPERTY_IMPL(StyleSheet, std::string, title);
HTML5_PROPERTY_IMPL(StyleSheet, std::string, type);
