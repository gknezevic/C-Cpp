#pragma once
#include <iostream>
#include <fstream>
#include <complex>
#include <mutex>
#include "Observer.h"
using namespace std;

class ProcessorClass : public Observer{

    istream* stream;
    int position;
    
public:

    ProcessorClass() : position(0) {}

    void startPreprocess(istream& newStream) {
        stream = &newStream;
        preprocess(*stream);
    }

    float preprocess(istream &stream) {        
        //unique_lock<mutex> lock(position);
        std::complex<float> z;
        
        int streamL = stream.tellg();
        stream.seekg(0, ios::beg);
        while(position < streamL) {
            stream.read((char *) &z, sizeof(z));
            cout << "\n Read from Stream \n";
            position += sizeof(z);
            stream.seekg(position, ios::beg);
            processor(z);
        }

    } 

    void processor(std::complex<float>& complexNumber) {
        cout << "\n Final Complex number: " << complexNumber << "\n";
    }

    void Notify(ostream& outFile) {
        cout << "\n Debug " << "\n";
        std::istream in(outFile.rdbuf());
        preprocess(in);
    }
};