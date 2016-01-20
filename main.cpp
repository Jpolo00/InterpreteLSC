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

//int main(int argc, char const *argv[])
int main()
{
    //   +-----------------------------------------------+
    //   |Usa este main para todas las pruebas que decees|
    //   |puedes usar el Script_Execute_App.sh           |
    //   +-----------------------------------------------+
    clock_t now, finish;
    Mat img;
    Mat tmp;
    
    VideoCapture cap(0);

    cap.set(CV_CAP_PROP_FRAME_WIDTH,320);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 210);

    PDI pdi(30, 1.0, 1.0);


    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

    int brithness = 255;
    int contrast = 300;
    int gamma = 100;
    //Create trackbars in "Control" window
    cvCreateTrackbar("brithness", "Control", &brithness, 510);
    cvCreateTrackbar("contrast", "Control", &contrast, 1000);
    cvCreateTrackbar("gamma", "Control", &gamma, 500);

    while(true)
    {
        now = clock();

        cap >> img;
        imshow("Original", img);

        pdi.setCaliber(brithness - 255, contrast / 300.0, gamma / 100.0);
        tmp =  pdi.preImprovement(img);
        imshow("preImprovement", tmp);

        tmp = pdi.convertColorSpace(tmp);
        tmp =  pdi.secImprovement(tmp);

        tmp = pdi.segmentation(tmp);
        //imshow("Test", tmp);

        if(waitKey(1) >= 0)
        {
            break;
        }

        finish = clock();

        //cout << "FPS:\t" << CLOCKS_PER_SEC / (finish - now) << endl;
    }

    return 0;
}