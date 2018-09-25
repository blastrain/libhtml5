#include "libhtml5.h"
#include "object.h"
#include "array.h"
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

Object *Object::create(Object *o)
{
    return create(o->v);
}

template<typename... Args>
Object *Object::assign(Object *target, const Args &... sources)
{
    return Object::create(HTML5_CALLv(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), assign, target->v, to_val(sources)...));
}

void Object::freeze(Object *o)
{
    HTML5_CALL(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), freeze, o->v);
}

Object *Object::getOwnPropertyDescriptor(Object *o, std::string prop)
{
    return Object::create(HTML5_CALLv(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), getOwnPropertyDescriptor, o->v, prop));
}

std::vector<std::string> Object::getOwnPropertyNames(Object *o)
{
    return toArray<std::string>(HTML5_CALLv(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), getOwnPropertyNames, o->v));
}

Object *Object::getPropertyOf(Object *o)
{
    return Object::create(HTML5_CALLv(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), getPropertyOf, o->v));
}

bool Object::is(std::string value1, std::string value2)
{
    return HTML5_CALLb(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), is, value1, value2);
}

bool Object::is(Object *value1, Object *value2)
{
    return HTML5_CALLb(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), is, value1, value2);
}

bool Object::is(int value1, int value2)
{
    return HTML5_CALLb(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), is, value1, value2);
}

bool Object::isExtensible(Object *o)
{
    return HTML5_CALLb(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), isExtensible, o->v);
}

bool Object::isFrozen(Object *o)
{
    return HTML5_CALLb(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), isFrozen, o->v);
}

bool Object::isSealed(Object *o)
{
    return HTML5_CALLb(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), isSealed, o->v);
}

std::vector<std::string> Object::keys(Object *o)
{
    return toArray<std::string>(HTML5_CALLv(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), keys, o->v));
}

Object *Object::preventExtensions(Object *o)
{
    return Object::create(HTML5_CALLv(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), preventExtensions, o->v));
}

Object *Object::seal(Object *o)
{
    return Object::create(HTML5_CALLv(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), seal, o->v));
}

Array *Object::values(Object *o)
{
    return Array::create(HTML5_CALLv(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), values, o->v));
}

Array *Object::entries(Object *o)
{
    return Array::create(HTML5_CALLv(HTML5_STATIC_PRIMITIVE_INSTANCE(Object), entries, o->v));
}

bool Object::hasOwnProperty(std::string prop)
{
    return HTML5_CALLb(this->v, hasOwnProperty, prop);
}

bool Object::isPrototypeOf(Object *o)
{
    return HTML5_CALLb(this->v, isPrototypeOf, o->v);
}

bool Object::propertyIsEnumerable(std::string s)
{
    return HTML5_CALLb(this->v, propertyIsEnumerable, s);
}

std::string Object::toLocaleString()
{
    return HTML5_CALLs(this->v, toLocaleString);
}

std::string Object::toString()
{
    return HTML5_CALLs(this->v, toString);
}

Object *Object::valueOf()
{
    return Object::create(HTML5_CALLv(this->v, valueOf));
}
