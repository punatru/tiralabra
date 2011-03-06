#include "filewriter.h"
FileWriter::FileWriter(string file){
    fout.open(file.c_str());    

}

void FileWriter::write(int number){
    unsigned char start = (number>>8);
    
    int mask = (1<<8)-1;

    unsigned char end = number & mask;
    
    fout<<start<<end; 
}

void FileWriter::writeemptymark(){
    write(65535);
}

void FileWriter::close(){
    fout.close();

}
