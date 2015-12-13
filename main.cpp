//Librerias Nativas
#include <iostream>
#include <string>
#include <vector>

//Otras Librerias
#include <cv.h>
#include <opencv2/opencv.hpp>

#include "MODEL/Manager_File.h"
#include "MODEL/PDI.h"

using namespace std;

int main(int argc, char const *argv[])
{
    //   +-----------------------------------------------+
    //   |Usa este main para todas las pruebas que decees|
    //   |puedes usar el Script_Execute_App.sh           |
    //   +-----------------------------------------------+

    Mat img = imread("test.jpg");
    imshow("Original", img);

    Mat tmp;

    PDI pdi(30, 1.0, 1.0);

    tmp =  pdi.preImprovement(img);
    imshow("Test", tmp);

    tmp = pdi.convertColorSpace(tmp);
    tmp =  pdi.secImprovement(tmp);

    imshow("Test2", tmp);
    tmp = pdi.segmentation(tmp);
    imshow("Test3", tmp);

    waitKey(0);
    return 0;
}