#include <iostream>
#include <complex>
#include <cstdlib>
#include <ctime>
using namespace std;

const char* OUTPUT_FILE_NAME = "input.txt";
const char* REGULAR_OUTPUT_FILE_NAME = "regular_input.txt";

void storeAsRegular(ofstream& regularOutFile, std::complex<float> z);

void generateRandomLengthStream() {
    ofstream outFile, regularOutFile;
    outFile.open(OUTPUT_FILE_NAME, ios::out | ios::binary);
    regularOutFile.open(REGULAR_OUTPUT_FILE_NAME, ios::out);
    int k = 10;
    for (k ; k > 0; k--) {
        cout << "\n Write from Stream \n";

        std::srand(time(0));
        int k = std::rand() % 101;
        //usleep(100*k);

        srand(time(NULL));
        int random_real = std::rand();
        int random_img = std::rand();
        std::complex<float> z;
        z.real(k*random_real);
        z.imag(k*random_img);
        storeAsRegular(regularOutFile, z);
        outFile.write( (char*)&z, sizeof(std::complex<float>));
    }
    outFile.close();
}

void storeAsRegular(ofstream& regularOutFile, std::complex<float> z) {
    regularOutFile << z;
}