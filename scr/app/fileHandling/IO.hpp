#ifndef IO_HPP
#define IO_HPP

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class IO{
    public:
        IO(const string &file_path);
        bool isFileOpen();
        fstream& getInputFile();
        ~IO();

    private:
        fstream usersFile;
};

#endif