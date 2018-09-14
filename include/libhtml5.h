#pragma once

#include "object.h"
#include <string>

#if PROPERTY_TRACE

#include <iostream>

#define HTML5_PROPERTY_TRACE_PRINT(prefix, content) (std::cout << prefix << " " << content << std::endl)

#else

#define HTML5_PROPERTY_TRACE_PRINT(prefix, content)

#endif


#if ENABLE_EMSCRIPTEN

#include <emscripten/emscripten.h>
#include <emscripten/val.h>
#include <emscripten/bind.h>

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

#define HTML5_STATIC_PRIMITIVE_INSTANCE(type, ...) (emscripten::val::global(#type))
#define HTML5_NEW_PRIMITIVE_INSTANCE(type, ...) (emscripten::val::global(#type).new_(__VA_ARGS__))

template<typename T> T *__html5_property_get__(Object *o, emscripten::val v)
{
    return T::create(v);
}

template<typename T> T __html5_property_get__(T o, emscripten::val v)
{
    return v.as<T>();
}

#define HTML5_PROPERTY_GET(pname, type) (__html5_property_get__<type>(this->_ ## pname, this->v[#pname]))

#define HTML5_CALL(v, method, ...)         v.call<void>(#method, ## __VA_ARGS__)
#define HTML5_CALLi(v, method, rtype, ...) v.call<rtype>(#method, ## __VA_ARGS__)
#define HTML5_CALLf(v, method, rtype, ...) v.call<rtype>(#method, ## __VA_ARGS__)
#define HTML5_CALLb(v, method, ...)        v.call<bool>(#method, ## __VA_ARGS__)
#define HTML5_CALLs(v, method, ...)        v.call<std::string>(#method, ## __VA_ARGS__)
#define HTML5_CALLv(v, method, ...)        v.call<emscripten::val>(#method, ## __VA_ARGS__)

template<typename T> emscripten::val toJSArray(std::vector<T> array)
{
    emscripten::val v = emscripten::val::array();
    for (size_t i = 0; i < array.size(); i++) {
        v.set(i, array[i]);
    }
    return v;
}

template<typename T> std::vector<T> toArray(emscripten::val v)
{
    return emscripten::vecFromJSArray<T>(v);
}

template<typename T> std::vector<T *> toObjectArray(emscripten::val v)
{
    std::vector<T *> ret;
    std::vector<emscripten::val> arr = emscripten::vecFromJSArray<emscripten::val>(v);
    for (size_t i = 0; arr.size(); i++) {
        ret.push_back(T::create(arr[i]));
    }
    return ret;
}

#else

#if defined __APPLE__

#include <Opengl/gl.h>

#endif

namespace emscripten {

    class val {
    public:
        void set(std::string name, double value) {};
        void set(std::string name, std::string value) {};
        void set(std::string name, val value) {};
    };

};

#define EM_ASM_(block, ...)

#define HTML5_STATIC_PRIMITIVE_INSTANCE(type, ...) emscripten::val()
#define HTML5_NEW_PRIMITIVE_INSTANCE(type, ...) emscripten::val()
#define HTML5_PROPERTY_GET(pname, type) this->_ ## pname
#define HTML5_CALL(v, method, ...)
#define HTML5_CALLi(v, method, rtype, ...) (0)
#define HTML5_CALLf(v, method, rtype, ...) (0)
#define HTML5_CALLb(v, method, ...) (false)
#define HTML5_CALLs(v, method, ...) ("")
#define HTML5_CALLv(v, method, ...) emscripten::val()

template<typename T> emscripten::val toJSArray(std::vector<T> array)
{
    return emscripten::val();
}

template<typename T> std::vector<T> toArray(emscripten::val v)
{
    std::vector<T> ret;
    return ret;
}

template<typename T> std::vector<T *> toObjectArray(emscripten::val v)
{
    std::vector<T *> ret;
    return ret;
}

#endif

#define HTML5_DELETE(o) do {                    \
        if (o) {                                \
            delete o;                           \
            o = NULL;                           \
        }                                       \
    } while (0)

#define HTML5_RELEASE(o) do {                   \
        if (o && o->isAutoRelease()) {          \
            o->release();                       \
        } else {                                \
            HTML5_DELETE(o);                    \
        }                                       \
    } while (0)

#define HTML5_PROPERTY_SET(pname, value) do {   \
        this->_ ## pname = value;               \
        this->v.set(#pname, value);             \
    } while (0)

#define HTML5_PROPERTY_OBJECT_SET(pname, value) do {                    \
        if (this->_ ## pname && this->_ ## pname->isAutoRelease()) {    \
            this->_ ## pname->release();                                \
        }                                                               \
        if (value && value->isAutoRelease()) {                          \
            value->retain();                                            \
        }                                                               \
        this->_ ## pname = value;                                       \
        this->v.set(#pname, value->v);                                  \
    } while (0)

#define CLASS_FACTORY_MAP(name) { #name, [](emscripten::val v){ auto klass = name::create(v); klass->autorelease(); return klass; } }

#define HTML5_PROPERTY(klass, type, name)                           \
    type _ ## name;                                                 \
    struct {                                                        \
        klass &self;                                                \
        void operator=(type value) { self.set_ ## name(value); };   \
        operator type() { return self.get_ ## name(); };            \
    } name{*this};                                                  \
    type get_ ## name() const;                                      \
    void set_ ## name(type value);

#define HTML5_EVENT_HANDLER_PROPERTY(klass, type, name) \
    HTML5_PROPERTY(klass, type, name);                  \
    void on_ ## name(emscripten::val e);

#define HTML5_ERROR_HANDLER_PROPERTY(klass, type, name)                 \
    HTML5_PROPERTY(klass, type, name);                                  \
    void on_ ## name(emscripten::val e, std::string source, unsigned long lineno, unsigned long colno, emscripten::val error);

#define HTML5_READONLY_PROPERTY(klass, type, name)          \
    type _ ## name;                                         \
    struct {                                                \
        klass &self;                                        \
        operator type() { return self.get_ ## name(); };    \
    } name{*this};                                          \
    type get_ ## name() const;

#define HTML5_PROPERTY_TRACE_GETTER(name) HTML5_PROPERTY_TRACE_PRINT("[property:getter]", #name)
#define HTML5_PROPERTY_TRACE_SETTER(name) HTML5_PROPERTY_TRACE_PRINT("[property:setter]", #name)

#define HTML5_PROPERTY_IMPL(klass, type, name)  \
    type klass::get_ ## name() const            \
    {                                           \
        HTML5_PROPERTY_TRACE_GETTER(name);      \
        return HTML5_PROPERTY_GET(name, type);  \
    }                                           \
                                                \
    void klass::set_ ## name(type value)        \
    {                                           \
        HTML5_PROPERTY_TRACE_SETTER(name);      \
        HTML5_PROPERTY_SET(name, value);        \
    }                                           

#define HTML5_EVENT_HANDLER_PROPERTY_IMPL(klass, type, name)            \
    type klass::get_ ## name() const                                    \
    {                                                                   \
        HTML5_PROPERTY_TRACE_GETTER(name);                              \
        return this->_ ## name;                                         \
    }                                                                   \
                                                                        \
    void klass::set_ ## name(type value)                                \
    {                                                                   \
        HTML5_PROPERTY_TRACE_SETTER(name);                              \
        HTML5_PROPERTY_SET(name, value);                                \
        EM_ASM_({                                                       \
                const elem = Module.to ## klass($0);                    \
                elem._value.name = function(e) { elem.on_ ## name(e); }; \
            }, this);                                                   \
    }                                                                   \
    void klass::on_ ## name(emscripten::val e)                          \
    {                                                                   \
        if (!this->_ ## name) return;                                   \
        (*this->_ ## name)(Event::create(e));                           \
    }

#define HTML5_ERROR_HANDLER_PROPERTY_IMPL(klass, type, name)            \
    type klass::get_ ## name() const                                    \
    {                                                                   \
        HTML5_PROPERTY_TRACE_GETTER(name);                              \
        return this->_ ## name;                                         \
    }                                                                   \
                                                                        \
    void klass::set_ ## name(type value)                                \
    {                                                                   \
        HTML5_PROPERTY_TRACE_SETTER(name);                              \
        HTML5_PROPERTY_SET(name, value);                                \
        EM_ASM_({                                                       \
                const elem = Module.to ## klass($0);                    \
                elem._value.name = function(event, source, lineno, colno, error) { \
                    elem.on_ ## name(event, source, lineno, colno, error); \
                };                                                      \
            }, this);                                                   \
    }                                                                   \
    void klass::on_ ## name(emscripten::val e, std::string source, unsigned long lineno, unsigned long colno, emscripten::val error) \
    {                                                                   \
        if (!this->_ ## name) return;                                   \
        (*this->_ ## name)(Event::create(e), source, lineno, colno, NULL); \
    }


#define HTML5_READONLY_PROPERTY_IMPL(klass, type, name) \
    type klass::get_ ## name() const                    \
    {                                                   \
        HTML5_PROPERTY_TRACE_GETTER(name);              \
        return HTML5_PROPERTY_GET(name, type);          \
    }

#define HTML5_PROPERTY_OBJECT_IMPL(klass, type, name)   \
    type *klass::get_ ## name() const                   \
    {                                                   \
        HTML5_PROPERTY_TRACE_GETTER(name);              \
        return HTML5_PROPERTY_GET(name, type);          \
    }                                                   \
                                                        \
    void klass::set_ ## name(type *value)               \
    {                                                   \
        HTML5_PROPERTY_TRACE_SETTER(name);              \
        HTML5_PROPERTY_OBJECT_SET(name, value);         \
    }

#define HTML5_READONLY_PROPERTY_OBJECT_IMPL(klass, type, name)  \
    type *klass::get_ ## name() const                           \
    {                                                           \
        HTML5_PROPERTY_TRACE_GETTER(name);                      \
        return HTML5_PROPERTY_GET(name, type);                  \
    }
