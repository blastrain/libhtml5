#include "libhtml5.h"
#include "array.h"
#include "html5_string.h"
#include "html5_regexp.h"

USING_NAMESPACE_HTML5;

string::string() :
    Object(HTML5_NEW_PRIMITIVE_INSTANCE(String))
{

}

string::string(const char *s) :
    Object(HTML5_NEW_PRIMITIVE_INSTANCE(String, std::string(s)))
{

}

string::string(const string& s) :
    Object(s.v)
{
}

string::string(const std::string& s) :
    Object(HTML5_NEW_PRIMITIVE_INSTANCE(String, s))
{

}

string::string(emscripten::val v) :
    Object(v)
{

}

string::~string()
{

}

string& string::operator=(const char *str)
{
    this->v = HTML5_NEW_PRIMITIVE_INSTANCE(String, str);
    return *this;
}
        
string& string::operator=(const std::string& str)
{
    this->v = HTML5_NEW_PRIMITIVE_INSTANCE(String, str);
    return *this;
}

string& string::operator+=(const html5::string &s)
{
    std::string src = HTML5_CALLs(this->v, toString);
    std::string dst = HTML5_CALLs(s.v, toString);
    this->v = HTML5_NEW_PRIMITIVE_INSTANCE(String, src + dst);
    return *this;
}

html5::string operator+(const html5::string &s1, const html5::string &s2)
{
    return string(HTML5_CALLs(s1.v, concat, s2.v));
}

std::ostream& operator<<(std::ostream& os, const html5::string& s)
{
    os << HTML5_CALLs(s.v, toString);
    return os;
}

string *string::create(emscripten::val v)
{
    auto str = new string(v);
    str->autorelease();
    return str;
}

string *string::create(std::string s)
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(string, s));
}

std::string string::charAt(int pos)
{
    return HTML5_CALLs(this->v, charAt, pos);
}

int string::charCodeAt(int pos)
{
    return HTML5_CALLi(this->v, charCodeAt, int, pos);
}

int string::codePointAt(int pos)
{
    return HTML5_CALLi(this->v, codePointAt, int, pos);
}

bool string::endsWidth(std::string searchstring)
{
    return HTML5_CALLb(this->v, endsWith, searchstring);
}

bool string::endsWidth(std::string searchstring, int length)
{
    return HTML5_CALLb(this->v, endsWith, searchstring, length);
}

std::string string::normalize()
{
    return HTML5_CALLs(this->v, normalize);
}

std::string string::normalize(std::string form)
{
    return HTML5_CALLs(this->v, normalize, form);
}

std::string string::padEnd(int targetLength, std::string padstring)
{
    return HTML5_CALLs(this->v, padEnd, targetLength, padstring);
}

std::string string::padStart(int targetLength, std::string padstring)
{
    return HTML5_CALLs(this->v, padStart, targetLength, padstring);
}

bool string::includes(std::string searchstring, int position)
{
    return HTML5_CALLb(this->v, includes, searchstring, position);
}

int string::indexOf(std::string searchstring, int position)
{
    return HTML5_CALLi(this->v, indexOf, int, searchstring, position);
}

int string::lastIndexOf(std::string searchstring)
{
    return HTML5_CALLi(this->v, lastIndexOf, int, searchstring);
}
    
int string::lastIndexOf(std::string searchstring, int position)
{
    return HTML5_CALLi(this->v, lastIndexOf, int, searchstring, position);
}

int string::localCompare(std::string that)
{
    return HTML5_CALLi(this->v, localCompare, int, that);
}

Array *string::match(RegExp *regexp)
{
    return Array::create(HTML5_CALLv(this->v, match, regexp->v));
}

std::string string::repeat(int count)
{
    return HTML5_CALLs(this->v, repeat, count);
}

std::string string::replace(RegExp *searchValue, std::string replaceValue)
{
    return HTML5_CALLs(this->v, replace, searchValue->v, replaceValue);
}

std::string string::replace(std::string searchValue, std::string replaceValue)
{
    return HTML5_CALLs(this->v, replace, searchValue, replaceValue);
}

int string::search(RegExp *regexp)
{
    return HTML5_CALLi(this->v, search, int, regexp->v);
}

std::string string::slice(int start, int end)
{
    return HTML5_CALLs(this->v, slice, start, end);
}

Array *string::split()
{
    return Array::create(HTML5_CALLv(this->v, split));
}

Array *string::split(std::string separator)
{
    return Array::create(HTML5_CALLv(this->v, split, separator));
}

Array *string::split(std::string separator, int limit)
{
    return Array::create(HTML5_CALLv(this->v, split, separator, limit));
}

bool string::startsWith(std::string searchstring, int position)
{
    return HTML5_CALLb(this->v, startsWith, searchstring, position);
}

std::string string::substr(int start)
{
    return HTML5_CALLs(this->v, substr, start);
}

std::string string::substr(int start, int length)
{
    return HTML5_CALLs(this->v, substr, start, length);
}

std::string string::substring(int start)
{
    return HTML5_CALLs(this->v, substring, start);
}

std::string string::substring(int start, int end)
{
    return HTML5_CALLs(this->v, substring, start, end);
}

std::string string::toLocaleLowerCase()
{
    return HTML5_CALLs(this->v, toLocaleLowerCase);
}

std::string string::toLocaleUpperCase()
{
    return HTML5_CALLs(this->v, toLocaleUpperCase);
}

std::string string::toLowerCase()
{
    return HTML5_CALLs(this->v, toLowerCase);
}

std::string string::toString()
{
    return HTML5_CALLs(this->v, toString);
}

std::string string::toUpperCase()
{
    return HTML5_CALLs(this->v, toUpperCase);
}

std::string string::trim()
{
    return HTML5_CALLs(this->v, trim);
}

std::string string::trimStart()
{
    return HTML5_CALLs(this->v, trimStart);
}

std::string string::trimLeft()
{
    return HTML5_CALLs(this->v, trimLeft);
}

std::string string::trimEnd()
{
    return HTML5_CALLs(this->v, trimEnd);
}

std::string string::trimRight()
{
    return HTML5_CALLs(this->v, trimRight);
}

std::string string::valueOf()
{
    return HTML5_CALLs(this->v, valueOf);
}

HTML5_PROPERTY_IMPL(string, int, length);
