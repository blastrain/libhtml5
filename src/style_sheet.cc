#include "media_list.h"
#include "element.h"
#include "style_sheet.h"
#include "css_style_sheet.h"

USING_NAMESPACE_HTML5;

static std::map<std::string, std::function<StyleSheet*(emscripten::val)>> classFactories = {
    CLASS_FACTORY_MAP(CSSStyleSheet),
};

StyleSheet::StyleSheet(emscripten::val v) :
    Object(v)
{

}

StyleSheet::~StyleSheet()
{

}

StyleSheet *StyleSheet::create(emscripten::val v)
{
#if ENABLE_EMSCRIPTEN
    std::string className = v["constructor"]["name"].as<std::string>();
    return classFactories[className](v);
#else
    StyleSheet *sheet = new StyleSheet(v);
    sheet->autorelease();
    return sheet;
#endif
}

HTML5_PROPERTY_IMPL(StyleSheet, bool, disabled);
HTML5_PROPERTY_IMPL(StyleSheet, std::string, href);
HTML5_PROPERTY_OBJECT_IMPL(StyleSheet, MediaList, media);
HTML5_PROPERTY_OBJECT_IMPL(StyleSheet, Element, ownerNode);
HTML5_PROPERTY_OBJECT_IMPL(StyleSheet, StyleSheet, parentStyleSheet);
HTML5_PROPERTY_IMPL(StyleSheet, std::string, title);
HTML5_PROPERTY_IMPL(StyleSheet, std::string, type);
