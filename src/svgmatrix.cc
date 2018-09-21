#include "svgmatrix.h"

USING_NAMESPACE_HTML5;

SVGMatrix::SVGMatrix(emscripten::val v) :
    Object(v)
{

}

SVGMatrix::~SVGMatrix()
{

}

SVGMatrix *SVGMatrix::create(emscripten::val v)
{
    SVGMatrix *mat = new SVGMatrix(v);
    mat->autorelease();
    return mat;
}

SVGMatrix *SVGMatrix::flipX()
{
    return SVGMatrix::create(HTML5_CALLv(this->v, flipX));
}

SVGMatrix *SVGMatrix::flipY()
{
    return SVGMatrix::create(HTML5_CALLv(this->v, flipY));
}

SVGMatrix *SVGMatrix::inverse()
{
    return SVGMatrix::create(HTML5_CALLv(this->v, inverse));
}

SVGMatrix *SVGMatrix::multiply(SVGMatrix *secondMatrix)
{
    return SVGMatrix::create(HTML5_CALLv(this->v, multiply, secondMatrix->v));
}

SVGMatrix *SVGMatrix::rotate(double angle)
{
    return SVGMatrix::create(HTML5_CALLv(this->v, rotate, angle));
}

SVGMatrix *SVGMatrix::rotateFromVector(double x, double y)
{
    return SVGMatrix::create(HTML5_CALLv(this->v, rotateFromVector, x, y));
}

SVGMatrix *SVGMatrix::scale(double scaleFactor)
{
    return SVGMatrix::create(HTML5_CALLv(this->v, scale, scaleFactor));
}

SVGMatrix *SVGMatrix::scaleNonUniform(double scaleFactorX, double scaleFactorY)
{
    return SVGMatrix::create(HTML5_CALLv(this->v, scaleNonUniform, scaleFactorX, scaleFactorY));
}

SVGMatrix *SVGMatrix::skewX(double angle)
{
    return SVGMatrix::create(HTML5_CALLv(this->v, skewX, angle));
}

SVGMatrix *SVGMatrix::skewY(double angle)
{
    return SVGMatrix::create(HTML5_CALLv(this->v, skewY, angle));
}

SVGMatrix *SVGMatrix::translate(double x, double y)
{
    return SVGMatrix::create(HTML5_CALLv(this->v, translate, x, y));
}

HTML5_PROPERTY_IMPL(SVGMatrix, double, a);
HTML5_PROPERTY_IMPL(SVGMatrix, double, b);
HTML5_PROPERTY_IMPL(SVGMatrix, double, c);
HTML5_PROPERTY_IMPL(SVGMatrix, double, d);
HTML5_PROPERTY_IMPL(SVGMatrix, double, e);
HTML5_PROPERTY_IMPL(SVGMatrix, double, f);
