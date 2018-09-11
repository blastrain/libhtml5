#pragma once

#include "object.h"
#include <vector>

class Array : public Object {
public:

    Array();
    virtual ~Array();
    static Array *create();
    void add(Object *o);

private:
    std::vector<Object *> arr;
};
