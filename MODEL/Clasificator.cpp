//Comentado porque no me dejo compilar :3, perdon Kelly :3
/*#include "Clasificator.h"

Clasificator::Clasificator(){}
Clasificator::~Clasificator(){}

void Clasificator::distanciaEuclidiana(vector<double> caracteristicas, vector<double> modelo){
		
		double temp=0.0;
		for (int i = 0; i < caracteristicas.size(); i++)
		{	
			temp += pow(caracteristicas[i]- modelo[i],2);
			
		}
		distEuclidiana.push_back(sqrt(temp));
}

int Clasificator::distanciaMinima(vector<double> distancia){
	int posicion = 0;
	double distMinima = distancia[0];

	for (int i = 1; i < distancia.size(); i++){

		if (distMinima > distancia[i])
		{
			distMinima = distancia[i];
			posicion=i;
		}else{
			posicion=0;
		}
	}

	return posicion;
}

string Clasificator::getCaracter(vector<string> caracterPatron, int item){
	string letra = caracterPatron[item];
	return letra;
} */