#pragma once
#include <iostream>
using namespace std;

class Observer {
    public:
        virtual void Notify(ostream& outFile) {};
    
};