#include <iostream>
#include <complex>
#include <cstdlib>
#include <ctime>
using namespace std;

const char* OUTPUT_FILE_NAME = "input.txt";
const char* REGULAR_OUTPUT_FILE_NAME = "regular_input.txt";

typedef std::complex<float> input_processor_type;

input_processor_type generateInput();

void storeAsRegular(ofstream& regularOutFile, input_processor_type z);

void generateRandomLengthStream() {
    ofstream outFile, regularOutFile;
    outFile.open(OUTPUT_FILE_NAME, ios::out | ios::binary);
    regularOutFile.open(REGULAR_OUTPUT_FILE_NAME, ios::out);
    int k = 10;
    for (k ; k > 0; k--) {
        cout << "\n Write from Stream \n";
        
        //usleep(100*k);
        
        input_processor_type z = generateInput();
        
        storeAsRegular(regularOutFile, z);
        outFile.write( (char*)&z, sizeof(input_processor_type));
    }
    outFile.close();
}

void storeAsRegular(ofstream& regularOutFile, input_processor_type z) {
    regularOutFile << z;
}

input_processor_type generateInput() {
    srand(time(NULL));
    int k = std::rand() % 101;
    int random_real = std::rand();
    input_processor_type z;
    if (typeid(input_processor_type) == typeid(std::complex<float>)) {
        int random_img = std::rand();
        z.real(k*random_real);
        z.imag(k*random_img);
    }
    return z;
}