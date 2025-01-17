#include<iostream>
#include<fstream>
#include "IO.hpp"

using namespace std;

IO::IO(const string &file_path){
    usersFile.open(file_path,ios::in|ios::out|ios::binary);
}

bool IO::isFileOpen(){ 
    return usersFile.is_open();
}

ifstream& IO::getInputFile(){ 
    return usersFile;
}

IO::~IO(){
    usersFile.close();
}