#include "trie.h"
#include<iostream>
#include<string>
using namespace std;
int Trie::find(string word){
    
    int j = -1;
    for(int i=0; i<nodes.size(); i++){
        j =  nodes[i].findWord(word, 0);
        if(j!=-1) return j;
    }
    return -1;
}

void Trie::add(string word) {
	bool exists = false;
    for(int i=0; i<nodes.size(); i++){
    	if(nodes[i].letter==word[0]){
            exists = true;
            nodes[i].addWord(word, 1);
        }
    }
    if(!exists){
        Node n;
        n.letter = word[0];
 //        n.number = 117; // private
//        n.children = new vector<Node>; // ei tarvi
        nodes.push_back(n);
        n.addWord(word, 1);
    }
}
