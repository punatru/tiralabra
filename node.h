#include<vector>
#include<string>
using namespace std;
class Node{
    private:
        int number;
        vector<Node> children;

    public:
        int findWord(string word, int index);
        void addWord(string word, int index);
        char letter;
};
