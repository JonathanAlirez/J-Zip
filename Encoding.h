#include <iostream>

class Encoding {
    private:
        std::string word;
        int count;

    public:
        Encoding(std::string name, int count);
        std::string getWord() const {return word;}
        int getCount() const {return count;}
        void setWord(std::string word);
        void setCount(int count);
};
        bool operator<(const Encoding& e1, const Encoding& e2);
