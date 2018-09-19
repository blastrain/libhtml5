#include "array_buffer.h"
#include "array_buffer_view.h"

USING_NAMESPACE_HTML5;

ArrayBufferView::ArrayBufferView(emscripten::val v) :
    Object(),
    v(v)
{

}

ArrayBufferView::~ArrayBufferView()
{

}

ArrayBufferView *ArrayBufferView::create(emscripten::val v)
{
    auto view = new ArrayBufferView(v);
    view->autorelease();
    return view;
}

HTML5_PROPERTY_OBJECT_IMPL(ArrayBufferView, ArrayBuffer, buffer);
HTML5_PROPERTY_IMPL(ArrayBufferView, unsigned long, byteLength);
HTML5_PROPERTY_IMPL(ArrayBufferView, unsigned long, byteOffset);
