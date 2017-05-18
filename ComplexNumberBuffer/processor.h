#pragma once
#include <iostream>
#include <fstream>
#include <complex>
#include "Observer.h"
using namespace std;

class ProcessorClass : public Observer{

    int length = 8;
    istream* stream;
    
public:

    void startPreprocess(istream& newStream) {
        this->stream = &newStream;
        preprocess(*stream);
    }

    float preprocess(istream& stream) {
        while(!stream.eof()) {
            cout << "\n Read from Stream \n";

            char * buffer = new char [length];
            stream.read(buffer, length);
            processor((std::complex<float>*) &buffer);
        }
        //stream.seekp(0, ios::beg);
        //stream.seekg(0, ios::beg);
        //stream.ignore(numeric_limits<streamsize>::max(),'\n');

        cout << "\n End Read pointer: " << stream.tellg() << "\n";
    } 

    void processor(std::complex<float>* complexNumber) {
        cout << "\n Final Complex number: " << *complexNumber;
    }

    void Notify() {
        preprocess(*stream);
    }
};