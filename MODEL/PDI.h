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
        double angle;
        double m;

        vector<double> dist;

        vector<vector<Point> > contours;
        vector<Vec4i> hierarchy;
        vector<Point> point;
        vector<Point2f> rectPoint;

        Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
        Mat tmp;
        Mat tmp2;
        Mat segmentation;
        Mat rot;

        vector<size_t> itemX;
        vector<size_t> itemY;

        vector<double> pointX;
        vector<double> pointY;

        Point pointCut1;
        Point pointCut2;

    public:
        PDI();
        PDI(int brightness,
            double contrast,
            double gamma);

        ~PDI();

        void setCaliber(int brightness,
                        double contrast,
                        double gamma);

        Mat preImprovement(Mat img);
        Mat rotImg(Mat img, Point2f center, double angle);
        Mat cutImg(Mat img, Point p1, Point p2);

        void swapDataVector(vector<size_t> item, vector<Point> point);
        void setContours(Mat img);
        
        double distPoint(Point p1, Point p2);
        double slope(Point p1, Point p2);
        double distPerpendicular(Point p1, Point p2, double m);
        double angle2Line(Point p1, double m1, Point p2, double m2);

        vector<size_t> orderVector(vector<double> data);
        vector<Point> filterContours(double threshold);
        vector<Vec4i> getHierarchy();
        vector<Point2f> rectImg(vector<Point> point);
        vector<vector<Point> > getContours();
        vector<double> getDist();
};
#endif