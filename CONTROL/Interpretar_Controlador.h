#ifndef INTERPRETAR_CONROLADOR_H
#define INTERPRETAR_cLASIFICADOR_H

#include <string>
#include <vector>
#include <iostream>

#include <cv.h>
#include <opencv2/opencv.hpp>

#include <MODEL/Clasificator.h>
#include <MODEL/PDI.h>

using namespace std;

class Interpretar_Controlador
{

    private:
        Clasificator clasificator;
        PDI pdi;
        Mat tmp;

        vector<vector<Point> > contours;
        vector<vector<double> > momentsHu;

        string character;

    public:
        Interpretar_Controlador();
        ~Interpretar_Controlador();
        string interpretar(Mat imgint, int brithness, 
                                       double contrast, 
                                       double gamma, 
                                       double alpha);
};

#endif