#pragma once

#include "libhtml5.h"

class SVGMatrix : public Object {
public:
    emscripten::val v;

    HTML5_PROPERTY(SVGMatrix, double, a);
    HTML5_PROPERTY(SVGMatrix, double, b);
    HTML5_PROPERTY(SVGMatrix, double, c);
    HTML5_PROPERTY(SVGMatrix, double, d);
    HTML5_PROPERTY(SVGMatrix, double, e);
    HTML5_PROPERTY(SVGMatrix, double, f);

    SVGMatrix(emscripten::val v);
    virtual ~SVGMatrix();
    static SVGMatrix *create(emscripten::val v);
    SVGMatrix *flipX();
    SVGMatrix *flipY();
    SVGMatrix *inverse();
    SVGMatrix *multiply(SVGMatrix *secondMatrix);
    SVGMatrix *rotate(double angle);
    SVGMatrix *rotateFromVector(double x, double y);
    SVGMatrix *scale(double scaleFactor);
    SVGMatrix *scaleNonUniform(double scaleFactorX, double scaleFactorY);
    SVGMatrix *skewX(double angle);
    SVGMatrix *skewY(double angle);
    SVGMatrix *translate(double x, double y);
};
