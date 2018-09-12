#include "uint8_clamped_array.h"
#include "image_data.h"

ImageData::ImageData(emscripten::val v) :
    Object(),
    v(v)
{

}

ImageData::~ImageData()
{

}

ImageData *ImageData::create(emscripten::val v)
{
    auto imagedata = new ImageData(v);
    imagedata->autorelease();
    return imagedata;
}

ImageData *ImageData::create(unsigned long sw, unsigned long sh)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(ImageData, sw, sh));
}

ImageData *ImageData::create(Uint8ClampedArray *data, unsigned long sw, unsigned long sh)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(ImageData, data->v, sw, sh));
}
    
Uint8ClampedArray *ImageData::getData() const
{
    return HTML5_PROPERTY_GET(data, Uint8ClampedArray);
}

void ImageData::setData(Uint8ClampedArray *value)
{
    this->_data = value;
    this->v.set("data", value->v);
}
    
unsigned long ImageData::getHeight() const
{
    return HTML5_PROPERTY_GET(height, unsigned long);
}

void ImageData::setHeight(unsigned long value)
{
    this->_height = value;
    this->v.set("height", value);
}

unsigned long ImageData::getWidth() const
{
    return HTML5_PROPERTY_GET(width, unsigned long);
}

void ImageData::setWidth(unsigned long value)
{
    this->_width = value;
    this->v.set("width", value);
}
