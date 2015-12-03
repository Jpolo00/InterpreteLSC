#include <iostream>
#include <string>
#include <vector>

#include "MODEL/Manager_File.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "All alright" << endl;

    Manager_File managerFile;

    vector<string> data(5);
    data[0] = "Hola";
    data[1] = "1";
    data[2] = "2";
    data[3] = "4";
    data[4] = "5.334";

    managerFile.createFile("prueba.txt", "Prueba/", data);
    cout << managerFile.loadFile("prueba.txt", "Prueba/")[0] << endl;
    return 0;
}