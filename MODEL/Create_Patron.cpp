#include <MODEL/Create_Patron.h>

Create_Patron::Create_Patron() {}
Create_Patron::~Create_Patron() {}

void Create_Patron::addVector(vector<double> dist)
{
    distAll.push_back(dist);
    cout << "Agregado" << endl;
}

void Create_Patron::setCharacter(string character)
{
    this->character = character;
}

void Create_Patron::average()
{
    double tmp = 0.0;
    pattern.clear();
    pattern.push_back(character);

    for (size_t i = 0; i < distAll[0].size(); i++)
    {
        tmp = distAll[0][i];
        tostring << tmp;
        pattern.push_back(tostring.str());
        tostring.str("");

    }

    distAll.clear();
}

void Create_Patron::createPatron()
{
    manager.createFile(character+".patron", "MODEL/PATRONES/", pattern);
    manager.addNewPattern(character+".patron");
}
