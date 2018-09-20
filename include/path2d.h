#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class SVGMatrix;

class Path2D : public Object {
public:

    Path2D(emscripten::val v);
    virtual ~Path2D();
    static Path2D *create(emscripten::val v);
    void addPath(Path2D *path);
    void addPath(Path2D *path, SVGMatrix *transformation);
    void arc(double x, double y, double radius, double startAngle, double endAngle, bool anticlockwise = false);
    void arcTo(double x1, double y1, double x2, double y2, double radius);
    void bezierCurveTo(double cp1x, double cp1y, double cp2x, double cp2y, double x, double y);
    void closePath();
    void ellipse(double x, double y, double radiusX, double radiusY, double rotation, double startAngle, double endAngle, bool anticlockwise = false);
    void lineTo(double x, double y);
    void moveTo(double x, double y);
    void quadraticCurveTo(double cpx, double cpy, double x, double y);
    void rect(double x, double y, double w, double h);
};

NAMESPACE_HTML5_END;
