#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class TimeRanges : public Object {
public:

    HTML5_PROPERTY(TimeRanges, unsigned long, length);

    TimeRanges(emscripten::val v);
    virtual ~TimeRanges();
    static TimeRanges *create(emscripten::val v);
    double start(unsigned long index);
    double end(unsigned long index);
};

NAMESPACE_HTML5_END;
