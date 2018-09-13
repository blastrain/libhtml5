#pragma once

#include "rendering_context.h"
#include "canvas_fill_rule.h"

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
    HTMLCanvasElement *_canvas;
    SVGMatrix *_currentTransform;
    std::string _direction;
    std::string _fillStyleColor;
    CanvasGradient *_fillStyleGradient;
    CanvasPattern *_fillStylePattern;
    std::string _font;
    double _globalAlpha;
    std::string _globalCompositeOperation;
    unsigned long _height;
    bool _imageSmoothingEnabled;
    std::string _lineCap;
    double _lineDashOffset;
    std::string _lineJoin;
    double _lineWidth;
    double _miterLimit;
    double _shadowBlur;
    std::string _shadowColor;
    double _shadowOffsetX;
    double _shadowOffsetY;
    std::string _strokeStyleColor;
    CanvasGradient *_strokeStyleGradient;
    CanvasPattern *_strokeStylePattern;
    std::string _textAlign;
    std::string _textBaseline;
    unsigned long _width;

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

    HTMLCanvasElement *getCanvas() const;
    void setCanvas(HTMLCanvasElement *value);
    SVGMatrix *getCurrentTransform() const;
    void setCurrentTransform(SVGMatrix *value);
    std::string getDirection() const;
    void setDirection(std::string value);
    void setFillStyle(std::string value);
    void setFillStyle(CanvasGradient *value);
    void setFillStyle(CanvasPattern *value);
    std::string getFont() const;
    void setFont(std::string value);
    double getGlobalAlpha() const;
    void setGlobalAlpha(double value);
    std::string getGlobalCompositeOperation() const;
    void setGlobalCompositeOperation(std::string value);
    unsigned long getHeight() const;
    void setHeight(unsigned long value);
    bool getImageSmoothingEnabled() const;
    void setImageSmoothingEnabled(bool value);
    std::string getLineCap() const;
    void setLineCap(std::string value);
    double getLineDashOffset() const;
    void setLineDashOffset(double value);
    std::string getLineJoin() const;
    void setLineJoin(std::string value);
    double getLineWidth() const;
    void setLineWidth(double value);
    double getMiterLimit() const;
    void setMiterLimit(double value);
    double getShadowBlur() const;
    void setShadowBlur(double value);
    std::string getShadowColor() const;
    void setShadowColor(std::string value);
    double getShadowOffsetX() const;
    void setShadowOffsetX(double value);
    double getShadowOffsetY() const;
    void setShadowOffsetY(double value);
    void setStrokeStyle(std::string value);
    void setStrokeStyle(CanvasGradient *value);
    void setStrokeStyle(CanvasPattern *value);
    std::string getTextAlign() const;
    void setTextAlign(std::string value);
    std::string getTextBaseLine() const;
    void setTextBaseLine(std::string value);
    unsigned long getWidth() const;
    void setWidth(unsigned long value);

    struct {
        CanvasRenderingContext2D &self;
        void operator=(HTMLCanvasElement *value) { self.setCanvas(value); };
        operator HTMLCanvasElement *() { return self.getCanvas(); };
    } canvas{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(SVGMatrix *value) { self.setCurrentTransform(value); };
        operator SVGMatrix *() { return self.getCurrentTransform(); };
    } currentTransform{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.setDirection(value); };
        operator std::string() { return self.getDirection(); };
    } direction{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.setFillStyle(value); };
        void operator=(CanvasGradient *value) { self.setFillStyle(value); };
        void operator=(CanvasPattern *value) { self.setFillStyle(value); };
    } fillStyle{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.setFont(value); };
        operator std::string() { return self.getFont(); };
    } font{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(double value) { self.setGlobalAlpha(value); };
        operator double() { return self.getGlobalAlpha(); };
    } globalAlpha{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.setGlobalCompositeOperation(value); };
        operator std::string() { return self.getGlobalCompositeOperation(); };
    } globalCompositeOperation{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(unsigned long value) { self.setHeight(value); };
        operator unsigned long() { return self.getHeight(); };
    } height{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(bool value) { self.setImageSmoothingEnabled(value); };
        operator bool() { return self.getImageSmoothingEnabled(); };
    } imageSmoothingEnabled{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.setLineCap(value); };
        operator std::string() { return self.getLineCap(); };
    } lineCap{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(double value) { self.setLineDashOffset(value); };
        operator double() { return self.getLineDashOffset(); };
    } lineDashOffset{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.setLineJoin(value); };
        operator std::string() { return self.getLineJoin(); };
    } lineJoin{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(double value) { self.setLineWidth(value); };
        operator double() { return self.getLineWidth(); };
    } lineWidth{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(double value) { self.setMiterLimit(value); };
        operator double() { return self.getMiterLimit(); };
    } miterLimit{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(double value) { self.setShadowBlur(value); };
        operator double() { return self.getShadowBlur(); };
    } shadowBlur{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.setShadowColor(value); };
        operator std::string() { return self.getShadowColor(); };
    } shadowColor{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(double value) { self.setShadowOffsetX(value); };
        operator double() { return self.getShadowOffsetX(); };
    } shadowOffsetX{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(double value) { self.setShadowOffsetY(value); };
        operator double() { return self.getShadowOffsetY(); };
    } shadowOffsetY{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.setStrokeStyle(value); };
        void operator=(CanvasGradient *value) { self.setStrokeStyle(value); };
        void operator=(CanvasPattern *value) { self.setStrokeStyle(value); };
    } strokeStyle{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.setTextAlign(value); };
        operator std::string() { return self.getTextAlign(); };
    } textAlign{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(std::string value) { self.setTextBaseLine(value); };
        operator std::string() { return self.getTextBaseLine(); };
    } textBaseline{*this};

    struct {
        CanvasRenderingContext2D &self;
        void operator=(double value) { self.setWidth(value); };
        operator double() { return self.getWidth(); };
    } width{*this};
};
