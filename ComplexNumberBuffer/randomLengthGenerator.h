#pragma once
#include <iostream>
#include <complex>
#include <cstdlib>
#include <ctime>
#include "Observee.h"
using namespace std;

const char* REGULAR_OUTPUT_FILE_NAME = "regular_input.txt";
//const char* OUTPUT_FILE_NAME = "input.txt";

typedef std::complex<float> input_processor_type;

input_processor_type generateInput();

void storeAsRegular(ofstream& regularOutFile, input_processor_type z);

class RandomLengthGenerator : Observee {
    ProcessorClass processorClass;

public:

    RandomLengthGenerator(ProcessorClass processorClass) {
        this->processorClass = processorClass;
    }

    void generateRandomLengthStream(ostream& outFile) {
        ofstream regularOutFile;
        regularOutFile.open(REGULAR_OUTPUT_FILE_NAME, ios::out);
        int k = 10;
        for (k ; k > 0; k--) {
            cout << "\n Write from Stream \n";
                        
            input_processor_type z = generateInput();
            
            storeAsRegular(regularOutFile, z);
            outFile.write( (char*)&z, sizeof(input_processor_type));
        }
        processorClass.Notify();
    }

    void storeAsRegular(ofstream& regularOutFile, input_processor_type z) {
        regularOutFile << z;
    }

    input_processor_type generateInput() {
        srand(time(0));
        int k = std::rand() % 101;
        int random_real = std::rand();
        input_processor_type z;
        int random_img = std::rand();
        z.real(k*random_real);
        z.imag(k*random_img);
        
        return z;
    }
};