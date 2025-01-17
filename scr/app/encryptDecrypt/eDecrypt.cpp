#include<iostream>
#include<vector>

#include "eDecrypt.hpp"

using namespace std;

void EDECRYPT::Encrypt(vector<char>& chunk,vector<char>& output_chunk){
    for(int i=0;i<chunk.size();i++){
        output_chunk[i]=chunk[i]-1;
    }
}

void EDECRYPT::Decrypt(vector<char>& chunk,vector<char>& output_chunk){
    for(int i=0;i<chunk.size();i++){
        output_chunk[i]=chunk[i]+1;
    }
}