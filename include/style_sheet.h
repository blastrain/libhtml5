#pragma once

#include "libhtml5.h"

class MediaList;
class Element;

class StyleSheet : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(StyleSheet, bool, disabled);
    HTML5_PROPERTY(StyleSheet, std::string, href);
    HTML5_PROPERTY_OBJECT(StyleSheet, MediaList, media);
    HTML5_PROPERTY_OBJECT(StyleSheet, Element, ownerNode);
    HTML5_PROPERTY_OBJECT(StyleSheet, StyleSheet, parentStyleSheet);
    HTML5_PROPERTY(StyleSheet, std::string, title);
    HTML5_PROPERTY(StyleSheet, std::string, type);

    StyleSheet(emscripten::val v);
    virtual ~StyleSheet();
    static StyleSheet *create(emscripten::val v);
};
