#include "element.h"
#include "path2d.h"
#include "hit_region_options.h"

HitRegionOptions::HitRegionOptions(emscripten::val v) :
    Object(),
    v(v)
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

Element *HitRegionOptions::getControl() const
{
    return HTML5_PROPERTY_GET(control, Element);
}

void HitRegionOptions::setControl(Element *value)
{

}

std::string HitRegionOptions::getCursor() const
{
    return HTML5_PROPERTY_GET(cursor, std::string);
}

void HitRegionOptions::setCursor(std::string value)
{
    this->_cursor = value;
    this->v.set("cursor", value);
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

std::string HitRegionOptions::getId() const
{
    return HTML5_PROPERTY_GET(id, std::string);
}

void HitRegionOptions::setId(std::string value)
{
    this->_id = value;
    this->v.set("id", value);
}

std::string HitRegionOptions::getLabel() const
{
    return HTML5_PROPERTY_GET(label, std::string);
}
    
void HitRegionOptions::setLabel(std::string value)
{
    this->_label = value;
    this->v.set("label", value);
}

std::string HitRegionOptions::getParentID() const
{
    return HTML5_PROPERTY_GET(parentID, std::string);
}

void HitRegionOptions::setParentID(std::string value)
{
    this->_parentID = value;
    this->v.set("parentID", value);
}

Path2D *HitRegionOptions::getPath() const
{
    return HTML5_PROPERTY_GET(path, Path2D);
}

void HitRegionOptions::setPath(Path2D *value)
{
    this->_path = value;
    this->v.set("path", value->v);
}

std::string HitRegionOptions::getRole() const
{
    return HTML5_PROPERTY_GET(role, std::string);
}

void HitRegionOptions::setRole(std::string value)
{
    this->_role = value;
    this->v.set("role", value);
}
