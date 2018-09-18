#include "text.h"

Text::Text(emscripten::val v) :
    CharacterData(v)
{

}

Text::~Text()
{

}

Text *Text::create(emscripten::val v)
{
    Text *text = new Text(v);
    text->autorelease();
    return text;
}

Text *Text::splitText(unsigned long offset)
{
    return Text::create(HTML5_CALLv(this->v, splitText, offset));
}

HTML5_PROPERTY_IMPL(Text, std::string, wholeText);
