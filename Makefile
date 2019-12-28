CC=gcc
TARGET_BIN=bin
OPENCV_INCLUDE=/usr/include/opencv4
SRC=src/examples
CFLAGS=-Wall -std=c++11 -I$(OPENCV_INCLUDE) -lstdc++ -lopencv_core \
	   -lopencv_highgui

all: show-image play-video videoplayer-trackbar
show-image:
	$(CC) $(SRC)/show-image.cpp -o $(TARGET_BIN)/show-image -lopencv_imgcodecs $(CFLAGS)
play-video:
	$(CC) $(SRC)/play-video.cpp -o $(TARGET_BIN)/play-video -lopencv_videoio $(CFLAGS)
videoplayer-trackbar:
	$(CC) $(SRC)/videoplayer-trackbar.cpp -o $(TARGET_BIN)/videoplayer-trackbar -lopencv_videoio $(CFLAGS)
clean:
	rm ${TARGET_BIN}/*
