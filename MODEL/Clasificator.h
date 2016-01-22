#ifndef CLASIFICATOR_H
#define CLASIFICATOR_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

class Clasificator
{
	private:
			
			vector<double> distEuclidiana;
			
			

	public:
		Clasificator();
        ~Clasificator();

        int distanciaMinima(vector<double> distancia);
        string getCaracter(vector<string> caracterPatron, int item);
        void distanciaEuclidiana(vector<double> caracteristicas, vetor<double> modelo);

};

#endif