#pragma once

#include "character_data.h"

NAMESPACE_HTML5_BEGIN;

class Comment : public CharacterData {
public:

    Comment(emscripten::val v);
    virtual ~Comment();
    static Comment *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
