#pragma once

class Object {
public:

    Object();
    virtual ~Object();
    void autorelease();
    void release();
    void retain();
    unsigned int referenceCount();
    bool isAutoRelease();

private:
    bool _isAutoRelease;
    unsigned int _refCount;
};