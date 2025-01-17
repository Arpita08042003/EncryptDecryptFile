#ifndef PROCESSMAG_HPP
#define PROCESSMAG_HPP

#include<iostream>
#include<vector>

#include "../fileHandling/IO.hpp"

using namespace std;

class PROCESSMAG{
    public:
        // PROCESSMAG();
        vector<vector<char>>& divideIntoChunks(ifstream& inputFile);
        // ~PROCESSMAG();
    private:
        vector<vector<char>> chunks;
        int CHUNKS_SIZE= 1024 ;

};



#endif
