#include "trie.h"
#include<string>
#include <cassert>
using namespace std;
Trie::Trie(){
    nextIndex = 256;
    for(int i=0; i<256; i++){
    	Node* n = new Node(i, i, 0);
        children.push_back(n);
        nodes.push_back(n);
    }
}	

int Trie::find(string word){
    
    int j = -1;
    for(int i=0; i<children.size(); i++){
        j =  nodes[i]->findWord(word, 0);
        if(j!=-1) return j;
    }
    return -1;
}

void Trie::add(string word) {
    Node* n = children[word[0]]->addWord(word, nextIndex, 1);
    nodes.push_back(n);
    
    nextIndex++;
}

string Trie::translate(int code){
	string word = "";
	if(code>=nextIndex) return word ;
    word = nodes[code]->translate();
    
    return word;
}

