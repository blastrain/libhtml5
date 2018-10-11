#pragma once

#include "object.h"

NAMESPACE_HTML5_BEGIN;

class Array;
class RegExp;

class String : public Object {
public:

    HTML5_PROPERTY(String, int, length);

    String(emscripten::val v);
    virtual ~String();
    static String *create(emscripten::val v);
    static String *create(std::string s);
    template<typename... Args> static std::string fromCharCode(Args ...args) {
        return HTML5_CALLs(HTML5_STATIC_PRIMITIVE_INSTANCE(String), fromCharCode, args...);
    };
    template<typename... Args> static std::string fromCodePoint(char code, Args ...args) {
        return HTML5_CALLs(HTML5_STATIC_PRIMITIVE_INSTANCE(String), fromCodePoint, args...);
    };
    std::string charAt(int pos);
    int charCodeAt(int pos);
    int codePointAt(int pos);
    template<typename... Args> std::string concat(Args ...args) {
        return HTML5_CALLs(this->v, concat, args...);
    };
    bool endsWidth(std::string searchString);
    bool endsWidth(std::string searchString, int length);
    std::string normalize();
    std::string normalize(std::string form);
    std::string padEnd(int targetLength, std::string padString = "");
    std::string padStart(int targetLength, std::string padString = " ");
    bool includes(std::string searchString, int position = 0);
    int indexOf(std::string searchString, int position = 0);
    int lastIndexOf(std::string searchString);
    int lastIndexOf(std::string searchString, int position);
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
    bool startsWith(std::string searchString, int position = 0);
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
