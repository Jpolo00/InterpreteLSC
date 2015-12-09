#ifndef PDI_H
#define PDI_H

#include <string>
#include <vector>

#include <cv.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class PDI
{
    private:
        int brightness;
        double contrast;
        double gamma;
    public:
        PDI();
        PDI(int brightness,
            double contrast,
            double gamma);
        ~PDI();
        void setCaliber(int brightness,
                        double contrast,
                        double gamma);
        Mat convertColorSpace(Mat img);
        Mat preImprovement(Mat img);
        Mat secImprovement(Mat img);
        Mat segmentation(Mat img);
        vector<double> characteristic(Mat img);
};
#endif