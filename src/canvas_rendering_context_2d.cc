#include "hit_region_options.h"
#include "html_image_element.h"
#include "html_video_element.h"
#include "html_canvas_element.h"
#include "svgmatrix.h"
#include "canvas_gradient.h"
#include "canvas_pattern.h"
#include "image_bitmap.h"
#include "image_data.h"
#include "text_metrics.h"
#include "path2d.h"
#include "canvas_rendering_context_2d.h"

CanvasRenderingContext2D::CanvasRenderingContext2D(emscripten::val v) :
    RenderingContext(v)
{

}

CanvasRenderingContext2D::~CanvasRenderingContext2D()
{

}

CanvasRenderingContext2D *CanvasRenderingContext2D::create(emscripten::val v)
{
    auto ctx = new CanvasRenderingContext2D(v);
    ctx->autorelease();
    return ctx;
}

void CanvasRenderingContext2D::addHitRegion(HitRegionOptions *option)
{
    HTML5_CALL(this->v, addHitRegion, option->v);
}

void CanvasRenderingContext2D::arc(double x, double y, double radius, double startAngle, double endAngle, bool anticlockwise)
{
    HTML5_CALL(this->v, arc, x, y, radius, startAngle, endAngle, anticlockwise);
}

void CanvasRenderingContext2D::arcTo(double x1, double y1, double x2, double y2, double radius)
{
    HTML5_CALL(this->v, arcTo, x1, y1, x2, y2, radius);
}

void CanvasRenderingContext2D::beginPath()
{
    HTML5_CALL(this->v, beginPath);
}

void CanvasRenderingContext2D::bezierCurveTo(double cp1x, double cp1y, double cp2x, double cp2y, double x, double y)
{
    HTML5_CALL(this->v, bezierCurveTo, cp1x, cp1y, cp2x, cp2y, x, y);
}

void CanvasRenderingContext2D::clearRect(double x, double y, double w, double h)
{
    HTML5_CALL(this->v, clearRect, x, y, w, h);
}

void CanvasRenderingContext2D::clip()
{
    HTML5_CALL(this->v, clip);
}
   
void CanvasRenderingContext2D::clip(CanvasFillRule fillRule)
{
    HTML5_CALL(this->v, clip, toCanvasFillRuleString(fillRule));
}

void CanvasRenderingContext2D::clip(Path2D *path, CanvasFillRule fillRule)
{
    HTML5_CALL(this->v, clip, path->v, toCanvasFillRuleString(fillRule));
}

void CanvasRenderingContext2D::closePath()
{
    HTML5_CALL(this->v, closePath);
}

void CanvasRenderingContext2D::commit()
{
    HTML5_CALL(this->v, commit);
}

ImageData *CanvasRenderingContext2D::createImageData(unsigned long width, unsigned long height)
{
    return ImageData::create(HTML5_CALLv(this->v, createImageData, width, height));
}

ImageData *CanvasRenderingContext2D::createImageData(ImageData *imagedata)
{
    return ImageData::create(HTML5_CALLv(this->v, createImageData, imagedata->v));
}

CanvasGradient *CanvasRenderingContext2D::createLinearGradient(double x0, double y0, double x1, double y1)
{
    return CanvasGradient::create(HTML5_CALLv(this->v, createLinearGradient, x0, y0, x1, y1));
}

CanvasPattern *CanvasRenderingContext2D::createPattern(HTMLImageElement *image, std::string repetition)
{
    return CanvasPattern::create(HTML5_CALLv(this->v, createPattern, image->v, repetition));
}

CanvasPattern *CanvasRenderingContext2D::createPattern(HTMLVideoElement *image, std::string repetition)
{
    return CanvasPattern::create(HTML5_CALLv(this->v, createPattern, image->v, repetition));
}

CanvasPattern *CanvasRenderingContext2D::createPattern(HTMLCanvasElement *image, std::string repetition)
{
    return CanvasPattern::create(HTML5_CALLv(this->v, createPattern, image->v, repetition));
}

CanvasPattern *CanvasRenderingContext2D::createPattern(CanvasRenderingContext2D *image, std::string repetition)
{
    return CanvasPattern::create(HTML5_CALLv(this->v, createPattern, image->v, repetition));
}

CanvasPattern *CanvasRenderingContext2D::createPattern(ImageBitmap *image, std::string repetition)
{
    return CanvasPattern::create(HTML5_CALLv(this->v, createPattern, image->v, repetition));
}

CanvasGradient *CanvasRenderingContext2D::createRadialGradient(double x0, double y0, double r0, double x1, double y1, double r1)
{
    return CanvasGradient::create(HTML5_CALLv(this->v, createRadialGradient, x0, y0, r0, x1, y1, r1));
}

void CanvasRenderingContext2D::drawImage(HTMLImageElement *image, double x, double y)
{
    HTML5_CALL(this->v, drawImage, image->v, x, y);
}

void CanvasRenderingContext2D::drawImage(HTMLImageElement *image, double dx, double dy, double dw, double dh)
{
    HTML5_CALL(this->v, drawImage, image->v, dx, dy, dw, dh);
}

void CanvasRenderingContext2D::drawImage(HTMLImageElement *image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh)
{
    HTML5_CALL(this->v, drawImage, image->v, sx, sy, sw, sh, dx, dy, dw, dh);
}

void CanvasRenderingContext2D::drawImage(HTMLVideoElement *image, double x, double y)
{
    HTML5_CALL(this->v, drawImage, image->v, x, y);
}

void CanvasRenderingContext2D::drawImage(HTMLVideoElement *image, double dx, double dy, double dw, double dh)
{
    HTML5_CALL(this->v, drawImage, image->v, dx, dy, dw, dh);
}

void CanvasRenderingContext2D::drawImage(HTMLVideoElement *image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh)
{
    HTML5_CALL(this->v, drawImage, image->v, sx, sy, sw, sh, dx, dy, dw, dh);
}

void CanvasRenderingContext2D::drawImage(HTMLCanvasElement *image, double x, double y)
{
    HTML5_CALL(this->v, drawImage, image->v, x, y);
}

void CanvasRenderingContext2D::drawImage(HTMLCanvasElement *image, double dx, double dy, double dw, double dh)
{
    HTML5_CALL(this->v, drawImage, image->v, dx, dy, dw, dh);
}

void CanvasRenderingContext2D::drawImage(HTMLCanvasElement *image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh)
{
    HTML5_CALL(this->v, drawImage, image->v, sx, sy, sw, sh, dx, dy, dw, dh);
}

void CanvasRenderingContext2D::drawImage(CanvasRenderingContext2D *image, double x, double y)
{
    HTML5_CALL(this->v, drawImage, image->v, x, y);
}

void CanvasRenderingContext2D::drawImage(CanvasRenderingContext2D *image, double dx, double dy, double dw, double dh)
{
    HTML5_CALL(this->v, drawImage, image->v, dx, dy, dw, dh);
}

void CanvasRenderingContext2D::drawImage(CanvasRenderingContext2D *image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh)
{
    HTML5_CALL(this->v, drawImage, image->v, sx, sy, sw, sh, dx, dy, dw, dh);
}

void CanvasRenderingContext2D::drawImage(ImageBitmap *image, double x, double y)
{
    HTML5_CALL(this->v, drawImage, image->v, x, y);
}

void CanvasRenderingContext2D::drawImage(ImageBitmap *image, double dx, double dy, double dw, double dh)
{
    HTML5_CALL(this->v, drawImage, image->v, dx, dy, dw, dh);
}

void CanvasRenderingContext2D::drawImage(ImageBitmap *image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh)
{
    HTML5_CALL(this->v, drawImage, image->v, sx, sy, sw, sh, dx, dy, dw, dh);
}

void CanvasRenderingContext2D::ellipse(double x, double y, double radiusX, double radiusY, double rotation, double startAngle, double endAngle, bool anticlockwise)
{
    HTML5_CALL(this->v, ellipse, x, y, radiusX, radiusY, rotation, startAngle, endAngle, anticlockwise);
}

void CanvasRenderingContext2D::fill(CanvasFillRule fillRule)
{
    HTML5_CALL(this->v, fill, toCanvasFillRuleString(fillRule));
}

void CanvasRenderingContext2D::fill(Path2D *path, CanvasFillRule fillRule)
{
    HTML5_CALL(this->v, path->v, toCanvasFillRuleString(fillRule));
}

void CanvasRenderingContext2D::fillRect(double x, double y, double w, double h)
{
    HTML5_CALL(this->v, fillRect, x, y, w, h);
}

void CanvasRenderingContext2D::fillText(std::string text, double x, double y)
{
    HTML5_CALL(this->v, fillText, text, x, y);
}

void CanvasRenderingContext2D::fillText(std::string text, double x, double y, double maxWidth)
{
    HTML5_CALL(this->v, text, x, y, maxWidth);
}

ImageData *CanvasRenderingContext2D::getImageData(double sx, double sy, double sw, double sh)
{
    return ImageData::create(HTML5_CALLv(this->v, getImageData, sx, sy, sw, sh));
}

std::vector<double> CanvasRenderingContext2D::getLineDash()
{
#if ENABLE_EMSCRIPTEN
    return emscripten::vecFromJSArray<double>(HTML5_CALLv(this->v, getLineDash));
#else
    std::vector<double> ret;
    return ret;
#endif
}

bool CanvasRenderingContext2D::isPointInPath(double x, double y, CanvasFillRule fillRule)
{
    return HTML5_CALLb(this->v, isPointInPath, x, y, toCanvasFillRuleString(fillRule));
}

bool CanvasRenderingContext2D::isPointInPath(Path2D *path, double x, double y, CanvasFillRule fillRule)
{
    return HTML5_CALLb(this->v, isPointInPath, path->v, x, y, toCanvasFillRuleString(fillRule));
}

bool CanvasRenderingContext2D::isPointStroke(double x, double y)
{
    return HTML5_CALLb(this->v, isPointStroke, x, y);
}

bool CanvasRenderingContext2D::isPointStroke(Path2D *path, double x, double y)
{
    return HTML5_CALLb(this->v, isPointStroke, path->v, x, y);
}

void CanvasRenderingContext2D::lineTo(double x, double y)
{
    HTML5_CALL(this->v, lineTo, x, y);
}

TextMetrics *CanvasRenderingContext2D::measureText(std::string text)
{
    return TextMetrics::create(HTML5_CALLv(this->v, measureText, text));
}

void CanvasRenderingContext2D::moveTo(double x, double y)
{
    HTML5_CALL(this->v, moveTo, x, y);
}

void CanvasRenderingContext2D::putImageData(ImageData *imageData, double dx, double dy)
{
    HTML5_CALL(this->v, putImageData, imageData->v, dx, dy);
}

void CanvasRenderingContext2D::putImageData(ImageData *imageData, double dx, double dy, double dirtyX, double dirtyY, double dirtyWidth, double dirtyHeight)
{
    HTML5_CALL(this->v, putImageData, imageData->v, dx, dy, dirtyX, dirtyY, dirtyWidth, dirtyHeight);
}

void CanvasRenderingContext2D::quadraticCurveTo(double cpx, double cpy, double x, double y)
{
    HTML5_CALL(this->v, quadraticCurveTo, cpx, cpy, x, y);
}

void CanvasRenderingContext2D::rect(double x, double y, double w, double h)
{
    HTML5_CALL(this->v, rect, x, y, w, h);
}

void CanvasRenderingContext2D::removeHitRegion(std::string id)
{
    HTML5_CALL(this->v, removeHitRegion, id);
}

void CanvasRenderingContext2D::resetClip()
{
    HTML5_CALL(this->v, resetClip);
}

void CanvasRenderingContext2D::resetTransform()
{
    HTML5_CALL(this->v, resetTransform);
}

void CanvasRenderingContext2D::restore()
{
    HTML5_CALL(this->v, restore);
}

void CanvasRenderingContext2D::rotate(double angle)
{
    HTML5_CALL(this->v, rotate, angle);
}

void CanvasRenderingContext2D::save()
{
    HTML5_CALL(this->v, save);
}
    
void CanvasRenderingContext2D::scale(double x, double y)
{
    HTML5_CALL(this->v, scale, x, y);
}

void CanvasRenderingContext2D::scrollPathIntoView()
{
    HTML5_CALL(this->v, scrollPathIntoView);
}

void CanvasRenderingContext2D::scrollPathIntoView(Path2D *path)
{
    HTML5_CALL(this->v, scrollPathIntoView, path->v);
}

void CanvasRenderingContext2D::setLineDash(std::vector<double> segments)
{
    HTML5_CALL(this->v, setLineDash, toJSArray<double>(segments));
}

void CanvasRenderingContext2D::setTransform(double a, double b, double c, double d, double e, double f)
{
    HTML5_CALL(this->v, setTransform, a, b, c, d, e, f);
}

void CanvasRenderingContext2D::stroke(Path2D *path)
{
    HTML5_CALL(this->v, stroke, path->v);
}
    
void CanvasRenderingContext2D::strokeRect(double x, double y, double w, double h)
{
    HTML5_CALL(this->v, strokeRect, x, y, w, h);
}

void CanvasRenderingContext2D::strokeText(std::string text, double x, double y)
{
    HTML5_CALL(this->v, strokeText, text, x, y);
}

void CanvasRenderingContext2D::strokeText(std::string text, double x, double y, double maxWidth)
{
    HTML5_CALL(this->v, strokeText, text, x, y, maxWidth);
}

void CanvasRenderingContext2D::transform(double a, double b, double c, double d, double e, double f)
{
    HTML5_CALL(this->v, transform, a, b, c, d, e, f);
}

void CanvasRenderingContext2D::translate(double x, double y)
{
    HTML5_CALL(this->v, translate, x, y);
}

HTMLCanvasElement *CanvasRenderingContext2D::getCanvas() const
{
    return HTML5_PROPERTY_GET(canvas, HTMLCanvasElement);
}

void CanvasRenderingContext2D::setCanvas(HTMLCanvasElement *value)
{
    HTML5_PROPERTY_OBJECT_SET(canvas, value);
}

SVGMatrix *CanvasRenderingContext2D::getCurrentTransform() const
{
    return HTML5_PROPERTY_GET(currentTransform, SVGMatrix);
}

void CanvasRenderingContext2D::setCurrentTransform(SVGMatrix *value)
{
    HTML5_PROPERTY_OBJECT_SET(currentTransform, value);
}

std::string CanvasRenderingContext2D::getDirection() const
{
    return HTML5_PROPERTY_GET(direction, std::string);
}

void CanvasRenderingContext2D::setDirection(std::string value)
{
    HTML5_PROPERTY_SET(direction, value);
}

void CanvasRenderingContext2D::setFillStyle(std::string value)
{
    this->_fillStyleColor = value;
    this->v.set("fillStyle", value);
}

void CanvasRenderingContext2D::setFillStyle(CanvasGradient *value)
{
    this->_fillStyleGradient = value;
    this->v.set("fillStyle", value->v);
}

void CanvasRenderingContext2D::setFillStyle(CanvasPattern *value)
{
    this->_fillStylePattern = value;
    this->v.set("fillStyle", value->v);
}

std::string CanvasRenderingContext2D::getFont() const
{
    return HTML5_PROPERTY_GET(font, std::string);
}

void CanvasRenderingContext2D::setFont(std::string value)
{
    HTML5_PROPERTY_SET(font, value);
}

double CanvasRenderingContext2D::getGlobalAlpha() const
{
    return HTML5_PROPERTY_GET(globalAlpha, double);
}

void CanvasRenderingContext2D::setGlobalAlpha(double value)
{
    HTML5_PROPERTY_SET(globalAlpha, value);
}

std::string CanvasRenderingContext2D::getGlobalCompositeOperation() const
{
    return HTML5_PROPERTY_GET(globalCompositeOperation, std::string);
}

void CanvasRenderingContext2D::setGlobalCompositeOperation(std::string value)
{
    HTML5_PROPERTY_SET(globalCompositeOperation, value);
}

unsigned long CanvasRenderingContext2D::getHeight() const
{
    return HTML5_PROPERTY_GET(height, unsigned long);
}

void CanvasRenderingContext2D::setHeight(unsigned long value)
{
    HTML5_PROPERTY_SET(height, value);
}

bool CanvasRenderingContext2D::getImageSmoothingEnabled() const
{
    return HTML5_PROPERTY_GET(imageSmoothingEnabled, bool);
}

void CanvasRenderingContext2D::setImageSmoothingEnabled(bool value)
{
    HTML5_PROPERTY_SET(imageSmoothingEnabled, value);
}

std::string CanvasRenderingContext2D::getLineCap() const
{
    return HTML5_PROPERTY_GET(lineCap, std::string);
}

void CanvasRenderingContext2D::setLineCap(std::string value)
{
    HTML5_PROPERTY_SET(lineCap, value);
}

double CanvasRenderingContext2D::getLineDashOffset() const
{
    return HTML5_PROPERTY_GET(lineDashOffset, double);
}

void CanvasRenderingContext2D::setLineDashOffset(double value)
{
    HTML5_PROPERTY_SET(lineDashOffset, value);
}

std::string CanvasRenderingContext2D::getLineJoin() const
{
    return HTML5_PROPERTY_GET(lineJoin, std::string);
}

void CanvasRenderingContext2D::setLineJoin(std::string value)
{
    HTML5_PROPERTY_SET(lineJoin, value);
}

double CanvasRenderingContext2D::getLineWidth() const
{
    return HTML5_PROPERTY_GET(lineWidth, double);
}

void CanvasRenderingContext2D::setLineWidth(double value)
{
    HTML5_PROPERTY_SET(lineWidth, value);
}

double CanvasRenderingContext2D::getMiterLimit() const
{
    return HTML5_PROPERTY_GET(miterLimit, double);
}
    
void CanvasRenderingContext2D::setMiterLimit(double value)
{
    HTML5_PROPERTY_SET(miterLimit, value);
}

double CanvasRenderingContext2D::getShadowBlur() const
{
    return HTML5_PROPERTY_GET(shadowBlur, double);
}

void CanvasRenderingContext2D::setShadowBlur(double value)
{
    HTML5_PROPERTY_SET(shadowBlur, value);
}

std::string CanvasRenderingContext2D::getShadowColor() const
{
    return HTML5_PROPERTY_GET(shadowColor, std::string);
}

void CanvasRenderingContext2D::setShadowColor(std::string value)
{
    HTML5_PROPERTY_SET(shadowColor, value);
}

double CanvasRenderingContext2D::getShadowOffsetX() const
{
    return HTML5_PROPERTY_GET(shadowOffsetX, double);
}

void CanvasRenderingContext2D::setShadowOffsetX(double value)
{
    HTML5_PROPERTY_SET(shadowOffsetX, value);
}

double CanvasRenderingContext2D::getShadowOffsetY() const
{
    return HTML5_PROPERTY_GET(shadowOffsetY, double);
}

void CanvasRenderingContext2D::setShadowOffsetY(double value)
{
    HTML5_PROPERTY_SET(shadowOffsetY, value);
}

void CanvasRenderingContext2D::setStrokeStyle(std::string value)
{
    this->_strokeStyleColor = value;
    this->v.set("strokeStyle", value);
}

void CanvasRenderingContext2D::setStrokeStyle(CanvasGradient *value)
{
    this->_strokeStyleGradient = value;
    this->v.set("strokeStyle", value->v);
}

void CanvasRenderingContext2D::setStrokeStyle(CanvasPattern *value)
{
    this->_strokeStylePattern = value;
    this->v.set("strokeStyle", value->v);
}

std::string CanvasRenderingContext2D::getTextAlign() const
{
    return HTML5_PROPERTY_GET(textAlign, std::string);
}

void CanvasRenderingContext2D::setTextAlign(std::string value)
{
    HTML5_PROPERTY_SET(textAlign, value);
}

std::string CanvasRenderingContext2D::getTextBaseLine() const
{
    return HTML5_PROPERTY_GET(textBaseline, std::string);
}

void CanvasRenderingContext2D::setTextBaseLine(std::string value)
{
    HTML5_PROPERTY_SET(textBaseline, value);
}

unsigned long CanvasRenderingContext2D::getWidth() const
{
    return HTML5_PROPERTY_GET(width, unsigned long);
}

void CanvasRenderingContext2D::setWidth(unsigned long value)
{
    HTML5_PROPERTY_SET(width, value);
}
