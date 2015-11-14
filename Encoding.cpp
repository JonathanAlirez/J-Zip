#include <iostream>
#include "Encoding.h"

using namespace std;
	// Encoding constructor, takes a word and the count of that word
    Encoding::Encoding(std::string w, int c) { word = w; count = c; };
	// setWord sets the word in the array
	void Encoding::setWord(std::string newWord) { word = newWord; }
	// setCount sets how much of that word is in the file
    void Encoding::setCount(int newCount) { count = newCount; }
    bool operator <(const Encoding& s1, const Encoding& s2)
    {
        if (s1.getCount() > s2.getCount())
            return true;
        else
            return false;
    }
