#ifndef INTERPRETAR_CONROLADOR_H
#define INTERPRETAR_cLASIFICADOR_H

#include <Clasificator.h>
#include <PDI.h>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Interpretar_Controlador
{

private:
	int item;
	vector<vector<double> patternLetters;
	vector<string> characters;
	vector<double> pattern;
	Clasificator clasificador;
	PDI pdi;

public:
	Interpretar_Controlador();
	~Interpretar_Controlador();
	void cargarAbecedario(string path);
	void setPattern(Mat img);
	void calcularDistancia(vector<double> pattern);
	string retornarLetra();
	
};

#endif