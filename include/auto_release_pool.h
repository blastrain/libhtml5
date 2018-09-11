#pragma once

#include <vector>

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
