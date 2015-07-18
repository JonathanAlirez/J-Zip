#include <iostream>
#include "Encoding.h"

using namespace std;
    Encoding::Encoding(std::string w, int c) { word = w; count = c; };
    void Encoding::setWord(std::string newWord) { word = newWord; }
    void Encoding::setCount(int newCount) { count = newCount; }
    bool operator <(const Encoding& s1, const Encoding& s2)
    {
        if (s1.getCount() > s2.getCount())
            return true;
        else
            return false;
    }
