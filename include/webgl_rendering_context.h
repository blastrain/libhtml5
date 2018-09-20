#pragma once

#include "rendering_context.h"

NAMESPACE_HTML5_BEGIN;

class WebGLBuffer;
class WebGLProgram;
class WebGLShader;
class WebGLRenderbuffer;
class WebGLFramebuffer;
class WebGLTexture;
class ArrayBufferView;
class ArrayBuffer;
class WebGLActiveInfo;
class WebGLContextAttributes;
class WebGLUniformLocation;
class WebGLShaderPrecisionFormat;
class HTMLCanvasElement;
class HTMLVideoElement;
class HTMLImageElement;
class ImageData;
class ImageBitmap;
class WebGLExtension;

class WebGLFramebufferAttachmentParameter : public Object {
public:

    WebGLFramebufferAttachmentParameter(emscripten::val v);
    virtual ~WebGLFramebufferAttachmentParameter();
    static WebGLFramebufferAttachmentParameter *create(emscripten::val v);
};

class WebGLParameter : public Object {
public:

    WebGLParameter(emscripten::val v);
    virtual ~WebGLParameter();
    static WebGLParameter *create(emscripten::val v);
};

class WebGLProgramParameter : public Object {
public:

    WebGLProgramParameter(emscripten::val v);
    virtual ~WebGLProgramParameter();
    static WebGLProgramParameter *create(emscripten::val v);
};

class WebGLRenderbufferParameter : public Object {
public:

    WebGLRenderbufferParameter(emscripten::val v);
    virtual ~WebGLRenderbufferParameter();
    static WebGLRenderbufferParameter *create(emscripten::val v);
};

class WebGLShaderParameter : public Object {
public:

    WebGLShaderParameter(emscripten::val v);
    virtual ~WebGLShaderParameter();
    static WebGLShaderParameter *create(emscripten::val v);
};

class WebGLTextureParameter : public Object {
public:

    WebGLTextureParameter(emscripten::val v);
    virtual ~WebGLTextureParameter();
    static WebGLTextureParameter *create(emscripten::val v);
};

class WebGLUniformParameter : public Object {
public:

    WebGLUniformParameter(emscripten::val v);
    virtual ~WebGLUniformParameter();
    static WebGLUniformParameter *create(emscripten::val v);
};

class WebGLVertexAttribute : public Object {
public:

    WebGLVertexAttribute(emscripten::val v);
    virtual ~WebGLVertexAttribute();
    static WebGLVertexAttribute *create(emscripten::val v);
};

class WebGLRenderingContext : public RenderingContext {
public:
    enum {
        ACTIVE_ATTRIBUTES = 0x8B89,
        ACTIVE_TEXTURE = 0x84E0,
        ACTIVE_UNIFORMS = 0x8B86,
        ALIASED_LINE_WIDTH_RANGE = 0x846E,
        ALIASED_POINT_SIZE_RANGE = 0x846D,
        ALPHA = 0x1906,
        ALPHA_BITS = 0x0D55,
        ALWAYS = 0x0207,
        ARRAY_BUFFER = 0x8892,
        ARRAY_BUFFER_BINDING = 0x8894,
        ATTACHED_SHADERS = 0x8B85,
        BACK = 0x0405,
        BLEND = 0x0BE2,
        BLEND_COLOR = 0x8005,
        BLEND_DST_ALPHA = 0x80CA,
        BLEND_DST_RGB = 0x80C8,
        BLEND_EQUATION = 0x8009,
        BLEND_EQUATION_ALPHA = 0x883D,
        BLEND_EQUATION_RGB = 0x8009,
        BLEND_SRC_ALPHA = 0x80CB,
        BLEND_SRC_RGB = 0x80C9,
        BLUE_BITS = 0x0D54,
        BOOL = 0x8B56,
        BOOL_VEC2 = 0x8B57,
        BOOL_VEC3 = 0x8B58,
        BOOL_VEC4 = 0x8B59,
        BROWSER_DEFAULT_WEBGL = 0x9244,
        BUFFER_SIZE = 0x8764,
        BUFFER_USAGE = 0x8765,
        BYTE = 0x1400,
        CCW = 0x0901,
        CLAMP_TO_EDGE = 0x812F,
        COLOR_ATTACHMENT0 = 0x8CE0,
        COLOR_BUFFER_BIT = 0x00004000,
        COLOR_CLEAR_VALUE = 0x0C22,
        COLOR_WRITEMASK = 0x0C23,
        COMPILE_STATUS = 0x8B81,
        COMPRESSED_TEXTURE_FORMATS = 0x86A3,
        CONSTANT_ALPHA = 0x8003,
        CONSTANT_COLOR = 0x8001,
        CONTEXT_LOST_WEBGL = 0x9242,
        CULL_FACE = 0x0B44,
        CULL_FACE_MODE = 0x0B45,
        CURRENT_PROGRAM = 0x8B8D,
        CURRENT_VERTEX_ATTRIB = 0x8626,
        CW = 0x0900,
        DECR = 0x1E03,
        DECR_WRAP = 0x8508,
        DELETE_STATUS = 0x8B80,
        DEPTH_ATTACHMENT = 0x8D00,
        DEPTH_BITS = 0x0D56,
        DEPTH_BUFFER_BIT = 0x00000100,
        DEPTH_CLEAR_VALUE = 0x0B73,
        DEPTH_COMPONENT = 0x1902,
        DEPTH_COMPONENT16 = 0x81A5,
        DEPTH_FUNC = 0x0B74,
        DEPTH_RANGE = 0x0B70,
        DEPTH_STENCIL = 0x84F9,
        DEPTH_STENCIL_ATTACHMENT = 0x821A,
        DEPTH_TEST = 0x0B71,
        DEPTH_WRITEMASK = 0x0B72,
        DITHER = 0x0BD0,
        DONT_CARE = 0x1100,
        DST_ALPHA = 0x0304,
        DST_COLOR = 0x0306,
        DYNAMIC_DRAW = 0x88E8,
        ELEMENT_ARRAY_BUFFER = 0x8893,
        ELEMENT_ARRAY_BUFFER_BINDING = 0x8895,
        EQUAL = 0x0202,
        FASTEST = 0x1101,
        FLOAT = 0x1406,
        FLOAT_MAT2 = 0x8B5A,
        FLOAT_MAT3 = 0x8B5B,
        FLOAT_MAT4 = 0x8B5C,
        FLOAT_VEC2 = 0x8B50,
        FLOAT_VEC3 = 0x8B51,
        FLOAT_VEC4 = 0x8B52,
        FRAGMENT_SHADER = 0x8B30,
        FRAMEBUFFER = 0x8D40,
        FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1,
        FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0,
        FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3,
        FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2,
        FRAMEBUFFER_BINDING = 0x8CA6,
        FRAMEBUFFER_COMPLETE = 0x8CD5,
        FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6,
        FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8CD9,
        FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7,
        FRAMEBUFFER_UNSUPPORTED = 0x8CDD,
        FRONT = 0x0404,
        FRONT_AND_BACK = 0x0408,
        FRONT_FACE = 0x0B46,
        FUNC_ADD = 0x8006,
        FUNC_REVERSE_SUBTRACT = 0x800B,
        FUNC_SUBTRACT = 0x800A,
        GENERATE_MIPMAP_HINT = 0x8192,
        GEQUAL = 0x0206,
        GREATER = 0x0204,
        GREEN_BITS = 0x0D53,
        HIGH_FLOAT = 0x8DF2,
        HIGH_INT = 0x8DF5,
        IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B,
        IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A,
        INCR = 0x1E02,
        INCR_WRAP = 0x8507,
        INT = 0x1404,
        INT_VEC2 = 0x8B53,
        INT_VEC3 = 0x8B54,
        INT_VEC4 = 0x8B55,
        INVALID_ENUM = 0x0500,
        INVALID_FRAMEBUFFER_OPERATION = 0x0506,
        INVALID_OPERATION = 0x0502,
        INVALID_VALUE = 0x0501,
        INVERT = 0x150A,
        KEEP = 0x1E00,
        LEQUAL = 0x0203,
        LESS = 0x0201,
        LINE_LOOP = 0x0002,
        LINE_STRIP = 0x0003,
        LINE_WIDTH = 0x0B21,
        LINEAR = 0x2601,
        LINEAR_MIPMAP_LINEAR = 0x2703,
        LINEAR_MIPMAP_NEAREST = 0x2701,
        LINES = 0x0001,
        LINK_STATUS = 0x8B82,
        LOW_FLOAT = 0x8DF0,
        LOW_INT = 0x8DF3,
        LUMINANCE = 0x1909,
        LUMINANCE_ALPHA = 0x190A,
        MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
        MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C,
        MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD,
        MAX_RENDERBUFFER_SIZE = 0x84E8,
        MAX_TEXTURE_IMAGE_UNITS = 0x8872,
        MAX_TEXTURE_SIZE = 0x0D33,
        MAX_VARYING_VECTORS = 0x8DFC,
        MAX_VERTEX_ATTRIBS = 0x8869,
        MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C,
        MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB,
        MAX_VIEWPORT_DIMS = 0x0D3A,
        MEDIUM_FLOAT = 0x8DF1,
        MEDIUM_INT = 0x8DF4,
        MIRRORED_REPEAT = 0x8370,
        NEAREST = 0x2600,
        NEAREST_MIPMAP_LINEAR = 0x2702,
        NEAREST_MIPMAP_NEAREST = 0x2700,
        NEVER = 0x0200,
        NICEST = 0x1102,
        NO_ERROR = 0,
        NONE = 0,
        NOTEQUAL = 0x0205,
        ONE = 1,
        ONE_MINUS_CONSTANT_ALPHA = 0x8004,
        ONE_MINUS_CONSTANT_COLOR = 0x8002,
        ONE_MINUS_DST_ALPHA = 0x0305,
        ONE_MINUS_DST_COLOR = 0x0307,
        ONE_MINUS_SRC_ALPHA = 0x0303,
        ONE_MINUS_SRC_COLOR = 0x0301,
        OUT_OF_MEMORY = 0x0505,
        PACK_ALIGNMENT = 0x0D05,
        POINTS = 0x0000,
        POLYGON_OFFSET_FACTOR = 0x8038,
        POLYGON_OFFSET_FILL = 0x8037,
        POLYGON_OFFSET_UNITS = 0x2A00,
        RED_BITS = 0x0D52,
        RENDERBUFFER = 0x8D41,
        RENDERBUFFER_ALPHA_SIZE = 0x8D53,
        RENDERBUFFER_BINDING = 0x8CA7,
        RENDERBUFFER_BLUE_SIZE = 0x8D52,
        RENDERBUFFER_DEPTH_SIZE = 0x8D54,
        RENDERBUFFER_GREEN_SIZE = 0x8D51,
        RENDERBUFFER_HEIGHT = 0x8D43,
        RENDERBUFFER_INTERNAL_FORMAT = 0x8D44,
        RENDERBUFFER_RED_SIZE = 0x8D50,
        RENDERBUFFER_STENCIL_SIZE = 0x8D55,
        RENDERBUFFER_WIDTH = 0x8D42,
        RENDERER = 0x1F01,
        REPEAT = 0x2901,
        REPLACE = 0x1E01,
        RGB = 0x1907,
        RGB565 = 0x8D62,
        RGB5_A1 = 0x8057,
        RGBA = 0x1908,
        RGBA4 = 0x8056,
        SAMPLE_ALPHA_TO_COVERAGE = 0x809E,
        SAMPLE_BUFFERS = 0x80A8,
        SAMPLE_COVERAGE = 0x80A0,
        SAMPLE_COVERAGE_INVERT = 0x80AB,
        SAMPLE_COVERAGE_VALUE = 0x80AA,
        SAMPLER_2D = 0x8B5E,
        SAMPLER_CUBE = 0x8B60,
        SAMPLES = 0x80A9,
        SCISSOR_BOX = 0x0C10,
        SCISSOR_TEST = 0x0C11,
        SHADER_TYPE = 0x8B4F,
        SHADING_LANGUAGE_VERSION = 0x8B8C,
        SHORT = 0x1402,
        SRC_ALPHA = 0x0302,
        SRC_ALPHA_SATURATE = 0x0308,
        SRC_COLOR = 0x0300,
        STATIC_DRAW = 0x88E4,
        STENCIL_ATTACHMENT = 0x8D20,
        STENCIL_BACK_FAIL = 0x8801,
        STENCIL_BACK_FUNC = 0x8800,
        STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802,
        STENCIL_BACK_PASS_DEPTH_PASS = 0x8803,
        STENCIL_BACK_REF = 0x8CA3,
        STENCIL_BACK_VALUE_MASK = 0x8CA4,
        STENCIL_BACK_WRITEMASK = 0x8CA5,
        STENCIL_BITS = 0x0D57,
        STENCIL_BUFFER_BIT = 0x00000400,
        STENCIL_CLEAR_VALUE = 0x0B91,
        STENCIL_FAIL = 0x0B94,
        STENCIL_FUNC = 0x0B92,
        STENCIL_INDEX = 0x1901,
        STENCIL_INDEX8 = 0x8D48,
        STENCIL_PASS_DEPTH_FAIL = 0x0B95,
        STENCIL_PASS_DEPTH_PASS = 0x0B96,
        STENCIL_REF = 0x0B97,
        STENCIL_TEST = 0x0B90,
        STENCIL_VALUE_MASK = 0x0B93,
        STENCIL_WRITEMASK = 0x0B98,
        STREAM_DRAW = 0x88E0,
        SUBPIXEL_BITS = 0x0D50,
        TEXTURE = 0x1702,
        TEXTURE0 = 0x84C0,
        TEXTURE1 = 0x84C1,
        TEXTURE10 = 0x84CA,
        TEXTURE11 = 0x84CB,
        TEXTURE12 = 0x84CC,
        TEXTURE13 = 0x84CD,
        TEXTURE14 = 0x84CE,
        TEXTURE15 = 0x84CF,
        TEXTURE16 = 0x84D0,
        TEXTURE17 = 0x84D1,
        TEXTURE18 = 0x84D2,
        TEXTURE19 = 0x84D3,
        TEXTURE2 = 0x84C2,
        TEXTURE20 = 0x84D4,
        TEXTURE21 = 0x84D5,
        TEXTURE22 = 0x84D6,
        TEXTURE23 = 0x84D7,
        TEXTURE24 = 0x84D8,
        TEXTURE25 = 0x84D9,
        TEXTURE26 = 0x84DA,
        TEXTURE27 = 0x84DB,
        TEXTURE28 = 0x84DC,
        TEXTURE29 = 0x84DD,
        TEXTURE3 = 0x84C3,
        TEXTURE30 = 0x84DE,
        TEXTURE31 = 0x84DF,
        TEXTURE4 = 0x84C4,
        TEXTURE5 = 0x84C5,
        TEXTURE6 = 0x84C6,
        TEXTURE7 = 0x84C7,
        TEXTURE8 = 0x84C8,
        TEXTURE9 = 0x84C9,
        TEXTURE_2D = 0x0DE1,
        TEXTURE_BINDING_2D = 0x8069,
        TEXTURE_BINDING_CUBE_MAP = 0x8514,
        TEXTURE_CUBE_MAP = 0x8513,
        TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
        TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
        TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A,
        TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
        TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
        TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
        TEXTURE_MAG_FILTER = 0x2800,
        TEXTURE_MIN_FILTER = 0x2801,
        TEXTURE_WRAP_S = 0x2802,
        TEXTURE_WRAP_T = 0x2803,
        TRIANGLE_FAN = 0x0006,
        TRIANGLE_STRIP = 0x0005,
        TRIANGLES = 0x0004,
        UNPACK_ALIGNMENT = 0x0CF5,
        UNPACK_COLORSPACE_CONVERSION_WEBGL = 0x9243,
        UNPACK_FLIP_Y_WEBGL = 0x9240,
        UNPACK_PREMULTIPLY_ALPHA_WEBGL = 0x9241,
        UNSIGNED_BYTE = 0x1401,
        UNSIGNED_INT = 0x1405,
        UNSIGNED_SHORT = 0x1403,
        UNSIGNED_SHORT_4_4_4_4 = 0x8033,
        UNSIGNED_SHORT_5_5_5_1 = 0x8034,
        UNSIGNED_SHORT_5_6_5 = 0x8363,
        VALIDATE_STATUS = 0x8B83,
        VENDOR = 0x1F00,
        VERSION = 0x1F02,
        VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
        VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622,
        VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A,
        VERTEX_ATTRIB_ARRAY_POINTER = 0x8645,
        VERTEX_ATTRIB_ARRAY_SIZE = 0x8623,
        VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624,
        VERTEX_ATTRIB_ARRAY_TYPE = 0x8625,
        VERTEX_SHADER = 0x8B31,
        VIEWPORT = 0x0BA2,
        ZERO = 0,
    };

    HTML5_PROPERTY(WebGLRenderingContext, HTMLCanvasElement *, canvas);
    HTML5_PROPERTY(WebGLRenderingContext, GLsizei, drawingBufferHeight);
    HTML5_PROPERTY(WebGLRenderingContext, GLsizei, drawingBufferWidth);

    WebGLRenderingContext(emscripten::val v);
    virtual ~WebGLRenderingContext();
    static WebGLRenderingContext *create(emscripten::val v);

    void activeTexture(GLenum texture);
    void attachShader(WebGLProgram *program, WebGLShader *shader);
    void bindAttribLocation(WebGLProgram *program, GLuint index, std::string name);
    void bindBuffer(GLenum target, WebGLBuffer *buffer);
    void bindFramebuffer(GLenum target, WebGLFramebuffer *framebuffer);
    void bindRenderbuffer(GLenum target, WebGLRenderbuffer *renderbuffer);
    void bindTexture(GLenum target, WebGLTexture *texture);
    void blendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    void blendEquation(GLenum mode);
    void blendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
    void blendFunc(GLenum sfactor, GLenum dfactor);
    void blendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    void bufferData(GLenum target, GLsizeiptr size, GLenum usage);
    void bufferData(GLenum target, ArrayBuffer *srcData, GLenum usage);
    void bufferData(GLenum target, ArrayBufferView *srcData, GLenum usage);
    void bufferSubData(GLenum target, GLintptr offset, ArrayBuffer *data);
    void bufferSubData(GLenum target, GLintptr offset, ArrayBufferView *data);
    GLenum checkFramebufferStatus(GLenum target);
    void clear(GLbitfield mask);
    void clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    void clearDepth(GLclampf depth);
    void clearStencil(GLint s);
    void colorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    void compileShader(WebGLShader *shader);
    void compressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, ArrayBufferView *data);
    void compressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, ArrayBufferView *data);
    void copyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    void copyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    WebGLBuffer *createBuffer();
    WebGLFramebuffer *createFramebuffer();
    WebGLProgram *createProgram();
    WebGLRenderbuffer *createRenderbuffer();
    WebGLShader *createShader(GLenum type);
    WebGLTexture *createTexture();
    void cullFace(GLenum mode);
    void deleteBuffer(WebGLBuffer *buffer);
    void deleteFramebuffer(WebGLFramebuffer *framebuffer);
    void deleteProgram(WebGLProgram *program);
    void deleteRenderbuffer(WebGLRenderbuffer *renderbuffer);
    void deleteShader(WebGLShader *shader);
    void deleteTexture(WebGLTexture *texture);
    void depthFunc(GLenum func);
    void depthMask(GLboolean flag);
    void depthRange(GLclampf zNear, GLclampf zFar);
    void detachShader(WebGLProgram *program, WebGLShader *shader);
    void disable(GLenum cap);
    void disableVertexAttribArray(GLuint index);
    void drawArrays(GLenum mode, GLint first, GLsizei count);
    void drawElements(GLenum mode, GLsizei count, GLenum type, GLintptr offset);
    void enable(GLenum cap);
    void enableVertexAttribArray(GLuint index);
    void finish();
    void flush();
    void framebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, WebGLRenderbuffer *renderbuffer);
    void framebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, WebGLTexture *texture, GLint level);
    void frontFace(GLenum mode);
    void generateMipmap(GLenum target);
    WebGLActiveInfo *getActiveAttrib(WebGLProgram *program, GLuint index);
    WebGLActiveInfo *getActiveUniform(WebGLProgram *program, GLuint index);
    std::vector<WebGLShader *> getAttachedShaders(WebGLProgram *program);
    GLint getAttribLocation(WebGLProgram *program, std::string name);
    GLenum getBufferParameter(GLenum target, GLenum pname);
    WebGLContextAttributes *getContextAttributes();
    GLenum getError();
    WebGLExtension *getExtension(std::string name);
    WebGLFramebufferAttachmentParameter *getFramebufferAttachmentParameter(GLenum target, GLenum attachment, GLenum pname);
    WebGLParameter *getParameter(GLenum pname);
    std::vector<std::string> getProgramInfoLog(WebGLProgram *program);
    WebGLProgramParameter *getProgramParameter(WebGLProgram *program, GLenum pname);
    WebGLRenderbufferParameter *getRenderbufferParameter(GLenum target, GLenum pname);
    std::vector<std::string> getShaderInfoLog(WebGLShader *shader);
    WebGLShaderParameter *getShaderParameter(WebGLShader *shader, GLenum pname);
    WebGLShaderPrecisionFormat *getShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype);
    std::string getShaderSource(WebGLShader *shader);
    std::vector<WebGLExtension *> getSupportedExtensions();
    WebGLTextureParameter *getTexParameter(GLenum target, GLenum pname);
    WebGLUniformParameter *getUniform(WebGLProgram *program, WebGLUniformLocation *location);
    WebGLUniformLocation *getUniformLocation(WebGLProgram *program, std::string name);
    WebGLVertexAttribute *getVertexAttrib(GLuint index, GLenum pname);
    GLsizeiptr getVertexAttribOffset(GLuint index, GLenum pname);
    void hint(GLenum target, GLenum mode);
    GLboolean isBuffer(WebGLBuffer *buffer);
    GLboolean isContextLost();
    GLboolean isEnabled(GLenum cap);
    GLboolean isFramebuffer(WebGLFramebuffer *framebuffer);
    GLboolean isProgram(WebGLProgram *program);
    GLboolean isRenderbuffer(WebGLRenderbuffer *renderbuffer);
    GLboolean isShader(WebGLShader *shader);
    GLboolean isTexture(WebGLTexture *texture);
    void lineWidth(GLfloat width);
    void linkProgram(WebGLProgram *program);
    void pixelStorei(GLenum pname, GLint param);
    void polygonOffset(GLfloat factor, GLfloat units);
    void readPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView *pixels);
    void renderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    void sampleCoverage(GLclampf value, GLboolean invert);
    void scissor(GLint x, GLint y, GLsizei width, GLsizei height);
    void shaderSource(WebGLShader *shader, std::string source);
    void stencilFunc(GLenum func, GLint ref, GLuint mask);
    void stencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
    void stencilMask(GLuint mask);
    void stencilMaskSeparate(GLenum face, GLuint mask);
    void stencilOp(GLenum fail, GLenum zfail, GLenum zpass);
    void stencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
    void texImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, ArrayBufferView *pixels);
    void texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, ImageData *pixels);
    void texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLImageElement *pixels);
    void texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLCanvasElement *pixels);
    void texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLVideoElement *pixels);
    void texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, ImageBitmap *pixels);
    void texParameterf(GLenum target, GLenum pname, GLfloat param);
    void texParameteri(GLenum target, GLenum pname, GLint param);
    void texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView *pixels);
    void texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, ImageData *pixels);
    void texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLImageElement *pixels);
    void texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLCanvasElement *pixels);
    void texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLVideoElement *pixels);
    void texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, ImageBitmap *pixels);
    void uniform1f(WebGLUniformLocation *location, GLfloat x);
    void uniform1fv(WebGLUniformLocation *location, std::vector<GLfloat> v);
    void uniform1i(WebGLUniformLocation *location, GLint x);
    void uniform1iv(WebGLUniformLocation *location, std::vector<GLint> v);
    void uniform2f(WebGLUniformLocation *location, GLfloat x, GLfloat y);
    void uniform2fv(WebGLUniformLocation *location, std::vector<GLfloat> v);
    void uniform2i(WebGLUniformLocation *location, GLint x, GLint y);
    void uniform2iv(WebGLUniformLocation *location, std::vector<GLint> v);
    void uniform3f(WebGLUniformLocation *location, GLfloat x, GLfloat y, GLfloat z);
    void uniform3fv(WebGLUniformLocation *location, std::vector<GLfloat> v);
    void uniform3i(WebGLUniformLocation *location, GLint x, GLint y, GLint z);
    void uniform3iv(WebGLUniformLocation *location, std::vector<GLint> v);
    void uniform4f(WebGLUniformLocation *location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void uniform4fv(WebGLUniformLocation *location, std::vector<GLfloat> v);
    void uniform4i(WebGLUniformLocation *location, GLint x, GLint y, GLint z, GLint w);
    void uniform4iv(WebGLUniformLocation *location, std::vector<GLint> v);
    void uniformMatrix2fv(WebGLUniformLocation *location, GLboolean transpose, std::vector<GLfloat> value);
    void uniformMatrix3fv(WebGLUniformLocation *location, GLboolean transpose, std::vector<GLfloat> value);
    void uniformMatrix4fv(WebGLUniformLocation *location, GLboolean transpose, std::vector<GLfloat> value);
    void useProgram(WebGLProgram *program);
    void validateProgram(WebGLProgram *program);
    void vertexAttrib1f(GLuint indx, GLfloat x);
    void vertexAttrib1fv(GLuint indx, std::vector<GLfloat> values);
    void vertexAttrib2f(GLuint indx, GLfloat x, GLfloat y);
    void vertexAttrib2fv(GLuint indx, std::vector<GLfloat> values);
    void vertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z);
    void vertexAttrib3fv(GLuint indx, std::vector<GLfloat> values);
    void vertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void vertexAttrib4fv(GLuint indx, std::vector<GLfloat> values);
    void vertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
    void viewport(GLint x, GLint y, GLsizei width, GLsizei height);
};

NAMESPACE_HTML5_END;
