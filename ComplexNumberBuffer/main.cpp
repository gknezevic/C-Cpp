#include <istream>
#include <iostream>
#include <fstream>
#include <thread>
#include <unistd.h>
#include <ios>
#include "processor.h"
#include "randomLengthGenerator.h"
using namespace std;

void generateThreadForProducingStream(ostream& out, ProcessorClass& processorClass);
void generateThreadForConsumingStream(istream& in, ProcessorClass& processorClass);

const char* OUTPUT_FILE_NAME = "input.txt";

int main() {
    cout << "Start application \n";
    ProcessorClass processorClass;

    filebuf fbuf;
    fbuf.open(OUTPUT_FILE_NAME, std::ios_base::in | std::ios_base::out);    

    std::istream in(&fbuf);
    std::ostream out(&fbuf);

    std::thread t1(generateThreadForProducingStream, std::ref(out), std::ref(processorClass));
    
    std::thread t2(generateThreadForConsumingStream, std::ref(in), std::ref(processorClass));

    t1.join();
    t2.join();

    return 0;
}

void generateThreadForProducingStream(ostream& out, ProcessorClass& processorClass) {
    RandomLengthGenerator randomLengthGenerator(processorClass);
    randomLengthGenerator.generateRandomLengthStream(out);
}

void generateThreadForConsumingStream(istream& in, ProcessorClass& processorClass) {
    processorClass.startPreprocess(in);
}