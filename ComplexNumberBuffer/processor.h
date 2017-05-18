#include <iostream>
#include <fstream>
#include <complex>
using namespace std;

int length = 8;
void processor(std::complex<float>* complexNumber);

float preprocess(ifstream& stream) {
    int i = 0;
    while(stream) {
        cout << "\n Read from Stream \n";

        char * buffer = new char [length];
        stream.read(buffer, length);
        processor((std::complex<float>*) &buffer);
       
        cout << "\n";
        if (++i > 10000) {
            break;
        }
    }
} 

void processor(std::complex<float>* complexNumber) {
    cout << "\n Final Complex number: " << *complexNumber;
}