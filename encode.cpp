#include "trie.h"
#include "filewriter.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
	if(argc!=3){
        cout<<"Usage: ./encode inputfile outputfile"<<endl;
        return 0;
	}
    ifstream fin;
    fin.open(argv[1]);

    FileWriter filewriter(argv[2]);

    string word;
    word = fin.get();

    Trie trie;

    char a = fin.get();


    while(!fin.eof()){
        int code = trie.find(word+a);
        if(code!=-1){
            word = word+a;
        }else{
            filewriter.write(trie.find(word));
            trie.add(word+a);
            word = a;
        }
        a = fin.get();
        if(trie.isemptyed()){
            filewriter.writeemptymark();
        }
    }
    
    
    filewriter.write(trie.find(word));
    fin.close();
    filewriter.close();
}
