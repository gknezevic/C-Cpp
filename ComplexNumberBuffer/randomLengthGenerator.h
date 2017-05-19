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
        srand(time(0));
        for (k ; k > 0; k--) {
            cout << "\n Write from Stream \n";
            //usleep(std::rand() % 10);
            input_processor_type z = generateInput();
            
            storeAsRegular(regularOutFile, z);
            outFile.write( (char*)&z, sizeof(input_processor_type));
            processorClass.Notify(outFile);
        }
        
    }

    void storeAsRegular(ofstream& regularOutFile, input_processor_type z) {
        regularOutFile << z;
    }

    input_processor_type generateInput() {
        // real and imag are 0 - 100
        int random_real = std::rand() % 101;
        input_processor_type z;
        int random_img = std::rand() % 101;
        z.real(random_real);
        z.imag(random_img);
        
        return z;
    }
};