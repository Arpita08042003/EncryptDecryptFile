#include <iostream>
#include<vector>

#include "processMag.hpp"

using namespace std;

vector<vector<char>>& PROCESSMAG::divideIntoChunks(ifstream& inputFile){
    while(!inputFile.eof()){
        vector<char> chunk(CHUNKS_SIZE);
        inputFile.read(chunk.data(),CHUNKS_SIZE);
        size_t bytesRead = inputFile.gcount();

        chunk.resize(bytesRead);
        if(!chunk.empty()) chunks.push_back(chunk);
    }
    return chunks;
}