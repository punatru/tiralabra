#include "node.h"
#include<string>

void Node::addWord(string word, int code, int index){
//    cout<<"Lisataan "<<word<<" index "<<index<<"("<<code<<")"<<endl;
    if(index>=word.size()){
        return;
    }

    bool exists = false;
    for(int i=0; i<children.size(); i++){
        if(children[i].letter==word[index]){
            children[i].addWord(word, code,index+1);
            exists = true;
        }

    }
    if(!exists){
        Node n;
        n.letter = word[index];
        n.number = code;
        n.addWord(word, code, index+1);
        children.push_back(n);
    }
}

int Node::findWord(string word, int index){
    if(word[index] == letter){
    	if(index==word.size()-1){
            return number;
    	}
        int j = -1;
        for(int i=0; i<children.size(); i++){
            j =  children[i].findWord(word, index+1);
            if(j!=-1) return j;
        }
    }
    return -1;

}
void Node::debug(){
  /*  cout<<number<<": "<<letter<<" (";
    for(int i=0;i<children.size();i++) {
    	cout<<children[i].letter<<"\t";
    }
    cout<<")\n";
   */ for(int i=0;i<children.size();i++) {
    	children[i].debug();
    	}

}
