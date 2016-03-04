#include <MODEL/Clasificator.h>

Clasificator::Clasificator() {}
Clasificator::~Clasificator() {}

void Clasificator::loadPatterns()
{
    vector<string> filesPatron;
    vector<string> dataFiles;

    filesPatron = manager.loadFile("Load.conf", "MODEL/PATRONES/");

    for (size_t i = 0; i < filesPatron.size(); i++)
    {
        dist.resize(filesPatron.size());
        dataFiles = manager.loadFile(filesPatron[i], "MODEL/PATRONES/");

        character.push_back(dataFiles[0]);

        for (size_t j = 1; j < dataFiles.size(); j++)
        {
            dist[i].push_back(atof(dataFiles[j].c_str()));
        }
    }
}

void Clasificator::distanceEuclidean(vector<double> characteristic)
{
    euclideanDist.clear();

    size_t sizeVector = 0;
    size_t sizeCaracter = 0;

    sizeCaracter = characteristic.size();

    for (size_t i = 0; i < dist.size(); i++)
    {
        tmp = 0.0;
        sizeVector = dist[i].size();

        if (sizeVector > sizeCaracter)
        {
            for (size_t j = 0;  j < (sizeVector - sizeCaracter); j++)
            {
                characteristic.push_back(0.0);
            }
        }
        else
        {
            for (size_t j = 0;  j < (sizeCaracter - sizeVector); j++)
            {
                dist[i].push_back(0.0);
            }
        }

        for (size_t j = 0; j < dist[i].size(); j++)
        {
            tmp += pow(characteristic[j]- dist[i][j], 2);
        }

        euclideanDist.push_back(sqrt(tmp));
    }
}

string Clasificator::distanceMin(vector<double> characteristic)
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

    for (size_t i = 0; i < euclideanDist.size(); i++)
    {
        cout <<character[i]<<"\t"<<euclideanDist[i] << endl;
    }

    answer = character[index];

    return answer;
}