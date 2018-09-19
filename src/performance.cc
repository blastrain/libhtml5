#include "performance_navigation.h"
#include "performance_entry.h"
#include "performance_timing.h"
#include "performance.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(Performance);

Performance::Performance(emscripten::val v) :
    Object(),
    v(v)
{

}

Performance::~Performance()
{

}

Performance *Performance::create(emscripten::val v)
{
    auto performance = new Performance(v);
    performance->autorelease();
    return performance;
}

void Performance::clearMarks()
{
    HTML5_CALL(this->v, clearMarks);
}

void Performance::clearMarks(std::string name)
{
    HTML5_CALL(this->v, clearMarks, name);
}

void Performance::clearMeasures()
{
    HTML5_CALL(this->v, clearMeasures);
}

void Performance::clearMeasures(std::string name)
{
    HTML5_CALL(this->v, clearMeasures, name);
}

void Performance::clearResourceTimings()
{
    HTML5_CALL(this->v, clearResourceTimings);
}

std::vector<PerformanceEntry *> Performance::getEntries()
{
    return toObjectArray<PerformanceEntry>(HTML5_CALLv(this->v, getEntries));
}

std::vector<PerformanceEntry *> Performance::getEntriesByName(std::string name)
{
    return toObjectArray<PerformanceEntry>(HTML5_CALLv(this->v, getEntriesByName, name));
}

std::vector<PerformanceEntry *> Performance::getEntriesByName(std::string name, std::string type)
{
    return toObjectArray<PerformanceEntry>(HTML5_CALLv(this->v, getEntriesByName, name, type));
}

std::vector<PerformanceEntry *> Performance::getEntriesByType(std::string type)
{
    return toObjectArray<PerformanceEntry>(HTML5_CALLv(this->v, getEntriesByType, type));
}

void Performance::mark(std::string name)
{
    HTML5_CALL(this->v, mark, name);
}

void Performance::measure(std::string name)
{
    HTML5_CALL(this->v, measure, name);
}

void Performance::measure(std::string name, std::string startMark)
{
    HTML5_CALL(this->v, measure, name, startMark);
}

void Performance::measure(std::string name, std::string startMark, std::string endMark)
{
    HTML5_CALL(this->v, measure, name, startMark, endMark);
}

double Performance::now()
{
    return HTML5_CALLf(this->v, now, double);
}

void Performance::setResourceTimingBufferSize(unsigned long maxSize)
{
    HTML5_CALL(this->v, setResourceTimingBufferSize, maxSize);
}

HTML5_READONLY_PROPERTY_OBJECT_IMPL(Performance, PerformanceNavigation, navigation);
HTML5_EVENT_HANDLER_PROPERTY_IMPL(Performance, EventHandler *, onresourcetimingbufferfull);
HTML5_READONLY_PROPERTY_OBJECT_IMPL(Performance, PerformanceTiming, timing);
HTML5_READONLY_PROPERTY_IMPL(Performance, double, timeOrigin);
