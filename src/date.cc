#include "date.h"

Date::Date(emscripten::val v) : v(v)
{

}

Date::~Date()
{

}

Date *Date::create()
{
    emscripten::val klass = emscripten::val::global("Date");
    return new Date(klass.new_());
}

Date *Date::create(emscripten::val v)
{
    return new Date(v);
}

Date *Date::create(int year, int month)
{
    emscripten::val klass = emscripten::val::global("Date");
    return new Date(klass.new_(year, month));
}

Date *Date::create(int year, int month, int date)
{
    emscripten::val klass = emscripten::val::global("Date");
    return new Date(klass.new_(year, month, date));
}

Date *Date::create(int year, int month, int date, int hours)
{
    emscripten::val klass = emscripten::val::global("Date");
    return new Date(klass.new_(year, month, date, hours));
}

Date *Date::create(int year, int month, int date, int hours, int minutes)
{
    emscripten::val klass = emscripten::val::global("Date");
    return new Date(klass.new_(year, month, date, hours, minutes));
}

Date *Date::create(int year, int month, int date, int hours, int minutes, int seconds)
{
    emscripten::val klass = emscripten::val::global("Date");
    return new Date(klass.new_(year, month, date, hours, minutes, seconds));
}

Date *Date::create(int year, int month, int date, int hours, int minutes, int seconds, int ms)
{
    emscripten::val klass = emscripten::val::global("Date");
    return new Date(klass.new_(year, month, date, hours, minutes, seconds, ms));
}

Date *Date::now()
{
    emscripten::val klass = emscripten::val::global("Date");
    return Date::create(klass.call<emscripten::val>("now"));
}

Date *Date::UTC(int year, int month)
{
    emscripten::val klass = emscripten::val::global("Date");
    return Date::create(klass.call<emscripten::val>("UTC", year, month));
}

Date *Date::UTC(int year, int month, int date)
{
    emscripten::val klass = emscripten::val::global("Date");
    return Date::create(klass.call<emscripten::val>("UTC", year, month, date));
}

Date *Date::UTC(int year, int month, int date, int hours)
{
    emscripten::val klass = emscripten::val::global("Date");
    return Date::create(klass.call<emscripten::val>("UTC", year, month, date, hours));
}

Date *Date::UTC(int year, int month, int date, int hours, int minutes)
{
    emscripten::val klass = emscripten::val::global("Date");
    return Date::create(klass.call<emscripten::val>("UTC", year, month, date, hours, minutes));
}

Date *Date::UTC(int year, int month, int date, int hours, int minutes, int seconds)
{
    emscripten::val klass = emscripten::val::global("Date");
    return Date::create(klass.call<emscripten::val>("UTC", year, month, date, hours, minutes, seconds));
}

Date *Date::UTC(int year, int month, int date, int hours, int minutes, int seconds, int ms)
{
    emscripten::val klass = emscripten::val::global("Date");
    return Date::create(klass.call<emscripten::val>("UTC", year, month, date, hours, minutes, seconds, ms));
}

double Date::getDate()
{
    return this->v.call<double>("getDate");
}

int Date::getDay()
{
    return this->v.call<int>("getDay");
}

int Date::getFullYear()
{
    return this->v.call<int>("getFullYear");
}

int Date::getHours()
{
    return this->v.call<int>("getHours");
}

int Date::getMilliseconds()
{
    return this->v.call<int>("getMilliseconds");
}

int Date::getMinutes()
{
    return this->v.call<int>("getMinutes");
}

int Date::getMonth()
{
    return this->v.call<int>("getMonth");
}

int Date::getSeconds()
{
    return this->v.call<int>("getSeconds");
}

double Date::getTime()
{
    return this->v.call<double>("getTime");
}

int Date::getTimezoneOffset()
{
    return this->v.call<int>("getTimezoneOffset");
}

double Date::getUTCDate()
{
    return this->v.call<double>("getUTCDate");
}

int Date::getUTCDay()
{
    return this->v.call<int>("getUTCDay");
}

int Date::getUTCFullYear()
{
    return this->v.call<int>("getUTCFullYear");
}

int Date::getUTCHours()
{
    return this->v.call<double>("getUTCHours");
}

int Date::getUTCMilliseconds()
{
    return this->v.call<double>("getUTCMilliseconds");
}

int Date::getUTCMinutes()
{
    return this->v.call<double>("getUTCMinutes");
}

int Date::getUTCMonth()
{
    return this->v.call<double>("getUTCMonth");
}

int Date::getUTCSeconds()
{
    return this->v.call<double>("getUTCSeconds");
}

double Date::setDate(int date)
{
    return this->v.call<double>("setDate", date);
}

double Date::setFullYear(int year)
{
    return this->v.call<double>("setFullYear", year);
}

double Date::setFullyear(int year, int month)
{
    return this->v.call<double>("setFullYear", year, month);
}

double Date::setFullyear(int year, int month, int date)
{
    return this->v.call<double>("setFullYear", year, month ,date);
}

double Date::setHours(int hour)
{
    return this->v.call<double>("setHours", hour);
}

double Date::setHours(int hour, int min)
{
    return this->v.call<double>("setHours", hour, min);
}

double Date::setHours(int hour, int min, int sec)
{
    return this->v.call<double>("setHours", hour, min, sec);
}

double Date::setHours(int hour, int min, int sec, int ms)
{
    return this->v.call<double>("setHours", hour, min, sec, ms);
}

double Date::setMilliseconds(int ms)
{
    return this->v.call<double>("setMilliseconds", ms);
}

double Date::setMinutes(int min)
{
    return this->v.call<double>("setMinutes", min);
}

double Date::setMinutes(int min, int sec)
{
    return this->v.call<double>("setMinutes", min, sec);
}

double Date::setMinutes(int min, int sec, int ms)
{
    return this->v.call<double>("setMinutes", min, sec, ms);
}

double Date::setMonth(int month)
{
    return this->v.call<double>("setMonth", month);
}

double Date::setMonth(int month, int date)
{
    return this->v.call<double>("setMonth", month, date);
}

double Date::setSeconds(int sec)
{
    return this->v.call<double>("setSeconds", sec);
}

double Date::setSeconds(int sec, int ms)
{
    return this->v.call<double>("setSeconds", sec, ms);
}

double Date::setTime(double time)
{
    return this->v.call<double>("setTime", time);
}

double Date::setUTCDate(int date)
{
    return this->v.call<double>("setUTCDate", date);
}

double Date::setUTCFullYear(int year)
{
    return this->v.call<double>("setUTCFullYear", year);
}

double Date::setUTCFullyear(int year, int month)
{
    return this->v.call<double>("setUTCFullYear", year, month);
}

double Date::setUTCFullyear(int year, int month, int date)
{
    return this->v.call<double>("setUTCFullYear", year, month, date);
}

double Date::setUTCHours(int hour)
{
    return this->v.call<double>("setUTCHours", hour);
}

double Date::setUTCHours(int hour, int min)
{
    return this->v.call<double>("setUTCHours", hour, min);
}

double Date::setUTCHours(int hour, int min, int sec)
{
    return this->v.call<double>("setUTCHours", hour, min, sec);
}

double Date::setUTCHours(int hour, int min, int sec, int ms)
{
    return this->v.call<double>("setUTCHours", hour, min, sec, ms);
}

double Date::setUTCMilliseconds(int ms)
{
    return this->v.call<double>("setUTCMilliseconds", ms);
}

double Date::setUTCMinutes(int min)
{
    return this->v.call<double>("setUTCMinutes", min);
}

double Date::setUTCMinutes(int min, int sec)
{
    return this->v.call<double>("setUTCMinutes", min, sec);
}

double Date::setUTCMinutes(int min, int sec, int ms)
{
    return this->v.call<double>("setUTCMinutes", min, sec, ms);
}

double Date::setUTCMonth(int month)
{
    return this->v.call<double>("setUTCMonth", month);
}

double Date::setUTCMonth(int month, int date)
{
    return this->v.call<double>("setUTCMonth", month, date);
}

double Date::setUTCSeconds(int sec)
{
    return this->v.call<double>("setUTCSeconds", sec);
}

double Date::setUTCSeconds(int sec, int ms)
{
    return this->v.call<double>("setUTCSeconds", sec, ms);
}

std::string Date::toDateString()
{
    return this->v.call<std::string>("toDateString");
}

std::string Date::toISOString()
{
    return this->v.call<std::string>("toISOString");
}

std::string Date::toJSON(std::string key)
{
    return this->v.call<std::string>("toJSON", key);
}
    
std::string Date::toLocaleDateString()
{
    return this->v.call<std::string>("toLocalDateString");
}

std::string Date::toLocaleString()
{
    return this->v.call<std::string>("toLocaleString");
}

std::string Date::toLocaleTimeString()
{
    return this->v.call<std::string>("toLocaleTimeString");
}

std::string Date::toString()
{
    return this->v.call<std::string>("toString");
}

std::string Date::toTimeString()
{
    return this->v.call<std::string>("toTimeString");
}

std::string Date::toUTCString()
{
    return this->v.call<std::string>("toUTCString");
}

double Date::valueOf()
{
    return this->v.call<double>("valueOf");
}
