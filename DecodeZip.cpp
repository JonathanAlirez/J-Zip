#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Encoding.h"

using namespace std;

vector<Encoding> wordPairs;

void decodeZip(string name)
{
    string line;
    ifstream file (name.c_str());
    if (file.is_open())
    {
        bool beforeText = true;
        //bool changed = false;
        string newFile = name.substr(0, name.size() - 5);
        string temp = newFile + ".txt";
        ofstream writeFile(temp.c_str());
        int firstLine = 0;
        while (getline(file, line))
        {
            if (line == "")
                beforeText = false;
            if (beforeText == true)
            {
                string buffer;
                stringstream ss(line);
                vector<string> tokens;
                while (ss >> buffer)
                    tokens.push_back(buffer);
                wordPairs.push_back(Encoding(tokens[0], atoi(tokens[1].c_str())));
            } else {
                if (line != "")
                {
                    string buffer;
                    stringstream ss(line);
                    vector<string> tokens;
                    while (ss >> buffer) {
                        tokens.push_back(buffer);
                    }
                    int i = 0;
                     if (firstLine == 0)
                         firstLine++;
                     else
                        writeFile << "\n";
                    while (i < tokens.size())
                    {
                        if (writeFile.is_open())
                        {
                            try {
                                int x = atoi(tokens[i].c_str());
                                if (x == 0 && tokens[i] != "0") {
                                    writeFile << tokens[i] << " ";
                                }
                                else {
                                    writeFile << wordPairs.at(x).getWord() << " ";
                                }
                            } catch (int e) {
                                cout << "ERROR: " << e << endl;
                            }
                            i++;
                        }
                    }
                }
            }
        }
    }
}
