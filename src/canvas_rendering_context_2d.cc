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

USING_NAMESPACE_HTML5;

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

HTML5_PROPERTY_OBJECT_IMPL(CanvasRenderingContext2D, HTMLCanvasElement, canvas);
HTML5_PROPERTY_OBJECT_IMPL(CanvasRenderingContext2D, SVGMatrix, currentTransform);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, std::string, direction);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, std::string, fillStyleColor);
HTML5_PROPERTY_OBJECT_IMPL(CanvasRenderingContext2D, CanvasGradient, fillStyleGradient);
HTML5_PROPERTY_OBJECT_IMPL(CanvasRenderingContext2D, CanvasPattern, fillStylePattern);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, std::string, font);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, double, globalAlpha);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, std::string, globalCompositeOperation);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, unsigned long, height);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, bool, imageSmoothingEnabled);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, std::string, lineCap);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, double, lineDashOffset);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, std::string, lineJoin);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, double, lineWidth);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, double, miterLimit);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, double, shadowBlur);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, std::string, shadowColor);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, double, shadowOffsetX);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, double, shadowOffsetY);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, std::string, strokeStyleColor);
HTML5_PROPERTY_OBJECT_IMPL(CanvasRenderingContext2D, CanvasGradient, strokeStyleGradient);
HTML5_PROPERTY_OBJECT_IMPL(CanvasRenderingContext2D, CanvasPattern, strokeStylePattern);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, std::string, textAlign);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, std::string, textBaseline);
HTML5_PROPERTY_IMPL(CanvasRenderingContext2D, unsigned long, width);
