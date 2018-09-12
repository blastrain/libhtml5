#include "promise.h"

Promise::Promise(emscripten::val v) :
    Object()
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
