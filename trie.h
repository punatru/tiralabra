#include "node.h"
#include<string>
#include "myvector.h"
#include<vector>
#define maxsize 65536
using namespace std;
class Trie {
    private:
        MyVector<Node> children;
        int nextIndex;
        bool isempty;
    public:
        Trie();
        Node* nodes[maxsize];
        void add(string word);
        int find(string word);
        string translate(int code);
        void empty();
        bool isemptyed();
};
