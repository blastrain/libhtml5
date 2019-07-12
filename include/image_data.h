#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class Uint8ClampedArray;

class ImageData : public Object {
public:

    HTML5_PROPERTY_OBJECT(ImageData, Uint8ClampedArray, data);
    HTML5_PROPERTY(ImageData, unsigned long, height);
    HTML5_PROPERTY(ImageData, unsigned long, width);

    ImageData(emscripten::val v);
    virtual ~ImageData();
    static ImageData *create(emscripten::val v);
    static ImageData *create(unsigned long sw, unsigned long sh);
    static ImageData *create(Uint8ClampedArray *data, unsigned long sw, unsigned long sh);
};

NAMESPACE_HTML5_END;
