#pragma once

#include "object.h"

NAMESPACE_HTML5_BEGIN;

class RegExp : public Object {
public:

    HTML5_PROPERTY(RegExp, bool, global);
    HTML5_PROPERTY(RegExp, bool, ignoreCase);
    HTML5_PROPERTY(RegExp, int, lastIndex);
    HTML5_PROPERTY(RegExp, bool, multiline);
    HTML5_PROPERTY(RegExp, std::string, source);

    RegExp(emscripten::val v);
    virtual ~RegExp();
    static RegExp *create(emscripten::val v);
    static RegExp *create(std::string pattern, std::string flags);
    bool test(std::string s);
};

NAMESPACE_HTML5_END;
