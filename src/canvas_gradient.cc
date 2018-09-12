#include "canvas_gradient.h"

CanvasGradient::CanvasGradient(emscripten::val v) :
    Object(),
    v(v)
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
