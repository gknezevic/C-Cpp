#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "student.h"
using namespace std;

int countRecords(ifstream& inFile);
const char* INPUT_FILE_NAME = "studentRecords.txt";
const char* OUTPUT_FILE_NAME = "results.txt";
void storeRecordsInArray(ifstream& inFile, string names[], int result[]);
string calculateGrade(int grade);
void checkIfIsHighestResult(string names, int result,string grade);
void checkIfIsLowestResult(string names, int result, string grade);

Student bestStudent;
Student worstStudent;

int main() {

    cout << "Students Application\n";
    // Step 3
    ifstream inFile;
    inFile.open(INPUT_FILE_NAME, ios::in);
    // Step 4
    int records = countRecords(inFile);
    cout << "Records: " << records << "\n";
    // Step 5
    inFile.clear();
    inFile.seekg(0, ios::beg);
    // Step 6
    string names[records];
    int result[records];
    storeRecordsInArray(inFile, names, result);
    inFile.close();
    // before we check best and worst student, we will initialize it
    bestStudent.setResult(-999);
    worstStudent.setResult(999);

    // put in file
    ofstream outFile;
    outFile.open(OUTPUT_FILE_NAME);
    int i =0;
    for (i = 0; i < records; i++) {
        string grade = calculateGrade(result[i]);
        cout << names[i] << " " << result[i] << " " << grade << "\n";
        outFile << names[i] << " " << result[i] << " " << grade << "\n";
        checkIfIsHighestResult(names[i], result[i], grade);
        checkIfIsLowestResult(names[i], result[i], grade);
    }
    outFile << "Highest result: " << bestStudent.getName() << " " << bestStudent.getResult() << "\n";
    outFile << "Lowest result: " << worstStudent.getName() << " " << worstStudent.getResult() << "\n";

    cout << "Highest result: " << bestStudent.getName() << " " << bestStudent.getResult() << "\n";
    cout << "Lowest result: " << worstStudent.getName() << " " << worstStudent.getResult() << "\n";

    outFile.close();
    
    cout << "End Of App\n";
    return 0;
}

void checkIfIsHighestResult(string name, int result,string grade) {
    if (bestStudent.getResult() < result) {
        bestStudent.setName(name);
        bestStudent.setResult(result);
        bestStudent.setGrade(grade);
    }
}

void checkIfIsLowestResult(string name, int result,string grade) {
    if (worstStudent.getResult() > result) {
        worstStudent.setName(name);
        worstStudent.setResult(result);
        worstStudent.setGrade(grade);
    }
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
