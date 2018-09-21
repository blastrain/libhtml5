#include "idb_index_parameters.h"

USING_NAMESPACE_HTML5;

IDBIndexParameters::IDBIndexParameters(emscripten::val v) :
    Object(v)
{

}

IDBIndexParameters::~IDBIndexParameters()
{

}

IDBIndexParameters *IDBIndexParameters::create(emscripten::val v)
{
    auto param = new IDBIndexParameters(v);
    param->autorelease();
    return param;
}

HTML5_PROPERTY_IMPL(IDBIndexParameters, bool, multiEntry);
HTML5_PROPERTY_IMPL(IDBIndexParameters, bool, unique);
