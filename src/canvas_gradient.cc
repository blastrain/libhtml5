#include "canvas_gradient.h"

USING_NAMESPACE_HTML5;

CanvasGradient::CanvasGradient(emscripten::val v) :
    Object(v)
{
}

CanvasGradient::~CanvasGradient()
{
}

CanvasGradient *CanvasGradient::create(emscripten::val v)
{
    auto grad = new CanvasGradient(v);
    grad->autorelease();
    return grad;
}

void CanvasGradient::addColorStop(double offset, std::string color)
{
    HTML5_CALL(this->v, addColorStop, offset, color);
}
