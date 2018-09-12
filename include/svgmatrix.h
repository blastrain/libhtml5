#pragma once

#include "libhtml5.h"

class SVGMatrix : public Object {
public:
    emscripten::val v;
    double _a;
    double _b;
    double _c;
    double _d;
    double _e;
    double _f;

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

    double getA() const;
    void setA(double value);
    double getB() const;
    void setB(double value);
    double getC() const;
    void setC(double value);
    double getD() const;
    void setD(double value);
    double getE() const;
    void setE(double value);
    double getF() const;
    void setF(double value);

    struct {
        SVGMatrix &self;
        void operator=(double value) { self.setA(value); };
        operator double() { return self.getA(); };
    } a{*this};

    struct {
        SVGMatrix &self;
        void operator=(double value) { self.setB(value); };
        operator double() { return self.getB(); };
    } b{*this};

    struct {
        SVGMatrix &self;
        void operator=(double value) { self.setC(value); };
        operator double() { return self.getC(); };
    } c{*this};

    struct {
        SVGMatrix &self;
        void operator=(double value) { self.setD(value); };
        operator double() { return self.getD(); };
    } d{*this};

    struct {
        SVGMatrix &self;
        void operator=(double value) { self.setE(value); };
        operator double() { return self.getE(); };
    } e{*this};

    struct {
        SVGMatrix &self;
        void operator=(double value) { self.setF(value); };
        operator double() { return self.getF(); };
    } f{*this};

};
