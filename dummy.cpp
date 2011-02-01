#include "dummy.h"
Dummy::Dummy() {
    nextIndex = 256;
}
void Dummy::add(string word) {
    dict[word]=nextIndex++;
    cout<<"Tallennetttiin "<<word<<" indeksille "<<dict[word]<<endl;
}
int Dummy::find(string word) {
    if(dict.count(word)==0) return -1;
    return dict[word];
}
