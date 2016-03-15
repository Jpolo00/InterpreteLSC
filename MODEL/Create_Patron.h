#ifndef CREATE_PATRON_H
#define CREATE_PATRON_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <math.h>

#include <MODEL/Manager_File.h>

using namespace std;

class Create_Patron
{
    private:
        string character;
        string file;
        ostringstream tostring;

        vector<double> distModel;
        vector<string> pattern;

        Manager_File manager;

    public:
        Create_Patron();
        ~Create_Patron();
        void setCharacter(string character);
        void addVector(vector<double> dist);
        void format();
        void createPatron();
};
#endif
