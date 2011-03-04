#include "node.h"
#include<string>

Node::Node(char letter, int code, Node* parent){
    this->letter = letter;
    this->code = code;
    this->parent = parent;
}	

Node::~Node(){
	int size = children.getsize();
	for(int i=0; i<size; i++){
        delete children[i];
	}
}

Node* Node::addWord(string word, int newcode, int index){

    if(index>=word.size()){
        return this;
    }
    int size = children.getsize();
    for(int i=0; i<size; i++){
    	Node* node = children[i];
        if(node->letter==word[index]){
            return node->addWord(word, newcode,index+1);   
        }
    }
    
	Node* n = new Node(word[index], newcode, this);
    children.push(n);
    return n->addWord(word, newcode+1, index+1);
}

int Node::findWord(string word, int index){
    if(index==word.size()-1){
        return code;
   	}
    
   	Node* child = children.find(word[index+1]);
   	if(child==0){
        return -1;
   	}
   	
   	return child->findWord(word, index+1);
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


