#include "PDI.h"

PDI::PDI()
{
    brightness = 0;
    contrast = 0.0;
    gamma = 0.0;
}

PDI::PDI(int brightness,
         double contrast,
         double gamma)
{
    this->brightness = brightness;
    this->contrast = contrast;
    this->gamma = gamma;
}

PDI::~PDI(){}

void PDI::setCaliber(int brightness,
                     double contrast,
                     double gamma)
{
    this->brightness = brightness;
    this->contrast = contrast;
    this->gamma = gamma;
}

Mat PDI::convertColorSpace(Mat img)
{
    cvtColor(img, img.clone(), CV_BGR2HSV);
    return img;
}

Mat PDI::preImprovement(Mat img)
{
    Mat tmp;
    //Gamma
    Mat lut_matrix(1, 256, CV_8UC1);

    uchar *ptr = lut_matrix.ptr();

    for(size_t i = 0; i < 256; i++)
    {
        ptr[i] = (int)(pow(i / 255.0, gamma) * 255.0);
    }

    LUT(img, lut_matrix, tmp);

    //Brightness  & Contrast
    tmp.convertTo(tmp.clone(), -1, contrast, brightness);

    //Gaussian Blur
    GaussianBlur(tmp, tmp.clone(), Size(3, 3), 1.0);

    return tmp;
}

/*
Mat PDI::secImprovement(Mat img)
{

}

Mat PDI::segmentation(Mat img)
{

}*/

vector<double> PDI::characteristic(Mat img)
{
    double arrayMomentsHU[7];
    vector<double> array(7);

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    Mat tmp;

    Canny(img, tmp, 50, 200, 3);
    findContours(tmp, contours, 
                      hierarchy, 
                      CV_RETR_TREE, 
                      CV_CHAIN_APPROX_SIMPLE, 
                      Point(0, 0));

    Moments mnts = moments(contours[0]);
    HuMoments(mnts, arrayMomentsHU);

    for (size_t i = 0; i < 7; i++)
    {
        array[i] = arrayMomentsHU[i];
    }

    return array;
}