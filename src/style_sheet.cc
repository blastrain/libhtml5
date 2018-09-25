#include "media_list.h"
#include "element.h"
#include "style_sheet.h"
#include "css_style_sheet.h"

USING_NAMESPACE_HTML5;

HTML5_CLASS_FACTORY(StyleSheet) {
    HTML5_SUBCLASS_FACTORY(CSSStyleSheet),
};

HTML5_CREATE_IMPL(StyleSheet);

StyleSheet::StyleSheet(emscripten::val v) :
    Object(v)
{

}

StyleSheet::~StyleSheet()
{

}

HTML5_PROPERTY_IMPL(StyleSheet, bool, disabled);
HTML5_PROPERTY_IMPL(StyleSheet, std::string, href);
HTML5_PROPERTY_OBJECT_IMPL(StyleSheet, MediaList, media);
HTML5_PROPERTY_OBJECT_IMPL(StyleSheet, Element, ownerNode);
HTML5_PROPERTY_OBJECT_IMPL(StyleSheet, StyleSheet, parentStyleSheet);
HTML5_PROPERTY_IMPL(StyleSheet, std::string, title);
HTML5_PROPERTY_IMPL(StyleSheet, std::string, type);
