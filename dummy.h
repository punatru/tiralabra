#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
class Dummy {
    private:
        int nextIndex;
        map<string, int> dict;
    public:
        Dummy();
        void add(string word);
        int find(string word);

};
