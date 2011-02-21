#include<vector>
#include<string>
using namespace std;
class Node{
    private:
        vector<Node*> children;
        Node* parent;

    public:
        Node(char letter, int code, Node* parent);
        int findWord(string word, int index);
        Node* addWord(string word, int code,  int index);
        string translate();
        char letter;
        int code;
};
