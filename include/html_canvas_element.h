#pragma once

#include "libhtml5.h"
#include "html_element.h"
#include "rendering_context.h"

class Blob;

class HTMLCanvasElement : public HTMLElement {
public:
    unsigned long _height;
    unsigned long _width;

    HTMLCanvasElement(emscripten::val v);
    virtual ~HTMLCanvasElement();
    emscripten::val getValue();
    static HTMLCanvasElement *create(emscripten::val v);
    RenderingContext *getContext(std::string contextId);
    void toBlob(std::function<void(Blob*)> *callback, std::string mimeType = "image/png", double qualityArgument = 1.0);
    void toBlobCallback(emscripten::val v);
    std::string toDataURL(std::string type, double encoderOptions = 0.92);

    unsigned long getHeight() const;
    void setHeight(unsigned long value);
    unsigned long getWidth() const;
    void setWidth(unsigned long value);

    struct {
        HTMLCanvasElement &self;
        void operator=(unsigned long value) { self.setHeight(value); };
        operator unsigned long() { return self.getHeight(); };
    } height{*this};

    struct {
        HTMLCanvasElement &self;
        void operator=(unsigned long value) { self.setWidth(value); };
        operator unsigned long() { return self.getWidth(); };
    } width{*this};

private:
    std::function<void(Blob*)> *_toBlobFn;
};
