#pragma once

#define NAMESPACE_HTML5_BEGIN namespace html5 {
#define NAMESPACE_HTML5_END   }
#define USING_NAMESPACE_HTML5 using namespace html5

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

#include "object.h"

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

#define HTML5_STATIC_PRIMITIVE_INSTANCE(type, ...) (emscripten::val::global(#type))
#define HTML5_NEW_PRIMITIVE_INSTANCE(type, ...) (emscripten::val::global(#type).new_(__VA_ARGS__))

inline std::string __html5_val_to_string__(emscripten::val v)
{
    if (v == emscripten::val::null()) {
        return "";
    } else if (v == emscripten::val::undefined()) {
        return "";
    }
    return v.as<std::string>();
}

template<typename T> T __html5_property_get__(std::string o, emscripten::val v)
{
    return __html5_val_to_string__(v);
}

template<typename T> T *__html5_property_get__(html5::NativeObject *o, emscripten::val v)
{
    if (v == emscripten::val::null()) {
        return nullptr;
    } else if (v == emscripten::val::undefined()) {
        return nullptr;
    }
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
#define HTML5_CALLs(v, method, ...)        __html5_val_to_string__(v.call<emscripten::val>(#method, ## __VA_ARGS__))
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

#define __to_text__(text) #text

#define HTML5_BIND_CLASS(klassname)                                     \
    static klassname *to ## klassname(intptr_t ptr)                     \
    {                                                                   \
        return (klassname *)ptr;                                        \
    }                                                                   \
    static emscripten::class_<klassname> klass = emscripten::class_<klassname>(#klassname); \
    EMSCRIPTEN_BINDINGS(klassname ## _to ## klassname) { function(__to_text__(to ## klassname), &to ## klassname, emscripten::allow_raw_pointers()); } \
    EMSCRIPTEN_BINDINGS(klassname ## _getValue) { klass.property("_value", &klassname::getValue); }

#define HTML5_BIND_METHOD(klassname, method) EMSCRIPTEN_BINDINGS(klassname ## method) { klass.function(#method, &klassname::method); }

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

#include "object.h"

#define EM_ASM_(block, ...)
#define EM_ASM_INT(block, ...) (0)

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

#define HTML5_BIND_CLASS(klassname)
#define HTML5_BIND_METHOD(klassname, method)

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

#define HTML5_CLASS_FACTORY(klass) static std::map<std::string, std::function<klass*(emscripten::val)>> classFactories =

#define HTML5_SUBCLASS_FACTORY(name) { #name, [](emscripten::val v){ auto klass = name::create(v); klass->autorelease(); return klass; } }

#if ENABLE_EMSCRIPTEN

#define HTML5_CREATE_IMPL(klass)                                        \
    klass *klass::create(emscripten::val v)                             \
    {                                                                   \
        std::string className = v["constructor"]["name"].as<std::string>(); \
        if (className == #klass) {                                      \
            klass *instance = new klass(v);                             \
            instance->autorelease();                                    \
            return instance;                                            \
        } else if (classFactories.find(className) == classFactories.end()) { \
            std::cout << "cannot find " << className << " in classFactories" << std::endl; \
            return nullptr;                                             \
        }                                                               \
        return classFactories[className](v);                            \
    }

#else

#define HTML5_CREATE_IMPL(klass)                \
    klass *klass::create(emscripten::val v)     \
    {                                           \
        klass *e = new klass(v);                \
        e->autorelease();                       \
        return e;                               \
    }

#endif

#define HTML5_PROPERTY(klass, type, name)                           \
    type _ ## name;                                                 \
    struct {                                                        \
        klass &self;                                                \
        void operator=(type value) { self.set_ ## name(value); };   \
        operator type() { return self.get_ ## name(); };            \
    } name{*this};                                                  \
    type get_ ## name() const;                                      \
    void set_ ## name(type value);

#define HTML5_READONLY_PROPERTY(klass, type, name)          \
    type _ ## name;                                         \
    struct {                                                \
        klass &self;                                        \
        operator type() { return self.get_ ## name(); };    \
    } name{*this};                                          \
    type get_ ## name() const;

#define HTML5_PROPERTY_OBJECT(klass, type, name)                    \
    type *_ ## name;                                                \
    struct {                                                        \
        klass &self;                                                \
        void operator=(type *value) { self.set_ ## name(value); };  \
        operator type*() { return self.get_ ## name(); };           \
        type *operator->() { return self.get_ ## name(); };         \
    } name{*this};                                                  \
    type *get_ ## name() const;                                     \
    void set_ ## name(type *value);

#define HTML5_READONLY_PROPERTY_OBJECT(klass, type, name)           \
    type *_ ## name;                                                \
    struct {                                                        \
        klass &self;                                                \
        operator type*() { return self.get_ ## name(); };           \
        type *operator->() { return self.get_ ## name(); };         \
    } name{*this};                                                  \
    type *get_ ## name() const;

#define HTML5_VIRTUAL_PROPERTY(klass, type, name)   \
    virtual type get_ ## name() const;              \
    virtual void set_ ## name(type value);

#define HTML5_VIRTUAL_READONLY_PROPERTY(klass, type, name) \
    virtual type get_ ## name() const;

#define HTML5_VIRTUAL_PROPERTY_OBJECT(klass, type, name)    \
    virtual type *get_ ## name() const;                     \
    virtual void set_ ## name(type *value);

#define HTML5_VIRTUAL_READONLY_PROPERTY_OBJECT(klass, type, name) \
    virtual type *get_ ## name() const;

#define HTML5_PURE_VIRTUAL_PROPERTY(klass, type, name)              \
    type _ ## name;                                                 \
    struct {                                                        \
        klass &self;                                                \
        void operator=(type value) { self.set_ ## name(value); };   \
        operator type() { return self.get_ ## name(); };            \
    } name{*this};                                                  \
    type get_ ## name() const = 0;                                  \
    void set_ ## name(type value) = 0;

#define HTML5_PURE_VIRTUAL_PROPERTY_OBJECT(klass, type, name)       \
    type *_ ## name;                                                \
    struct {                                                        \
        klass &self;                                                \
        void operator=(type *value) { self.set_ ## name(value); };  \
        operator type*() { return self.get_ ## name(); };           \
        type *operator->() { return self.get_ ## name(); };         \
    } name{*this};                                                  \
    virtual type *get_ ## name() const = 0;                         \
    virtual void set_ ## name(type *value) = 0;

#define HTML5_PURE_VIRTUAL_READONLY_PROPERTY(klass, type, name) \
    type _ ## name;                                             \
    struct {                                                    \
        klass &self;                                            \
        operator type() { return self.get_ ## name(); };        \
    } name{*this};                                              \
    virtual type get_ ## name() const = 0;

#define HTML5_PURE_VIRTUAL_READONLY_PROPERTY_OBJECT(klass, type, name)  \
    type *_ ## name;                                                     \
    struct {                                                            \
        klass &self;                                                    \
        operator type*() { return self.get_ ## name(); };               \
    } name{*this};                                                      \
    virtual type *get_ ## name() const = 0;

#define HTML5_EVENT_HANDLER_PROPERTY(klass, type, name) \
    HTML5_PROPERTY(klass, type, name);                  \
    void callback_ ## name(emscripten::val e);

#define HTML5_ERROR_HANDLER_PROPERTY(klass, type, name)                 \
    HTML5_PROPERTY(klass, type, name);                                  \
    void callback_ ## name(emscripten::val e, std::string source, unsigned long lineno, unsigned long colno, emscripten::val error);

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
        this->_ ## name = value;                                        \
        EM_ASM_({                                                       \
                const elem = Module.to ## klass($0);                    \
                elem._value.name = function(e) { elem.callback_ ## name(e); }; \
            }, this);                                                   \
    }                                                                   \
    void klass::callback_ ## name(emscripten::val e)                    \
    {                                                                   \
        if (!this->_ ## name) return;                                   \
        (*this->_ ## name)(Event::create(e));                           \
    }                                                                   \
    HTML5_BIND_METHOD(klass, callback_ ## name);

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
        this->_ ## name = value;                                        \
        EM_ASM_({                                                       \
                const elem = Module.to ## klass($0);                    \
                elem._value.name = function(event, source, lineno, colno, error) { \
                    elem.callback_ ## name(event, source, lineno, colno, error); \
                };                                                      \
            }, this);                                                   \
    }                                                                   \
    void klass::callback_ ## name(emscripten::val e, std::string source, unsigned long lineno, unsigned long colno, emscripten::val error) \
    {                                                                   \
        if (!this->_ ## name) return;                                   \
        (*this->_ ## name)(Event::create(e), source, lineno, colno, NULL); \
    }                                                                   \
    HTML5_BIND_METHOD(klass, callback_ ## name);


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

#define HTML5_PURE_VIRTUAL_PROPERTY_OBJECT(klass, type, name)       \
    type *_ ## name;                                                \
    struct {                                                        \
        klass &self;                                                \
        void operator=(type *value) { self.set_ ## name(value); };  \
        operator type*() { return self.get_ ## name(); };           \
        type *operator->() { return self.get_ ## name(); };         \
    } name{*this};                                                  \
    virtual type *get_ ## name() const = 0;                         \
    virtual void set_ ## name(type *value) = 0;

#define HTML5_VIRTUAL_PROPERTY_OBJECT(klass, type, name)    \
    virtual type *get_ ## name() const;                     \
    virtual void set_ ## name(type *value);

#include "export.h"
