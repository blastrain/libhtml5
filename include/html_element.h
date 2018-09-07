#pragma once

#include "element.h"
#include <emscripten/val.h>

class HTMLElement : public Element {
public:
    std::string _accessKey;
    std::string _accessKeyLabel;
    bool _commandChecked;
    bool _commandDisabled;
    bool _commandHidden;
    std::string _commandIcon;
    std::string _commandLabel;
    std::string _commandType;
    std::string _contentEditable;

    HTMLElement(emscripten::val v);
    virtual ~HTMLElement();
    static HTMLElement *create(emscripten::val v);
};
