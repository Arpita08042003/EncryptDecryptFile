#include<iostream>
#include<fstream>
#include "IO.hpp"

int main(){
    IO IO("./test.txt"); 
    if(IO.isFileOpen()){
        string line;
        while(getline(IO.getInputFile(),line)){
            cout<<line<<endl;
        }
    }else{
        cout<<"cant open file";
    }
}