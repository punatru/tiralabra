#include<string>
#include<fstream>
using namespace std;
class FileReader{
    public:
        FileReader(string file);
        int read();
        void close();
        bool eof();
    private:
        ifstream fin;
};
