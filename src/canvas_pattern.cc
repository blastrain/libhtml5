#include "svgmatrix.h"
#include "canvas_pattern.h"

CanvasPattern::CanvasPattern(emscripten::val v) :
    Object(),
    v(v)
{
}

CanvasPattern::~CanvasPattern()
{
}

CanvasPattern *CanvasPattern::create(emscripten::val v)
{
    auto pat = new CanvasPattern(v);
    pat->autorelease();
    return pat;
}

void CanvasPattern::setTransform(SVGMatrix *transform)
{
    HTML5_CALL(this->v, setTransform, transform->v);
}
