#include "node.h"
#include<string>
#include<vector>
using namespace std;
class Trie {
    private:
        vector<Node> nodes;
        int nextIndex;
    public:
        Trie();
        void add(string word);
        int find(string word);

};