#include "parse.h"

ParseIni::ParseIni():sFileName("cfg.ini")
{
    
}

ParseIni::ParseIni(std::string _sFileName):sFileName(_sFileName)
{
    
}

void ParseIni::setFileName(std::string _sFileName)
{
    sFileName = _sFileName;
}

std::string ParseIni::getFileName()
{
    return sFileName;
}

ParseIni::~ParseIni()
{
    
}

bool ParseIni::startParse()
{
    read_ini(sFileName, pt);
    iBlurWidth = pt.get<int>("Blur.W");
    iBlurHeight = pt.get<int>("Blur.H");
    sVideoSource = pt.get<std::string>("SourceVideo.File");
    return true;
}

int ParseIni::getBlurWidth()
{
    return iBlurWidth;
}

int ParseIni::getBlurHeight()
{
    return iBlurHeight;
}

std::string ParseIni::getVideoSource()
{
    return sVideoSource;
}
