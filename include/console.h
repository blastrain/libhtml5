#pragma once

#include "libhtml5.h"
#include "html5_string.h"
#include "array.h"

NAMESPACE_HTML5_BEGIN;

class Console : public Object {
public:

    Console(emscripten::val v);
    virtual ~Console();
    static Console *create();
    static Console *create(emscripten::val v);
    template<typename... Args> void _assert(bool expr, const Args&... args) {
        HTML5_CALL(this->v, assert, expr, to_val(args)...);
    };
    void clear();
    void count();
    void count(std::string label);
    void countReset();
    void countReset(std::string label);
    void dir(Object *object);
    void dirxml(Object *object);
    template<typename... Args> void error(const Args&... args) {
        HTML5_CALL(this->v, error, to_val(args)...);
    };
    template<typename... Args> void exception(const Args&... args) {
        HTML5_CALL(this->v, exception, to_val(args)...);
    };
    void group();
    void group(std::string label);
    void groupCollapsed();
    void groupCollapsed(std::string label);
    void groupEnd();
    template<typename... Args> void info(const Args&... args) {
        HTML5_CALL(this->v, info, to_val(args)...);
    };
    template<typename... Args> void log(const Args&... args) {
        HTML5_CALL(this->v, log, to_val(args)...);
    };
    void profile();
    void profile(std::string profileName);
    void profileEnd();
    void profileEnd(std::string profileName);
    void table(Object *data);
    void table(Object *data, std::vector<std::string> columns);
    void time();
    void time(std::string label);
    void timeEnd();
    void timeEnd(std::string label);
    void timeLog();
    void timeLog(std::string label);
    void timeStamp();
    void timeStamp(std::string label);
    void trace();
    template<typename... Args> void warn(const Args&... args) {
        HTML5_CALL(this->v, warn, to_val(args)...);
    };

private:
    emscripten::val to_val(Object *o) { return o->v; };
    emscripten::val to_val(const array &o) { return o.v; };
    emscripten::val to_val(const html5::string &s) {
        return s.v;
    }
    emscripten::val to_val(const std::string &s) {
#if ENABLE_EMSCRIPTEN
        return emscripten::val(s);
#else
        return emscripten::val();
#endif
    }
    emscripten::val to_val(const char *s) {
        return to_val(std::string(s));
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
