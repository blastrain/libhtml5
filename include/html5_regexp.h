#pragma once

#include "object.h"

NAMESPACE_HTML5_BEGIN;

class regexp : public Object {
public:

    HTML5_PROPERTY(regexp, bool, global);
    HTML5_PROPERTY(regexp, bool, ignoreCase);
    HTML5_PROPERTY(regexp, int, lastIndex);
    HTML5_PROPERTY(regexp, bool, multiline);
    HTML5_PROPERTY(regexp, std::string, source);

    regexp(const char *pattern);
    regexp(const char *pattern, const char *flags);
    regexp(const std::string &pattern);
    regexp(const std::string &pattern, const std::string &flags);
    regexp(emscripten::val v);
    virtual ~regexp();
    regexp& operator=(const char *str);
    regexp& operator=(const std::string& s);
    static regexp *create(emscripten::val v);
    static regexp *create(std::string pattern);
    static regexp *create(std::string pattern, std::string flags);
    bool test(std::string s);
    std::vector<html5::string> exec(std::string s);
};

NAMESPACE_HTML5_END;
