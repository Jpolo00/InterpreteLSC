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

    Mat img = imread("imgTest.jpg");
    imshow("Original", img);

    Mat tmp;

    PDI pdi(30, 1.0, 1.0);

    tmp =  pdi.preImprovement(img);
    imshow("Test", tmp);

    vector<double> array = pdi.characteristic(tmp);
    cout << array[1] << endl;

    waitKey(0);
    return 0;
}