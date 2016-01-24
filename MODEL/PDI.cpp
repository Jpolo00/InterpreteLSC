#include "PDI.h"

//CONSTRUCTORS
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

//DESTROLLER
PDI::~PDI(){}

//FUNCTION
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
    cvtColor(img, tmp, CV_BGR2HSV);
    return tmp;
}


Mat PDI::preImprovement(Mat img)
{
    Mat lut_matrix(1, 256, CV_8UC1);
    uchar *ptr = lut_matrix.ptr();

    for(size_t i = 0; i < 256; i++)
    {
        //Gamma [0 - 5.0]
        ptr[i] = (int)(pow(i / 255.0, gamma) * 255.0);
    }

    LUT(img, lut_matrix, tmp);

    tmp.convertTo(tmp, -1, contrast, brightness);

    return tmp;
}

Mat PDI::secImprovement(Mat img)
{
    GaussianBlur(img, tmp, Size(3, 3), 1.0);

    return tmp;
}

Mat PDI::segmentation(Mat img)
{
    double arrayMomentsHU[7];
    vector<double> array(7);

    tmp = groupColorRang(img);
    threshold(tmp, tmp2, 128, 255, THRESH_BINARY_INV);

    tmp = tmp2;

    erode(tmp, tmp2, element);
    tmp = tmp2;

    dilate(tmp, tmp2, element);
    tmp = tmp2;

    medianBlur(tmp, tmp2, 3);
    GaussianBlur(tmp2, tmp, Size(5, 5), 5, 10);

    imshow("Test1", tmp2);

    Canny(tmp, tmp2, 200, 255, 3);
    tmp = tmp2;

    imshow("Test2", tmp2);

    findContours(tmp, contours, 
                      hierarchy, 
                      CV_RETR_CCOMP, //CV_RETR_TREE, //CV_RETR_EXTERNAL, //CV_RETR_LIST 
                      CV_CHAIN_APPROX_SIMPLE, //CV_CHAIN_APPROX_TC89_KCOS, //CV_CHAIN_APPROX_TC89_L1, //CV_CHAIN_APPROX_NONE, 
                      Point(0, 0));

    characteristic(contours);

    Mat drawing = Mat::zeros(tmp.size(), CV_8UC3 );

    for(size_t i = 0; i< contours.size(); i++)
    {
        if (arcLength( contours[i], true ) > 100.0)
        {
            drawContours( drawing, contours, i, Scalar(0, 255, 0), 1, 8, hierarchy, 0, Point(0, 0));
        }
    }

    imshow("Test", drawing);
    return drawing;
}

Mat PDI::groupColorRang(Mat img)
{
    for (size_t j = 0; j < sizeMatColorRang; j++)
    {
        for (size_t i = 0; i < sizeColorRang; i += 2)
        {
            inRange(img, colorRang[i], colorRang[i + 1], matColorRang[j]);

        }
    }

    tmp =  matColorRang[0];

    for (size_t i = 1; i < sizeMatColorRang ; i++)
    {
        addWeighted(tmp.clone(), 1.0, matColorRang[i], 1.0, 0.0, tmp);
    }

    return tmp;
}

vector<double> PDI::characteristic(vector<vector<Point> > contours)
{
    double arrayMomentsHU[7];
    vector<double> array(7);

    for(size_t i = 0; i < contours.size(); i++)
    {
        mnts = moments(contours[i]);
        HuMoments(mnts, arrayMomentsHU);

        cout << "Contorno " << i << "-------------------" << endl;
        for (size_t i = 0; i < 7; i++)
        {
            cout << arrayMomentsHU[i] << endl;
        }
    }


    // for (size_t i = 0; i < 7; i++)
    // {
    //     array[i] = arrayMomentsHU[i];
    // }

    return array;
}