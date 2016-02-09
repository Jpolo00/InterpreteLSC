#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <vector>
#include <iostream>

#include <cv.h>
#include <opencv2/opencv.hpp>

#include <MODEL/Create_Patron.h>
#include <MODEL/PDI.h>

using namespace std;

class Patron {

	private:
		Create_Patron createPattern;
		PDI pdi;
		Mat tmp;
		vector<vector<Point> > contours;
        vector<vector<double> > momentsHu;

	public:
		Patron();
		~Patron();
		void addPattern(Mat img,int brithness, double contrast, double gamma);
		void setCharacter(string character);
		void create();

};

#endif