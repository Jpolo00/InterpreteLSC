#include <MODEL/Create_Patron.h>

Create_Patron::Create_Patron() {}
Create_Patron::~Create_Patron() {}

void Create_Patron::addVector(vector<double> moment)
{
    momentsHu.push_back(moment);
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

    for (size_t j = 0; j < momentsHu[0].size(); j++)
    {
        tmp = 0.0;

        for (size_t i = 0; i < momentsHu.size(); i++)
        {
            tmp += momentsHu[i][j] / (momentsHu[i].size() * 1.0);
        }

        tostring << tmp;

        pattern.push_back(tostring.str());

        tostring.str("");
    }

    momentsHu.clear();
}

void Create_Patron::createPatron()
{
    manager.createFile(character+".patron", "MODEL/PATRONES/", pattern);
    manager.addNewPattern(character+".patron");
}
