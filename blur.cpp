#include "blur.h"

using namespace cv;

using namespace std;

#define VIDEO_PATH "./test.mov"

#define ESC     27

BlurImage::BlurImage():sz(2,2),width(0),height(0)
{
    fileName = VIDEO_PATH;
}

BlurImage::BlurImage(Size _sz):sz(_sz),width(0),height(0)
{
    fileName = VIDEO_PATH;
}
    
BlurImage::BlurImage(Size _sz, String _fileName):sz(_sz),fileName(_fileName),width(0),height(0)
{

}
 
Size BlurImage::getBlurArea()
{
    return sz;
}
    
void BlurImage::setBlurArea(Size _sz)
{
    sz = _sz;
}
    
String BlurImage::getFileName()
{
    return fileName;
}
    
void BlurImage::setFileName(String _fileName)
{
    fileName = _fileName;
}
    
BlurImage::~BlurImage()
{
    
}
    
void BlurImage::callBackFunc(int event, int x, int y, int flags, void* ptrdata)
{
    if ( event == EVENT_MOUSEMOVE )
    {
        if(ptrdata)
        {
            Size *sz = (Size *)ptrdata;
            sz->width = x;
            sz->height = y;
        }
    }
}
    
bool BlurImage::init()
{
     if (!videoSource.open(VIDEO_PATH))
    {            
        std::cout<<"Video not found at "<<VIDEO_PATH<<std::endl;
        return false;
    }
    videoSource.set(CV_CAP_PROP_CONVERT_RGB, 1);
    
    width = videoSource.get(CV_CAP_PROP_FRAME_WIDTH);
    height = videoSource.get(CV_CAP_PROP_FRAME_HEIGHT);
    float aspectRatio = width / height;

    std::cout << "Resolution: " << width <<", "<< height <<" aspect ratio: "<< aspectRatio << std::endl;
    return true;
}
    
int BlurImage::procces()
{
    Rect rect;
    Size _szMouse(0, 0);
    int borderX = 0, borderY = 0;
    
    while(true)
    {
        videoSource >> frame;
        if(frame.empty())
            break;  

        setMouseCallback("VIDEO - 1", callBackFunc, &_szMouse);
        if((_szMouse.width && _szMouse.height) && (_szMouse.width < width && _szMouse.height < height))
        {
            if(borderX != _szMouse.width && borderY != _szMouse.height)
            {
                borderX = _szMouse.width;
                borderY = _szMouse.height;
            }
            else
            {
                if(_szMouse.width + sz.width < width && _szMouse.height + sz.height < height)
                {
                    rect = Rect(_szMouse.width, _szMouse.height, sz.width, sz.height);
                    Mat imgRoi = frame(rect);
                    blur(imgRoi, imgRoi, sz, Point(-1,-1));
                    imgRoi.copyTo(frame(rect));
                }
            }
        }
        imshow("VIDEO - 1", frame);

        if(waitKey(25) == ESC)
        {
            cout << "Press ESC" << endl;
            break;
        }
    }
   waitKey(0);
   return 1;
}
