#ifndef __MXL___H__
#define __MXL___H__

#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<cstdlib>
#include<cstdio>
#include "symbol.hpp"


extern std::string current_name;
extern std::unordered_map<std::string, std::unordered_map<std::string, std::string> > vars;
extern void mxlerror(const char *src, ...);
extern int mxllineno;

namespace mxl {
    
    using subIt = std::unordered_map<std::string, std::string>::iterator;
    using It = std::unordered_map<std::string, std::unordered_map<std::string, std::string>>::iterator;
    
    class MXL {
    public:
        MXL() = default;
        MXL(const std::unordered_map<std::string, std::unordered_map<std::string, std::string>> &v);
        MXL(std::unordered_map<std::string, std::unordered_map<std::string, std::string>> &&v);
        MXL(const MXL &m);
        MXL(MXL &&m);
        MXL &operator=(const MXL &m);
        MXL &operator=(MXL &&m);
        MXL &operator+=(MXL &m);
        MXL &operator+=(std::unordered_map<std::string, std::unordered_map<std::string, std::string>> &v);
        
        std::string &operator()(std::string cat, std::string key);
        std::string &table(std::string cat, std::string key);
        
        bool loadFromFile(const std::string &n);
        
        template<typename T>
        void setTableValue(std::string cat, std::string key, const T &type) {
            std::ostringstream stream;
            stream << type;
            vars[cat][key] = stream.str();
        }
        
        
        subIt begin_sub(const std::string &n);
        subIt end_sub(const std::string &n);
        It begin_mxl();
        It end_mxl();
        
        long getTableInteger(std::string cat, std::string key);
        double getTableDouble(std::string cat, std::string key);
        void setValue(std::string cat, std::string key, std::string val);
        void echoTokens();
        bool writeToFile(std::string filename);
        bool sortedWriteToFile(std::string filename);
        static MXL *parseMXL(const std::string &n);
        void mergeMap(std::unordered_map<std::string, std::unordered_map<std::string, std::string>> &m);
        void mergeMap(MXL &m);
        bool keyValid(const std::string &cat, const std::string &key);
        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> &mxlmap() { return vars; }
        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> *operator->() { return &vars; }
    private:
        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> vars;
    };
    
    bool readSource();
    bool readSource(std::string data);
    void echoTokens();
    std::string &getValue(std::string tag, std::string key);
    std::string trimQuotes(std::string value);
    extern int error_count;
}

#endif

