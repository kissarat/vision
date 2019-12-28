#include <opencv2/opencv.hpp>

using namespace cv;
const char* window = "Play Video";

int main(int argc, char** argv) {
    VideoCapture capture;
    capture.open(argv[1]);
    Mat frame;
    do {
        capture >> frame;
        if (frame.empty()) {
            break;
        }
        imshow(window, frame);
    } while(waitKey(1) < 0);
    return 0;
}
