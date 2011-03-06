#include<string>
#include<fstream>
using namespace std;
class FileWriter{
    public:
        FileWriter(string file);
        void write(int number);
        void writeemptymark();
        void close();
    private:
        ofstream fout;
};
