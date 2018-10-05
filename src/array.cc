#include "libhtml5.h"
#include "array.h"

USING_NAMESPACE_HTML5;

Array::Array(emscripten::val v) :
    Object(v)
{

}

Array::~Array()
{
}

Array *Array::create(emscripten::val v)
{
    Array *arr = new Array(v);
    arr->autorelease();
    return arr;
}

Array *Array::create(unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(Array, length));
}

Array::Element::Element(emscripten::val v, size_t index) :
    v(v),
    index(index)
{

}

Array::Element::~Element()
{

}

void Array::Element::operator=(int value)
{
    this->v.set(this->index, value);
}

void Array::Element::operator=(double value)
{
    this->v.set(this->index, value);
}

void Array::Element::operator=(std::string value)
{
    this->v.set(this->index, value);
}

void Array::Element::operator=(Object *value)
{
    this->v.set(this->index, value->v);
}

Array::Element Array::operator[](std::size_t index) const
{
    return Array::Element(this->v, index);
}

Array::Element Array::operator[](std::size_t index)
{
    return Array::Element(this->v, index);
}

void Array::forEach(std::function<void(const Array::Element &elem)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        callback((*this)[i]);
    }
}

void Array::forEach(std::function<void(const Array::Element &elem, int index)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        callback((*this)[i], i);
    }
}

void Array::forEach(std::function<void(const Array::Element &elem, int index, Array *array)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        callback((*this)[i], i, this);
    }
}

template<typename T> T toVal(Object *o, emscripten::val v)
{
    return dynamic_cast<T>(Object::create(v));
}

template<typename T> T toVal(T i, emscripten::val v)
{
    return v.as<T>();
}

template<typename T> T Array::pop()
{
    T tmp;
    return toVal<T>(tmp, HTML5_CALLv(this->v, pop));
}

HTML5_PROPERTY_IMPL(Array, unsigned long, length);
