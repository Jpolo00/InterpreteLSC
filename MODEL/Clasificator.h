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
        vector<vector<double> > momentsHu;
        vector<double> euclideanDist;
        double tmp;

        Manager_File manager;

        void distanceEuclidean(vector<double> characteristic);

    public:
        Clasificator();
        ~Clasificator();
        string distanceMin(vector<double> characteristic, 
                           double threshold);
};

#endif