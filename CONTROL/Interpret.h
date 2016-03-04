#ifndef INTERPRET_H
#define INTERPRET_H

#include <string>
#include <vector>
#include <iostream>

#include <cv.h>
#include <opencv2/opencv.hpp>

#include <MODEL/Clasificator.h>
#include <MODEL/PDI.h>

using namespace std;

class Interpret
{

    private:
        Clasificator clasificator;
        PDI pdi;
        Mat tmp;

        vector<double> dist;

        string character;

    public:
        Interpret();
        ~Interpret();
        void updatePattern();
        string interpretSing(Mat imgint, int brithness, 
                                       double contrast, 
                                       double gamma);
};

#endif