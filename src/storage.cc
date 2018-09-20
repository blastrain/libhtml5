#include "storage.h"

USING_NAMESPACE_HTML5;

Storage::Storage(emscripten::val v) :
    Object(v)
{

}

Storage::~Storage()
{

}

Storage *Storage::create(emscripten::val v)
{
    auto storage = new Storage(v);
    storage->autorelease();
    return storage;
}

void Storage::clear()
{
    HTML5_CALL(this->v, clear);
}

std::string Storage::getItem(std::string key)
{
    return HTML5_CALLs(this->v, getItem, key);
}

std::string Storage::key(unsigned long index)
{
    return HTML5_CALLs(this->v, key, index);
}

void Storage::removeItem(std::string key)
{
    HTML5_CALL(this->v, removeItem, key);
}

void Storage::setItem(std::string key, std::string value)
{
    HTML5_CALL(this->v, setItem, key, value);
}

HTML5_PROPERTY_IMPL(Storage, unsigned long, length);
