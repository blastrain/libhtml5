#include "libhtml5.h"
#include "array.h"
#include "html5_string.h"
#include "html5_regexp.h"

USING_NAMESPACE_HTML5;

String::String(emscripten::val v) :
    Object(v)
{

}

String::~String()
{

}

String *String::create(emscripten::val v)
{
    auto string = new String(v);
    string->autorelease();
    return string;
}

String *String::create(std::string s)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(String, s));
}

std::string String::charAt(int pos)
{
    return HTML5_CALLs(this->v, charAt, pos);
}

int String::charCodeAt(int pos)
{
    return HTML5_CALLi(this->v, charCodeAt, int, pos);
}

int String::codePointAt(int pos)
{
    return HTML5_CALLi(this->v, codePointAt, int, pos);
}

bool String::endsWidth(std::string searchString)
{
    return HTML5_CALLb(this->v, endsWith, searchString);
}

bool String::endsWidth(std::string searchString, int length)
{
    return HTML5_CALLb(this->v, endsWith, searchString, length);
}

std::string String::normalize()
{
    return HTML5_CALLs(this->v, normalize);
}

std::string String::normalize(std::string form)
{
    return HTML5_CALLs(this->v, normalize, form);
}

std::string String::padEnd(int targetLength, std::string padString)
{
    return HTML5_CALLs(this->v, padEnd, targetLength, padString);
}

std::string String::padStart(int targetLength, std::string padString)
{
    return HTML5_CALLs(this->v, padStart, targetLength, padString);
}

bool String::includes(std::string searchString, int position)
{
    return HTML5_CALLb(this->v, includes, searchString, position);
}

int String::indexOf(std::string searchString, int position)
{
    return HTML5_CALLi(this->v, indexOf, int, searchString, position);
}

int String::lastIndexOf(std::string searchString)
{
    return HTML5_CALLi(this->v, lastIndexOf, int, searchString);
}
    
int String::lastIndexOf(std::string searchString, int position)
{
    return HTML5_CALLi(this->v, lastIndexOf, int, searchString, position);
}

int String::localCompare(std::string that)
{
    return HTML5_CALLi(this->v, localCompare, int, that);
}

Array *String::match(RegExp *regexp)
{
    return Array::create(HTML5_CALLv(this->v, match, regexp->v));
}

std::string String::repeat(int count)
{
    return HTML5_CALLs(this->v, repeat, count);
}

std::string String::replace(RegExp *searchValue, std::string replaceValue)
{
    return HTML5_CALLs(this->v, replace, searchValue->v, replaceValue);
}

std::string String::replace(std::string searchValue, std::string replaceValue)
{
    return HTML5_CALLs(this->v, replace, searchValue, replaceValue);
}

int String::search(RegExp *regexp)
{
    return HTML5_CALLi(this->v, search, int, regexp->v);
}

std::string String::slice(int start, int end)
{
    return HTML5_CALLs(this->v, slice, start, end);
}

Array *String::split()
{
    return Array::create(HTML5_CALLv(this->v, split));
}

Array *String::split(std::string separator)
{
    return Array::create(HTML5_CALLv(this->v, split, separator));
}

Array *String::split(std::string separator, int limit)
{
    return Array::create(HTML5_CALLv(this->v, split, separator, limit));
}

bool String::startsWith(std::string searchString, int position)
{
    return HTML5_CALLb(this->v, startsWith, searchString, position);
}

std::string String::substr(int start)
{
    return HTML5_CALLs(this->v, substr, start);
}

std::string String::substr(int start, int length)
{
    return HTML5_CALLs(this->v, substr, start, length);
}

std::string String::substring(int start)
{
    return HTML5_CALLs(this->v, substring, start);
}

std::string String::substring(int start, int end)
{
    return HTML5_CALLs(this->v, substring, start, end);
}

std::string String::toLocaleLowerCase()
{
    return HTML5_CALLs(this->v, toLocaleLowerCase);
}

std::string String::toLocaleUpperCase()
{
    return HTML5_CALLs(this->v, toLocaleUpperCase);
}

std::string String::toLowerCase()
{
    return HTML5_CALLs(this->v, toLowerCase);
}

std::string String::toString()
{
    return HTML5_CALLs(this->v, toString);
}

std::string String::toUpperCase()
{
    return HTML5_CALLs(this->v, toUpperCase);
}

std::string String::trim()
{
    return HTML5_CALLs(this->v, trim);
}

std::string String::trimStart()
{
    return HTML5_CALLs(this->v, trimStart);
}

std::string String::trimLeft()
{
    return HTML5_CALLs(this->v, trimLeft);
}

std::string String::trimEnd()
{
    return HTML5_CALLs(this->v, trimEnd);
}

std::string String::trimRight()
{
    return HTML5_CALLs(this->v, trimRight);
}

std::string String::valueOf()
{
    return HTML5_CALLs(this->v, valueOf);
}

HTML5_PROPERTY_IMPL(String, int, length);
