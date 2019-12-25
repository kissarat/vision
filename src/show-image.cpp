#include <opencv2/opencv.hpp>

using namespace cv;
const char* window = "First";

int main(int argc, char** argv) {
    Mat img = imread(argv[1], -1);
    if (img.empty()) {
        return -1;
    }
    namedWindow(window, WINDOW_AUTOSIZE);
    imshow(window, img);
    waitKey(0);
    destroyWindow(window);
    return 0;
}
