#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

using namespace cv;

std::string g_window = "Trackball";
int g_slider_position = 0;
bool g_run = true;
bool g_dontset = false;
VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
    g_cap.set(CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset) {
        g_run = true;
    }
    g_dontset = false;
}

int main(int argc, char** argv) {
    // namedWindow(g_window, WINDOW_AUTOSIZE);
    g_cap.open(std::string(argv[1]));
    int frames = (int) g_cap.get(CAP_PROP_FRAME_COUNT);
    int tmpw = (int) g_cap.get(CAP_PROP_FRAME_WIDTH);
    int tmph = (int) g_cap.get(CAP_PROP_FRAME_HEIGHT);
    printf("Video has %i frames of dimension (%i,%i)\n", frames, tmpw, tmph);
    return 0;
}
