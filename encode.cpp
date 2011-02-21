#include "trie.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
	if(argc!=3){
        cout<<"Usage: ./lzw inputfile outputfile"<<endl;
        return 0;
	}
    ifstream fin;
    fin.open(argv[1]);

    ofstream fout;
    fout.open(argv[2]);

    string word;
    word = fin.get();

    Trie trie;

    while(!fin.eof()){
        char a = fin.get();
        int code = trie.find(word+a);
        if(code!=-1){
            word = word+a;
        }else{
            fout<<trie.find(word)<<" ";
            trie.add(word+a);
            word = a;
        }
    }

    fin.close();
    fout.close();
}
