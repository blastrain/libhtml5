#include "libhtml5.h"
#include "object.h"
#include "auto_release_pool.h"

USING_NAMESPACE_HTML5;

Object::Object(emscripten::val v) :
    NativeObject(),
    v(v)
{
}

Object::~Object()
{

}

Object *Object::create()
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Object));
}

Object *Object::create(emscripten::val v)
{
    auto o = new Object(v);
    o->autorelease();
    return o;
}
