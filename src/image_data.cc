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

HTML5_PROPERTY_OBJECT_IMPL(ImageData, Uint8ClampedArray, data);
HTML5_PROPERTY_IMPL(ImageData, unsigned long, height);
HTML5_PROPERTY_IMPL(ImageData, unsigned long, width);
