#pragma once

#include "character_data.h"

NAMESPACE_HTML5_BEGIN;

class StyleSheet;

class ProcessingInstruction : public CharacterData {
public:

    HTML5_PROPERTY_OBJECT(ProcessingInstruction, StyleSheet, sheet);
    HTML5_PROPERTY(ProcessingInstruction, std::string, target);

    ProcessingInstruction(emscripten::val v);
    virtual ~ProcessingInstruction();
    static ProcessingInstruction *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
