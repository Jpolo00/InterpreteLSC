#!/bin/bash
echo -e "\n\n\e[1;32mScript para compilar el Main"
echo -e "ya tiene todas las clases y carpetas incluidas"
echo -e "ademas del OpenCV"
echo -e "Creado por: Jp\e[0m"

rm -f app
 g++ -I/usr/local/include/opencv \
     -I/usr/local/include/opencv2 \
     -L/usr/local/lib/ \
     -g -o app  *.cpp  MODEL/*.cpp CONTROL/*.cpp VIEW/*.cpp \
                        -lopencv_core -lopencv_imgproc -lopencv_highgui \
                       -lopencv_ml -lopencv_video -lopencv_features2d \
                       -lopencv_calib3d -lopencv_objdetect -lopencv_contrib \
                       -lopencv_legacy -lopencv_stitching
 ./app
