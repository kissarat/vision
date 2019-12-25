CC=gcc
TARGET_BIN=bin
OPENCV_INCLUDE=/usr/include/opencv4
CFLAGS=-Wall -std=c++11 -I$(OPENCV_INCLUDE) -lstdc++ -lopencv_core \
	   -lopencv_highgui -lopencv_imgcodecs
show-image:
	$(CC) src/show-image.cpp -o $(TARGET_BIN)/show-image $(CFLAGS)
all: shoe-image	
clean:
	rm ${TARGET_BIN}/*
