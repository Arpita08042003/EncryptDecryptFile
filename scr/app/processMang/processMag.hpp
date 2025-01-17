#ifndef PROCESSMAG_HPP
#define PROCESSMAG_HPP

#include<iostream>
#include<vector>

#include "../fileHandling/IO.hpp"

using namespace std;

class PROCESSMAG{
    public:
        // PROCESSMAG();
        vector<vector<char>>& divideIntoChunks(fstream& inputFile);
        void changeFile(fstream& inputFile,vector<vector<char>>& output_chunks);
        // ~PROCESSMAG();
    private:
        vector<vector<char>> chunks;
        int CHUNKS_SIZE= 1024 ;

};



#endif
