#include "node.h"
#include <vector>
#include<string>
using namespace std;

int Node::findWord(string word, int index) {

    if(word[index]==letter){
    	if(word.size()-1==index){
            return number;
    	}
    	if(children.size()==0){
            return -1;
        }
        int j = -1;
    	for(int i=0; i<children.size(); i++){
            j = children[0].findWord(word, index+1);
            if(j!=-1){
                return j;
            }
        }
    }
    return -1;
}

void Node::addWord(string word, int index){

    if(index>=word.size()){
        return;
    }

    bool exists = false;
    for(int i=0; i<children.size(); i++){
        if(children[i].letter==word[index]){
            children[i].addWord(word, index+1);
            exists = true;
        }

    }
    if(!exists){
        Node n;
        n.letter = word[index];
        n.number = 117;
//        n.children = new vector<Node>; // ei tarvi
        children.push_back(n);
        n.addWord(word, index+1);
    }
}


