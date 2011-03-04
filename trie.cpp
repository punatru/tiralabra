#include"trie.h"
#include<string>
#include<iostream>
#include <cassert>
using namespace std;
Trie::Trie(){
    nextIndex = 256;
    isempty = false;
    for(int i=0; i<nextIndex; i++){
    	Node* n = new Node(i, i, 0);
        children.push(n);
        nodes[i] = n;
    }
    for(int i=nextIndex; i<maxsize; i++){
        nodes[i] = 0;
    }
}	

int Trie::find(string word){
    
    return children.find(word[0])->findWord(word, 0);
}
void Trie::add(string word) {
    if(nextIndex == maxsize-1){
        empty();
    }else{
        Node* n = children.find(word[0])->addWord(word, nextIndex, 1);
        
        nodes[nextIndex] = n;
        nextIndex++;
    }
}

string Trie::translate(int code){
	string word = "";
	if(code>=nextIndex) return word ;
    word = nodes[code]->translate();
    
    return word;
}

void Trie::empty(){
	int size = children.getsize();
    for(int i=0; i<size; i++){
        delete children[i];
    }
    children.resize(0);
    for(int i=0; i<maxsize; i++){
    	nodes[i] = 0;
    }
    for(int i=0; i<256; i++){
    	Node* n = new Node(i, i, 0);
        children.push(n);
        nodes[i] = n;
    }
    isempty = true;
    nextIndex = 256;
}

bool Trie::isemptyed(){
	bool emptyed = isempty;
	isempty = false;
    return emptyed;
}
