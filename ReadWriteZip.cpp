#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Encoding.h"

using namespace std;

vector<Encoding> occWords;

void readFileToZip(string fileName)
{
    string line;
    ifstream file (fileName.c_str());
    if (file.is_open())
    {
        while (getline(file, line))
        {
            string buffer;
            stringstream ss(line);
            vector<string> tokens;
            while (ss >> buffer)
                tokens.push_back(buffer);
            for (int i = 0; i < tokens.size(); i++)
            {
                bool added = false;
                if (i > 0)
                {
                    for (int j = 0; j < occWords.size(); j++)
                    {
                        if (occWords.at(j).getWord().compare(tokens[i]) == 0)
                        {
                            occWords.at(j).setCount(occWords.at(j).getCount() + 1);
                            added = true;
                            break;
                        }
                    }
                    if (added == false)
                    {
                        occWords.push_back(Encoding(tokens[i], 1));
                    }
                }
                else {
                    string temp = tokens[i];
                    occWords.push_back(Encoding(temp, 1));
                }
            }
        }
        file.close();
        sort(occWords.begin(), occWords.end());
    }
    else
        cout << "Error, cannot open file" << endl;
}

void writeFileToZip(string fileName)
{
    string newFileName = fileName.substr(0, fileName.size() - 4);
    string tempFile = newFileName + ".jzip";
    ofstream file(tempFile.c_str());
    ifstream fileRead(fileName.c_str());
    string line;
    vector<Encoding> encodeList;
    if (fileRead.is_open())
    {
         for (int i = 0; i < occWords.size(); i++)
            {
                if (occWords.at(i).getCount() > 1)
                {
                  encodeList.push_back(Encoding(occWords.at(i).getWord(),i));
                  file << occWords.at(i).getWord() << " " << i << endl;
                }
            }
        while ( getline(fileRead,line))
        {
            file << "\n";
            if (file.is_open())
            {
                string buffer;
                stringstream ss(line);
                vector<string> tokens;
                while (ss >> buffer)
                    tokens.push_back(buffer);
                for (int i = 0; i < tokens.size(); i++)
                {
                    bool changed = false;
                    for (int j = 0; j < encodeList.size(); j++)
                    {
                        if (encodeList.at(j).getWord().compare(tokens[i]) == 0)
                        {
                            file << encodeList.at(j).getCount() << " ";
                            changed = true;
                            break;
                        }
                    }
                    if (changed == false)
                    {
                        file << tokens[i] << " ";
                    }
                }
            }
        }
    } else
        cout << "Error couldn't open file." <<endl;
}
