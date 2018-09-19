#pragma once

#include "character_data.h"

NAMESPACE_HTML5_BEGIN;

class Text : public CharacterData {
public:

    HTML5_PROPERTY(Text, std::string, wholeText);

    Text(emscripten::val v);
    virtual ~Text();
    static Text *create(emscripten::val v);
    Text *splitText(unsigned long offset);
};

NAMESPACE_HTML5_END;
