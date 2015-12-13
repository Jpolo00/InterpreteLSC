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
    Mat tmp;
    cvtColor(img, tmp, CV_BGR2HSV);
    return tmp;
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

    return tmp;
}

Mat PDI::secImprovement(Mat img)
{
    Mat tmp;

    GaussianBlur(img, tmp, Size(3, 3), 1.0);

    return tmp;
}

//Segmentation ############################################
Mat PDI::segmentation(Mat img)
{
    Mat tmp;
    Mat element;
    vector<Mat> tmpRang;

    //Initializer Colors for Range
    vector <vector <Scalar> > color(2);
    color[0].push_back(Scalar(0, 100, 100));
    color[0].push_back(Scalar(10, 255, 255));

    color[1].push_back(Scalar(160, 100, 100));
    color[1].push_back(Scalar(179, 255, 255));

    tmpRang = groupRangColor(img, color);
    tmp = groupRang(tmpRang);

    element = getStructuringElement(2, Size(25, 25), Point(2, 2));

    dilate(tmp, tmp.clone(), element);
    erode(tmp, tmp.clone(), element);
    medianBlur(tmp, tmp.clone(), 11);

    return tmp;
}

Mat PDI::groupRang(vector<Mat> colorRang)
{
    size_t size = colorRang.size() - 1;
    Mat tmp;

    for (size_t i = 0; i < size; i++)
    {
        //Do the group of different color rang in one image
        addWeighted(colorRang[i], 1.0, 
                    colorRang[i + 1], 1.0, 
                    0.0, tmp);
        colorRang[i + 1] = tmp;
    }

    return tmp;
}

vector<Mat> PDI::groupRangColor(Mat img, vector<vector<Scalar> > color)
{
    vector<Mat> tmp(color.size());

    for (size_t i = 0; i < tmp.size(); i++)
    {
        //Save different color rang, segmentation for color hsv
        inRange(img, color[i][0], color[i][1], tmp[i]);
    }

    return tmp;
}
//##########################################################

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