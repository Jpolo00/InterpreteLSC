#include <MODEL/Create_Patron.h>

Create_Patron::Create_Patron() {}
Create_Patron::~Create_Patron() {}

void Create_Patron::addVector(vector<double> dist)
{
    distModel.clear();
    distModel = dist;
    cout << "Agregado" << endl;
}

void Create_Patron::setCharacter(string character)
{
    this->character = character;
}

void Create_Patron::format()
{
    double tmp = 0.0;
    pattern.clear();
    pattern.push_back(character);

    for (size_t i = 0; i < distModel.size(); i++)
    {
        tmp = distModel[i];
        tostring << tmp;
        pattern.push_back(tostring.str());
        tostring.str("");
    }

    distModel.clear();
}

void Create_Patron::createPatron()
{
    size_t i = 0;
    tostring.str("");
    tostring << i;
    string file = character + tostring.str();
    while (manager.checkFile("MODEL/PATRONES/"+file+".patron"))
    {
        i++;
        tostring.str("");
        tostring << i;
        file = character + tostring.str();
    }

    manager.createFile(file+".patron", "MODEL/PATRONES/", pattern);
    manager.addNewPattern(file+".patron");
}
