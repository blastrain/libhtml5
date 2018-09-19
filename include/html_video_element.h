#pragma once

#include "html_media_element.h"

NAMESPACE_HTML5_BEGIN;

class HTMLVideoElement : public HTMLMediaElement {
public:

    HTML5_PROPERTY(HTMLVideoElement, double, height);
    HTML5_PROPERTY(HTMLVideoElement, std::string, poster);
    HTML5_PROPERTY(HTMLVideoElement, double, videoHeight);
    HTML5_PROPERTY(HTMLVideoElement, double, videoWidth);
    HTML5_PROPERTY(HTMLVideoElement, double, width);
    
    HTMLVideoElement(emscripten::val v);
    ~HTMLVideoElement();
    static HTMLVideoElement *create();
    static HTMLVideoElement *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
