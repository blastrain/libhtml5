#include "time_ranges.h"

TimeRanges::TimeRanges(emscripten::val v) : v(v)
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

unsigned long TimeRanges::getLength() const
{
    return HTML5_PROPERTY_GET(length, unsigned long);
}

void TimeRanges::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}
