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

Array::Element Array::pop()
{
    return Array::Element(HTML5_CALLv(this->v, pop));
}

Array *Array::concat(Array *array)
{
    return Array::create(HTML5_CALLv(this->v, concat, array->v));
}

bool Array::includes(int searchElement, int fromIndex)
{
    return HTML5_CALLb(this->v, includes, searchElement, fromIndex);
}

bool Array::includes(double searchElement, int fromIndex)
{
    return HTML5_CALLb(this->v, includes, searchElement, fromIndex);
}

bool Array::includes(std::string searchElement, int fromIndex)
{
    return HTML5_CALLb(this->v, includes, searchElement, fromIndex);
}

std::string Array::join(std::string separator)
{
    return HTML5_CALLs(this->v, join, separator);
}

Array *Array::slice(int begin)
{
    return Array::create(HTML5_CALLv(this->v, slice, begin));
}

Array *Array::slice(int begin, int end)
{
    return Array::create(HTML5_CALLv(this->v, slice, begin, end));
}

int Array::indexOf(int searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, indexOf, int, searchElement, fromIndex);
}

int Array::indexOf(double searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, indexOf, int, searchElement, fromIndex);
}

int Array::indexOf(std::string searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, indexOf, int, searchElement, fromIndex);
}

int Array::lastIndexOf(int searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, lastIndexOf, int, searchElement, fromIndex);
}

int Array::lastIndexOf(double searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, lastIndexOf, int, searchElement, fromIndex);
}

int Array::lastIndexOf(std::string searchElement, int fromIndex)
{
    return HTML5_CALLi(this->v, lastIndexOf, int, searchElement, fromIndex);
}

bool Array::every(std::function<bool(const Element &elem)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        if (!callback((*this)[i])) {
            return false;
        }
    }
    return true;
}

bool Array::some(std::function<bool(const Element &elem)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        if (callback((*this)[i])) {
            return true;
        }
    }
    return false;
}

Array *Array::filter(std::function<bool(const Element &elem)> callback)
{
    Array *newArray = Array::create();
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        if (callback((*this)[i])) {
            newArray->push((*this)[i]);
        }
    }
    return newArray;
}

Array::Element Array::find(std::function<bool(const Element &elem)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        if (callback((*this)[i])) {
            return (*this)[i];
        }
    }
#if ENABLE_EMSCRIPTEN
    return Array::Element(emscripten::val::undefined());
#else
    return Array::Element(emscripten::val(0));
#endif
}

int Array::findIndex(std::function<bool(const Element &elem)> callback)
{
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        if (callback((*this)[i])) {
            return i;
        }
    }
    return -1;
}

Array *Array::map(std::function<Element(const Element &elem)> callback)
{
    Array *newArray = Array::create();
    for (size_t i = 0; i < this->v["length"].as<unsigned long>(); i++) {
        newArray->push(callback((*this)[i]));
    }
    return newArray;
}

Array::Element Array::reduce(std::function<Element(Element,Element)> callback)
{
    // TODO
    return Array::Element(emscripten::val(0));
}

Array::Element Array::reduce(std::function<Element(Element,Element,int)> callback)
{
    // TODO
    return Array::Element(emscripten::val(0));
}

Array::Element Array::reduce(std::function<Element(Element,Element,int,Array*)> callback)
{
    // TODO
    return Array::Element(emscripten::val(0));
}

Array::Element Array::reduceRight(std::function<Element(Element,Element)> callback)
{
    // TODO
    return Array::Element(emscripten::val(0));
}

Array::Element Array::reduceRight(std::function<Element(Element,Element,int)> callback)
{
    // TODO
    return Array::Element(emscripten::val(0));
}

Array::Element Array::reduceRight(std::function<Element(Element,Element,int,Array*)> callback)
{
    // TODO
    return Array::Element(emscripten::val(0));
}

void Array::fill(int value, int start)
{
    HTML5_CALL(this->v, fill, value, start);
}

void Array::fill(int value, int start, int end)
{
    HTML5_CALL(this->v, fill, value, start, end);
}

void Array::fill(double value, int start)
{
    HTML5_CALL(this->v, fill, value, start);
}

void Array::fill(double value, int start, int end)
{
    HTML5_CALL(this->v, fill, value, start, end);
}

void Array::fill(std::string value, int start)
{
    HTML5_CALL(this->v, fill, value, start);
}

void Array::fill(std::string value, int start, int end)
{
    HTML5_CALL(this->v, fill, value, start, end);
}

Array *Array::reverse()
{
    return Array::create(HTML5_CALLv(this->v, reverse));
}

Array::Element Array::shift()
{
    return Array::Element(HTML5_CALLv(this->v, shift));
}

Array *Array::sort()
{
    return Array::create(HTML5_CALLv(this->v, sort));
}

Array *Array::sort(std::function<int(const Element &a, const Element &b)> compareFn)
{
    // TODO
    return Array::create();
}

Array *Array::splice(int index)
{
    return Array::create(HTML5_CALLv(this->v, splice, index));
}

Array *Array::splice(int index, unsigned long howMany)
{
    return Array::create(HTML5_CALLv(this->v, splice, index, howMany));
}

HTML5_PROPERTY_IMPL(Array, unsigned long, length);
