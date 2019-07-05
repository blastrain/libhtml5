#pragma once

#include "libhtml5.h"
#include <functional>

NAMESPACE_HTML5_BEGIN;

typedef std::function<void()> chainVoid;
typedef std::function<void(const std::string&)> chainString;

typedef std::function<void(chainVoid, chainVoid)> executor;
typedef std::function<void(chainString, chainVoid)> executorString;


class Promise : public Object {
public:

    HTML5_PROPERTY(Promise, unsigned long, length);

    Promise(emscripten::val v);
    virtual ~Promise();
    static Promise *create(executor fn);
    static Promise *create(executorString fn);
    static Promise *create(emscripten::val v);
    Promise *all(std::vector<Promise *> iterable);
    Promise *race(std::vector<Promise *> iterable);
    Promise *reject(std::string reason);
    Promise *resolve(void *value);
    Promise *pcatch(std::function<Promise*(Promise*)> onRejected);
    Promise *then(chainString onFulfilled);

    executorString execStr;
    std::vector<chainString> chainFns;

    void executeString(emscripten::val resolve, emscripten::val reject);
    void callbackThenString(emscripten::val resolve);
};

NAMESPACE_HTML5_END;
