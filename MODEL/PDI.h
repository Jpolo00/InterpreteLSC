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
        //Variables
        int brightness;
        double contrast;
        double gamma;
        double momentsHu[7];

        size_t sizeMatColorRang = 1;
        size_t sizeColorRang = 2;

        Mat tmp;
        Mat tmp2;
        //Mat element = getStructuringElement(MORPH_CROSS, Size(25, 25), Point(2, 2)); //Option 1
        //Mat element = getStructuringElement(MORPH_ELLIPSE, Size(7, 7)); //Option 2
        Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5, 5)); //Option 2
        Mat matColorRang[1];
        Mat drawing;

        //Scalar colorRang[2] = {Scalar(0, 0, 45), Scalar(25, 160, 245)}; //Color Rang 1
        //Scalar colorRang[2] = {Scalar(0, 50, 0), Scalar(40, 255, 255)}; //Color Rang 2
        Scalar colorRang[2] = {Scalar(0, 50, 100), Scalar(30, 240, 255)}; //Color Rang 3

        vector<vector<Point> > contours;
        vector<vector<Point> > contours2;
        vector<Vec4i> hierarchy;

        vector<double> arrayMomentsHu;

        Moments mnts;

        //Metodos
        Mat groupColorRang(Mat img);

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
        vector<vector<Point> > filterContours(vector<vector<Point> > contours);
        vector<vector<Point> > segmentation(Mat img);
        vector<double> characteristic(vector<vector<Point> > contours);
};
#endif