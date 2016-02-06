#ifndef CLASIFICATOR_H
#define CLASIFICATOR_H

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>

#include "Manager_File.h"

using namespace std;

class Clasificator
{
    private:
        vector<vector<double> > momentsHu;
        vector<string> character;
        vector<double> euclideanDist;
        double tmp;

        Manager_File manager;

        void distanceEuclidean(vector<vector<double> > characteristic);

    public:
        Clasificator();
        ~Clasificator();
        string distanceMin(vector<vector<double> > characteristic, 
                           double threshold);
};

#endif