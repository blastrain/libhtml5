#include "libhtml5.h"
#include "html5_regexp.h"

USING_NAMESPACE_HTML5;

regexp::regexp(const char *pattern) :
    Object(HTML5_NEW_PRIMITIVE_INSTANCE(RegExp, std::string(pattern)))
{

}

regexp::regexp(const char *pattern, const char *flags) :
    Object(HTML5_NEW_PRIMITIVE_INSTANCE(RegExp, std::string(pattern), std::string(flags)))
{

}

regexp::regexp(const std::string &pattern) :
    Object(HTML5_NEW_PRIMITIVE_INSTANCE(RegExp, pattern))
{

}

regexp::regexp(const std::string &pattern, const std::string &flags) :
    Object(HTML5_NEW_PRIMITIVE_INSTANCE(RegExp, pattern, flags))
{

}

regexp::regexp(emscripten::val v) :
    Object(v)
{

}

regexp::~regexp()
{

}

regexp& regexp::operator=(const char *str)
{
    this->v = HTML5_NEW_PRIMITIVE_INSTANCE(RegExp, std::string(str));
    return *this;
}

regexp& regexp::operator=(const std::string& s)
{
    this->v = HTML5_NEW_PRIMITIVE_INSTANCE(RegExp, s);
    return *this;
}

regexp *regexp::create(emscripten::val v)
{
    auto re = new regexp(v);
    re->autorelease();
    return re;
}

regexp *regexp::create(std::string pattern, std::string flags)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(RegExp, pattern, flags));
}

bool regexp::test(std::string s)
{
    return HTML5_CALLb(this->v, test, s);
}

std::vector<html5::string> regexp::exec(std::string s)
{
    auto v = HTML5_CALLv(this->v, exec, s);
    if (v.isNull()) {
        return std::vector<html5::string>();
    }
    return toArray<html5::string>(v);
}

HTML5_PROPERTY_IMPL(regexp, bool, global);
HTML5_PROPERTY_IMPL(regexp, bool, ignoreCase);
HTML5_PROPERTY_IMPL(regexp, int, lastIndex);
HTML5_PROPERTY_IMPL(regexp, bool, multiline);
HTML5_PROPERTY_IMPL(regexp, std::string, source);
