#ifndef CREATE_PATRON_H
#define CREATE_PATRON_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Create_Patron
{
    private:
        int numVectors;
        string letter;
        vector<vector<double> > sinNombre;
        vector<double> patron;

    public:
        Create_Patron(int numVectors, string letter);
        ~Create_Patron();

        void addVectors(vector<double> patron);
        void createPattern();
};
#endif
