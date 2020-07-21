#include "parse.h"
#include "blur.h"

int main()
{
    ParseIni parse("cfg.ini");
    if(parse.startParse())
    {
        //Size _sz(25, 25);
        //String _fileName("./test.mov");
   
        Size _sz(parse.getBlurWidth(), parse.getBlurHeight());
        String _fileName(parse.getVideoSource());

        BlurImage blur(_sz, _fileName);
        if(blur.init())
            blur.procces();
    }
    
    return 0;
}
