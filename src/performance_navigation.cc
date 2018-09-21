#include "performance_navigation.h"

USING_NAMESPACE_HTML5;

PerformanceNavigation::PerformanceNavigation(emscripten::val v) :
    Object(v)
{

}

PerformanceNavigation::~PerformanceNavigation()
{

}

PerformanceNavigation *PerformanceNavigation::create(emscripten::val v)
{
    auto navi = new PerformanceNavigation(v);
    navi->autorelease();
    return navi;
}

HTML5_READONLY_PROPERTY_IMPL(PerformanceNavigation, unsigned short, type);
HTML5_READONLY_PROPERTY_IMPL(PerformanceNavigation, unsigned short, redirectCount);
