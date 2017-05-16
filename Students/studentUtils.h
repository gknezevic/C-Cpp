#include <string>
#include "student.h"
using namespace std;

namespace studentUtils{

    void putNewResult(Student& student, string name, int result, string grade) {
        student.setName(name);
        student.setResult(result);
        student.setGrade(grade);
    }

    string calculateGrade(int grade) {
        if (grade >= 90) {
            return "HD";
        }
        if (grade >= 70) {
            return "DI";
        }
        return "CR";
    }

    void storeRecordsInArray(ifstream& inFile, string names[], int result[]) {
        char data[100];
        int row = 0;    
        
        while (!inFile.eof()) {
            inFile.getline(data, 100);
            string line  = data;
            int indexOfSpace = line.find(" ");
            names[row] = line.substr(0,indexOfSpace);
            string singleResult = line.substr(indexOfSpace, line.length());
            stringstream(singleResult) >> result[row];
            row++;
        }
    }

    int countRecords(ifstream& inFile) {
        char data[100];
        int totalRecords = 0;
        
        while (!inFile.eof()) {
            inFile.getline(data, 100);
            totalRecords++;
        }

        return totalRecords;
    }
}