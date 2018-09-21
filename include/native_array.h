#pragma once

#include "native_object.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class NativeArray : public NativeObject {
public:

    NativeArray();
    virtual ~NativeArray();
    static NativeArray *create();
    void add(NativeObject *o);

private:
    std::vector<NativeObject *> arr;
};

NAMESPACE_HTML5_END;
