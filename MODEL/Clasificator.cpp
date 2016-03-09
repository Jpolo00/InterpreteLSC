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
        model.resize(filesPatron.size());
        dataFiles = manager.loadFile(filesPatron[i], "MODEL/PATRONES/");

        character.push_back(dataFiles[0]);

        for (size_t j = 1; j < dataFiles.size(); j++)
        {
            model[i].push_back(atof(dataFiles[j].c_str()));
        }
    }
}

double Clasificator::distanceEuclidean(double num1, double num2)
{
    return sqrt(pow(num1 - num2, 2));
}

string Clasificator::dtw(vector<double> characteristic)
{
    string answer = "No Found";
    size_t n = characteristic.size();
    size_t modelSize = model.size();
    double index[model.size()];

    for (size_t k = 0; k < modelSize; k++)
    {
        distModel = model[k];
        size_t m = distModel.size();

        double cost[m][n];
        cost[0][0] = distanceEuclidean(distModel[0], characteristic[0]);

        for(size_t i = 1; i < m; i++)
        {
            cost[i][0] = cost[i-1][0] + distanceEuclidean(distModel[i], 
                                                          characteristic[0]);
        }

        for(size_t j = 1; j < n; j++)
        {
            cost[0][j] = cost[0][j-1] + distanceEuclidean(distModel[0], 
                                                          characteristic[j]);
        }

        for(size_t i = 1; i < m; i++)
        {
            for(size_t j = 1; j < n; j++)
            {
                cost[i][j] = min(cost[i-1][j], min(cost[i][j-1], cost[i-1][j-1])) 
                             + distanceEuclidean(distModel[i],characteristic[j]);
            }
        }

        index[k] = cost[m-1][n-1];
    }

    double min = index[0];
    size_t item = 0;
    for (size_t i = 0; i < modelSize; i++)
    {
        if (min >= index[i])
        {
            min = index[i];
            item = i;
        }
    }

    answer = character[item];

    return answer;
}