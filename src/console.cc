#include "console.h"

Console::Console(emscripten::val v)
{

}

Console::~Console()
{

}

Console *Console::create()
{
    return create(HTML5_NEW_PRIMITIVE_INSTANCE(console));
}

Console *Console::create(emscripten::val v)
{
    Console *console = new Console(v);
    console->autorelease();
    return console;
}

void Console::assert(bool expr, std::string ...args)
{
    HTML5_CALL(this->v, assert, expr, args...);
};

void Console::clear()
{

}

void Console::count()
{

}

void Console::count(std::string label)
{

}
    
void Console::countReset()
{

}

void Console::countReset(std::string label)
{

}
    
void Console::dir(Object *o)
{

}
