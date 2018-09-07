#pragma once

#include "html_media_element.h"

class HTMLVideoElement : public HTMLMediaElement {
public:
    double _width;
    double _height;
    double _videoWidth;
    double _videoHeight;
    std::string _poster;
    bool _complete;
    std::string _pixiId;
    
    HTMLVideoElement(emscripten::val v);
    ~HTMLVideoElement();
    static HTMLVideoElement *create();
    static HTMLVideoElement *create(emscripten::val v);
    void removeEventListener(std::string event, std::function<void(void*)> *fn, void *context = NULL);
    double width();
    void width(double value);
    double videoWidth();
    double height();
    void height(double value);
    double videoHeight();
    std::string poster();
    bool complete();
    void complete(bool value);
};
