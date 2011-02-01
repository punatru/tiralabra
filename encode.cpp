#include<iostream>
#include "trie.h"
#include<string>
#include<fstream>
#include "dummy.h"
using namespace std;

int maain() {
    Trie trie;
 //   trie.add("m");
    trie.add("mo");
  //  trie.add("moi");
    cout<<trie.find("mo")<<endl;
}

int main(int argc, char *argv[]) {
    ifstream fin;
    fin.open(argv[1]);

    ofstream fout;
    fout.open(argv[2]);

    string word;
    word += fin.get();

    Trie trie;

    while(!fin.eof()){
        char a = fin.get();
//        cout<<a<<endl;
        int code = trie.find(word+a);
        if(code!=-1){
            word = word+a;
        	cout<<code;
        }else{
        	cout<<word<<" "<<trie.find(word)<<endl;
        fout<<trie.find(word)<<" ";
            trie.add(word+a);
            word = a;
        }
    }

    fin.close();
    fout.close();
}
