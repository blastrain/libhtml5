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
    return this->v.call<double>("start", index);
}

double TimeRanges::end(unsigned long index)
{
    return this->v.call<double>("end", index);
}

unsigned long TimeRanges::getLength() const
{
    return this->v["length"].as<unsigned long>();
}

void TimeRanges::setLength(unsigned long value)
{
    this->_length = value;
    this->v.set("length", value);
}
