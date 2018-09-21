#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class NativeObject {
public:

    NativeObject();
    virtual ~NativeObject();
    void autorelease();
    void release();
    void retain();
    unsigned int referenceCount();
    bool isAutoRelease();

private:
    bool _isAutoRelease;
    unsigned int _refCount;
};

NAMESPACE_HTML5_END;
