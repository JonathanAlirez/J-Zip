#include <iostream>
#include <vector>
#include <string>
#include "ReadWriteZip.h"
#include "DecodeZip.h"

using namespace std;

int main(int argc, char*argv[])
{
    if (argc == 1)
        cout << "Error, no input file detected..." << endl;
    else if (argc > 2)
        cout << "Error, to many arguments..." << endl;
    else
    {
        string fileName = argv[1];
        string afterDot;
        string arg1(argv[1]);
        bool afDot = false;
        for (int i(0); i < arg1.length(); i++)
        {
            if (afDot == true)
                afterDot += arg1[i];
            if (arg1[i] == '.')
                afDot = true;
        }
        if (afterDot != "jzip")
        {
            readFileToZip(fileName);
            writeFileToZip(fileName);
        } else {
            decodeZip(fileName);
        }
    }
    return 0;
}
