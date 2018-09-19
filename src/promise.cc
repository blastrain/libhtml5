#include "promise.h"

USING_NAMESPACE_HTML5;

Promise::Promise(emscripten::val v) :
    Object(),
    v(v)
{

}

Promise::~Promise()
{

}

Promise *Promise::create(emscripten::val v)
{
    Promise *p = new Promise(v);
    p->autorelease();
    return p;
}

HTML5_PROPERTY_IMPL(Promise, unsigned long, length);
