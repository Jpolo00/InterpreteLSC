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
        //Control Scene
        int brightness;
        double contrast;
        double gamma;
        Mat tmp;

        //Erode & Dilate SEGMENTATION
        //Mat element = getStructuringElement(MORPH_CROSS, Size(25, 25), Point(2, 2)); //Option 1
        Mat element = getStructuringElement(MORPH_ELLIPSE, Size(7, 7)); //Option 2

        //Color for inRang SEGMENTATION
        size_t sizeMatColorRang = 1;
        Mat matColorRang[1];
        size_t sizeColorRang = 2;
        Scalar colorRang[2] = {Scalar(0, 0, 45), Scalar(25, 160, 245)}; //Color Rang 1
        Mat groupColorRang(Mat img);

        //Get Characteristic
        vector<vector<Point> > contours;
        vector<Vec4i> hierarchy;
        Moments mnts;

    public:
        //CONSTRUCTORS
        PDI();
        PDI(int brightness,
            double contrast,
            double gamma);

        //DESTROLLER
        ~PDI();

        //FUNCTIONS
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