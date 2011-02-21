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

    Trie trie;
    
    int  oldcode;
    fin>>oldcode;
    char oldchar = (char)oldcode;
    fout<<oldchar;


    
    while(!fin.eof()){
        int newcode;
        fin>>newcode;
        string translation;
        if(trie.translate(newcode).empty()){
            translation = trie.translate(oldcode);
            translation += oldchar;
        }
        else{
            translation = trie.translate(newcode);
        }
        fout<<translation;
        oldchar = translation[0];
        string finalword = "";
        
        finalword += trie.translate(oldcode);
        finalword += oldchar;
        trie.add(finalword);

        
        oldcode = newcode;
    }
    fin.close();
    fout.close();
}
