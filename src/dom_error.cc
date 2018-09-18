#include "dom_error.h"

DOMError::DOMError(emscripten::val v) :
    Object(),
    v(v)
{

}

DOMError::~DOMError()
{

}

DOMError *DOMError::create(emscripten::val v)
{
    auto error = new DOMError(v);
    error->autorelease();
    return error;
}

HTML5_PROPERTY_IMPL(DOMError, std::string, message);
HTML5_PROPERTY_IMPL(DOMError, std::string, name);
