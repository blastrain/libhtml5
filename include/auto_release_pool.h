#pragma once

#include "libhtml5.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class Object;

class AutoReleasePool {
public:

    AutoReleasePool();
    ~AutoReleasePool();
    static AutoReleasePool *sharedInstance();
    void addObject(Object *o);
    void clear();
    bool contains(Object *o) const;
    void releaseObjects();

private:
    std::vector<Object *> objects;
};

NAMESPACE_HTML5_END;
