//Librerias Nativas
#include <iostream>
#include <string>
#include <vector>

//Otras Librerias
#include <cv.h>
#include <opencv2/opencv.hpp>

#include "MODEL/Clasificator.h"
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



    // Mat src = imread("patron.png");
    // Mat tmpA;
    // Mat tmpA2;
    // cvtColor(src, tmpA, CV_RGB2GRAY);
    // GaussianBlur(tmpA, tmpA2, Size(5, 5), 5, 10);
    // tmpA = tmpA2;

    // Canny(tmpA, tmpA2, 200, 255, 3);
    // tmpA = tmpA2;

    // imshow("TestA", tmpA);

    // vector<vector<Point> > contoursA;
    // vector<Vec4i> hierarchyA;

    // findContours(tmpA, contoursA, 
    //                   hierarchyA, 
    //                   CV_RETR_CCOMP, //CV_RETR_TREE, //CV_RETR_EXTERNAL, //CV_RETR_LIST 
    //                   CV_CHAIN_APPROX_SIMPLE, //CV_CHAIN_APPROX_TC89_KCOS, //CV_CHAIN_APPROX_TC89_L1, //CV_CHAIN_APPROX_NONE, 
    //                   Point(0, 0));
    // while(true)
    // {#include "MODEL/Manager_File.h"
    //     now = clock();

    //     cap >> img;
    //     //imshow("Original", img);

    //     pdi.setCaliber(brithness - 255, contrast / 300.0, gamma / 100.0);
    //     tmp =  pdi.preImprovement(img);
    //     imshow("preImprovement", tmp);

    //     tmp = pdi.convertColorSpace(tmp);
    //     tmp =  pdi.secImprovement(tmp);

    //     tmp = pdi.segmentation(tmp, contoursA);
    //     imshow("Test", tmp);

    //     if(waitKey(1) >= 0)
    //     {
    //         break;
    //     }

    //     finish = clock();

    //     cout << "FPS:\t" << CLOCKS_PER_SEC / (finish - now) << endl;
    // }

    Clasificator clasificador;

    return 0;
}