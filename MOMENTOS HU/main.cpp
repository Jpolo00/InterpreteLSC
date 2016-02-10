#include <cv.h>
#include <highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;

int main( int argc, char** argv)
{
    Mat src = imread("patron.png");
    Mat tmp;
    Mat tmp2;

    cvtColor(src, tmp, CV_BGR2GRAY);
    GaussianBlur(tmp, tmp2, Size(5, 5), 5, 10);
    tmp = tmp2;

    Canny(tmp, tmp2, 200, 255, 3);
    tmp = tmp2;

    imshow("Test", tmp);

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    findContours(tmp, contours, 
                      hierarchy, 
                      CV_RETR_CCOMP, //CV_RETR_TREE, //CV_RETR_EXTERNAL, //CV_RETR_LIST 
                      CV_CHAIN_APPROX_SIMPLE, //CV_CHAIN_APPROX_TC89_KCOS, //CV_CHAIN_APPROX_TC89_L1, //CV_CHAIN_APPROX_NONE, 
                      Point(0, 0));

    double arrayMomentsHU[7];
    Moments mnts;

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

    waitKey(0);
}
