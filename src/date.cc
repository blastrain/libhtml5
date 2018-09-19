#include "date.h"

USING_NAMESPACE_HTML5;

Date::Date(emscripten::val v) : v(v)
{

}

Date::~Date()
{

}

Date *Date::create()
{
    Date *d = new Date(HTML5_NEW_PRIMITIVE_INSTANCE(Date));
    d->autorelease();
    return d;
}

Date *Date::create(emscripten::val v)
{
    Date *d = new Date(v);
    d->autorelease();
    return d;
}

Date *Date::create(int year, int month)
{
    Date *d = new Date(HTML5_NEW_PRIMITIVE_INSTANCE(Date, year, month));
    d->autorelease();
    return d;
}

Date *Date::create(int year, int month, int date)
{
    Date *d = new Date(HTML5_NEW_PRIMITIVE_INSTANCE(Date, year, month, date));
    d->autorelease();
    return d;
}

Date *Date::create(int year, int month, int date, int hours)
{
    Date *d = new Date(HTML5_NEW_PRIMITIVE_INSTANCE(Date, year, month, date, hours));
    d->autorelease();
    return d;
}

Date *Date::create(int year, int month, int date, int hours, int minutes)
{
    Date *d = new Date(HTML5_NEW_PRIMITIVE_INSTANCE(Date, year, month, date, hours, minutes));
    d->autorelease();
    return d;
}

Date *Date::create(int year, int month, int date, int hours, int minutes, int seconds)
{
    Date *d = new Date(HTML5_NEW_PRIMITIVE_INSTANCE(Date, year, month, date, hours, minutes, seconds));
    d->autorelease();
    return d;
}

Date *Date::create(int year, int month, int date, int hours, int minutes, int seconds, int ms)
{
    Date *d = new Date(HTML5_NEW_PRIMITIVE_INSTANCE(Date, year, month, date, hours, minutes, seconds, ms));
    d->autorelease();
    return d;
}

Date *Date::now()
{
    emscripten::val klass = HTML5_STATIC_PRIMITIVE_INSTANCE(Date);
    return Date::create(HTML5_CALLv(klass, now));
}

Date *Date::UTC(int year, int month)
{
    emscripten::val klass = HTML5_STATIC_PRIMITIVE_INSTANCE(Date);
    return Date::create(HTML5_CALLv(klass, UTC, year, month));
}

Date *Date::UTC(int year, int month, int date)
{
    emscripten::val klass = HTML5_STATIC_PRIMITIVE_INSTANCE(Date);
    return Date::create(HTML5_CALLv(klass, UTC, year, month, date));
}

Date *Date::UTC(int year, int month, int date, int hours)
{
    emscripten::val klass = HTML5_STATIC_PRIMITIVE_INSTANCE(Date);
    return Date::create(HTML5_CALLv(klass, UTC, year, month, date, hours));
}

Date *Date::UTC(int year, int month, int date, int hours, int minutes)
{
    emscripten::val klass = HTML5_STATIC_PRIMITIVE_INSTANCE(Date);
    return Date::create(HTML5_CALLv(klass, UTC, year, month, date, hours, minutes));
}

Date *Date::UTC(int year, int month, int date, int hours, int minutes, int seconds)
{
    emscripten::val klass = HTML5_STATIC_PRIMITIVE_INSTANCE(Date);
    return Date::create(HTML5_CALLv(klass, UTC, year, month, date, hours, minutes, seconds));
}

Date *Date::UTC(int year, int month, int date, int hours, int minutes, int seconds, int ms)
{
    emscripten::val klass = HTML5_STATIC_PRIMITIVE_INSTANCE(Date);
    return Date::create(HTML5_CALLv(klass, UTC, year, month, date, hours, minutes, seconds, ms));
}

double Date::getDate()
{
    return HTML5_CALLf(this->v, getDate, double);
}

int Date::getDay()
{
    return HTML5_CALLi(this->v, getDay, int);
}

int Date::getFullYear()
{
    return HTML5_CALLi(this->v, getFullYear, int);
}

int Date::getHours()
{
    return HTML5_CALLi(this->v, getHours, int);
}

int Date::getMilliseconds()
{
    return HTML5_CALLi(this->v, getMilliseconds, int);
}

int Date::getMinutes()
{
    return HTML5_CALLi(this->v, getMinutes, int);
}

int Date::getMonth()
{
    return HTML5_CALLi(this->v, getMonth, int);
}

int Date::getSeconds()
{
    return HTML5_CALLi(this->v, getSeconds, int);
}

double Date::getTime()
{
    return HTML5_CALLf(this->v, getTime, double);
}

int Date::getTimezoneOffset()
{
    return HTML5_CALLi(this->v, getTimezoneOffset, int);
}

double Date::getUTCDate()
{
    return HTML5_CALLf(this->v, getUTCDate, double);
}

int Date::getUTCDay()
{
    return HTML5_CALLi(this->v, getUTCDay, int);
}

int Date::getUTCFullYear()
{
    return HTML5_CALLi(this->v, getUTCFullYear, int);
}

int Date::getUTCHours()
{
    return HTML5_CALLi(this->v, getUTCHours, int);
}

int Date::getUTCMilliseconds()
{
    return HTML5_CALLi(this->v, getUTCMilliseconds, int);
}

int Date::getUTCMinutes()
{
    return HTML5_CALLi(this->v, getUTCMinutes, int);
}

int Date::getUTCMonth()
{
    return HTML5_CALLi(this->v, getUTCMonth, int);
}

int Date::getUTCSeconds()
{
    return HTML5_CALLi(this->v, getUTCSeconds, int);
}

double Date::setDate(int date)
{
    return HTML5_CALLf(this->v, setDate, double, date);
}

double Date::setFullYear(int year)
{
    return HTML5_CALLf(this->v, setFullYear, double, year);
}

double Date::setFullyear(int year, int month)
{
    return HTML5_CALLf(this->v, setFullYear, double, year, month);
}

double Date::setFullyear(int year, int month, int date)
{
    return HTML5_CALLf(this->v, setFullYear, double, year, month ,date);
}

double Date::setHours(int hour)
{
    return HTML5_CALLf(this->v, setHours, double, hour);
}

double Date::setHours(int hour, int min)
{
    return HTML5_CALLf(this->v, setHours, double, hour, min);
}

double Date::setHours(int hour, int min, int sec)
{
    return HTML5_CALLf(this->v, setHours, double, hour, min, sec);
}

double Date::setHours(int hour, int min, int sec, int ms)
{
    return HTML5_CALLf(this->v, setHours, double, hour, min, sec, ms);
}

double Date::setMilliseconds(int ms)
{
    return HTML5_CALLf(this->v, setMilliseconds, double, ms);
}

double Date::setMinutes(int min)
{
    return HTML5_CALLf(this->v, setMinutes, double, min);
}

double Date::setMinutes(int min, int sec)
{
    return HTML5_CALLf(this->v, setMinutes, double, min, sec);
}

double Date::setMinutes(int min, int sec, int ms)
{
    return HTML5_CALLf(this->v, setMinutes, double, min, sec, ms);
}

double Date::setMonth(int month)
{
    return HTML5_CALLf(this->v, setMonth, double, month);
}

double Date::setMonth(int month, int date)
{
    return HTML5_CALLf(this->v, setMonth, double, month, date);
}

double Date::setSeconds(int sec)
{
    return HTML5_CALLf(this->v, setSeconds, double, sec);
}

double Date::setSeconds(int sec, int ms)
{
    return HTML5_CALLf(this->v, setSeconds, double, sec, ms);
}

double Date::setTime(double time)
{
    return HTML5_CALLf(this->v, setTime, double, time);
}

double Date::setUTCDate(int date)
{
    return HTML5_CALLf(this->v, setUTCDate, double, date);
}

double Date::setUTCFullYear(int year)
{
    return HTML5_CALLf(this->v, setUTCFullYear, double, year);
}

double Date::setUTCFullyear(int year, int month)
{
    return HTML5_CALLf(this->v, setUTCFullYear, double, year, month);
}

double Date::setUTCFullyear(int year, int month, int date)
{
    return HTML5_CALLf(this->v, setUTCFullYear, double, year, month, date);
}

double Date::setUTCHours(int hour)
{
    return HTML5_CALLf(this->v, setUTCHours, double, hour);
}

double Date::setUTCHours(int hour, int min)
{
    return HTML5_CALLf(this->v, setUTCHours, double, hour, min);
}

double Date::setUTCHours(int hour, int min, int sec)
{
    return HTML5_CALLf(this->v, setUTCHours, double, hour, min, sec);
}

double Date::setUTCHours(int hour, int min, int sec, int ms)
{
    return HTML5_CALLf(this->v, setUTCHours, double, hour, min, sec, ms);
}

double Date::setUTCMilliseconds(int ms)
{
    return HTML5_CALLf(this->v, setUTCMilliseconds, double, ms);
}

double Date::setUTCMinutes(int min)
{
    return HTML5_CALLf(this->v, setUTCMinutes, double, min);
}

double Date::setUTCMinutes(int min, int sec)
{
    return HTML5_CALLf(this->v, setUTCMinutes, double, min, sec);
}

double Date::setUTCMinutes(int min, int sec, int ms)
{
    return HTML5_CALLf(this->v, setUTCMinutes, double, min, sec, ms);
}

double Date::setUTCMonth(int month)
{
    return HTML5_CALLf(this->v, setUTCMonth, double, month);
}

double Date::setUTCMonth(int month, int date)
{
    return HTML5_CALLf(this->v, setUTCMonth, double, month, date);
}

double Date::setUTCSeconds(int sec)
{
    return HTML5_CALLf(this->v, setUTCSeconds, double, sec);
}

double Date::setUTCSeconds(int sec, int ms)
{
    return HTML5_CALLf(this->v, setUTCSeconds, double, sec, ms);
}

std::string Date::toDateString()
{
    return HTML5_CALLs(this->v, toDateString);
}

std::string Date::toISOString()
{
    return HTML5_CALLs(this->v, toISOString);
}

std::string Date::toJSON(std::string key)
{
    return HTML5_CALLs(this->v, toJSON, key);
}
    
std::string Date::toLocaleDateString()
{
    return HTML5_CALLs(this->v, toLocalDateString);
}

std::string Date::toLocaleString()
{
    return HTML5_CALLs(this->v, toLocaleString);
}

std::string Date::toLocaleTimeString()
{
    return HTML5_CALLs(this->v, toLocaleTimeString);
}

std::string Date::toString()
{
    return HTML5_CALLs(this->v, toString);
}

std::string Date::toTimeString()
{
    return HTML5_CALLs(this->v, toTimeString);
}

std::string Date::toUTCString()
{
    return HTML5_CALLs(this->v, toUTCString);
}

double Date::valueOf()
{
    return HTML5_CALLf(this->v, valueOf, double);
}
