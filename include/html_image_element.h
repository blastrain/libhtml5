#pragma once

#include "html_element.h"

class HTMLImageElement : public HTMLElement {
public:

    HTML5_PROPERTY(HTMLImageElement, std::string, alt);
    HTML5_PROPERTY(HTMLImageElement, bool, complete);
    HTML5_PROPERTY(HTMLImageElement, std::string, crossOrigin);
    HTML5_PROPERTY(HTMLImageElement, unsigned long, height);
    HTML5_PROPERTY(HTMLImageElement, bool, isMap);
    HTML5_PROPERTY(HTMLImageElement, unsigned long, naturalHeight);
    HTML5_PROPERTY(HTMLImageElement, unsigned long, naturalWidth);
    HTML5_PROPERTY(HTMLImageElement, std::string, src);
    HTML5_PROPERTY(HTMLImageElement, std::string, srcset);
    HTML5_PROPERTY(HTMLImageElement, std::string, useMap);
    HTML5_PROPERTY(HTMLImageElement, unsigned long, width);

    HTMLImageElement(emscripten::val v);
    virtual ~HTMLImageElement();
    static HTMLImageElement *create();
    static HTMLImageElement *create(emscripten::val v);
    static HTMLImageElement *create(unsigned long width, unsigned long height);
};
