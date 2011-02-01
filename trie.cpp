#include "trie.h"
#include<iostream>
#include<string>
using namespace std;
Trie::Trie(){
    nextIndex = 256;
    for(int i=0; i<256; i++){
    	Node n;
    	n.letter = i;
    	n.number = i;
        nodes.push_back(n);
    }
}	

int Trie::find(string word){
    
    int j = -1;
    for(int i=0; i<nodes.size(); i++){
        j =  nodes[i].findWord(word, 0);
        if(j!=-1) return j;
    }
    return -1;
}

void Trie::add(string word) {
//	cout<<"Lisataa "<<word<<endl;
//	bool exists = false;
  /*  for(int i=0; i<nodes.size(); i++){
    	if(nodes[i].letter==word[0]){
            exists = true;
    */        nodes[word[0]].addWord(word, nextIndex, 1);
      /*  
        }
    }*//*
    if(!exists){
        Node n;
        n.letter = word[0];
        n.number = word[0];
        n.addWord(word, nextIndex, 1);
        nodes.push_back(n);
    }*/
    nextIndex++;
    for(int i=0;i<nodes.size();i++) {
    	nodes[i].debug();
    }
//    cout<<"----\n";
}

