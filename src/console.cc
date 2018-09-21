#include "console.h"

USING_NAMESPACE_HTML5;

Console::Console(emscripten::val v) :
    Object(v)
{

}

Console::~Console()
{

}

Console *Console::create()
{
    return create(HTML5_STATIC_PRIMITIVE_INSTANCE(console));
}

Console *Console::create(emscripten::val v)
{
    Console *console = new Console(v);
    console->autorelease();
    return console;
}

template<typename... Args>
void Console::_assert(bool expr, const Args&... args)
{
    HTML5_CALL(this->v, assert, expr, args...);
};

void Console::clear()
{
    HTML5_CALL(this->v, clear);
}

void Console::count()
{
    HTML5_CALL(this->v, count);
}

void Console::count(std::string label)
{
    HTML5_CALL(this->v, count, label);
}
    
void Console::countReset()
{
    HTML5_CALL(this->v, countReset);
}

void Console::countReset(std::string label)
{
    HTML5_CALL(this->v, countReset, label);
}
    
void Console::dir(Object *object)
{
    HTML5_CALL(this->v, dir, object->v);
}

void Console::dirxml(Object *object)
{
    HTML5_CALL(this->v, dirxml, object->v);
}

template<typename... Args>
void Console::error(const Args&... args)
{
    HTML5_CALL(this->v, error, args...);
}

template<typename... Args>
void Console::exception(const Args&... args)
{
    HTML5_CALL(this->v, exception, args...);
}

void Console::group()
{
    HTML5_CALL(this->v, group);
}

void Console::group(std::string label)
{
    HTML5_CALL(this->v, group, label);
}

void Console::groupCollapsed()
{
    HTML5_CALL(this->v, groupCollapsed);
}

void Console::groupCollapsed(std::string label)
{
    HTML5_CALL(this->v, groupCollapsed, label);
}
    
void Console::groupEnd()
{
    HTML5_CALL(this->v, groupEnd);
}
    
template<typename... Args>
void Console::info(const Args&... args)
{
    HTML5_CALL(this->v, info, args...);
}

template<typename... Args>
void Console::log(const Args&... args)
{
    HTML5_CALL(this->v, log, args...);
}

void Console::profile()
{
    HTML5_CALL(this->v, profile);
}
    
void Console::profile(std::string profileName)
{
    HTML5_CALL(this->v, profile, profileName);
}

void Console::profileEnd()
{
    HTML5_CALL(this->v, profileEnd);
}

void Console::profileEnd(std::string profileName)
{
    HTML5_CALL(this->v, profileEnd, profileName);
}
    
void Console::table(Object *data)
{
    HTML5_CALL(this->v, data->v);
}

void Console::table(Object *data, std::vector<std::string> columns)
{
    HTML5_CALL(this->v, data->v, toJSArray<std::string>(columns));
}

void Console::time()
{
    HTML5_CALL(this->v, time);
}

void Console::time(std::string label)
{
    HTML5_CALL(this->v, time, label);
}

void Console::timeEnd()
{
    HTML5_CALL(this->v, timeEnd);
}

void Console::timeEnd(std::string label)
{
    HTML5_CALL(this->v, timeEnd, label);
}

void Console::timeLog()
{
    HTML5_CALL(this->v, timeLog);
}

void Console::timeLog(std::string label)
{
    HTML5_CALL(this->v, timeLog, label);
}

void Console::timeStamp()
{
    HTML5_CALL(this->v, timeStamp);
}

void Console::timeStamp(std::string label)
{
    HTML5_CALL(this->v, timeStamp, label);
}

void Console::trace()
{
    HTML5_CALL(this->v, trace);
}

template<typename... Args>
void Console::warn(const Args&... args)
{
    HTML5_CALL(this->v, warn, args...);
}
