CC=gcc
TARGET_BIN=bin
OPENCV_INCLUDE=/usr/include/opencv4
CFLAGS=-Wall -std=c++11 -I$(OPENCV_INCLUDE) -lstdc++ -lopencv_core \
	   -lopencv_highgui

show-image:
	$(CC) src/show-image.cpp -o $(TARGET_BIN)/show-image -lopencv_imgcodecs $(CFLAGS)
play-video:
	$(CC) src/play-video.cpp -o $(TARGET_BIN)/play-video -lopencv_videoio $(CFLAGS)
all: show-image play-video
clean:
	rm ${TARGET_BIN}/*
