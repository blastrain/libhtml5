#pragma once

#include "libhtml5.h"

class ImageBitmap : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(ImageBitmap, unsigned long, height);
    HTML5_PROPERTY(ImageBitmap, unsigned long, width);

    ImageBitmap(emscripten::val v);
    virtual ~ImageBitmap();
    static ImageBitmap *create(emscripten::val v);
};
