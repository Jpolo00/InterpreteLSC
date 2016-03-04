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
// #include <MODEL/PDI.h>

using namespace std;

int main()
{
    cout << "CORRECT COMPILER & EXECUTE!!!!" << endl;

    VideoCapture cap(0);

    cap.set(CV_CAP_PROP_FRAME_WIDTH,320);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 210);

    int brithness = 255;
    int contrast = 300;
    int gamma = 100;

    namedWindow("Control", CV_WINDOW_AUTOSIZE);
    cvCreateTrackbar("brithness", "Control", &brithness, 510);
    cvCreateTrackbar("contrast", "Control", &contrast, 1000);
    cvCreateTrackbar("gamma", "Control", &gamma, 1000);

    Mat img;
    bool t = true;

    Interpret interpret;
    Patron patron;
    string tmp;
    string charater = "";

    interpret.updatePattern();

    while (t)
    {
        cap >> img;
        tmp = "";

        patron.setImg(img, brithness, contrast, gamma);

        switch(waitKey(10))
        {
            case 48:
            {
                cout << "Esperando letra" << endl;
                cin >> charater;
                patron.setCharacter(charater);
                break;
            }
            case 65:
            case 97:
            {
                patron.create();
                interpret.updatePattern();
                break;
            }
            case 71:
            case 103:
            {
                tmp = interpret.interpretSing(img, brithness, 
                                                   contrast, 
                                                   gamma);
                cout << tmp << endl;
                break;
            }
            case 32:
            {
                patron.addPattern();
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