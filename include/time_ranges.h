#pragma once

#include "libhtml5.h"

class TimeRanges : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(TimeRanges, unsigned long, length);

    TimeRanges(emscripten::val v);
    virtual ~TimeRanges();
    static TimeRanges *create(emscripten::val v);
    double start(unsigned long index);
    double end(unsigned long index);
};
