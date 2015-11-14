#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Encoding.h"

using namespace std;

// vector of the word pairs, Word, Count
vector<Encoding> wordPairs;

// function to decode the existing zip file
void decodeZip(string name)
{
	// read in the file given
    string line;
    ifstream file (name.c_str());
    if (file.is_open())
    {
		// get rid of jzip and make it a .txt file
        bool beforeText = true;
        string newFile = name.substr(0, name.size() - 5);
        string temp = newFile + ".txt";
        ofstream writeFile(temp.c_str());
        int firstLine = 0;
		// loop through the top part, with Word + i value
        while (getline(file, line))
        {
			// blank line
            if (line == "")
                beforeText = false;
			// make a vector of tokens, push into the word pairs, the values to change latter
            if (beforeText == true)
            {
                string buffer;
                stringstream ss(line);
                vector<string> tokens;
                while (ss >> buffer)
                    tokens.push_back(buffer);
				// making the wordPairs
                wordPairs.push_back(Encoding(tokens[0], atoi(tokens[1].c_str())));
            } else {
                if (line != "")
                {
					// making more tokens
                    string buffer;
                    stringstream ss(line);
                    vector<string> tokens;
                    while (ss >> buffer) {
                        tokens.push_back(buffer);
                    }
					// if first line do nothing
                    int i = 0;
                     if (firstLine == 0)
                         firstLine++;
                     else
                        writeFile << "\n";
					// i < all tokens, read from buffer
                    while (i < tokens.size())
                    {
                        if (writeFile.is_open())
                        {
                            try {
                                int x = atoi(tokens[i].c_str());
								// if tokens and x are 0, write the 0
                                if (x == 0 && tokens[i] != "0") {
                                    writeFile << tokens[i] << " ";
                                }
								// else if there is a number, write to the file, the word at that x value
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