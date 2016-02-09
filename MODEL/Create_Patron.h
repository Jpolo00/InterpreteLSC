#ifndef CREATE_PATRON_H
#define CREATE_PATRON_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include <MODEL/Manager_File.h>

using namespace std;

class Create_Patron
{
    private:
        string character;
         ostringstream tostring;

        vector<vector<double> > momentsHu;
        vector<string> pattern;

        Manager_File manager;

    public:
        Create_Patron();
        ~Create_Patron();
        void setCharacter(string character);
        void addVector(vector<double> moments);
        void average();
        void createPatron();
};
#endif
