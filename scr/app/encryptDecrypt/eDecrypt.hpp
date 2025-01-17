#ifndef EDECRYPT_HPP
#define ENCRRYPT_HPP

#include <iostream>
#include<vector>

using namespace std;

class EDECRYPT{
    public:
        void Encrypt(vector<char>& chunk,vector<char>& output_chunk);
        void Decrypt(vector<char>& chunk,vector<char>& output_chunk);
};

#endif