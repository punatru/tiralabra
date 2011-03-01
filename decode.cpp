#include "trie.h"
#include "filereader.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
	if(argc!=3){
        cout<<"Usage: ./decode inputfile outputfile"<<endl;
        return 0;
	}
    FileReader filereader(argv[1]);

    ofstream fout;
    fout.open(argv[2]);

    Trie trie;
    
    int  oldcode;
    oldcode = filereader.read();
    char oldchar = (char)oldcode;
    fout<<oldchar;
    
    
    int newcode;
    
    newcode = filereader.read();
    while(!filereader.eof()){
        string translation;
        if(trie.translate(newcode).empty()){
            translation = trie.translate(oldcode);
       // cout<<oldcode<<endl;
            translation += oldchar;
        }
        else{
            translation = trie.translate(newcode);
       // cout<<newcode<<endl;
        }
        fout<<translation;
        oldchar = translation[0];
        string finalword = "";
        
        finalword += trie.translate(oldcode);
        finalword += oldchar;
        trie.add(finalword);

        
        oldcode = newcode;
        newcode = filereader.read();
    }
    filereader.close();
    fout.close();
}
