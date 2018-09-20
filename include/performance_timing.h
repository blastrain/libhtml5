#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class PerformanceTiming : public Object {
public:

    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, navigationStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, unloadEventStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, unloadEventEnd);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, redirectStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, redirectEnd);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, fetchStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, domainLookupStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, domainLookupEnd);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, connectStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, connectEnd);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, secureConnectionStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, requestStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, responseStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, responseEnd);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, domLoading);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, domInteractive);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, domContentLoadedEventStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, domContentLoadedEventEnd);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, domComplete);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, loadEventStart);
    HTML5_READONLY_PROPERTY(PerformanceTiming, unsigned long long, loadEventEnd);

    PerformanceTiming(emscripten::val v);
    virtual ~PerformanceTiming();
    static PerformanceTiming *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
