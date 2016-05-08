#pragma once

#include <vector>
#include <string>
#include <memory>
#include <map>

namespace tables
{
    typedef void* (*iconv_open_func)(const char* tocode, const char* fromcode);
    extern iconv_open_func iconv_open_;
    
    typedef size_t (*iconv_func)(void* icd, char** inbuf, size_t* inbytesleft, char** outbuf, size_t* outbytesleft);
    extern iconv_func iconv_;
    
    typedef int (*iconv_close_func)(void* icd);
    extern iconv_close_func iconv_close_;
    
    extern void FieldCallback(void *s, size_t len, void *data);
    extern void RecordCallback(int c, void *data);
    
    struct InterDataCarrier
    {
#ifdef SAFE_TABLE_READER
        std::map<std::string, std::vector<std::string>> m3;
#endif
        std::vector<std::vector<std::string>> m2;
        std::vector<std::string> m1;
        std::string Error;
        
        InterDataCarrier(unsigned const char* data, size_t size, const char* additionalNote);
        std::string GetField(int row, int column, const char* columnName, bool utf8 = false) const;
        size_t GetRecordCount() const;
    };
}