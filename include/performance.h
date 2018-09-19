#pragma once

#include "libhtml5.h"
#include "event_handler.h"
#include <vector>

NAMESPACE_HTML5_BEGIN;

class PerformanceNavigation;
class PerformanceEntry;
class PerformanceTiming;

class Performance : public Object {
public:
    emscripten::val v;

    HTML5_READONLY_PROPERTY(Performance, PerformanceNavigation *, navigation);
    HTML5_EVENT_HANDLER_PROPERTY(Performance, EventHandler *, onresourcetimingbufferfull);
    HTML5_READONLY_PROPERTY(Performance, PerformanceTiming *, timing);
    HTML5_READONLY_PROPERTY(Performance, double, timeOrigin);

    Performance(emscripten::val v);
    virtual ~Performance();
    static Performance *create(emscripten::val v);
    emscripten::val getValue() const { return this->v; };
    void clearMarks();
    void clearMarks(std::string name);
    void clearMeasures();
    void clearMeasures(std::string name);
    void clearResourceTimings();
    std::vector<PerformanceEntry *> getEntries();
    std::vector<PerformanceEntry *> getEntriesByName(std::string name);
    std::vector<PerformanceEntry *> getEntriesByName(std::string name, std::string type);
    std::vector<PerformanceEntry *> getEntriesByType(std::string type);
    void mark(std::string name);
    void measure(std::string name);
    void measure(std::string name, std::string startMark);
    void measure(std::string name, std::string startMark, std::string endMark);
    double now();
    void setResourceTimingBufferSize(unsigned long maxSize);
};

NAMESPACE_HTML5_END;
