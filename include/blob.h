#pragma once

#include "libhtml5.h"

class Blob : public Object {
public:
    emscripten::val v;
    unsigned long long _size;
    std::string _type;

    Blob(emscripten::val v);
    virtual ~Blob();
    static Blob *create(emscripten::val v);
    void close();
    Blob *slice(long long start = 0);
    Blob *slice(long long start, long long end, std::string contentType = "");
    unsigned long long getSize() const;
    void setSize(unsigned long long value);
    std::string getType() const;
    void setType(std::string value);

    struct {
        Blob &self;
        void operator=(unsigned long long value) { self.setSize(value); };
        operator unsigned long long() { return self.getSize(); };
    } size{*this};

    struct {
        Blob &self;
        void operator=(std::string value) { self.setType(value); };
        operator std::string() { return self.getType(); };
    } type{*this};

};
