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
        vector<vector<double> > dist;
        vector<double> euclideanDist;
        double tmp;

        Manager_File manager;

        void distanceEuclidean(vector<double> characteristic);

    public:
        Clasificator();
        ~Clasificator();
        void loadPatterns();
        string distanceMin(vector<double> characteristic);
};

#endif