#pragma once

#include "object.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class Array : public Object {
public:

    Array(emscripten::val v);
    virtual ~Array();
    static std::unique_ptr<Array> create(emscripten::val v);
};

NAMESPACE_HTML5_END;
