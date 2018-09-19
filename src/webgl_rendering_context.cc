#include "webgl_buffer.h"
#include "webgl_program.h"
#include "webgl_shader.h"
#include "webgl_renderbuffer.h"
#include "webgl_framebuffer.h"
#include "webgl_texture.h"
#include "array_buffer_view.h"
#include "array_buffer.h"
#include "webgl_active_info.h"
#include "webgl_context_attributes.h"
#include "webgl_uniform_location.h"
#include "webgl_shader_precision_format.h"
#include "html_video_element.h"
#include "html_image_element.h"
#include "html_canvas_element.h"
#include "image_data.h"
#include "image_bitmap.h"
#include "webgl_extension.h"
#include "webgl_rendering_context.h"

USING_NAMESPACE_HTML5;

WebGLFramebufferAttachmentParameter::WebGLFramebufferAttachmentParameter(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLFramebufferAttachmentParameter::~WebGLFramebufferAttachmentParameter()
{

}

WebGLFramebufferAttachmentParameter *WebGLFramebufferAttachmentParameter::create(emscripten::val v)
{
    auto param = new WebGLFramebufferAttachmentParameter(v);
    param->autorelease();
    return param;
}

WebGLParameter::WebGLParameter(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLParameter::~WebGLParameter()
{

}

WebGLParameter *WebGLParameter::create(emscripten::val v)
{
    auto param = new WebGLParameter(v);
    param->autorelease();
    return param;
}


WebGLProgramParameter::WebGLProgramParameter(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLProgramParameter::~WebGLProgramParameter()
{

}

WebGLProgramParameter *WebGLProgramParameter::create(emscripten::val v)
{
    auto param = new WebGLProgramParameter(v);
    param->autorelease();
    return param;
}

WebGLRenderbufferParameter::WebGLRenderbufferParameter(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLRenderbufferParameter::~WebGLRenderbufferParameter()
{

}

WebGLRenderbufferParameter *WebGLRenderbufferParameter::create(emscripten::val v)
{
    auto param = new WebGLRenderbufferParameter(v);
    param->autorelease();
    return param;
}

WebGLShaderParameter::WebGLShaderParameter(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLShaderParameter::~WebGLShaderParameter()
{

}

WebGLShaderParameter *WebGLShaderParameter::create(emscripten::val v)
{
    auto param = new WebGLShaderParameter(v);
    param->autorelease();
    return param;
}

WebGLTextureParameter::WebGLTextureParameter(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLTextureParameter::~WebGLTextureParameter()
{

}

WebGLTextureParameter *WebGLTextureParameter::create(emscripten::val v)
{
    auto param = new WebGLTextureParameter(v);
    param->autorelease();
    return param;
}

WebGLVertexAttribute::WebGLVertexAttribute(emscripten::val v) :
    Object(),
    v(v)
{

}

WebGLVertexAttribute::~WebGLVertexAttribute()
{

}

WebGLVertexAttribute *WebGLVertexAttribute::create(emscripten::val v)
{
    auto param = new WebGLVertexAttribute(v);
    param->autorelease();
    return param;
}

WebGLRenderingContext::WebGLRenderingContext(emscripten::val v) :
    RenderingContext(v)
{

}

WebGLRenderingContext::~WebGLRenderingContext()
{

}

WebGLRenderingContext *WebGLRenderingContext::create(emscripten::val v)
{
    auto ctx = new WebGLRenderingContext(v);
    ctx->autorelease();
    return ctx;
}

void WebGLRenderingContext::activeTexture(GLenum texture)
{
    HTML5_CALL(this->v, activeTexture, texture);
}

void WebGLRenderingContext::attachShader(WebGLProgram *program, WebGLShader *shader)
{
    HTML5_CALL(this->v, attachShader, program->v, shader->v);
}

void WebGLRenderingContext::bindAttribLocation(WebGLProgram *program, GLuint index, std::string name)
{
    HTML5_CALL(this->v, bindAttribLocation, program->v, index, name);
}

void WebGLRenderingContext::bindBuffer(GLenum target, WebGLBuffer *buffer)
{
    HTML5_CALL(this->v, bindBuffer, target, buffer->v);
}

void WebGLRenderingContext::bindFramebuffer(GLenum target, WebGLFramebuffer *framebuffer)
{
    HTML5_CALL(this->v, bindFramebuffer, target, framebuffer->v);
}

void WebGLRenderingContext::bindRenderbuffer(GLenum target, WebGLRenderbuffer *renderbuffer)
{
    HTML5_CALL(this->v, bindRenderbuffer, target, renderbuffer->v);
}

void WebGLRenderingContext::bindTexture(GLenum target, WebGLTexture *texture)
{
    HTML5_CALL(this->v, bindTexture, target, texture->v);
}

void WebGLRenderingContext::blendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    HTML5_CALL(this->v, blendColor, red, green, blue, alpha);
}

void WebGLRenderingContext::blendEquation(GLenum mode)
{
    HTML5_CALL(this->v, blendEquation, mode);
}

void WebGLRenderingContext::blendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
    HTML5_CALL(this->v, blendEquationSeparate, modeRGB, modeAlpha);
}

void WebGLRenderingContext::blendFunc(GLenum sfactor, GLenum dfactor)
{
    HTML5_CALL(this->v, blendFunc, sfactor, dfactor);
}

void WebGLRenderingContext::blendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    HTML5_CALL(this->v, blendFuncSeparate, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void WebGLRenderingContext::bufferData(GLenum target, GLsizeiptr size, GLenum usage)
{
    HTML5_CALL(this->v, bufferData, target, size, usage);
}

void WebGLRenderingContext::bufferData(GLenum target, ArrayBuffer *srcData, GLenum usage)
{
    HTML5_CALL(this->v, bufferData, target, srcData->v, usage);
}

void WebGLRenderingContext::bufferData(GLenum target, ArrayBufferView *srcData, GLenum usage)
{
    HTML5_CALL(this->v, bufferData, target, srcData->v, usage);
}

void WebGLRenderingContext::bufferSubData(GLenum target, GLintptr offset, ArrayBuffer *data)
{
    HTML5_CALL(this->v, bufferSubData, target, offset, data->v);
}

void WebGLRenderingContext::bufferSubData(GLenum target, GLintptr offset, ArrayBufferView *data)
{
    HTML5_CALL(this->v, bufferSubData, target, offset, data->v);
}

GLenum WebGLRenderingContext::checkFramebufferStatus(GLenum target)
{
    return HTML5_CALLi(this->v, checkFramebufferStatus, GLenum, target);
}

void WebGLRenderingContext::clear(GLbitfield mask)
{
    HTML5_CALL(this->v, clear, mask);
}

void WebGLRenderingContext::clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    HTML5_CALL(this->v, clearColor, red, green, blue, alpha);
}

void WebGLRenderingContext::clearDepth(GLclampf depth)
{
    HTML5_CALL(this->v, clearDepth, depth);
}

void WebGLRenderingContext::clearStencil(GLint s)
{
    HTML5_CALL(this->v, clearStencil, s);
}

void WebGLRenderingContext::colorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    HTML5_CALL(this->v, clearMask, red, green, blue, alpha);
}

void WebGLRenderingContext::compileShader(WebGLShader *shader)
{
    HTML5_CALL(this->v, compileShader, shader->v);
}

void WebGLRenderingContext::compressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, ArrayBufferView *data)
{
    HTML5_CALL(this->v, compressedTexImage2D, target, level, internalformat, width, height, border, data->v);
}

void WebGLRenderingContext::compressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, ArrayBufferView *data)
{
    HTML5_CALL(this->v, compressedTexSubImage2D, target, level, xoffset, yoffset, width, height, format, data->v);
}

void WebGLRenderingContext::copyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    HTML5_CALL(this->v, copyTexImage2D, target, level, internalformat, x, y, width, height, border);
}

void WebGLRenderingContext::copyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    HTML5_CALL(this->v, copyTexSubImage2D, target, level, xoffset, yoffset, x, y, width, height);
}

WebGLBuffer *WebGLRenderingContext::createBuffer()
{
    return WebGLBuffer::create(HTML5_CALLv(this->v, createBuffer));
}

WebGLFramebuffer *WebGLRenderingContext::createFramebuffer()
{
    return WebGLFramebuffer::create(HTML5_CALLv(this->v, createFramebuffer));
}

WebGLProgram *WebGLRenderingContext::createProgram()
{
    return WebGLProgram::create(HTML5_CALLv(this->v, createProgram));
}

WebGLRenderbuffer *WebGLRenderingContext::createRenderbuffer()
{
    return WebGLRenderbuffer::create(HTML5_CALLv(this->v, createRenderbuffer));
}

WebGLShader *WebGLRenderingContext::createShader(GLenum type)
{
    return WebGLShader::create(HTML5_CALLv(this->v, createShader, type));
}

WebGLTexture *WebGLRenderingContext::createTexture()
{
    return WebGLTexture::create(HTML5_CALLv(this->v, createTexture));
}

void WebGLRenderingContext::cullFace(GLenum mode)
{
    HTML5_CALL(this->v, cullFace, mode);
}

void WebGLRenderingContext::deleteBuffer(WebGLBuffer *buffer)
{
    HTML5_CALL(this->v, deleteBuffer, buffer->v);
}

void WebGLRenderingContext::deleteFramebuffer(WebGLFramebuffer *framebuffer)
{
    HTML5_CALL(this->v, deleteFramebuffer, framebuffer->v);
}

void WebGLRenderingContext::deleteProgram(WebGLProgram *program)
{
    HTML5_CALL(this->v, deleteProgram, program->v);
}

void WebGLRenderingContext::deleteRenderbuffer(WebGLRenderbuffer *renderbuffer)
{
    HTML5_CALL(this->v, deleteRenderbuffer, renderbuffer->v);
}

void WebGLRenderingContext::deleteShader(WebGLShader *shader)
{
    HTML5_CALL(this->v, deleteShader, shader->v);
}

void WebGLRenderingContext::deleteTexture(WebGLTexture *texture)
{
    HTML5_CALL(this->v, deleteTexture, texture->v);
}

void WebGLRenderingContext::depthFunc(GLenum func)
{
    HTML5_CALL(this->v, depthFunc, func);
}

void WebGLRenderingContext::depthMask(GLboolean flag)
{
    HTML5_CALL(this->v, depthMask, flag);
}

void WebGLRenderingContext::depthRange(GLclampf zNear, GLclampf zFar)
{
    HTML5_CALL(this->v, depthRange, zNear, zFar);
}

void WebGLRenderingContext::detachShader(WebGLProgram *program, WebGLShader *shader)
{
    HTML5_CALL(this->v, detachShader, program->v, shader->v);
}

void WebGLRenderingContext::disable(GLenum cap)
{
    HTML5_CALL(this->v, disable, cap);
}

void WebGLRenderingContext::disableVertexAttribArray(GLuint index)
{
    HTML5_CALL(this->v, disableVertexAttribArray, index);
}

void WebGLRenderingContext::drawArrays(GLenum mode, GLint first, GLsizei count)
{
    HTML5_CALL(this->v, drawArrays, mode, first, count);
}

void WebGLRenderingContext::drawElements(GLenum mode, GLsizei count, GLenum type, GLintptr offset)
{
    HTML5_CALL(this->v, drawElements, mode, count, type, offset);
}

void WebGLRenderingContext::enable(GLenum cap)
{
    HTML5_CALL(this->v, enable, cap);
}

void WebGLRenderingContext::enableVertexAttribArray(GLuint index)
{
    HTML5_CALL(this->v, enableVertexAttribArray, index);
}

void WebGLRenderingContext::finish()
{
    HTML5_CALL(this->v, finish);
}

void WebGLRenderingContext::flush()
{
    HTML5_CALL(this->v, flush);
}

void WebGLRenderingContext::framebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, WebGLRenderbuffer *renderbuffer)
{
    HTML5_CALL(this->v, framebufferRenderbuffer, target, attachment, renderbuffertarget, renderbuffer->v);
}

void WebGLRenderingContext::framebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, WebGLTexture *texture, GLint level)
{
    HTML5_CALL(this->v, framebufferTexture2D, target, attachment, textarget, texture->v, level);
}

void WebGLRenderingContext::frontFace(GLenum mode)
{
    HTML5_CALL(this->v, frontFace, mode);
}

void WebGLRenderingContext::generateMipmap(GLenum target)
{
    HTML5_CALL(this->v, generateMipmap, target);
}

WebGLActiveInfo *WebGLRenderingContext::getActiveAttrib(WebGLProgram *program, GLuint index)
{
    return WebGLActiveInfo::create(HTML5_CALLv(this->v, getActiveAttrib, program->v, index));
}

WebGLActiveInfo *WebGLRenderingContext::getActiveUniform(WebGLProgram *program, GLuint index)
{
    return WebGLActiveInfo::create(HTML5_CALLv(this->v, getActiveUniform, program->v, index));
}

std::vector<WebGLShader *> WebGLRenderingContext::getAttachedShaders(WebGLProgram *program)
{
    return toObjectArray<WebGLShader>(HTML5_CALLv(this->v, getAttachedShaders, program->v));
}

GLint WebGLRenderingContext::getAttribLocation(WebGLProgram *program, std::string name)
{
    return HTML5_CALLi(this->v, getAttribLocation, GLint, program->v, name);
}

GLenum WebGLRenderingContext::getBufferParameter(GLenum target, GLenum pname)
{
    return HTML5_CALLi(this->v, getBufferParameter, GLenum, target, pname);
}

WebGLContextAttributes *WebGLRenderingContext::getContextAttributes()
{
    return WebGLContextAttributes::create(HTML5_CALLv(this->v, getContextAttributes));
}

GLenum WebGLRenderingContext::getError()
{
    return HTML5_CALLi(this->v, getError, GLenum);
}

WebGLExtension *WebGLRenderingContext::getExtension(std::string name)
{
    return WebGLExtension::create(HTML5_CALLv(this->v, getExtension, name));
}

WebGLFramebufferAttachmentParameter * WebGLRenderingContext::getFramebufferAttachmentParameter(GLenum target, GLenum attachment, GLenum pname)
{
    return WebGLFramebufferAttachmentParameter::create(HTML5_CALLv(this->v, getFramebufferAttachmentParameter, target, attachment, pname));
}

WebGLParameter *WebGLRenderingContext::getParameter(GLenum pname)
{
    return WebGLParameter::create(HTML5_CALLv(this->v, getParameter, pname));
}

std::vector<std::string> WebGLRenderingContext::getProgramInfoLog(WebGLProgram *program)
{
    return toArray<std::string>(HTML5_CALLv(this->v, getProgramInfoLog, program->v));
}

WebGLProgramParameter *WebGLRenderingContext::getProgramParameter(WebGLProgram *program, GLenum pname)
{
    return WebGLProgramParameter::create(HTML5_CALLv(this->v, getProgramParameter, program->v, pname));
}

WebGLRenderbufferParameter *WebGLRenderingContext::getRenderbufferParameter(GLenum target, GLenum pname)
{
    return WebGLRenderbufferParameter::create(HTML5_CALLv(this->v, getRenderbufferParameter, target, pname));
}

std::vector<std::string> WebGLRenderingContext::getShaderInfoLog(WebGLShader *shader)
{
    return toArray<std::string>(HTML5_CALLv(this->v, getShaderInfoLog, shader->v));
}

WebGLShaderParameter *WebGLRenderingContext::getShaderParameter(WebGLShader *shader, GLenum pname)
{
    return WebGLShaderParameter::create(HTML5_CALLv(this->v, getShaderParameter, shader->v, pname));
}

WebGLShaderPrecisionFormat *WebGLRenderingContext::getShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype)
{
    return WebGLShaderPrecisionFormat::create(HTML5_CALLv(this->v, getShaderPrecisionFormat, shadertype, precisiontype));
}

std::string WebGLRenderingContext::getShaderSource(WebGLShader *shader)
{
    return HTML5_CALLs(this->v, getShaderSource, shader->v);
}

std::vector<WebGLExtension *> WebGLRenderingContext::getSupportedExtensions()
{
    return toObjectArray<WebGLExtension>(HTML5_CALLv(this->v, getSupportedExtensions));
}

WebGLTextureParameter *WebGLRenderingContext::getTexParameter(GLenum target, GLenum pname)
{
    return WebGLTextureParameter::create(HTML5_CALLv(this->v, getTexParameter, target, pname)); 
}

WebGLUniformParameter *WebGLRenderingContext::getUniform(WebGLProgram *program, WebGLUniformLocation *location)
{
    return WebGLUniformParameter::create(HTML5_CALLv(this->v, getUniform, program->v, location->v));
}

WebGLUniformLocation *WebGLRenderingContext::getUniformLocation(WebGLProgram *program, std::string name)
{
    return WebGLUniformLocation::create(HTML5_CALLv(this->v, getUniformLocation, program->v, name));
}

WebGLVertexAttribute *WebGLRenderingContext::getVertexAttrib(GLuint index, GLenum pname)
{
    return WebGLVertexAttribute::create(HTML5_CALLv(this->v, getVertexAttrib, index, pname));
}

GLsizeiptr WebGLRenderingContext::getVertexAttribOffset(GLuint index, GLenum pname)
{
    return HTML5_CALLi(this->v, getVertexAttribOffset, GLsizeiptr, index, pname);
}

void WebGLRenderingContext::hint(GLenum target, GLenum mode)
{
    HTML5_CALL(this->v, hint, target, mode);
}

GLboolean WebGLRenderingContext::isBuffer(WebGLBuffer *buffer)
{
    return HTML5_CALLb(this->v, isBuffer, buffer->v);
}

GLboolean WebGLRenderingContext::isContextLost()
{
    return HTML5_CALLb(this->v, isContextLost);
}

GLboolean WebGLRenderingContext::isEnabled(GLenum cap)
{
    return HTML5_CALLb(this->v, isEnabled, cap);
}

GLboolean WebGLRenderingContext::isFramebuffer(WebGLFramebuffer *framebuffer)
{
    return HTML5_CALLb(this->v, isFramebuffer, framebuffer->v);
}

GLboolean WebGLRenderingContext::isProgram(WebGLProgram *program)
{
    return HTML5_CALLb(this->v, isProgram, program->v);
}

GLboolean WebGLRenderingContext::isRenderbuffer(WebGLRenderbuffer *renderbuffer)
{
    return HTML5_CALLb(this->v, isRenderbuffer, renderbuffer->v);
}

GLboolean WebGLRenderingContext::isShader(WebGLShader *shader)
{
    return HTML5_CALLb(this->v, isShader, shader->v);
}

GLboolean WebGLRenderingContext::isTexture(WebGLTexture *texture)
{
    return HTML5_CALLb(this->v, isTexture, texture->v);
}

void WebGLRenderingContext::lineWidth(GLfloat width)
{
    HTML5_CALL(this->v, lineWidth, width);
}

void WebGLRenderingContext::linkProgram(WebGLProgram *program)
{
    HTML5_CALL(this->v, linkProgram, program->v);
}

void WebGLRenderingContext::pixelStorei(GLenum pname, GLint param)
{
    HTML5_CALL(this->v, pixelStorei, pname, param);
}

void WebGLRenderingContext::polygonOffset(GLfloat factor, GLfloat units)
{
    HTML5_CALL(this->v, polygonOffset, factor, units);
}

void WebGLRenderingContext::readPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView *pixels)
{
    HTML5_CALL(this->v, readPixels, x, y, width, height, format, type, pixels->v);
}

void WebGLRenderingContext::renderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    HTML5_CALL(this->v, renderbufferStorage, target, internalformat, width, height);
}

void WebGLRenderingContext::sampleCoverage(GLclampf value, GLboolean invert)
{
    HTML5_CALL(this->v, sampleCoverage, value, invert);
}

void WebGLRenderingContext::scissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    HTML5_CALL(this->v, scissor, x, y, width, height);
}

void WebGLRenderingContext::shaderSource(WebGLShader *shader, std::string source)
{
    HTML5_CALL(this->v, shaderSource, shader->v, source);
}

void WebGLRenderingContext::stencilFunc(GLenum func, GLint ref, GLuint mask)
{
    HTML5_CALL(this->v, stencilFunc, func, ref, mask);
}

void WebGLRenderingContext::stencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
    HTML5_CALL(this->v, stencilFuncSeparate, face, func, ref, mask);
}

void WebGLRenderingContext::stencilMask(GLuint mask)
{
    HTML5_CALL(this->v, stencilMask, mask);
}

void WebGLRenderingContext::stencilMaskSeparate(GLenum face, GLuint mask)
{
    HTML5_CALL(this->v, stencilMaskSeparate, face, mask);
}

void WebGLRenderingContext::stencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    HTML5_CALL(this->v, stencilOp, fail, zfail, zpass);
}

void WebGLRenderingContext::stencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
    HTML5_CALL(this->v, face, fail, zfail, zpass);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, ArrayBufferView *pixels)
{
    HTML5_CALL(this->v, texImage2D, target, level, internalformat, width, height, border, format, type, pixels->v);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, ImageData *pixels)
{
    HTML5_CALL(this->v, texImage2D, target, level, internalformat, format, type, pixels->v);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLImageElement *pixels)
{
    HTML5_CALL(this->v, texImage2D, target, level, internalformat, format, type, pixels->v);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLCanvasElement *pixels)
{
    HTML5_CALL(this->v, texImage2D, target, level, internalformat, format, type, pixels->v);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLVideoElement *pixels)
{
    HTML5_CALL(this->v, texImage2D, target, level, internalformat, format, type, pixels->v);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, ImageBitmap *pixels)
{
    HTML5_CALL(this->v, texImage2D, target, level, internalformat, format, type, pixels->v);
}

void WebGLRenderingContext::texParameterf(GLenum target, GLenum pname, GLfloat param)
{
    HTML5_CALL(this->v, texParameterf, target, pname, param);
}

void WebGLRenderingContext::texParameteri(GLenum target, GLenum pname, GLint param)
{
    HTML5_CALL(this->v, texParameteri, target, pname, param);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView *pixels)
{
    HTML5_CALL(this->v, texSubImage2D, target, level, xoffset, yoffset, width, height, format, type, pixels->v);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, ImageData *pixels)
{
    HTML5_CALL(this->v, texSubImage2D, target, level, xoffset, yoffset, format, type, pixels->v);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLImageElement *pixels)
{
    HTML5_CALL(this->v, texSubImage2D, target, level, xoffset, yoffset, format, type, pixels->v);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLCanvasElement *pixels)
{
    HTML5_CALL(this->v, texSubImage2D, target, level, xoffset, yoffset, format, type, pixels->v);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLVideoElement *pixels)
{
    HTML5_CALL(this->v, texSubImage2D, target, level, xoffset, yoffset, format, type, pixels->v);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLenum level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, ImageBitmap *pixels)
{
    HTML5_CALL(this->v, texSubImage2D, target, level, xoffset, yoffset, format, type, pixels->v);
}

void WebGLRenderingContext::uniform1f(WebGLUniformLocation *location, GLfloat x)
{
    HTML5_CALL(this->v, uniform1f, location->v, x);
}

void WebGLRenderingContext::uniform1fv(WebGLUniformLocation *location, std::vector<GLfloat> v)
{
    HTML5_CALL(this->v, uniform1fv, location->v, toJSArray<GLfloat>(v));
}

void WebGLRenderingContext::uniform1i(WebGLUniformLocation *location, GLint x)
{
    HTML5_CALL(this->v, uniform1i, location->v, x);
}

void WebGLRenderingContext::uniform1iv(WebGLUniformLocation *location, std::vector<GLint> v)
{
    HTML5_CALL(this->v, uniform1iv, location->v, toJSArray<GLint>(v));
}

void WebGLRenderingContext::uniform2f(WebGLUniformLocation *location, GLfloat x, GLfloat y)
{
    HTML5_CALL(this->v, uniform2f, location->v, x, y);
}

void WebGLRenderingContext::uniform2fv(WebGLUniformLocation *location, std::vector<GLfloat> v)
{
    HTML5_CALL(this->v, uniform2fv, location->v, toJSArray<GLfloat>(v));
}

void WebGLRenderingContext::uniform2i(WebGLUniformLocation *location, GLint x, GLint y)
{
    HTML5_CALL(this->v, uniform2i, location->v, x, y);
}

void WebGLRenderingContext::uniform2iv(WebGLUniformLocation *location, std::vector<GLint> v)
{
    HTML5_CALL(this->v, uniform2iv, location->v, toJSArray<GLint>(v));
}

void WebGLRenderingContext::uniform3f(WebGLUniformLocation *location, GLfloat x, GLfloat y, GLfloat z)
{
    HTML5_CALL(this->v, uniform3f, location->v, x, y, z);
}

void WebGLRenderingContext::uniform3fv(WebGLUniformLocation *location, std::vector<GLfloat> v)
{
    HTML5_CALL(this->v, uniform3fv, location->v, toJSArray<GLfloat>(v));
}

void WebGLRenderingContext::uniform3i(WebGLUniformLocation *location, GLint x, GLint y, GLint z)
{
    HTML5_CALL(this->v, uinform3i, location->v, x, y, z);
}

void WebGLRenderingContext::uniform3iv(WebGLUniformLocation *location, std::vector<GLint> v)
{
    HTML5_CALL(this->v, uniform3iv, location->v, toJSArray<GLint>(v));
}

void WebGLRenderingContext::uniform4f(WebGLUniformLocation *location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    HTML5_CALL(this->v, uniform4f, location->v, x, y, z, w);
}

void WebGLRenderingContext::uniform4fv(WebGLUniformLocation *location, std::vector<GLfloat> v)
{
    HTML5_CALL(this->v, uniform4fv, location->v, toJSArray<GLfloat>(v));
}

void WebGLRenderingContext::uniform4i(WebGLUniformLocation *location, GLint x, GLint y, GLint z, GLint w)
{
    HTML5_CALL(this->v, uniform4i, location->v, x, y, z, w);
}

void WebGLRenderingContext::uniform4iv(WebGLUniformLocation *location, std::vector<GLint> v)
{
    HTML5_CALL(this->v, uniform4iv, location->v, toJSArray<GLint>(v));
}

void WebGLRenderingContext::uniformMatrix2fv(WebGLUniformLocation *location, GLboolean transpose, std::vector<GLfloat> value)
{
    HTML5_CALL(this->v, uniformMatrix2fv, location->v, transpose, toJSArray<GLfloat>(value));
}

void WebGLRenderingContext::uniformMatrix3fv(WebGLUniformLocation *location, GLboolean transpose, std::vector<GLfloat> value)
{
    HTML5_CALL(this->v, uniformMatrix3fv, location->v, transpose, toJSArray<GLfloat>(value));
}

void WebGLRenderingContext::uniformMatrix4fv(WebGLUniformLocation *location, GLboolean transpose, std::vector<GLfloat> value)
{
    HTML5_CALL(this->v, uniformMatrix4fv, location->v, transpose, toJSArray<GLfloat>(value));
}

void WebGLRenderingContext::useProgram(WebGLProgram *program)
{
    HTML5_CALL(this->v, useProgram, program->v);
}

void WebGLRenderingContext::validateProgram(WebGLProgram *program)
{
    HTML5_CALL(this->v, validateProgram, program->v);
}

void WebGLRenderingContext::vertexAttrib1f(GLuint indx, GLfloat x)
{
    HTML5_CALL(this->v, vertexAttrib1f, indx, x);
}

void WebGLRenderingContext::vertexAttrib1fv(GLuint indx, std::vector<GLfloat> values)
{
    HTML5_CALL(this->v, vertexAttrib1fv, indx, toJSArray<GLfloat>(values));
}

void WebGLRenderingContext::vertexAttrib2f(GLuint indx, GLfloat x, GLfloat y)
{
    HTML5_CALL(this->v, vertexAttrib2f, indx, x, y);
}

void WebGLRenderingContext::vertexAttrib2fv(GLuint indx, std::vector<GLfloat> values)
{
    HTML5_CALL(this->v, vertexAttrib2fv, indx, toJSArray<GLfloat>(values));
}

void WebGLRenderingContext::vertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
    HTML5_CALL(this->v, vertexAttrib3f, indx, x, y, z);
}

void WebGLRenderingContext::vertexAttrib3fv(GLuint indx, std::vector<GLfloat> values)
{
    HTML5_CALL(this->v, vertexAttrib3fv, indx, toJSArray<GLfloat>(values));
}

void WebGLRenderingContext::vertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    HTML5_CALL(this->v, vertexAttrib4f, indx, x, y, z, w);
}

void WebGLRenderingContext::vertexAttrib4fv(GLuint indx, std::vector<GLfloat> values)
{
    HTML5_CALL(this->v, vertexAttrib4fv, indx, toJSArray<GLfloat>(values));
}

void WebGLRenderingContext::vertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset)
{
    HTML5_CALL(this->v, vertexAttribPointer, indx, size, type, normalized, stride, offset);
}

void WebGLRenderingContext::viewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    HTML5_CALL(this->v, viewport, x, y, width, height);
}

HTML5_PROPERTY_OBJECT_IMPL(WebGLRenderingContext, HTMLCanvasElement, canvas);
HTML5_PROPERTY_IMPL(WebGLRenderingContext, GLsizei, drawingBufferHeight);
HTML5_PROPERTY_IMPL(WebGLRenderingContext, GLsizei, drawingBufferWidth);
