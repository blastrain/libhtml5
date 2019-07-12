#pragma once

#include "html5.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class NativeObject;

class AutoReleasePool {
public:

    AutoReleasePool();
    ~AutoReleasePool();
    static AutoReleasePool *sharedInstance();
    void addObject(NativeObject *o);
    void clear();
    bool contains(NativeObject *o) const;
    void releaseObjects();

private:
    std::vector<NativeObject *> objects;
};

NAMESPACE_HTML5_END;
