#include "text_metrics.h"

USING_NAMESPACE_HTML5;

TextMetrics::TextMetrics(emscripten::val v) :
    Object(v)
{

}

TextMetrics::~TextMetrics()
{

}

TextMetrics *TextMetrics::create(emscripten::val v)
{
    TextMetrics *tm = new TextMetrics(v);
    tm->autorelease();
    return tm;
}

HTML5_PROPERTY_IMPL(TextMetrics, double, actualBoundingBoxAscent);
HTML5_PROPERTY_IMPL(TextMetrics, double, actualBoundingBoxDescent);
HTML5_PROPERTY_IMPL(TextMetrics, double, actualBoundingBoxLeft);
HTML5_PROPERTY_IMPL(TextMetrics, double, actualBoundingBoxRight);
HTML5_PROPERTY_IMPL(TextMetrics, double, alphabeticBaseline);
HTML5_PROPERTY_IMPL(TextMetrics, double, emHeightAscent);
HTML5_PROPERTY_IMPL(TextMetrics, double, emHeightDescent);
HTML5_PROPERTY_IMPL(TextMetrics, double, fontBoundingBoxAscent);
HTML5_PROPERTY_IMPL(TextMetrics, double, fontBoundingBoxDescent);
HTML5_PROPERTY_IMPL(TextMetrics, double, hangingBaseline);
HTML5_PROPERTY_IMPL(TextMetrics, double, ideographicBaseline);
HTML5_PROPERTY_IMPL(TextMetrics, double, width);
