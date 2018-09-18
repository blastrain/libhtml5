#include "style_sheet.h"
#include "processing_instruction.h"

ProcessingInstruction::ProcessingInstruction(emscripten::val v) :
    CharacterData(v)
{

}

ProcessingInstruction::~ProcessingInstruction()
{

}

ProcessingInstruction *ProcessingInstruction::create(emscripten::val v)
{
    auto inst = new ProcessingInstruction(v);
    inst->autorelease();
    return inst;
}

HTML5_PROPERTY_OBJECT_IMPL(ProcessingInstruction, StyleSheet, sheet);
HTML5_PROPERTY_IMPL(ProcessingInstruction, std::string, target);
