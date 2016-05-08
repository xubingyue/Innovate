#define _CRT_SECURE_NO_WARNINGS

#include "TableHelper.h"
#include "csv.h"
#include <algorithm>
#include <unordered_map>

namespace tables
{
    iconv_open_func iconv_open_ = NULL;
    iconv_func iconv_ = NULL;
    iconv_close_func iconv_close_ = NULL;
    
    void FieldCallback(void *s, size_t len, void *data)
    {
        auto idc = (InterDataCarrier*)data;
        idc->m1.emplace_back(std::string((char*)s));
    }
    
    void RecordCallback(int c, void *data)
    {
        auto idc = (InterDataCarrier*)data;
        idc->m2.emplace_back(std::move(idc->m1));
    }
    
    InterDataCarrier::InterDataCarrier(unsigned const char* data, size_t size, const char* additionalNote)
    {
        if (data == NULL)
        {
            Error = "'data' cannot be NULL! [" + std::string(additionalNote) + "]";
            return;
        }
        if (size == 0)
        {
            Error = "'size' cannot be zero! [" + std::string(additionalNote) + "]";
            return;
        }
        if (additionalNote == NULL)
        {
            Error = "'additionalNote' cannot be NULL!";
            return;
        }
        
        struct csv_parser parser;
        csv_init(&parser, CSV_STRICT | CSV_APPEND_NULL);
        
#ifdef _DEBUG
        m2.reserve(1024 * 16);
#endif
        
        if (csv_parse(&parser, data, size, FieldCallback, RecordCallback, this) != size)
        {
            Error = "Error occurred when parsing a table. [" + std::string(additionalNote) + "]\n" + csv_strerror(csv_error(&parser));
            return;
        }
        
        csv_fini(&parser, FieldCallback, RecordCallback, this);
        
        m2.erase(std::remove_if(m2.begin(), m2.end(), [](const std::vector<std::string>& v) -> bool
                                {
                                    return !v.empty() && !v.front().empty() && v.front().front() == '#';
                                }), m2.end());
        
#ifdef SAFE_TABLE_READER
        std::unordered_map<std::string, std::string> cn2f;
        cn2f.reserve(m2[0].size());
        
        for (size_t column = 0; column < m2[0].size(); column++)
        {
            std::vector<std::string> cd;
            for (size_t row = 1; row < m2.size(); row++)
                cd.push_back(m2[row][column]);
            
            const auto& columnName = m2[0][column];
            auto it = cn2f.find(columnName);
            if (it == cn2f.end())
            {
                size_t pos1 = columnName.find("===");
                size_t pos2 = columnName.find("===", pos1 + 1);
                while (columnName[pos1] == '=' || columnName[pos1] == '\r' || columnName[pos1] == '\n') pos1++;
                while (columnName[pos2] == '=' || columnName[pos2] == '\r' || columnName[pos2] == '\n') pos2--;
                cn2f[columnName] = columnName.substr(pos1, pos2 - pos1 + 1);
                it = cn2f.find(columnName);
            }
            
            m3[it->second] = cd;
        }
#endif
    }
    
    std::string InterDataCarrier::GetField(int row, int column, const char* columnName, bool utf8 /*= false*/) const
    {
#ifdef SAFE_TABLE_READER
#else
        row++;
#endif
        
        if (utf8 && iconv_open_ != NULL && iconv_ != NULL && iconv_close_ != NULL)
        {
#ifdef SAFE_TABLE_READER
            std::string src = m3.at(columnName)[row];
#else
            std::string src = m2[row][column];
#endif
            std::string dst;
            dst.resize(src.length() * 4);
            
            void* icd = iconv_open_("UTF-8", "GBK");
            if ((long)icd != -1)
            {
                std::shared_ptr<void> iconv_close_helper(icd, iconv_close_);
                
                char* inbuf = (char*)src.c_str();
                size_t inbytesLeft = src.length();
                char* outbuf = (char*)dst.c_str();
                size_t outbytesLeft = dst.capacity();
                size_t r = iconv_(icd, &inbuf, &inbytesLeft, &outbuf, &outbytesLeft);
                if (r != -1 && inbytesLeft == 0)
                {
                    dst.resize(dst.capacity() - outbytesLeft);
                    return dst;
                }
            }
        }
        
#ifdef SAFE_TABLE_READER
        return m3.at(columnName)[row];
#else
        return m2[row][column];
#endif
    }
    
    size_t InterDataCarrier::GetRecordCount() const
    {
        return m2.empty() ? 0 : m2.size() - 1;
    }
}