#pragma once

#include "object.h"
#include <emscripten/val.h>
#include <string>

class CSSStyleSheet;

class CSSRule : public Object {
public:

    enum {
        STYLE_RULE     = 1,
        CHARSET_RULE   = 2,
        IMPORT_RULE    = 3,
        MEDIA_RULE     = 4,
        FONT_FACE_RULE = 5,
        PAGE_RULE      = 6,
        MARGIN_RULE    = 9,
        NAMESPACE_RULE = 10,
        HOST_RULE      = 1001,
    };

    emscripten::val v;
    std::string _cssText;
    CSSRule *_parentRule;
    CSSStyleSheet *_parentStyleSheet;
    unsigned short _type;

    CSSRule(emscripten::val v);
    virtual ~CSSRule();
    static CSSRule *create(emscripten::val v);
    std::string getCSSText() const;
    void setCSSText(std::string value);
    CSSRule *getParentRule() const;
    void setParentRule(CSSRule *value);
    CSSStyleSheet *getParentStyleSheet() const;
    void setParentStyleSheet(CSSStyleSheet *value);
    unsigned short getType() const;
    void setType(unsigned short value);

    struct {
        CSSRule &self;
        void operator=(std::string value) { self.setCSSText(value); };
        operator std::string() { return self.getCSSText(); };
    } cssText{*this};

    struct {
        CSSRule &self;
        void operator=(CSSRule *value) { self.setParentRule(value); };
        operator CSSRule *() { return self.getParentRule(); };
    } parentRule{*this};

    struct {
        CSSRule &self;
        void operator=(CSSStyleSheet *value) { self.setParentStyleSheet(value); };
        operator CSSStyleSheet *() { return self.getParentStyleSheet(); };
    } parentStyleSheet{*this};

    struct {
        CSSRule &self;
        void operator=(unsigned short value) { self.setType(value); };
        operator unsigned short() { return self.getType(); };
    } type{*this};

};
