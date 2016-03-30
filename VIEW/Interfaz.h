#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <cstdlib> 

#include <cv.h>
#include <opencv2/opencv.hpp>

#include <CONTROL/Interpret.h>
#include <CONTROL/Patron.h>

using namespace std;
using namespace cv;

class Interfaz
{
    private:
        int brithness;
        int contrast;
        int gamma;

        string selection;

        VideoCapture cap;
        Interpret interpret;
        Patron patron;
    public:
        Interfaz();
        ~Interfaz();
        void vistaPrincipal();
        void vistaInterpretar();
        void vistaAgregar();
};
#endif
