#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class ImageBitmap : public Object {
public:

    HTML5_PROPERTY(ImageBitmap, unsigned long, height);
    HTML5_PROPERTY(ImageBitmap, unsigned long, width);

    ImageBitmap(emscripten::val v);
    virtual ~ImageBitmap();
    static ImageBitmap *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
