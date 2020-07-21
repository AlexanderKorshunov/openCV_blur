#ifndef PARSE_H
#define PARSE_H

#include <boost/property_tree/ini_parser.hpp>
#include <iostream>

using boost::property_tree::ptree;

class ParseIni
{
    std::string sFileName;
    ptree pt;
    int iBlurWidth;
    int iBlurHeight;
    std::string sVideoSource;
public:
    ParseIni();
    ParseIni(std::string);
    void setFileName(std::string);
    std::string getFileName();
    ~ParseIni();
    bool startParse();
    int getBlurWidth();
    int getBlurHeight();
    std::string getVideoSource();
};

#endif
