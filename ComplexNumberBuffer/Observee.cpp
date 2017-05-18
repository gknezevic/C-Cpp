#include "Observee.h"
#include <algorithm>

void Observee::AddObserver(Observer newObserver ) {
	    list.push_back(newObserver);
}

void Observee::NotifyObservers() {
    for(vector<Observer>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->Notify();
        }
    }
}