#pragma once

#include "libhtml5.h"

class PerformanceNavigation : public Object {
public:
    emscripten::val v;

    HTML5_READONLY_PROPERTY(PerformanceNavigation, unsigned short, type);
    HTML5_READONLY_PROPERTY(PerformanceNavigation, unsigned short, redirectCount);

    PerformanceNavigation(emscripten::val v);
    virtual ~PerformanceNavigation();
    static PerformanceNavigation *create(emscripten::val v);
};
