#include "plugin.h"
#include "plugin_array.h"

USING_NAMESPACE_HTML5;

PluginArray::PluginArray(emscripten::val v) :
    Object(),
    v(v)
{

}

PluginArray::~PluginArray()
{

}

PluginArray *PluginArray::create(emscripten::val v)
{
    auto array = new PluginArray(v);
    array->autorelease();
    return array;
}

Plugin *PluginArray::item(unsigned long index)
{
    return Plugin::create(HTML5_CALLv(this->v, item, index));
}

Plugin *PluginArray::namedItem(std::string name)
{
    return Plugin::create(HTML5_CALLv(this->v, namedItem, name));
}

void PluginArray::refresh(bool reload)
{
    HTML5_CALL(this->v, refresh, reload);
}

HTML5_PROPERTY_IMPL(PluginArray, unsigned long, length);
