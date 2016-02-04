#include "Clasificator.h"

Clasificator::Clasificator()
{
    vector<string> filesPatron;
    vector<string> dataFiles;

    filesPatron = manager.loadFile("Load.conf", "MODEL/PATRONES/");

    for (size_t i = 0; i < filesPatron.size(); i++)
    {
        dataFiles = manager.loadFile(filesPatron[i], "MODEL/PATRONES/");
        momentosHu.resize(dataFiles.size());

        character.push_back(dataFiles[0]);

        for (size_t j = 1; j < dataFiles.size(); j++)
        {
            momentosHu[i].push_back(atof(dataFiles[j].c_str()));
        }
    }
}

Clasificator::~Clasificator(){}

// void Clasificator::distanciaEuclidiana(vector<double> caracteristicas, vector<double> modelo)
// {
//     double tmp = 0.0;
//     for (size_t i = 0; i < caracteristicas.size(); i++)
//     {
//         temp += pow(caracteristicas[i]- modelo[i],2);
//     }
//     distEuclidiana.push_back(sqrt(temp));
// }

// int Clasificator::distanciaMinima(vector<double> distancia){
// 	int posicion = 0;
// 	double distMinima = distancia[0];

// 	for (int i = 1; i < distancia.size(); i++){

// 		if (distMinima > distancia[i])
// 		{
// 			distMinima = distancia[i];
// 			posicion=i;
// 		}else{
// 			posicion=0;
// 		}
// 	}

// 	return posicion;
// }

// string Clasificator::getCaracter(vector<string> caracterPatron, int item){
// 	string letra = caracterPatron[item];
// 	return letra;
// }
