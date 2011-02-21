#include "node.h"
#include<string>
#include<vector>
using namespace std;
class Trie {
    private:
        vector<Node*> children;
        int nextIndex;
    public:
        Trie();
        vector<Node*> nodes;
        void add(string word);
        int find(string word);
        string translate(int code);
};
