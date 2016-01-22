#include "clasificator.h"

clasificator::clasificator(){}
clasificator::~clasificator(){}

void Clasificator::distanciaEuclidiana(vector<double> caracteristicas, vetor<double> modelo){
		
		double temp=0.0;
		for (int i = 0; i < caracteristicas.size(); i++)
		{	
			temp += pow(caracteristicas[i]-modelo[i],2);
			
		}
		distEuclidiana.push_back(sqrt(temp));
}

int Clasificator::distanciaMinima(vector<double> distancia){
	int posicion = 0;
	double distMinima = distancia[0];

	for (int i = 1; i < distancia.size(); i++){

		if (distMinima>distancia[i])
		{
			distMinima=distancia[i];
			posicion=i;
		}else{
			posicion=0;
		}
	}

	return posicion;
}

String Clasificator::getCaracter(vector<string> caracterPatron, int item){
	string letra = caracterPatron[item];
	return letra;
} 