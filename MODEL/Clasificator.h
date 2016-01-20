#ifndef CLASIFICATOR_H
#define CLASIFICATOR_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Clasificator
{
	private:
			Manager_File manager;
			vector<string> patron;

	public:
		Clasificator();
        ~Clasificator();

        int distanciaMinima(vector<double> distancia);
        string getCaracter(vector<string> caracterPatron, int item);
        vector<double> distanciaEuclidiana(vector<double> caracteristicas, vetor<double> modelo);

};

#endif