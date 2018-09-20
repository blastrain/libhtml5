#include "dom_error.h"

USING_NAMESPACE_HTML5;

DOMError::DOMError(emscripten::val v) :
    Object(v)
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
