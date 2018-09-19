#pragma once

#include "libhtml5.h"
#include "html_element.h"
#include "rendering_context.h"

class Blob;

class HTMLCanvasElement : public HTMLElement {
public:

    HTML5_PROPERTY(HTMLCanvasElement, unsigned long, height);
    HTML5_PROPERTY(HTMLCanvasElement, unsigned long, width);

    HTMLCanvasElement(emscripten::val v);
    virtual ~HTMLCanvasElement();
    static HTMLCanvasElement *create(emscripten::val v);
    RenderingContext *getContext(std::string contextId);
    void toBlob(std::function<void(Blob*)> *callback, std::string mimeType = "image/png", double qualityArgument = 1.0);
    void toBlobCallback(emscripten::val v);
    std::string toDataURL(std::string type, double encoderOptions = 0.92);

private:
    std::function<void(Blob*)> *_toBlobFn;
};
