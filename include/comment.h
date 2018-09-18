#pragma once

#include "character_data.h"

class Comment : public CharacterData {
public:

    Comment(emscripten::val v);
    virtual ~Comment();
    static Comment *create(emscripten::val v);
};
