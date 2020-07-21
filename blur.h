#ifndef BLUR_H
#define BLUR_H

#include "highgui.hpp"

#include "imgproc.hpp"

#include "core.hpp"

#include <constants_c.h>

#include <core_c.h>

#include <iostream>

using namespace cv;

using namespace std;

class BlurImage
{
    VideoCapture videoSource;
    
    Mat frame;
    
    String fileName;
    
    Size sz;    // blur area
    
    int width;  // width video
    
    int height; // height video

public:
    BlurImage();
    
    BlurImage(Size);
    
    BlurImage(Size, String);
    
    Size getBlurArea();
    
    void setBlurArea(Size);
    
    String getFileName();
    
    void setFileName(String);
    
    virtual ~BlurImage();
    
    static void callBackFunc(int event, int x, int y, int flags, void* ptrdata);
    
    bool init();
    
    int procces();
};

#endif
