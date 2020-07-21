CC 		:= g++
CFLAGS 		:= -I/usr/local/include/opencv4/opencv2 -I/usr/local/include/opencv4 -I/usr/local/include/opencv4/opencv2/core -I/usr/local/include/opencv4/opencv2/videoio/legacy -L/usr/local/lib
OBJECTS 	:= 
LIBRARIES 	:= -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_face -lopencv_imgcodecs -lopencv_videoio
BOOSTFLAGS	:= -I/usr/include/boost/property_tree -L/usr/lib/x86_64-linux-gnu
BOOSTLIBRARIES	:= -lboost_log

.PHONY: all clean

all: EXE

EXE: main.o blur.o parse.o
	$(CC) $(CFLAGS) -o EXE main.o blur.o parse.o $(LIBRARIES)
	
blur.o: blur.cpp blur.h
	$(CC) $(CFLAGS) -c blur.cpp $(LIBRARIES)
	
main.o: main.cpp blur.h
	$(CC) $(CFLAGS) -c main.cpp $(LIBRARIES)
	
parse.o: parse.cpp parse.h
	$(CC) $(BOOSTFLAGS) -c parse.cpp $(BOOSTLIBRARIES)
	
clean:
	rm -f *.o
	
