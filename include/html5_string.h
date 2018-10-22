#pragma once

#include "object.h"

NAMESPACE_HTML5_BEGIN;

class Array;
class RegExp;

class string : public Object {
public:

    HTML5_PROPERTY(string, int, length);

    string();
    string(const char *str);
    string(const string& s);
    string(const std::string& s);
    string(emscripten::val v);
    virtual ~string();
    string& operator=(const char *str);
    string& operator=(const std::string& s);
    string& operator+=(const html5::string &s);
    static string *create(emscripten::val v);
    static string *create(std::string s);
    template<typename... Args> static std::string fromCharCode(Args ...args) {
        return HTML5_CALLs(HTML5_STATIC_PRIMITIVE_INSTANCE(string), fromCharCode, args...);
    };
    template<typename... Args> static std::string fromCodePoint(char code, Args ...args) {
        return HTML5_CALLs(HTML5_STATIC_PRIMITIVE_INSTANCE(string), fromCodePoint, args...);
    };
    std::string charAt(int pos);
    int charCodeAt(int pos);
    int codePointAt(int pos);
    template<typename... Args> std::string concat(const Args& ...args) {
        return HTML5_CALLs(this->v, concat, args...);
    };
    bool endsWidth(std::string searchstring);
    bool endsWidth(std::string searchstring, int length);
    std::string normalize();
    std::string normalize(std::string form);
    std::string padEnd(int targetLength, std::string padstring = "");
    std::string padStart(int targetLength, std::string padstring = " ");
    bool includes(std::string searchstring, int position = 0);
    int indexOf(std::string searchstring, int position = 0);
    int lastIndexOf(std::string searchstring);
    int lastIndexOf(std::string searchstring, int position);
    int localCompare(std::string that);
    Array *match(RegExp *regexp);
    std::string repeat(int count);
    std::string replace(RegExp *searchValue, std::string replaceValue);
    std::string replace(std::string searchValue, std::string replaceValue);
    int search(RegExp *regexp);
    std::string slice(int start, int end);
    Array *split();
    Array *split(std::string separator);
    Array *split(std::string separator, int limit);
    bool startsWith(std::string searchstring, int position = 0);
    std::string substr(int start);
    std::string substr(int start, int length);
    std::string substring(int start);
    std::string substring(int start, int end);
    std::string toLocaleLowerCase();
    std::string toLocaleUpperCase();
    std::string toLowerCase();
    std::string toString();
    std::string toUpperCase();
    std::string trim();
    std::string trimStart();
    std::string trimLeft();
    std::string trimEnd();
    std::string trimRight();
    std::string valueOf();
};

NAMESPACE_HTML5_END;

std::ostream& operator<<(std::ostream& os, const html5::string& s);
html5::string operator+(const html5::string &s1, const html5::string &s2);
