#include "html_style_element.h"

USING_NAMESPACE_HTML5;

HTMLStyleElement::HTMLStyleElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLStyleElement::~HTMLStyleElement()
{

}

HTMLStyleElement *HTMLStyleElement::create(emscripten::val v)
{
    auto elem = new HTMLStyleElement(v);
    elem->autorelease();
    return elem;
}

HTML5_PROPERTY_IMPL(HTMLStyleElement, std::string, media);
HTML5_PROPERTY_IMPL(HTMLStyleElement, bool, scoped);
HTML5_READONLY_PROPERTY_OBJECT_IMPL(HTMLStyleElement, StyleSheet, sheet);
HTML5_PROPERTY_IMPL(HTMLStyleElement, std::string, type);