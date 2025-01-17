#include<iostream>
#include<thread>
#include<mutex>

#include "./scr/app/fileHandling/IO.hpp"
#include "./scr/app/processMang/processMag.hpp"
#include "./scr/app/encryptDecrypt/eDecrypt.hpp"

using namespace std;
mutex mtx;

int main(){
    IO IO("./test.txt");
    bool encrypt;
    cout<<"for Encrypt press 1 and for decrypt press 0 ";
    cin>>encrypt;
    if(IO.isFileOpen()){ 
        PROCESSMAG processMag;
        fstream& inputFile = IO.getInputFile();
        auto& chunks = processMag.divideIntoChunks(inputFile);
        vector<vector<char>> output(chunks.size());

        EDECRYPT eDecrypt;
        vector<thread> threads; 

        for(int i=0;i<chunks.size();++i){
            threads.emplace_back([&,i](){
                vector<char> outputChunk(chunks[i].size());
                if(encrypt){
                    eDecrypt.Encrypt(chunks[i],outputChunk);
                }else{
                    eDecrypt.Decrypt(chunks[i],outputChunk);
                }
                lock_guard<mutex> lock(mtx);
                output[i] = move(outputChunk);
            });
        }

        for(auto &t:threads){
            if(t.joinable()) t.join();
        }

        processMag.changeFile(inputFile,output);
        inputFile.close();
    }else{
        cout<<"cant open file";
    }
     
}