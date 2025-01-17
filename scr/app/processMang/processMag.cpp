#include <iostream>
#include<vector>
#include <sys/mman.h>  // mmap
#include <fcntl.h>     // open
#include <unistd.h>    // close, lseek

#include "processMag.hpp"

using namespace std;

vector<vector<char>>& PROCESSMAG::divideIntoChunks(fstream& inputFile){
    while(!inputFile.eof()){
        vector<char> chunk(CHUNKS_SIZE);
        inputFile.read(chunk.data(),CHUNKS_SIZE);
        size_t bytesRead = inputFile.gcount();

        chunk.resize(bytesRead);
        if(!chunk.empty()) chunks.push_back(chunk);
    } 

    // string filePath = "./test.txt";
    // size_t CHUNKS_SIZE =1024;
    // int fd = open(filePath.c_str(), O_RDWR);
    //     if (fd == -1) {
    //         perror("Error opening file");
    //         throw std::runtime_error("Failed to open file");
    //     }

    //     // Get the file size
    //     off_t fileSize = lseek(fd, 0, SEEK_END);
    //     if (fileSize == -1) {
    //         perror("Error determining file size");
    //         close(fd);
    //         throw std::runtime_error("Failed to determine file size");
    //     }

    //     // Memory map the file
    //     char* fileData = static_cast<char*>(mmap(nullptr, fileSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
    //     if (fileData == MAP_FAILED) {
    //         perror("Error mapping file");
    //         close(fd);
    //         throw std::runtime_error("Failed to map file");
    //     }

    //     // Divide file data into chunks
    //     size_t offset = 0;
    //     while (offset < fileSize) {
    //         size_t chunkSize = std::min(CHUNKS_SIZE, static_cast<size_t>(fileSize - offset));
    //         chunks.emplace_back(std::vector<char>(fileData + offset, fileData + offset + chunkSize));
    //         offset += chunkSize;
    //     }

    //     // Example: Modify the first byte of the first chunk (you can customize this logic)
    //     if (!chunks.empty() && !chunks[0].empty()) {
    //         chunks[0][0] = 'X';  // Modify the first byte of the first chunk
    //         // Flush the changes back to the file using msync
    //         if (msync(fileData, fileSize, MS_SYNC) == -1) {
    //             perror("msync failed");
    //         } else {
    //             std::cout << "Changes flushed to file!" << std::endl;
    //         }
    //     }

    //     // Clean up
    //     munmap(fileData, fileSize);
    //     close(fd);

    return chunks;
}

void PROCESSMAG::changeFile(fstream& inputFile,vector<vector<char>>& output_chunks){ 
    unsigned long long pos=0;
    cout<<output_chunks.size();
    for(auto &chunk:output_chunks){ 
        string str="";
        for(auto i:chunk){str+=i;}
            inputFile.clear();
            inputFile.seekp(pos);
            if (!inputFile) {
                std::cerr << "seekp failed at position " << pos << std::endl;
                break;
            }
            inputFile.write(str.c_str(),str.size());
            if (!inputFile) {
                std::cerr << "write failed at position " << pos << std::endl;
                break;
            }
            inputFile.flush();
            pos+=str.size(); 
    }
}