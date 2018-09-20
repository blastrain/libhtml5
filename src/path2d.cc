#include "svgmatrix.h"
#include "path2d.h"

USING_NAMESPACE_HTML5;

Path2D::Path2D(emscripten::val v) :
    Object(v)
{

}

Path2D::~Path2D()
{

}

Path2D *Path2D::create(emscripten::val v)
{
    Path2D *p = new Path2D(v);
    p->autorelease();
    return p;
}

void Path2D::addPath(Path2D *path)
{
    HTML5_CALL(this->v, addPath, path->v);
}

void Path2D::addPath(Path2D *path, SVGMatrix *transformation)
{
    HTML5_CALL(this->v, addPath, path->v, transformation->v);
}

void Path2D::arc(double x, double y, double radius, double startAngle, double endAngle, bool anticlockwise)
{
    HTML5_CALL(this->v, arc, x, y, radius, startAngle, endAngle, anticlockwise);
}

void Path2D::arcTo(double x1, double y1, double x2, double y2, double radius)
{
    HTML5_CALL(this->v, arcTo, x1, y1, x2, y2, radius);
}

void Path2D::bezierCurveTo(double cp1x, double cp1y, double cp2x, double cp2y, double x, double y)
{
    HTML5_CALL(this->v, cp1x, cp1y, cp2x, cp2y, x, y);
}

void Path2D::closePath()
{
    HTML5_CALL(this->v, closePath);
}

void Path2D::ellipse(double x, double y, double radiusX, double radiusY, double rotation, double startAngle, double endAngle, bool anticlockwise)
{
    HTML5_CALL(this->v, ellipse, x, y, radiusX, radiusY, rotation, startAngle, endAngle, anticlockwise);
}

void Path2D::lineTo(double x, double y)
{
    HTML5_CALL(this->v, lineTo, x, y);
}

void Path2D::moveTo(double x, double y)
{
    HTML5_CALL(this->v, moveTo, x, y);
}

void Path2D::quadraticCurveTo(double cpx, double cpy, double x, double y)
{
    HTML5_CALL(this->v, quadraticCurveTo, cpx, cpy, x, y);
}

void Path2D::rect(double x, double y, double w, double h)
{
    HTML5_CALL(this->v, rect, x, y, w, h);
}
