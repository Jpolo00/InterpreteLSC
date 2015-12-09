#include "Manager_File.h"

Manager_File::Manager_File(){}
Manager_File::~Manager_File(){}

void Manager_File::createFile(string name, 
                              string path, 
                              vector<string> data)
{
    string tmp = path + name;
    ofstream File (tmp.c_str(), ios_base::out);

    for (size_t i = 0; i < data.size(); i++)
    {
        File << data[i] << endl;
    }

    File.close();
}

vector<string> Manager_File::loadFile(string name, string path)
{
    string tmp = path + name;
    string line;
    int sizeVector = 1;

    ifstream File (tmp.c_str());
    if(! File.is_open())
    {
        cout << "File " << tmp << " no found..."<<endl;
    }

    data.resize(sizeVector);

    while (getline(File, line))
    {
        getline(File, line);
        if (line != "/")
        {
            data[sizeVector - 1] = line;
            sizeVector ++;
            data.resize(sizeVector);
        }
    }

    return data;
}