#pragma once

#include "event_target.h"

NAMESPACE_HTML5_BEGIN;

class Blob;
class File;
class ArrayBuffer;

class FileReader : public EventTarget {
public:
    struct {
        FileReader &self;
        operator ArrayBuffer *() { return self.resultArrayBuffer(); };
        operator std::string () { return self.resultString(); };
    } result{*this};
    HTML5_EVENT_HANDLER_PROPERTY(FileReader, EventHandler, onload);

    FileReader(emscripten::val v);
    virtual ~FileReader();
    static FileReader *create();
    void abort();
    void readAsArrayBuffer(Blob *blob);
    void readAsArrayBuffer(File *file);
    void readAsBinaryString(Blob *blob);
    void readAsBinaryString(File *file);
    void readAsDataURL(Blob *blob);
    void readAsDataURL(File *file);
    void readAsText(Blob *blob, const std::string &encoding = "utf-8");
    void readAsText(File *file, const std::string &encoding = "utf-8");

    ArrayBuffer *resultArrayBuffer() const;
    std::string resultString() const;
};

NAMESPACE_HTML5_END;