#ifndef PDI_H
#define PDI_H

#include <string>
#include <vector>

using namespace std;

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