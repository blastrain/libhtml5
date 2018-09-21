#include "external.h"

USING_NAMESPACE_HTML5;

External::External(emscripten::val v) :
    Object(v)
{

}

External::~External()
{

}

External *External::create(emscripten::val v)
{
    auto external = new External(v);
    external->autorelease();
    return external;
}

void External::AddSearchProvider(std::string engineURL)
{
    HTML5_CALL(this->v, AddSearchProvider, engineURL);
}

unsigned long External::IsSearchProviderInstalled(std::string engineURL)
{
    return HTML5_CALLi(this->v, IsSearchProviderInstalled, unsigned long, engineURL);
}
