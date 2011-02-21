#include "node.h"
#include<string>

Node::Node(char letter, int code, Node* parent){
    this->letter = letter;
    this->code = code;
    this->parent = parent;
}	

Node* Node::addWord(string word, int newcode, int index){

    if(index>=word.size()){
        return this;
    }
    
    for(int i=0; i<children.size(); i++){
        if(children[i]->letter==word[index]){
            return children[i]->addWord(word, newcode,index+1);   
        }
    }
    
	Node* n = new Node(word[index], newcode, this);
    children.push_back(n);
    return n;
}

int Node::findWord(string word, int index){
    if(word[index] == letter){
    	if(index==word.size()-1){
            return code;
    	}
        int j = -1;
        for(int i=0; i<children.size(); i++){
            j =  children[i]->findWord(word, index+1);
            if(j!=-1) return j;
        }
    }
    return -1;
}

string Node::translate(){
    if(this->parent==0){
    
        string word="";
        word+=this->letter;
        return word;
    }
    string translation = this->parent->translate();
    translation.push_back(this->letter);
    return translation;
}
