#pragma once

#include "object.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class Array : public Object {
public:

    HTML5_PROPERTY(Array, unsigned long, length);

    class Element {
    public:
        emscripten::val v;
        size_t index;

        Element(emscripten::val v, size_t index);
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
        operator Array*() const {
            return Array::create(this->v[this->index].as<emscripten::val>());
        };
        operator Object*() const {
            return Object::create(this->v[this->index].as<emscripten::val>());
        };
    };

    class iterator {
    public:
        iterator(Array *list, unsigned long index = 0) :
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
        Array *_list;
    };
    iterator begin() { return iterator(this); };
    iterator end() { return iterator(this, this->length); };

    Array(emscripten::val v);
    virtual ~Array();
    static Array *create(emscripten::val v);
    static Array *create(unsigned long length);
    Element operator[](std::size_t index) const;
    Element operator[](std::size_t index);
    void forEach(std::function<void(const Element &elem)> callback);
    void forEach(std::function<void(const Element &elem, int index)> callback);
    void forEach(std::function<void(const Element &elem, int index, Array *array)> callback);
    template<typename... Args> unsigned long push(const Args&... args) {
        return HTML5_CALL(this->v, push, to_val(args)...);
    };
    template<typename T> T pop();

private:
    emscripten::val to_val(Object *o) { return o->v; };
    emscripten::val to_val(std::string o) {
#if ENABLE_EMSCRIPTEN
        return emscripten::val(o);
#else
        return emscripten::val();
#endif
    }
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
