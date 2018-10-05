#include "libhtml5.h"
#include "html5_regexp.h"

USING_NAMESPACE_HTML5;

RegExp::RegExp(emscripten::val v) :
    Object(v)
{

}

RegExp::~RegExp()
{

}

RegExp *RegExp::create(emscripten::val v)
{
    auto regexp = new RegExp(v);
    regexp->autorelease();
    return regexp;
}

RegExp *RegExp::create(std::string pattern, std::string flags)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(RegExp, pattern, flags));
}

bool RegExp::test(std::string s)
{
    return HTML5_CALLb(this->v, test, s);
}

HTML5_PROPERTY_IMPL(RegExp, bool, global);
HTML5_PROPERTY_IMPL(RegExp, bool, ignoreCase);
HTML5_PROPERTY_IMPL(RegExp, int, lastIndex);
HTML5_PROPERTY_IMPL(RegExp, bool, multiline);
HTML5_PROPERTY_IMPL(RegExp, std::string, source);
