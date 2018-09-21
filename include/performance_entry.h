#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class PerformanceEntry : public Object {
public:

    HTML5_READONLY_PROPERTY(PerformanceEntry, std::string, name);
    HTML5_READONLY_PROPERTY(PerformanceEntry, std::string, entryType);
    HTML5_READONLY_PROPERTY(PerformanceEntry, double, startTime);
    HTML5_READONLY_PROPERTY(PerformanceEntry, double, duration);

    PerformanceEntry(emscripten::val v);
    virtual ~PerformanceEntry();
    static PerformanceEntry *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
