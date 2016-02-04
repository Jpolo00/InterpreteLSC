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
        vector<vector<double> > momentosHu;
        vector<string> character;
        vector<double> distEuclidiana;

        Manager_File manager;

    public:
        Clasificator();
        ~Clasificator();
        // int distanciaMinima(vector<double> distancia);
        // string getCaracter(vector<string> caracterPatron, int item);
        // void distanciaEuclidiana(vector<double> caracteristicas, vector<double> modelo);
};

#endif