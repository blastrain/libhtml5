#pragma once

#include "libhtml5.h"

class ImageBitmap : public Object {
public:
    emscripten::val v;
    unsigned long _height;
    unsigned long _width;

    ImageBitmap(emscripten::val v);
    virtual ~ImageBitmap();
    static ImageBitmap *create(emscripten::val v);

    unsigned long getHeight() const;
    void setHeight(unsigned long value);
    unsigned long getWidth() const;
    void setWidth(unsigned long value);

    struct {
        ImageBitmap &self;
        void operator=(unsigned long value) { self.setHeight(value); };
        operator unsigned long() { return self.getHeight(); };
    } height{*this};

    struct {
        ImageBitmap &self;
        void operator=(unsigned long value) { self.setWidth(value); };
        operator unsigned long() { return self.getWidth(); };
    } width{*this};

};
