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
    operator std::string() const {
        return HTML5_CALLs(this->v, toString);
    };
    static string *create(emscripten::val v);
    static string *create(std::string s);
    template<typename... Args> static string fromCharCode(Args ...args) {
        return HTML5_CALLs(HTML5_STATIC_PRIMITIVE_INSTANCE(string), fromCharCode, args...);
    };
    template<typename... Args> static string fromCodePoint(char code, Args ...args) {
        return HTML5_CALLs(HTML5_STATIC_PRIMITIVE_INSTANCE(string), fromCodePoint, args...);
    };
    string charAt(int pos);
    int charCodeAt(int pos);
    int codePointAt(int pos);
    template<typename... Args> string concat(const Args& ...args) {
        return HTML5_CALLs(this->v, concat, args...);
    };
    bool endsWidth(std::string searchstring);
    bool endsWidth(std::string searchstring, int length);
    string normalize();
    string normalize(std::string form);
    string padEnd(int targetLength, std::string padstring = "");
    string padStart(int targetLength, std::string padstring = " ");
    bool includes(std::string searchstring, int position = 0);
    int indexOf(std::string searchstring, int position = 0);
    int lastIndexOf(std::string searchstring);
    int lastIndexOf(std::string searchstring, int position);
    int localCompare(std::string that);
    Array *match(RegExp *regexp);
    string repeat(int count);
    string replace(RegExp *searchValue, std::string replaceValue);
    string replace(std::string searchValue, std::string replaceValue);
    int search(RegExp *regexp);
    string slice(int start, int end);
    Array *split();
    Array *split(std::string separator);
    Array *split(std::string separator, int limit);
    bool startsWith(std::string searchstring, int position = 0);
    string substr(int start);
    string substr(int start, int length);
    string substring(int start);
    string substring(int start, int end);
    string toLocaleLowerCase();
    string toLocaleUpperCase();
    string toLowerCase();
    string toString();
    string toUpperCase();
    string trim();
    string trimStart();
    string trimLeft();
    string trimEnd();
    string trimRight();
    string valueOf();
};

NAMESPACE_HTML5_END;

std::ostream& operator<<(std::ostream& os, const html5::string& s);
html5::string operator+(const html5::string &s1, const html5::string &s2);
