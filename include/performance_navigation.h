#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class PerformanceNavigation : public Object {
public:

    HTML5_READONLY_PROPERTY(PerformanceNavigation, unsigned short, type);
    HTML5_READONLY_PROPERTY(PerformanceNavigation, unsigned short, redirectCount);

    PerformanceNavigation(emscripten::val v);
    virtual ~PerformanceNavigation();
    static PerformanceNavigation *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
