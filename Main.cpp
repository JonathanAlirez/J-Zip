#include <iostream>
#include <vector>
#include <string>
#include "ReadWriteZip.h"
#include "DecodeZip.h"

using namespace std;

int main(int argc, char*argv[])
{
	// get the cmd args
    if (argc == 1)
        cout << "Error, no input file detected..." << endl;
    else if (argc > 2)
        cout << "Error, to many arguments..." << endl;
    else
    {
		// set fileName to the arg sent in
        string fileName = argv[1];
		// afterDot is what is after . such as foo.txt, would be txt
        string afterDot;
        string arg1(argv[1]);
        bool afDot = false;
		// loop through the cmd arg to get the string after dot, do what needs to be done
        for (int i(0); i < arg1.length(); i++)
        {
            if (afDot == true)
                afterDot += arg1[i];
            if (arg1[i] == '.')
                afDot = true;
        }
		// if jzip, decode, any other extension, zip it
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
