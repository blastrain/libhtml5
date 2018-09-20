#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class Console : public Object {
public:

    Console(emscripten::val v);
    virtual ~Console();
    static Console *create();
    static Console *create(emscripten::val v);
    template<typename... Args> void _assert(bool expr, const Args&... args);
    void clear();
    void count();
    void count(std::string label);
    void countReset();
    void countReset(std::string label);
    void dir(Object *object);
    void dirxml(Object *object);
    template<typename... Args> void error(const Args&... args);
    template<typename... Args> void exception(const Args&... args);
    void group();
    void group(std::string label);
    void groupCollapsed();
    void groupCollapsed(std::string label);
    void groupEnd();
    template<typename... Args> void info(const Args&... args);
    template<typename... Args> void log(const Args&... args);
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
    template<typename... Args> void warn(const Args&... args);
};

NAMESPACE_HTML5_END;