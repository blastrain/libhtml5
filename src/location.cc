#include "location.h"

USING_NAMESPACE_HTML5;

Location::Location(emscripten::val v) :
    Object(),
    v(v)
{

}
   
Location::~Location()
{

}

Location *Location::create(emscripten::val v)
{
    auto location = new Location(v);
    location->autorelease();
    return location;
}

void Location::assign(std::string url)
{
    HTML5_CALL(this->v, assign, url);
}

void Location::reload()
{
    HTML5_CALL(this->v, reload);
}

void Location::replace(std::string url)
{
    HTML5_CALL(this->v, replace, url);
}
