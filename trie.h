#include "node.h"
#include<string>
#include<vector>
using namespace std;
class Trie {
    private:
        vector<Node> nodes;

    public:
        void add(string word);
        int find(string word);

};
