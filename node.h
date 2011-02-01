#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Node{
    private:
        vector<Node> children;

    public:
        int findWord(string word, int index);
        void addWord(string word, int code,  int index);
        char letter;
        int number;
        void debug();
};
