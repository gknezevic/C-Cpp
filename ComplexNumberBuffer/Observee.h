#pragma once
#include <vector>
#include <list>
#include "Observer.h"

class Observee
{
    std::vector<Observer> list;
public:
    void AddObserver(Observer observer);
    void NotifyObservers(); 
};
