#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

using namespace cv;

const char KEYBOARD_ESC = 27;
const char KEYBOARD_SPACE = 32;
const char COMMAND_EXIT = KEYBOARD_ESC;
const char COMMAND_PAUSE = KEYBOARD_SPACE;
const char COMMAND_SINGLE_STEP = 'c';
const char COMMAND_RUN_MODE = 'r';
std::string g_window = "TrackbarWindow";
std::string g_trackbar = "Trackbar";
int g_slider_position = 0;
int g_run = 1;
bool g_dontset = false;
VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
    g_cap.set(CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset) {
        g_run = 1;
    }
    g_dontset = false;
}

int main(int argc, char** argv) {
    namedWindow(g_window, WINDOW_AUTOSIZE);
    g_cap.open(std::string(argv[1]));
    int frames = (int) g_cap.get(CAP_PROP_FRAME_COUNT);
    int tmpw = (int) g_cap.get(CAP_PROP_FRAME_WIDTH);
    int tmph = (int) g_cap.get(CAP_PROP_FRAME_HEIGHT);
    printf("Video has %i frames of dimension (%i,%i)\n", frames, tmpw, tmph);
    createTrackbar(g_trackbar, g_window, &g_slider_position, frames, onTrackbarSlide);
    Mat frame;
    while(true) {
        if (0 != g_run) {
            g_cap >> frame;
            if (frame.empty()) {
                break;
            }
            int current_pos = (int) g_cap.get(CAP_PROP_POS_FRAMES);
            g_dontset = true;
            setTrackbarPos(g_trackbar, g_window, current_pos);
            g_run = 1;
        }
        char c = (char) waitKey(10);
        switch (c)
        {
        case COMMAND_SINGLE_STEP:
            g_run = 1;
            printf("Single step, run %i\n", g_run);
            break;
        
        case COMMAND_RUN_MODE:
            g_run = -1;
            printf("Run mode, run %i\n", g_run);
            break;
        
        case COMMAND_PAUSE:
            g_run = 0;
            std::cout << "Pause";
            break;
        
        case COMMAND_EXIT:
            g_run = 0;
            std::cout << "EXIT";
            break;
        default:
            std::cout << "Invalid command with code" << c << std::endl;
            break;
        }
    }
    return 0;
}
