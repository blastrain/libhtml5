#pragma once

#include "rendering_context.h"
#include "canvas_fill_rule.h"

NAMESPACE_HTML5_BEGIN;

class HitRegionOptions;
class HTMLImageElement;
class HTMLVideoElement;
class HTMLCanvasElement;
class SVGMatrix;
class CanvasGradient;
class CanvasPattern;
class ImageData;
class ImageBitmap;
class TextMetrics;
class Path2D;

class CanvasRenderingContext2D : public RenderingContext {
public:

    HTML5_PROPERTY_OBJECT(CanvasRenderingContext2D, HTMLCanvasElement, canvas);
    HTML5_PROPERTY_OBJECT(CanvasRenderingContext2D, SVGMatrix, currentTransform);
    HTML5_PROPERTY(CanvasRenderingContext2D, std::string, direction);
    HTML5_PROPERTY(CanvasRenderingContext2D, std::string, fillStyleColor);
    HTML5_PROPERTY_OBJECT(CanvasRenderingContext2D, CanvasGradient, fillStyleGradient);
    HTML5_PROPERTY_OBJECT(CanvasRenderingContext2D, CanvasPattern, fillStylePattern);
    HTML5_PROPERTY(CanvasRenderingContext2D, std::string, font);
    HTML5_PROPERTY(CanvasRenderingContext2D, double, globalAlpha);
    HTML5_PROPERTY(CanvasRenderingContext2D, std::string, globalCompositeOperation);
    HTML5_PROPERTY(CanvasRenderingContext2D, unsigned long, height);
    HTML5_PROPERTY(CanvasRenderingContext2D, bool, imageSmoothingEnabled);
    HTML5_PROPERTY(CanvasRenderingContext2D, std::string, lineCap);
    HTML5_PROPERTY(CanvasRenderingContext2D, double, lineDashOffset);
    HTML5_PROPERTY(CanvasRenderingContext2D, std::string, lineJoin);
    HTML5_PROPERTY(CanvasRenderingContext2D, double, lineWidth);
    HTML5_PROPERTY(CanvasRenderingContext2D, double, miterLimit);
    HTML5_PROPERTY(CanvasRenderingContext2D, double, shadowBlur);
    HTML5_PROPERTY(CanvasRenderingContext2D, std::string, shadowColor);
    HTML5_PROPERTY(CanvasRenderingContext2D, double, shadowOffsetX);
    HTML5_PROPERTY(CanvasRenderingContext2D, double, shadowOffsetY);
    HTML5_PROPERTY(CanvasRenderingContext2D, std::string, strokeStyleColor);
    HTML5_PROPERTY_OBJECT(CanvasRenderingContext2D, CanvasGradient, strokeStyleGradient);
    HTML5_PROPERTY_OBJECT(CanvasRenderingContext2D, CanvasPattern, strokeStylePattern);
    HTML5_PROPERTY(CanvasRenderingContext2D, std::string, textAlign);
    HTML5_PROPERTY(CanvasRenderingContext2D, std::string, textBaseline);
    HTML5_PROPERTY(CanvasRenderingContext2D, unsigned long, width);

    CanvasRenderingContext2D(emscripten::val v);
    virtual ~CanvasRenderingContext2D();
    static CanvasRenderingContext2D *create(emscripten::val v);
    void addHitRegion(HitRegionOptions *option);
    void arc(double x, double y, double radius, double startAngle, double endAngle, bool anticlockwise = false);
    void arcTo(double x1, double y1, double x2, double y2, double radius);
    void beginPath();
    void bezierCurveTo(double cp1x, double cp1y, double cp2x, double cp2y, double x, double y);
    void clearRect(double x, double y, double w, double h);
    void clip();
    void clip(CanvasFillRule fillRule);
    void clip(Path2D *path, CanvasFillRule fillRule);
    void closePath();
    void commit();
    ImageData *createImageData(unsigned long width, unsigned long height);
    ImageData *createImageData(ImageData *imagedata);
    CanvasGradient *createLinearGradient(double x0, double y0, double x1, double y1);
    CanvasPattern *createPattern(HTMLImageElement *image, std::string repetition);
    CanvasPattern *createPattern(HTMLVideoElement *image, std::string repetition);
    CanvasPattern *createPattern(HTMLCanvasElement *image, std::string repetition);
    CanvasPattern *createPattern(CanvasRenderingContext2D *image, std::string repetition);
    CanvasPattern *createPattern(ImageBitmap *image, std::string repetition);
    CanvasGradient *createRadialGradient(double x0, double y0, double r0, double x1, double y1, double r1);
    void drawImage(HTMLImageElement *image, double x, double y);
    void drawImage(HTMLImageElement *image, double dx, double dy, double dw, double dh);
    void drawImage(HTMLImageElement *image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh);
    void drawImage(HTMLVideoElement *image, double x, double y);
    void drawImage(HTMLVideoElement *image, double dx, double dy, double dw, double dh);
    void drawImage(HTMLVideoElement *image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh);
    void drawImage(HTMLCanvasElement *image, double x, double y);
    void drawImage(HTMLCanvasElement *image, double dx, double dy, double dw, double dh);
    void drawImage(HTMLCanvasElement *image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh);
    void drawImage(CanvasRenderingContext2D *image, double x, double y);
    void drawImage(CanvasRenderingContext2D *image, double dx, double dy, double dw, double dh);
    void drawImage(CanvasRenderingContext2D *image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh);
    void drawImage(ImageBitmap *image, double x, double y);
    void drawImage(ImageBitmap *image, double dx, double dy, double dw, double dh);
    void drawImage(ImageBitmap *image, double sx, double sy, double sw, double sh, double dx, double dy, double dw, double dh);
    void ellipse(double x, double y, double radiusX, double radiusY, double rotation, double startAngle, double endAngle, bool anticlockwise);
    void fill(CanvasFillRule fillRule = CanvasFillRule::NONZERO);
    void fill(Path2D *path, CanvasFillRule fillRule = CanvasFillRule::NONZERO);
    void fillRect(double x, double y, double w, double h);
    void fillText(std::string text, double x, double y);
    void fillText(std::string text, double x, double y, double maxWidth);
    ImageData *getImageData(double sx, double sy, double sw, double sh);
    std::vector<double> getLineDash();
    bool isPointInPath(double x, double y, CanvasFillRule fillRule = CanvasFillRule::NONZERO);
    bool isPointInPath(Path2D *path, double x, double y, CanvasFillRule fillRule = CanvasFillRule::NONZERO);
    bool isPointStroke(double x, double y);
    bool isPointStroke(Path2D *path, double x, double y);
    void lineTo(double x, double y);
    TextMetrics *measureText(std::string text);
    void moveTo(double x, double y);
    void putImageData(ImageData *imageData, double dx, double dy);
    void putImageData(ImageData *imageData, double dx, double dy, double dirtyX, double dirtyY, double dirtyWidth, double dirtyHeight);
    void quadraticCurveTo(double cpx, double cpy, double x, double y);
    void rect(double x, double y, double w, double h);
    void removeHitRegion(std::string id);
    void resetClip();
    void resetTransform();
    void restore();
    void rotate(double angle);
    void save();
    void scale(double x, double y);
    void scrollPathIntoView();
    void scrollPathIntoView(Path2D *path);
    void setLineDash(std::vector<double> segments);
    void setTransform(double a, double b, double c, double d, double e, double f);
    void stroke(Path2D *path);
    void strokeRect(double x, double y, double w, double h);
    void strokeText(std::string text, double x, double y);
    void strokeText(std::string text, double x, double y, double maxWidth);
    void transform(double a, double b, double c, double d, double e, double f);
    void translate(double x, double y);

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.set_fillStyleColor(value); };
        void operator=(std::unique_ptr<CanvasGradient> value) { self.set_fillStyleGradient(value); };
        void operator=(std::unique_ptr<CanvasPattern> value) { self.set_fillStylePattern(value); };
    } fillStyle{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.set_strokeStyleColor(value); };
        void operator=(std::unique_ptr<CanvasGradient> value) { self.set_strokeStyleGradient(value); };
        void operator=(std::unique_ptr<CanvasPattern> value) { self.set_strokeStylePattern(value); };
    } strokeStyle{*this};

};

NAMESPACE_HTML5_END;
