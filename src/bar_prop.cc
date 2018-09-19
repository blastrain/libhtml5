#include "bar_prop.h"

USING_NAMESPACE_HTML5;

BarProp::BarProp(emscripten::val v) :
    Object(),
    v(v)
{

}

BarProp::~BarProp()
{

}

BarProp *BarProp::create(emscripten::val v)
{
    auto barProp = new BarProp(v);
    barProp->autorelease();
    return barProp;
}

HTML5_PROPERTY_IMPL(BarProp, bool, visible);
