#pragma once

#include "object.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class Array : public Object {
public:

    Array();
    virtual ~Array();
    static Array *create();
    void add(Object *o);

private:
    std::vector<Object *> arr;
};

NAMESPACE_HTML5_END;
