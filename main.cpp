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

    Mat img = imread("imgTest.png");
    PDI pdi(80, 1.2, 0.2);
    imshow("Original", img);
    imshow("Test", pdi.preImprovement(img));
    waitKey(0);
    return 0;
}