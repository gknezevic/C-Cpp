#include <istream>
#include <iostream>
#include <fstream>
#include <thread>
#include <unistd.h>
#include <ios>
#include "processor.h"
#include "randomLengthGenerator.h"
#include "customStream.h"
using namespace std;

void generateThreadForProducingStream();
void generateThreadForConsumingStream();

int main() {
    cout << "Start application \n";

    //istream cStream ;
    //cStream.write("a");

    std::thread t1(generateThreadForProducingStream);
    
    std::thread t2(generateThreadForConsumingStream);

    t1.join();
    t2.join();

    return 0;
}

void generateThreadForProducingStream() {
    generateRandomLengthStream();
}

void generateThreadForConsumingStream() {
    std::ifstream inputs ("input.txt", std::ifstream::binary);
    ProcessorClass processorClass;
    processorClass.preprocess(inputs);
}