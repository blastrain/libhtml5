#include "text_metrics.h"

TextMetrics::TextMetrics(emscripten::val v) : v(v)
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

double TextMetrics::getActualBoundingBoxAscent() const
{
    return HTML5_PROPERTY_GET(actualBoundingBoxAscent, double);
}

void TextMetrics::setActualBoundingBoxAscent(double value)
{
    this->_actualBoundingBoxAscent = value;
    this->v.set("actualBoundingBoxAscent", value);
}

double TextMetrics::getActualBoundingBoxDescent() const
{
    return HTML5_PROPERTY_GET(actualBoundingBoxDescent, double);
}

void TextMetrics::setActualBoundingBoxDescent(double value)
{
    this->_actualBoundingBoxDescent = value;
    this->v.set("actualBoundingBoxDescent", value);
}

double TextMetrics::getActualBoundingBoxLeft() const
{
    return HTML5_PROPERTY_GET(actualBoundingBoxLeft, double);
}

void TextMetrics::setActualBoundingBoxLeft(double value)
{
    this->_actualBoundingBoxLeft = value;
    this->v.set("actualBoundingBoxLeft", value);
}

double TextMetrics::getActualBoundingBoxRight() const
{
    return HTML5_PROPERTY_GET(actualBoundingBoxRight, double);
}

void TextMetrics::setActualBoundingBoxRight(double value)
{
    this->_actualBoundingBoxRight = value;
    this->v.set("actualBoundingBoxRight", value);
}

double TextMetrics::getAlphabeticBaseline() const
{
    return HTML5_PROPERTY_GET(alphabeticBaseline, double);
}

void TextMetrics::setAlphabeticBaseline(double value)
{
    this->_alphabeticBaseline = value;
    this->v.set("alphabeticBaseline", value);
}

double TextMetrics::getEmHeightAscent() const
{
    return HTML5_PROPERTY_GET(emHeightAscent, double);
}

void TextMetrics::setEmHeightAscent(double value)
{
    this->_emHeightAscent = value;
    this->v.set("emHeightAscent", value);
}

double TextMetrics::getEmHeightDescent() const
{
    return HTML5_PROPERTY_GET(emHeightDescent, double);
}

void TextMetrics::setEmHeightDescent(double value)
{
    this->_emHeightDescent = value;
    this->v.set("emHeightDescent", value);
}

double TextMetrics::getFontBoundingBoxAscent() const
{
    return HTML5_PROPERTY_GET(fontBoundingBoxAscent, double);
}

void TextMetrics::setFontBoundingBoxAscent(double value)
{
    this->_fontBoundingBoxAscent = value;
    this->v.set("fontBoundingBoxAscent", value);
}

double TextMetrics::getFontBoundingBoxDescent() const
{
    return HTML5_PROPERTY_GET(fontBoundingBoxDescent, double);
}

void TextMetrics::setFontBoundingBoxDescent(double value)
{
    this->_fontBoundingBoxDescent = value;
    this->v.set("fontBoundingBoxDescent", value);
}

double TextMetrics::getHangingBaseline() const
{
    return HTML5_PROPERTY_GET(hangingBaseline, double);
}

void TextMetrics::setHangingBaseline(double value)
{
    this->_hangingBaseline = value;
    this->v.set("hangingBaseline", value);
}

double TextMetrics::getIdeographicBaseline() const
{
    return HTML5_PROPERTY_GET(ideographicBaseline, double);
}

void TextMetrics::setIdeographicBaseline(double value)
{
    this->_ideographicBaseline = value;
    this->v.set("ideographicBaseline", value);
}

double TextMetrics::getWidth() const
{
    return HTML5_PROPERTY_GET(width, double);
}

void TextMetrics::setWidth(double value)
{
    this->_width = value;
    this->v.set("width", value);
}
