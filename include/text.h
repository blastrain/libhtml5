#pragma once

#include "character_data.h"

class Text : public CharacterData {
public:

    HTML5_PROPERTY(Text, std::string, wholeText);

    Text(emscripten::val v);
    virtual ~Text();
    static Text *create(emscripten::val v);
    Text *splitText(unsigned long offset);
};
