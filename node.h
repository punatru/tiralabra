#include"myvector.h"
#include<string>
#include <vector>
using namespace std;
class Node{
    private:
        MyVector<Node> children;

    public:
        Node(char letter, int code, Node* parent);
        ~Node();
        int findWord(string word, int index);
        Node* addWord(string word, int code,  int index);
        string translate();
        char letter;
        int code;
        Node* parent;
        void debug();
        bool operator<(const Node& toinennode) const{
            return (letter)<(toinennode.letter);
        } 
        bool operator<(const char& other) const{
            return letter<other;
        } 
        bool operator>(const char& other) const{
            return letter>other;
        } 
        bool operator==(const char& other) const{
            return letter==other;
        } 
        
};  
