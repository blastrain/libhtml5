#include "libhtml5.h"
#include "array.h"

USING_NAMESPACE_HTML5;

array::array(emscripten::val v) :
    Object(v)
{

}

array::~array()
{
}

array *array::create(emscripten::val v)
{
    array *arr = new array(v);
    arr->autorelease();
    return arr;
}

array *array::create(unsigned long length)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(array, length));
}

array::Element::Element(emscripten::val v, size_t index) :
    v(v),
    index(index)
{

}

array::Element::~Element()
{

}

void array::Element::operator=(int value)
{
    this->v.set(this->index, value);
}

void array::Element::operator=(double value)
{
    this->v.set(this->index, value);
}

void array::Element::operator=(std::string value)
{
    this->v.set(this->index, value);
}

void array::Element::operator=(Object *value)
{
    this->v.set(this->index, value->v);
}

array::Element array::operator[](std::size_t index) const
{
    return array::Element(this->v, index);
}

array::Element array::operator[](std::size_t index)
{
    return array::Element(this->v, index);
}

void array::forEach(std::function<void(const array::Element &elem)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        callback((*this)[i]);
    }
}

void array::forEach(std::function<void(const array::Element &elem, int index)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        callback((*this)[i], i);
    }
}

void array::forEach(std::function<void(const array::Element &elem, int index, const array &array)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        callback((*this)[i], i, *this);
    }
}

array::Element array::pop()
{
    return array::Element(HTML5_CALLv(this->v, pop));
}

array array::concat(const array &arr)
{
    return array(HTML5_CALLv(this->v, concat, arr.v));
}

bool array::includes(int searchElement, int fromIndex)
{
    return HTML5_CALLb(this->v, includes, searchElement, fromIndex);
}

bool array::includes(double searchElement, int fromIndex)
{
    return HTML5_CALLb(this->v, includes, searchElement, fromIndex);
}

bool array::includes(std::string searchElement, int fromIndex)
{
    return HTML5_CALLb(this->v, includes, searchElement, fromIndex);
}

std::string array::join(std::string separator)
{
    return HTML5_CALLs(this->v, join, separator);
}

array array::slice(int begin)
{
    return array(HTML5_CALLv(this->v, slice, begin));
}

array array::slice(int begin, int end)
{
    return array(HTML5_CALLv(this->v, slice, begin, end));
}

int array::indexOf(int searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, indexOf, int, searchElement, fromIndex);
}

int array::indexOf(double searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, indexOf, int, searchElement, fromIndex);
}

int array::indexOf(std::string searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, indexOf, int, searchElement, fromIndex);
}

int array::lastIndexOf(int searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, lastIndexOf, int, searchElement, fromIndex);
}

int array::lastIndexOf(double searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, lastIndexOf, int, searchElement, fromIndex);
}

int array::lastIndexOf(std::string searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, lastIndexOf, int, searchElement, fromIndex);
}

bool array::every(std::function<bool(const Element &elem)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        if (!callback((*this)[i])) {
            return false;
        }
    }
    return true;
}

bool array::some(std::function<bool(const Element &elem)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        if (callback((*this)[i])) {
            return true;
        }
    }
    return false;
}

array array::filter(std::function<bool(const Element &elem)> callback)
{
    array newarray;
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        if (callback((*this)[i])) {
            newarray.push((*this)[i]);
        }
    }
    return newarray;
}

array::Element array::find(std::function<bool(const Element &elem)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        if (callback((*this)[i])) {
            return (*this)[i];
        }
    }
#if ENABLE_EMSCRIPTEN
    return array::Element(emscripten::val::undefined());
#else
    return array::Element(emscripten::val(0));
#endif
}

int array::findIndex(std::function<bool(const Element &elem)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        if (callback((*this)[i])) {
            return i;
        }
    }
    return -1;
}

array array::map(std::function<Element(const Element &elem)> callback)
{
    array newarray;
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        newarray.push(callback((*this)[i]));
    }
    return newarray;
}

array::Element array::reduce(std::function<Element(Element,Element)> callback)
{
    // TODO
    return array::Element(emscripten::val(0));
}

array::Element array::reduce(std::function<Element(Element,Element,int)> callback)
{
    // TODO
    return array::Element(emscripten::val(0));
}

array::Element array::reduce(std::function<Element(Element,Element,int,const array&)> callback)
{
    // TODO
    return array::Element(emscripten::val(0));
}

array::Element array::reduceRight(std::function<Element(Element,Element)> callback)
{
    // TODO
    return array::Element(emscripten::val(0));
}

array::Element array::reduceRight(std::function<Element(Element,Element,int)> callback)
{
    // TODO
    return array::Element(emscripten::val(0));
}

array::Element array::reduceRight(std::function<Element(Element,Element,int,const array&)> callback)
{
    // TODO
    return array::Element(emscripten::val(0));
}

void array::fill(int value, int start)
{
    HTML5_CALL(this->v, fill, value, start);
}

void array::fill(int value, int start, int end)
{
    HTML5_CALL(this->v, fill, value, start, end);
}

void array::fill(double value, int start)
{
    HTML5_CALL(this->v, fill, value, start);
}

void array::fill(double value, int start, int end)
{
    HTML5_CALL(this->v, fill, value, start, end);
}

void array::fill(std::string value, int start)
{
    HTML5_CALL(this->v, fill, value, start);
}

void array::fill(std::string value, int start, int end)
{
    HTML5_CALL(this->v, fill, value, start, end);
}

array array::reverse()
{
    return array(HTML5_CALLv(this->v, reverse));
}

array::Element array::shift()
{
    return array::Element(HTML5_CALLv(this->v, shift));
}

array array::sort()
{
    return array(HTML5_CALLv(this->v, sort));
}

array array::sort(std::function<int(const Element &a, const Element &b)> compareFn)
{
    // TODO
    return array();
}

array array::splice(int index)
{
    return array(HTML5_CALLv(this->v, splice, index));
}

array array::splice(int index, unsigned long howMany)
{
    return array(HTML5_CALLv(this->v, splice, index, howMany));
}

HTML5_PROPERTY_IMPL(array, unsigned long, length);
