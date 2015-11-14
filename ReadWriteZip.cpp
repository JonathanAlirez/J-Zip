#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Encoding.h"

using namespace std;

// vector of Encoding, class, that has the occurence of words and count of those words
vector<Encoding> occWords;

// function to read a file passed in through args, and J-Zip it in writeFileToZip
void readFileToZip(string fileName)
{
    string line;
    ifstream file (fileName.c_str());
    if (file.is_open())
    {
		// Opens the file and loop through it
        while (getline(file, line))
        {
			// put into the tokens vector all words
            string buffer;
            stringstream ss(line);
            vector<string> tokens;
			// push them into array
            while (ss >> buffer)
                tokens.push_back(buffer);
			// loop through tokens array for duplicates
            for (int i = 0; i < tokens.size(); i++)
            {
                bool added = false;
				// if i = 0, it is the first word, so put it in.
                if (i > 0)
                {
					// Loop through the occWords array
                    for (int j = 0; j < occWords.size(); j++)
                    {
						// if the new word, i, is in occWords array, than add 1 to that words count
                        if (occWords.at(j).getWord().compare(tokens[i]) == 0)
                        {
                            occWords.at(j).setCount(occWords.at(j).getCount() + 1);
                            added = true;
                            break;
                        }
                    }
					// if it isn't in the array, than add it to the array occWords and set it's count to 1
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
		// close file and sort it based on word count, so 
        file.close();
        sort(occWords.begin(), occWords.end());
    }
    else
        cout << "Error, cannot open file" << endl;
}

// function to write this file to the zip file
void writeFileToZip(string fileName)
{
	// get ride of .txt at end
    string newFileName = fileName.substr(0, fileName.size() - 4);
    // add .jzip to the end
	string tempFile = newFileName + ".jzip";
    // output stream to write to .jzip file
	ofstream file(tempFile.c_str());
	// input stream to read in file
    ifstream fileRead(fileName.c_str());
    string line;
    vector<Encoding> encodeList;
    if (fileRead.is_open())
    {
		// loop through occWords for all the word counts
         for (int i = 0; i < occWords.size(); i++)
            {
				// get rid of words that are unique, only have 1 occurence in the program, not worth memory
                if (occWords.at(i).getCount() > 1)
                {
					// write the occWords at the top of the file, with the i value
					encodeList.push_back(Encoding(occWords.at(i).getWord(),i));
					file << occWords.at(i).getWord() << " " << i << endl;
                }
            }
		// read file to start writing and switching the values around
        while ( getline(fileRead,line))
        {
			// space things out
            file << "\n";
            if (file.is_open())
            {
				// writing to the file
                string buffer;
                stringstream ss(line);
                vector<string> tokens;
                while (ss >> buffer)
                    tokens.push_back(buffer);
				// get tokens ready
                for (int i = 0; i < tokens.size(); i++)
                {
                    bool changed = false;
					// loop through the new encodeList that contains the WORD, i value
                    for (int j = 0; j < encodeList.size(); j++)
                    {
						// compare value with list
                        if (encodeList.at(j).getWord().compare(tokens[i]) == 0)
                        {
							// write the encodeList count value
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