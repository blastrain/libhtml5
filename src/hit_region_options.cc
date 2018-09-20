#include "element.h"
#include "path2d.h"
#include "hit_region_options.h"

USING_NAMESPACE_HTML5;

HitRegionOptions::HitRegionOptions(emscripten::val v) :
    Object(v)
{

}

HitRegionOptions::~HitRegionOptions()
{

}

HitRegionOptions *HitRegionOptions::create(emscripten::val v)
{
    auto opt = new HitRegionOptions(v);
    opt->autorelease();
    return opt;
}

std::string HitRegionOptions::getFillRule()
{
#if ENABLE_EMSCRIPTEN
    return this->v["fillRule"].as<std::string>();
#else
    return "";
#endif
}

void HitRegionOptions::setFillRule(CanvasFillRule value)
{
    this->_fillRule = value;
    switch (value) {
    case CanvasFillRule::NONZERO:
        this->v.set("fillRule", "nonzero");
        break;
    case CanvasFillRule::EVENODD:
        this->v.set("fillRule", "evenodd");
        break;
    }
}

HTML5_PROPERTY_OBJECT_IMPL(HitRegionOptions, Element, control);
HTML5_PROPERTY_IMPL(HitRegionOptions, std::string, cursor);
HTML5_PROPERTY_IMPL(HitRegionOptions, std::string, id);
HTML5_PROPERTY_IMPL(HitRegionOptions, std::string, label);
HTML5_PROPERTY_IMPL(HitRegionOptions, std::string, parentID);
HTML5_PROPERTY_OBJECT_IMPL(HitRegionOptions, Path2D, path);
HTML5_PROPERTY_IMPL(HitRegionOptions, std::string, role);
