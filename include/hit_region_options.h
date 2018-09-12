#pragma once

#include "libhtml5.h"
#include "canvas_fill_rule.h"

class Path2D;
class Element;

class HitRegionOptions : public Object {
public:
    emscripten::val v;
    Element *_control;
    std::string _cursor;
    CanvasFillRule _fillRule;
    std::string _id;
    std::string _label;
    std::string _parentID;
    Path2D *_path;
    std::string _role;

    HitRegionOptions(emscripten::val v);
    virtual ~HitRegionOptions();
    static HitRegionOptions *create(emscripten::val v);
    Element *getControl() const;
    void setControl(Element *value);
    std::string getCursor() const;
    void setCursor(std::string value);
    std::string getFillRule();
    void setFillRule(CanvasFillRule value);
    std::string getId() const;
    void setId(std::string value);
    std::string getLabel() const;
    void setLabel(std::string value);
    std::string getParentID() const;
    void setParentID(std::string value);
    Path2D *getPath() const;
    void setPath(Path2D *value);
    std::string getRole() const;
    void setRole(std::string value);

    struct {
        HitRegionOptions &self;
        void operator=(Element *value) { self.setControl(value); };
        operator Element *() { return self.getControl(); };
    } control{*this};

    struct {
        HitRegionOptions &self;
        void operator=(std::string value) { self.setCursor(value); };
        operator std::string() { return self.getCursor(); };
    } cursor{*this};

    struct {
        HitRegionOptions &self;
        void operator=(CanvasFillRule value) { self.setFillRule(value); };
        operator std::string() { return self.getFillRule(); };
    } fillRule{*this};

    struct {
        HitRegionOptions &self;
        void operator=(std::string value) { self.setId(value); };
        operator std::string() { return self.getId(); };
    } id{*this};

    struct {
        HitRegionOptions &self;
        void operator=(std::string value) { self.setLabel(value); };
        operator std::string() { return self.getLabel(); };
    } label{*this};

    struct {
        HitRegionOptions &self;
        void operator=(std::string value) { self.setParentID(value); };
        operator std::string() { return self.getParentID(); };
    } parentID{*this};

    struct {
        HitRegionOptions &self;
        void operator=(Path2D *value) { self.setPath(value); };
        operator Path2D *() { return self.getPath(); };
    } path{*this};

    struct {
        HitRegionOptions &self;
        void operator=(std::string value) { self.setRole(value); };
        operator std::string() { return self.getRole(); };
    } role{*this};

};
