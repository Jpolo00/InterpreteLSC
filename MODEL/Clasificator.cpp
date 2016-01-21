#include "clasificator.h"

clasificator::clasificator(){}
clasificator::~clasificator(){}

void clasificator::distanciaEuclidiana(vector<double> caracteristicas, vetor<double> modelo){
		
		double temp=0.0;
		for (int i = 0; i < caracteristicas.size(); i++)
		{	
			temp += pow(caracteristicas[i]-modelo[i],2);
			
		}
		distEuclidiana.push_back(sqrt(temp));
}