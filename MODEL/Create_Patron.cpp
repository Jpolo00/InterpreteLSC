#include "Create_Patron.h"

Create_Patron::Create_Patron(int numV, string letra)
	this->numVectors=numVectors;
	this->letter=letter;
}
Create_Patron::~Create_Patron(){}


void Create_Patron::addVectors(vector<double> patron)
{
   sinNombre.push_back(patron);
}

void Create_Patron::createPattern()
{
	double temp=0.0;
	for(int i=0; i<7; i++){
		for(int j=0; j<sinNombre.size(); j++){
			temp += sinNombre[j][i];
		}
		int aux= temp/sinNombre.size();
		patron.push_back(aux);
		temp=0.0;
	}
}
