//Librerias Nativas
#include <iostream>
#include <string>
#include <vector>

//Otras Librerias
#include <cv.h>
#include <opencv2/opencv.hpp>

//Nuestras Librerias

#include <CONTROL/Interpret.h>
#include <CONTROL/Patron.h>

using namespace std;

//int main(int argc, char const *argv[])
int main()
{
    cout << "CORRECT COMPILER & EXECUTE!!!!" << endl;
    //   +-----------------------------------------------+
    //   |Usa este main para todas las pruebas que decees|
    //   |puedes usar el Script_Execute_App.sh           |
    //   +-----------------------------------------------+

    VideoCapture cap(1);

    cap.set(CV_CAP_PROP_FRAME_WIDTH,320);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 210);

    Mat img;

    Interpret interpret;
    Patron c;
    string tmp;
    string charter = "";

     namedWindow("Control", CV_WINDOW_AUTOSIZE);

    int brithness = 255;
    int contrast = 300;
    int gamma = 100;
    int sen = 70;

    brithness = 255;
    contrast = 588;
    gamma = 434;
    sen = 70;

    cvCreateTrackbar("brithness", "Control", &brithness, 510);
    cvCreateTrackbar("contrast", "Control", &contrast, 1000);
    cvCreateTrackbar("gamma", "Control", &gamma, 500);
    cvCreateTrackbar("sensibilidad", "Control", &sen, 1000);

    bool t = true;

    //img = imread("patron.jpg");

    interpret.updatePattern();

    while (t)
    {
        cap >> img;

        imshow("Original", img);
        c.drawContour(img, brithness, contrast, gamma);

        tmp = "";

        switch(waitKey(1))
        {
            case 48:
            {
                cout << "Esperando letra" << endl;
                cin >> charter;
                c.setCharacter(charter);
                break;
            }
            case 65:
            case 97:
            {
                c.create();
                interpret.updatePattern();
                break;
            }
            case 71:
            case 103:
            {
                tmp = interpret.interpretSing(img, brithness, 
                                              contrast, 
                                              gamma, 
                                              sen / 7.0);
                cout << tmp << endl;
                break;
            }
            case 32:
            {
                c.addPattern();
                break;
            }
            case 27:
            {
                t = false;
                break;
            }
        }
    }

    return 0;
}