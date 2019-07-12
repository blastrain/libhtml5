#pragma once

#include "object.h"
#include "html5_string.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class array : public Object {
public:

    HTML5_PROPERTY(array, unsigned long, length);

    class Element {
    public:
        emscripten::val v;
        size_t index;

        Element(emscripten::val v, size_t index = 0);
        ~Element();
        void operator=(int value);
        void operator=(double value);
        void operator=(std::string value);
        void operator=(Object *value);
        operator int() const {
            return this->v[this->index].as<int>();
        };
        operator double() const {
            return this->v[this->index].as<double>();
        };
        operator std::string() const {
            return this->v[this->index].as<std::string>();
        };
        operator html5::string() const {
            return html5::string(this->v[this->index].as<emscripten::val>());
        }
        operator array*() const {
            return array::create(this->v[this->index].as<emscripten::val>());
        };
        operator Object*() const {
            return Object::create(this->v[this->index].as<emscripten::val>());
        };
    };

    class iterator {
    public:
        iterator(array *list, unsigned long index = 0) :
            _list(list),
            _index(index){};
        virtual ~iterator() {};
        Element operator*() { return (*this->_list)[this->_index]; };
        iterator& operator++() {  
            this->_index++;
            return *this;
        };
        bool operator!=(const iterator& v) { return this->_index != v._index; };
    private:
        unsigned long _index;
        array *_list;
    };
    iterator begin() { return iterator(this); };
    iterator end() { return iterator(this, this->length); };

    array(emscripten::val v);
    template<typename... Args> array(const Args&... args) : Object(HTML5_NEW_PRIMITIVE_INSTANCE(Array)) {
        push(args...);
    };
    virtual ~array();
    static array *create(emscripten::val v);
    static array *create(unsigned long length = 0);
    Element operator[](std::size_t index) const;
    Element operator[](std::size_t index);
    void forEach(std::function<void(const Element &elem)> callback);
    void forEach(std::function<void(const Element &elem, int index)> callback);
    void forEach(std::function<void(const Element &elem, int index, const array &array)> callback);
    template<typename... Args> unsigned long push(const Args&... args) {
        return HTML5_CALLi(this->v, push, unsigned long, to_val(args)...);
    };
    Element pop();
    array concat(const array &array);
    bool includes(int searchElement, int fromIndex = 0);
    bool includes(double searchElement, int fromIndex = 0);
    bool includes(std::string searchElement, int fromIndex = 0);
    std::string join(std::string separator = ",");
    array slice(int begin = 0);
    array slice(int begin, int end);
    int indexOf(int searchElement, int fromIndex = 0);
    int indexOf(double searchElement, int fromIndex = 0);
    int indexOf(std::string searchElement, int fromIndex = 0);
    int lastIndexOf(int searchElement, int fromIndex = 0);
    int lastIndexOf(double searchElement, int fromIndex = 0);
    int lastIndexOf(std::string searchElement, int fromIndex = 0);
    bool every(std::function<bool(const Element &elem)> callback);
    bool some(std::function<bool(const Element &elem)> callback);
    array filter(std::function<bool(const Element &elem)> callback);
    Element find(std::function<bool(const Element &elem)> callback);
    int findIndex(std::function<bool(const Element &elem)> callback);
    array map(std::function<Element(const Element &elem)> callback);
    Element reduce(std::function<Element(Element,Element)> callback);
    Element reduce(std::function<Element(Element,Element,int)> callback);
    Element reduce(std::function<Element(Element,Element,int,const array&)> callback);
    Element reduceRight(std::function<Element(Element,Element)> callback);
    Element reduceRight(std::function<Element(Element,Element,int)> callback);
    Element reduceRight(std::function<Element(Element,Element,int,const array&)> callback);
    void fill(int value, int start = 0);
    void fill(int value, int start, int end);
    void fill(double value, int start = 0);
    void fill(double value, int start, int end);
    void fill(std::string value, int start = 0);
    void fill(std::string value, int start, int end);
    array reverse();
    Element shift();
    array sort();
    array sort(std::function<int(const Element &a, const Element &b)> compareFn);
    array splice(int index);
    array splice(int index, unsigned long howMany);
    template<typename... Args> array splice(int index, unsigned long howMany, const Args&... args) {
        return array(HTML5_CALL(this->v, splice, index, howMany, to_val(args)...));
    };
    template<typename... Args> unsigned long unshift(const Args& ...args) {
        return HTML5_CALLi(this->v, unshift, unsigned long, to_val(args)...);
    };
    
private:
    emscripten::val to_val(Object *o) { return o->v; };
    emscripten::val to_val(const array &o) { return o.v; };
    emscripten::val to_val(const Element &o) { return o.v; };
    emscripten::val to_val(std::string o) {
#if ENABLE_EMSCRIPTEN
        return emscripten::val(o);
#else
        return emscripten::val();
#endif
    }
    emscripten::val to_val(const char *o) { return to_val(std::string(o)); };
    emscripten::val to_val(int o) {
#if ENABLE_EMSCRIPTEN
        return emscripten::val(o);
#else
        return emscripten::val();
#endif
    }
    emscripten::val to_val(double o) {
#if ENABLE_EMSCRIPTEN
        return emscripten::val(o);
#else
        return emscripten::val();
#endif
    }
};

NAMESPACE_HTML5_END;
