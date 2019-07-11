#include "file_reader.h"
#include "blob.h"
#include "array_buffer.h"

USING_NAMESPACE_HTML5;

HTML5_BIND_CLASS(FileReader);

FileReader::FileReader(emscripten::val v) :
    EventTarget(v)
{
}

FileReader::~FileReader()
{
}

FileReader *FileReader::create()
{
    auto reader = new FileReader(HTML5_NEW_PRIMITIVE_INSTANCE(FileReader));
    reader->autorelease();
    return reader;
}

void FileReader::abort()
{
    HTML5_CALL(this->v, abort);
}

void FileReader::readAsArrayBuffer(Blob *blob)
{
    HTML5_CALL(this->v, readAsArrayBuffer, blob->v);
}

void FileReader::readAsArrayBuffer(File *file)
{
//    HTML5_CALL(this->v, readAsArrayBuffer, file->v);
}

void FileReader::readAsBinaryString(Blob *blob)
{
    HTML5_CALL(this->v, readAsBinaryString, blob->v);
}

void FileReader::readAsBinaryString(File *file)
{
    //HTML5_CALL(this->v, readAsBinaryString, file->v);
}

void FileReader::readAsDataURL(Blob *blob)
{
    HTML5_CALL(this->v, readAsDataURL, blob->v);
}

void FileReader::readAsDataURL(File *file)
{
    //HTML5_CALL(this->v, readAsDataURL, file->v);
}

void FileReader::readAsText(Blob *blob, const std::string &encoding)
{
    HTML5_CALL(this->v, readAsText, blob->v, encoding);
}

void FileReader::readAsText(File *file, const std::string &encoding)
{
    //HTML5_CALL(this->v, readAsText, file->v, encoding);
}

ArrayBuffer *FileReader::resultArrayBuffer() const
{
    return ArrayBuffer::create(this->v["result"]);
}

std::string FileReader::resultString() const
{
    return this->v["result"].as<std::string>();
}

HTML5_EVENT_HANDLER_PROPERTY_IMPL_NEW(FileReader, EventHandler, onload);