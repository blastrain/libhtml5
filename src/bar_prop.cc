#include "bar_prop.h"

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
