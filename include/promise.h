#pragma once

#include "libhtml5.h"
#include <functional>

class Promise : public Object {
public:
    unsigned long _length;

    Promise(emscripten::val v);
    virtual ~Promise();
    static Promise *create(std::function<Promise*(std::function<void*>,std::function<void*>)> fn);
    static Promise *create(emscripten::val v);
    Promise *all(std::vector<Promise *> iterable);
    Promise *race(std::vector<Promise *> iterable);
    Promise *reject(std::string reason);
    Promise *resolve(void *value);
    Promise *pcatch(std::function<Promise*(Promise*)> onRejected);
    Promise *then(std::function<Promise*(Promise*)> onFulfilled);
};
