#ifndef CLASIFICATOR_H
#define CLASIFICATOR_H

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>

#include <MODEL/Manager_File.h>

using namespace std;

class Clasificator
{
    private:
        vector<string> character;
        vector<vector<double> > model;
        vector<double> distModel;
        double tmp;

        Manager_File manager;

        double distanceEuclidean(double num1, double num2);

    public:
        Clasificator();
        ~Clasificator();
        void loadPatterns();
        string dtw(vector<double> characteristic);
};

#endif