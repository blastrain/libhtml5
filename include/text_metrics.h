#pragma once

#include "libhtml5.h"

NAMESPACE_HTML5_BEGIN;

class TextMetrics : public Object {
public:

    HTML5_PROPERTY(TextMetrics, double, actualBoundingBoxAscent);
    HTML5_PROPERTY(TextMetrics, double, actualBoundingBoxDescent);
    HTML5_PROPERTY(TextMetrics, double, actualBoundingBoxLeft);
    HTML5_PROPERTY(TextMetrics, double, actualBoundingBoxRight);
    HTML5_PROPERTY(TextMetrics, double, alphabeticBaseline);
    HTML5_PROPERTY(TextMetrics, double, emHeightAscent);
    HTML5_PROPERTY(TextMetrics, double, emHeightDescent);
    HTML5_PROPERTY(TextMetrics, double, fontBoundingBoxAscent);
    HTML5_PROPERTY(TextMetrics, double, fontBoundingBoxDescent);
    HTML5_PROPERTY(TextMetrics, double, hangingBaseline);
    HTML5_PROPERTY(TextMetrics, double, ideographicBaseline);
    HTML5_PROPERTY(TextMetrics, double, width);
    
    TextMetrics(emscripten::val v);
    virtual ~TextMetrics();
    static TextMetrics *create(emscripten::val v);
};

NAMESPACE_HTML5_END;
