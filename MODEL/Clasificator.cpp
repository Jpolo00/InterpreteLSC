#include "Clasificator.h"

Clasificator::Clasificator()
{
    vector<string> filesPatron;
    vector<string> dataFiles;

    filesPatron = manager.loadFile("Load.conf", "MODEL/PATRONES/");

    for (size_t i = 0; i < filesPatron.size(); i++)
    {
        momentsHu.resize(filesPatron.size());
        dataFiles = manager.loadFile(filesPatron[i], "MODEL/PATRONES/");

        character.push_back(dataFiles[0]);

        for (size_t j = 1; j < dataFiles.size(); j++)
        {
            momentsHu[i].push_back(atof(dataFiles[j].c_str()));
        }
    }
}

Clasificator::~Clasificator(){}

void Clasificator::distanceEuclidean(vector<vector<double> > characteristic)
{
    euclideanDist.clear();

    for (size_t k = 0; k < characteristic.size(); k++)
    {
        for (size_t i = 0; i < momentsHu.size(); i++)
        {
            tmp = 0.0;

            for (size_t j = 0; j < momentsHu[i].size(); j++)
            {
                tmp += pow(characteristic[k][j]- momentsHu[i][j], 2);
            }
            euclideanDist.push_back(sqrt(tmp));
        }
    }
}

string Clasificator::distanceMin(vector<vector<double> > characteristic, 
                                 double threshold)
{
    distanceEuclidean(characteristic);

    tmp = euclideanDist[0];
    size_t index = 0;
    string answer = "No Found";

    for (size_t i = 1; i < euclideanDist.size(); i++)
    {
        if (tmp > euclideanDist[i])
        {
            tmp = euclideanDist[i];
            index = i;
        }
    }

    if (euclideanDist[index] <= threshold)
    {
        answer = character[index];
    }

    return answer;
}