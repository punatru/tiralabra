
#include<iostream>
#include "trie.h"
#include<string>
#include<fstream>
#include "dummy.h"
using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin;
    fin.open(argv[1]);

    ofstream fout;
    fout.open(argv[2]);

    Trie trie;
    
    string word;
    fin>>word;
    fout<<(char)word;

    while(!fin.eof()){
        int a;
        fin>>a;
        string b = a;
        fout<<b;
        char c = b[0];
        trie.add(word+c);
    }

    fin.close();
    fout.close();
}
