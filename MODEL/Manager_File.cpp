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

    ifstream File (tmp.c_str());

    if(! File.is_open())
    {
        cout << "File " << tmp << " no found..."<<endl;
    }

    data.clear();

    while (getline(File, line))
    {
        data.push_back(line);
    }

    return data;
}