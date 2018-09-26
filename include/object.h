#pragma once

#include "libhtml5.h"
#include "native_object.h"
#include <map>

NAMESPACE_HTML5_BEGIN;

class Array;

class Object : public NativeObject {
public:
    emscripten::val v;

    Object(emscripten::val v);
    virtual ~Object();
    static Object *create();
    static Object *create(emscripten::val v);
    static Object *create(Object *o);
    template<typename... Args>
    static Object *assign(Object *target, const Args &... sources);
    static void freeze(Object *o);
    static Object *getOwnPropertyDescriptor(Object *o, std::string prop);
    static std::vector<std::string> getOwnPropertyNames(Object *o);
    static Object *getPropertyOf(Object *o);
    static bool is(std::string value1, std::string value2);
    static bool is(Object *value1, Object *value2);
    static bool is(int value1, int value2);
    static bool isExtensible(Object *o);
    static bool isFrozen(Object *o);
    static bool isSealed(Object *o);
    static std::vector<std::string> keys(Object *o);
    static Object *preventExtensions(Object *o);
    static Object *seal(Object *o);
    static Array *values(Object *o);
    static Array *entries(Object *o);
    virtual emscripten::val getValue() const { return this->v; };
    bool hasOwnProperty(std::string prop);
    bool isPrototypeOf(Object *o);
    bool propertyIsEnumerable(std::string s);
    std::string toLocaleString();
    std::string toString();
    Object *valueOf();

    template<typename T> T userData(const std::string &key);
    void userData(const std::string &key, int value);
    void userData(const std::string &key, double value);
    void userData(const std::string &key, std::string value);

private:
    std::map<std::string, std::tuple<int,double,std::string>> _userData;
    static emscripten::val to_val(Object *o) { return o->v; };
};

NAMESPACE_HTML5_END;
