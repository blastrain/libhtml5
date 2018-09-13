#include "html_image_element.h"
#include <iostream>

HTMLImageElement::HTMLImageElement(emscripten::val v) :
    HTMLElement(v)
{

}

HTMLImageElement::~HTMLImageElement()
{

}

HTMLImageElement *HTMLImageElement::create(emscripten::val v)
{
    HTMLImageElement *image = new HTMLImageElement(v);
    image->autorelease();
    return image;
}

HTMLImageElement *HTMLImageElement::create()
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Image));
}

HTMLImageElement *HTMLImageElement::create(unsigned long width, unsigned long height)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE("Image", width, height));
}

HTML5_PROPERTY_IMPL(HTMLImageElement, std::string, alt);
HTML5_PROPERTY_IMPL(HTMLImageElement, bool, complete);
HTML5_PROPERTY_IMPL(HTMLImageElement, std::string, crossOrigin);
HTML5_PROPERTY_IMPL(HTMLImageElement, unsigned long, height);
HTML5_PROPERTY_IMPL(HTMLImageElement, bool, isMap);
HTML5_PROPERTY_IMPL(HTMLImageElement, unsigned long, naturalHeight);
HTML5_PROPERTY_IMPL(HTMLImageElement, unsigned long, naturalWidth);
HTML5_PROPERTY_IMPL(HTMLImageElement, std::string, src);
HTML5_PROPERTY_IMPL(HTMLImageElement, std::string, srcset);
HTML5_PROPERTY_IMPL(HTMLImageElement, std::string, useMap);
HTML5_PROPERTY_IMPL(HTMLImageElement, unsigned long, width);
