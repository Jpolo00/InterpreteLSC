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
        vectors <vector<double>>;

    public:
        Create_Patron();
        ~Create_Patron();

        void setNumVectors(int num);
        void addVectors(vector<double> patron);
        void createPattern();
};
#endif
