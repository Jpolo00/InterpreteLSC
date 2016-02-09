#ifndef MANAGER_FILE_H
#define MANAGER_FILE_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Manager_File
{
    private:
        string path;
        vector<string> data;

    public:
        Manager_File();
        ~Manager_File();

        void createFile(string name, 
                        string path, 
                        vector<string> data);

        void addNewPattern(string character);

        vector<string> loadFile(string name, string path);
};
#endif