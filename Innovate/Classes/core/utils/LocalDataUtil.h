//
//  LocalDataUtil.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/18.
//
//

#ifndef LocalDataUtil_hpp
#define LocalDataUtil_hpp

class LocalDataUtil
{
public:
    
    static LocalDataUtil* getInstance();
    
    LocalDataUtil();
    ~LocalDataUtil();
    
    bool getBoolForKey(const char* key);
    bool getBoolForKey(const char* key, bool defaultValue);
    
    int getIntegerForKey(const char* key);
    int getIntegerForKey(const char* key, int defaultValue);
    
    float getFloatForKey(const char* key);
    float getFloatForKey(const char* key, float defaultValue);
    
    double  getDoubleForKey(const char* key);
    double getDoubleForKey(const char* key, double defaultValue);
    
    std::string getStringForKey(const char* key);
    std::string getStringForKey(const char* key, const std::string & defaultValue);
    
    void setIntegerForKey(const char* key, int value);
    void setFloatForKey(const char* key, float value);
    void setDoubleForKey(const char* key, double value);
    void setStringForKey(const char* key, const std::string & value);
    void flush();
    
    void deleteValueForKey(const char* key);
    

    
};

#endif /* LocalDataUtil_hpp */
