#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class Date : public Object {
public:

    Date(emscripten::val v);
    virtual ~Date();
    static Date *create();
    static Date *create(emscripten::val v);
    static Date *create(int year, int month);
    static Date *create(int year, int month, int date);
    static Date *create(int year, int month, int date, int hours);
    static Date *create(int year, int month, int date, int hours, int minutes);
    static Date *create(int year, int month, int date, int hours, int minutes, int seconds);
    static Date *create(int year, int month, int date, int hours, int minutes, int seconds, int ms);
    static Date *now();
    static Date *UTC(int year, int month);
    static Date *UTC(int year, int month, int date);
    static Date *UTC(int year, int month, int date, int hours);
    static Date *UTC(int year, int month, int date, int hours, int minutes);
    static Date *UTC(int year, int month, int date, int hours, int minutes, int seconds);
    static Date *UTC(int year, int month, int date, int hours, int minutes, int seconds, int ms);
    double getDate();
    int getDay();
    int getFullYear();
    int getHours();
    int getMilliseconds();
    int getMinutes();
    int getMonth();
    int getSeconds();
    double getTime();
    int getTimezoneOffset();
    double getUTCDate();
    int getUTCDay();
    int getUTCFullYear();
    int getUTCHours();
    int getUTCMilliseconds();
    int getUTCMinutes();
    int getUTCMonth();
    int getUTCSeconds();
    double setDate(int date);
    double setFullYear(int year);
    double setFullyear(int year, int month);
    double setFullyear(int year, int month, int date);
    double setHours(int hour);
    double setHours(int hour, int min);
    double setHours(int hour, int min, int sec);
    double setHours(int hour, int min, int sec, int ms);
    double setMilliseconds(int ms);
    double setMinutes(int min);
    double setMinutes(int min, int sec);
    double setMinutes(int min, int sec, int ms);
    double setMonth(int month);
    double setMonth(int month, int date);
    double setSeconds(int sec);
    double setSeconds(int sec, int ms);
    double setTime(double time);
    double setUTCDate(int date);
    double setUTCFullYear(int year);
    double setUTCFullyear(int year, int month);
    double setUTCFullyear(int year, int month, int date);
    double setUTCHours(int hour);
    double setUTCHours(int hour, int min);
    double setUTCHours(int hour, int min, int sec);
    double setUTCHours(int hour, int min, int sec, int ms);
    double setUTCMilliseconds(int ms);
    double setUTCMinutes(int min);
    double setUTCMinutes(int min, int sec);
    double setUTCMinutes(int min, int sec, int ms);
    double setUTCMonth(int month);
    double setUTCMonth(int month, int date);
    double setUTCSeconds(int sec);
    double setUTCSeconds(int sec, int ms);
    std::string toDateString();
    std::string toISOString();
    std::string toJSON(std::string key);
    std::string toLocaleDateString();
    std::string toLocaleString();
    std::string toLocaleTimeString();
    std::string toString();
    std::string toTimeString();
    std::string toUTCString();
    double valueOf();
};

NAMESPACE_HTML5_END;
