#include "filereader.h"
FileReader::FileReader(string file){
   fin.open(file.c_str());  
}


int FileReader::read(){
    unsigned char start, end;
    if(fin.eof()){
        return 0;
    }
    start = fin.get();
    if(fin.eof()){
        return 0;
    }
    end = fin.get();
    int  startint = (start<<8);
    int ret = startint | end;
    return startint | end;
}

void FileReader::close(){
    fin.close();
}

bool FileReader::eof(){
    return fin.eof();
}
