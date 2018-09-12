#include "image_bitmap.h"

ImageBitmap::ImageBitmap(emscripten::val v) :
    Object(),
    v(v)
{

}

ImageBitmap::~ImageBitmap()
{

}

ImageBitmap *ImageBitmap::create(emscripten::val v)
{
    auto bitmap = new ImageBitmap(v);
    bitmap->autorelease();
    return bitmap;
}

unsigned long ImageBitmap::getHeight() const
{
    return HTML5_PROPERTY_GET(height, unsigned long);
}

void ImageBitmap::setHeight(unsigned long value)
{
    this->_height = value;
    this->v.set("height", value);
}

unsigned long ImageBitmap::getWidth() const
{
    return HTML5_PROPERTY_GET(width, unsigned long);
}

void ImageBitmap::setWidth(unsigned long value)
{
    this->_width = value;
    this->v.set("width", value);
}
