#pragma once

#include "libhtml5.h"

class Uint8ClampedArray;

class ImageData : public Object {
public:
    emscripten::val v;
    Uint8ClampedArray *_data;
    unsigned long _height;
    unsigned long _width;

    ImageData(emscripten::val v);
    virtual ~ImageData();
    static ImageData *create(emscripten::val v);
    static ImageData *create(unsigned long sw, unsigned long sh);
    static ImageData *create(Uint8ClampedArray *data, unsigned long sw, unsigned long sh);
    
    Uint8ClampedArray *getData() const;
    void setData(Uint8ClampedArray *value);
    unsigned long getHeight() const;
    void setHeight(unsigned long value);
    unsigned long getWidth() const;
    void setWidth(unsigned long value);

    struct {
        ImageData &self;
        void operator=(Uint8ClampedArray *value) { self.setData(value); };
        operator Uint8ClampedArray *() { return self.getData(); };
    } data{*this};

    struct {
        ImageData &self;
        void operator=(unsigned long value) { self.setHeight(value); };
        operator unsigned long() { return self.getHeight(); };
    } height{*this};

    struct {
        ImageData &self;
        void operator=(unsigned long value) { self.setWidth(value); };
        operator unsigned long() { return self.getWidth(); };
    } width{*this};

};
