#include "time_ranges.h"

USING_NAMESPACE_HTML5;

TimeRanges::TimeRanges(emscripten::val v) :
    Object(v)
{
    
}

TimeRanges::~TimeRanges()
{

}

TimeRanges *TimeRanges::create(emscripten::val v)
{
    TimeRanges *tr = new TimeRanges(v);
    tr->autorelease();
    return tr;
}

double TimeRanges::start(unsigned long index)
{
    return HTML5_CALLf(this->v, start, double, index);
}

double TimeRanges::end(unsigned long index)
{
    return HTML5_CALLf(this->v, end, double, index);
}

HTML5_PROPERTY_IMPL(TimeRanges, unsigned long, length);
