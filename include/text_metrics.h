#pragma once

#include "libhtml5.h"

class TextMetrics : public Object {
public:
    emscripten::val v;
    double _actualBoundingBoxAscent;
    double _actualBoundingBoxDescent;
    double _actualBoundingBoxLeft;
    double _actualBoundingBoxRight;
    double _alphabeticBaseline;
    double _emHeightAscent;
    double _emHeightDescent;
    double _fontBoundingBoxAscent;
    double _fontBoundingBoxDescent;
    double _hangingBaseline;
    double _ideographicBaseline;
    double _width;
    
    TextMetrics(emscripten::val v);
    virtual ~TextMetrics();
    static TextMetrics *create(emscripten::val v);

    double getActualBoundingBoxAscent() const;
    void setActualBoundingBoxAscent(double value);
    double getActualBoundingBoxDescent() const;
    void setActualBoundingBoxDescent(double value);
    double getActualBoundingBoxLeft() const;
    void setActualBoundingBoxLeft(double value);
    double getActualBoundingBoxRight() const;
    void setActualBoundingBoxRight(double value);
    double getAlphabeticBaseline() const;
    void setAlphabeticBaseline(double value);
    double getEmHeightAscent() const;
    void setEmHeightAscent(double value);
    double getEmHeightDescent() const;
    void setEmHeightDescent(double value);
    double getFontBoundingBoxAscent() const;
    void setFontBoundingBoxAscent(double value);
    double getFontBoundingBoxDescent() const;
    void setFontBoundingBoxDescent(double value);
    double getHangingBaseline() const;
    void setHangingBaseline(double value);
    double getIdeographicBaseline() const;
    void setIdeographicBaseline(double value);
    double getWidth() const;
    void setWidth(double value);

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setActualBoundingBoxAscent(value); };
        operator double() { return self.getActualBoundingBoxAscent(); };
    } actualBoundingBoxAscent{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setActualBoundingBoxDescent(value); };
        operator double() { return self.getActualBoundingBoxDescent(); };
    } actualBoundingBoxDescent{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setActualBoundingBoxLeft(value); };
        operator double() { return self.getActualBoundingBoxLeft(); };
    } actualBoundingBoxLeft{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setActualBoundingBoxRight(value); };
        operator double() { return self.getActualBoundingBoxRight(); };
    } actualBoundingBoxRight{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setAlphabeticBaseline(value); };
        operator double() { return self.getAlphabeticBaseline(); };
    } alphabeticBaseline{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setEmHeightAscent(value); };
        operator double() { return self.getEmHeightAscent(); };
    } emHeightAscent{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setEmHeightDescent(value); };
        operator double() { return self.getEmHeightDescent(); };
    } emHeightDescent{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setFontBoundingBoxAscent(value); };
        operator double() { return self.getFontBoundingBoxAscent(); };
    } fontBoundingBoxAscent{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setFontBoundingBoxDescent(value); };
        operator double() { return self.getFontBoundingBoxDescent(); };
    } fontBoundingBoxDescent{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setHangingBaseline(value); };
        operator double() { return self.getHangingBaseline(); };
    } hangingBaseline{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setIdeographicBaseline(value); };
        operator double() { return self.getIdeographicBaseline(); };
    } ideographicBaseline{*this};

    struct {
        TextMetrics &self;
        void operator=(double value) { self.setWidth(value); };
        operator double() { return self.getWidth(); };
    } width{*this};

};
