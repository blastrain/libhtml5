#pragma once

#include "libhtml5.h"
#include "canvas_fill_rule.h"

NAMESPACE_HTML5_BEGIN;

class Path2D;
class Element;

class HitRegionOptions : public Object {
public:

    HTML5_PROPERTY_OBJECT(HitRegionOptions, Element, control);
    HTML5_PROPERTY(HitRegionOptions, std::string, cursor);
    HTML5_PROPERTY(HitRegionOptions, std::string, id);
    HTML5_PROPERTY(HitRegionOptions, std::string, label);
    HTML5_PROPERTY(HitRegionOptions, std::string, parentID);
    HTML5_PROPERTY_OBJECT(HitRegionOptions, Path2D, path);
    HTML5_PROPERTY(HitRegionOptions, std::string, role);
    CanvasFillRule _fillRule;

    HitRegionOptions(emscripten::val v);
    virtual ~HitRegionOptions();
    static HitRegionOptions *create(emscripten::val v);
    std::string getFillRule();
    void setFillRule(CanvasFillRule value);

    struct {
        HitRegionOptions &self;
        void operator=(CanvasFillRule value) { self.setFillRule(value); };
        operator std::string() { return self.getFillRule(); };
    } fillRule{*this};
};

NAMESPACE_HTML5_END;
