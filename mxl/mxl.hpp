#ifndef __MXL___H__
#define __MXL___H__

#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<cstdlib>
#include<cstdio>
#include "symbol.hpp"

extern std::string current_name;
extern std::map<std::string, std::map<std::string, std::string> > vars;
extern void mxlerror(const char *src, ...);
extern int mxllineno;

namespace mxl {
    class MXL {
    public:
        MXL() = default;
        MXL(const std::map<std::string, std::map<std::string, std::string>> &v);
        MXL(std::map<std::string, std::map<std::string, std::string>> &&v);
        MXL(const MXL &m);
        MXL(MXL &&m);
        MXL &operator=(const MXL &m);
        MXL &operator=(MXL &&m);
        std::string &operator()(std::string cat, std::string key);
        std::string &table(std::string cat, std::string key);
        
        template<typename T>
        void setTableValue(std::string cat, std::string key, const T &type) {
            std::ostringstream stream;
            stream << type;
            vars[cat][key] = stream.str();
        }
        
        long getTableInteger(std::string cat, std::string key);
        double getTableDouble(std::string cat, std::string key);
        void setValue(std::string cat, std::string key, std::string val);
        void echoTokens();
        bool writeToFile(std::string filename);
        bool sortedWriteToFile(std::string filename);
        static MXL *parseMXL(const std::string &n);
        void mergeMap(std::map<std::string, std::map<std::string, std::string>> &m);
        void mergeMap(MXL &m);
        bool keyValid(const std::string &cat, const std::string &key);
        std::map<std::string, std::map<std::string, std::string>> &mxlmap() { return vars; }
        std::map<std::string, std::map<std::string, std::string>> *operator->() { return &vars; }
    private:
        std::map<std::string, std::map<std::string, std::string>> vars;
    };
    
    bool readSource();
    bool readSource(std::string data);
    void echoTokens();
    std::string &getValue(std::string tag, std::string key);
    std::string trimQuotes(std::string value);
    extern int error_count;
}

#endif

