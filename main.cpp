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

#include <MODEL/Create_Patron.h>

using namespace std;

//int main(int argc, char const *argv[])
int main()
{
    cout << "CORRECT COMPILER & EXECUTE!!!!" << endl;
    //   +-----------------------------------------------+
    //   |Usa este main para todas las pruebas que decees|
    //   |puedes usar el Script_Execute_App.sh           |
    //   +-----------------------------------------------+

     VideoCapture cap(0);

     cap.set(CV_CAP_PROP_FRAME_WIDTH,320);
     cap.set(CV_CAP_PROP_FRAME_HEIGHT, 210);

     Mat img;

    // Interpret interpret;
     Patron c;
    // string tmp;

     namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

     int brithness = 255;
     int contrast = 300;
     int gamma = 100;
    // int sen = 70;

     cvCreateTrackbar("brithness", "Control", &brithness, 510);
     cvCreateTrackbar("contrast", "Control", &contrast, 1000);
     cvCreateTrackbar("gamma", "Control", &gamma, 500);
    // cvCreateTrackbar("sensibilidad", "Control", &sen, 1000);

     c.setCharacter("K");

    while (true)
    {
        cap >> img;

        imshow("Original", img);

        if(waitKey(1)== 32){
            c.addPattern(img, brithness, contrast, gamma);
            c.create();
        }

        else if(waitKey(1)==48){
            c.create();
            cout<<"crear"<<endl;
        }



        //tmp = "";
        //tmp = interpret.interpretSing(img, brithness, 
          //                                  contrast, 
            //                                gamma, 
              //                              sen / 7.0);
        //cout << tmp << endl;

        else if(waitKey(1) == 27)
        {
            break;
        }
    }
//-----------------------------------



//-----------------------------------
    // clock_t now, finish;
    // Mat img;
    // Mat tmp;

    // VideoCapture cap(0);

    // cap.set(CV_CAP_PROP_FRAME_WIDTH,320);
    // cap.set(CV_CAP_PROP_FRAME_HEIGHT, 210);

    // // PDI pdi(30, 1.0, 1.0);

    // namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

    // int brithness = 255;
    // int contrast = 300;
    // int gamma = 100;

    // cvCreateTrackbar("brithness", "Control", &brithness, 510);
    // cvCreateTrackbar("contrast", "Control", &contrast, 1000);
    // cvCreateTrackbar("gamma", "Control", &gamma, 500);

    // vector<vector<Point> > contours;
    // vector<vector<double> > momentsHu;

    // while (true)
    // {
    //     now = clock();

    //     cap >> img;

    //     pdi.setCaliber(brithness - 255, contrast / 300.0, gamma / 100.0);
    //     tmp = pdi.preImprovement(img);
    //     imshow("Test", tmp);

    //     tmp = pdi.convertColorSpace(tmp);
    //     contours.clear();
    //     contours = pdi.segmentation(tmp);

    //     momentsHu.clear();
    //     momentsHu = pdi.characteristic(contours);


    //     if(waitKey(1) >= 0)
    //     {
    //         break;
    //     }

    //     finish = clock();

    //     cout << "FPS:\t" << CLOCKS_PER_SEC / (finish - now) << endl;

    //     for (size_t i = 0; i < momentsHu.size(); i++)
    //     {
    //         cout << endl;
    //         cout << "Moment: " << i << endl;
    //         for (size_t j = 0; j < momentsHu[i].size(); j++)
    //         {
    //             cout << momentsHu[i][j] << endl;
    //         }
    //     }
    // }

    // vector<vector<double> > prueba(2);

    // prueba[0].push_back(2.0);
    // prueba[0].push_back(3.0);
    // prueba[0].push_back(4.0);
    // prueba[0].push_back(5.0);
    // prueba[0].push_back(6.0);
    // prueba[0].push_back(7.0);
    // prueba[0].push_back(12.0);

    // prueba[1].push_back(1.0);
    // prueba[1].push_back(1.0);
    // prueba[1].push_back(2.0);
    // prueba[1].push_back(1.0);
    // prueba[1].push_back(1.0);
    // prueba[1].push_back(2.0);
    // prueba[1].push_back(1.0);

    // Clasificator clasificator;

    // for (size_t i = 0; i < prueba.size(); i++)
    // {
    //     cout << clasificator.distanceMin(prueba[i], 7.0) << endl;
    // }

    return 0;
}