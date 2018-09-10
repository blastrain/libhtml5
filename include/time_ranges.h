#pragma once

#include <emscripten/val.h>

class TimeRanges {
public:
    emscripten::val v;
    unsigned long _length;

    TimeRanges(emscripten::val v);
    virtual ~TimeRanges();
    static TimeRanges *create(emscripten::val v);
    double start(unsigned long index);
    double end(unsigned long index);

    struct {
        TimeRanges &self;
        void operator=(unsigned long value) { self.setLength(value); };
        operator unsigned long() { return self.getLength(); };
    } length{*this};

    unsigned long getLength() const;
    void setLength(unsigned long value);
};
