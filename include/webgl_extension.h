#pragma once

#include "html5.h"

NAMESPACE_HTML5_BEGIN;

class WebGLExtension : public Object {
public:

    WebGLExtension(emscripten::val v);
    virtual ~WebGLExtension();
    static WebGLExtension *create(emscripten::val v);
};

class AngleInstancedArrays : public WebGLExtension {
public:

    HTML5_READONLY_PROPERTY(AngleInstancedArrays, GLenum, VERTEX_ATTRIB_ARRAY_DIVISOR_ANGLE);

    AngleInstancedArrays(emscripten::val v);
    virtual ~AngleInstancedArrays();
    static AngleInstancedArrays *create(emscripten::val v);
    void drawArraysInstancedANGLE(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
    void drawElementsInstancedANGLE(GLenum mode, GLsizei count, GLenum type, GLintptr offset, GLsizei primcount);
    void vertexAttribDivisorANGLE(GLuint index, GLuint divisor);
};

class EXTBlendMinMax : public WebGLExtension {
public:

    HTML5_READONLY_PROPERTY(EXTBlendMinMax, GLenum, MIN_EXT);
    HTML5_READONLY_PROPERTY(EXTBlendMinMax, GLenum, MAX_EXT);

    EXTBlendMinMax(emscripten::val v);
    virtual ~EXTBlendMinMax();
    static EXTBlendMinMax *create(emscripten::val v);
};

class EXTColorBufferFloat : public WebGLExtension {
public:

    EXTColorBufferFloat(emscripten::val v);
    virtual ~EXTColorBufferFloat();
    static EXTColorBufferFloat *create(emscripten::val v);
    void renderbufferStorage(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height);
};

class EXTColorBufferHalfFloat : public WebGLExtension {
public:
    HTML5_READONLY_PROPERTY(EXTColorBufferHalfFloat, GLenum, RGBA16F_EXT);
    HTML5_READONLY_PROPERTY(EXTColorBufferHalfFloat, GLenum, RGB16F_EXT);
    HTML5_READONLY_PROPERTY(EXTColorBufferHalfFloat, GLenum, FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE_EXT);
    HTML5_READONLY_PROPERTY(EXTColorBufferHalfFloat, GLenum, UNSIGNED_NORMALIZED_EXT);

    EXTColorBufferHalfFloat(emscripten::val v);
    virtual ~EXTColorBufferHalfFloat();
    static EXTColorBufferHalfFloat *create(emscripten::val v);
    void renderbufferStorage(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height);
};

class WebGLQuery;

class EXTDisjointTimerQuery : public WebGLExtension {
public:
    HTML5_READONLY_PROPERTY(EXTDisjointTimerQuery, GLenum, QUERY_COUNTER_BITS_EXT);
    HTML5_READONLY_PROPERTY(EXTDisjointTimerQuery, GLenum, CURRENT_QUERY_EXT);
    HTML5_READONLY_PROPERTY(EXTDisjointTimerQuery, GLenum, QUERY_RESULT_EXT);
    HTML5_READONLY_PROPERTY(EXTDisjointTimerQuery, GLenum, QUERY_RESULT_AVAILABLE_EXT);
    HTML5_READONLY_PROPERTY(EXTDisjointTimerQuery, GLenum, TIME_ELAPSED_EXT);
    HTML5_READONLY_PROPERTY(EXTDisjointTimerQuery, GLenum, TIMESTAMP_EXT);
    HTML5_READONLY_PROPERTY(EXTDisjointTimerQuery, GLenum, GPU_DISJOINT_EXT);

    EXTDisjointTimerQuery(emscripten::val v);
    virtual ~EXTDisjointTimerQuery();
    static EXTDisjointTimerQuery *create(emscripten::val v);
    WebGLQuery *createQueryEXT();
    void deleteQueryEXT(WebGLQuery *query);
    GLboolean isQueryEXT(WebGLQuery *query);
    void beginQueryEXT(GLenum target, WebGLQuery *query);
    void endQueryEXT(GLenum target);
    void queryCounterEXT(WebGLQuery *query, GLenum target);
    WebGLQuery *getCurrentQueryEXT(GLenum target);
    GLint getQueryCounterBitsEXT(GLenum target);
    uint64_t getQueryResultEXT(WebGLQuery *query);
    GLboolean getQueryResultAvailableEXT(WebGLQuery *query);
};

NAMESPACE_HTML5_END;
