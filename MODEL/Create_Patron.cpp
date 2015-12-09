#include "Create_Patron.h"

Create_Patron::Create_Patron(){}
Create_Patron::~Create_Patron(){}

void Create_Patron::setNumVectors(int num)
{
    numVectors=num;   
}

void Create_Patron::addVectors(vector<double> patron)
{
   vectors.push_back(patron);
}

void Create_Patron::createPattern()
{

}
