#include "svgmatrix.h"

SVGMatrix::SVGMatrix(emscripten::val v) :
    Object(),
    v(v)
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

double SVGMatrix::getA() const
{
    return HTML5_PROPERTY_GET(a, double);
}

void SVGMatrix::setA(double value)
{
    this->_a = value;
    this->v.set("a", value);
}

double SVGMatrix::getB() const
{
    return HTML5_PROPERTY_GET(b, double);
}

void SVGMatrix::setB(double value)
{
    this->_b = value;
    this->v.set("b", value);
}

double SVGMatrix::getC() const
{
    return HTML5_PROPERTY_GET(c, double);
}

void SVGMatrix::setC(double value)
{
    this->_c = value;
    this->v.set("c", value);
}

double SVGMatrix::getD() const
{
    return HTML5_PROPERTY_GET(d, double);
}

void SVGMatrix::setD(double value)
{
    this->_d = value;
    this->v.set("d", value);
}

double SVGMatrix::getE() const
{
    return HTML5_PROPERTY_GET(e, double);
}

void SVGMatrix::setE(double value)
{
    this->_e = value;
    this->v.set("e", value);
}

double SVGMatrix::getF() const
{
    return HTML5_PROPERTY_GET(f, double);
}

void SVGMatrix::setF(double value)
{
    this->_f = value;
    this->v.set("f", value);
}
