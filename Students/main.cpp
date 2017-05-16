#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "resources.h"
#include "studentUtils.h"
using namespace std;
using namespace studentUtils;

int countRecords(ifstream& inFile);

void storeRecordsInArray(ifstream& inFile, string names[], int result[]);
void checkStudentResult(string name, int result,string grade);

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

    // put in file
    ofstream outFile;
    outFile.open(OUTPUT_FILE_NAME);
    int i =0;
    for (i = 0; i < records; i++) {
        string grade = calculateGrade(result[i]);
        cout << names[i] << " " << result[i] << " " << grade << "\n";
        outFile << names[i] << " " << result[i] << " " << grade << "\n";
        checkStudentResult(names[i], result[i], grade);
    }
    
    outFile << "Highest result: " << bestStudent.getName() << " " << bestStudent.getResult() << "\n";
    outFile << "Lowest result: " << worstStudent.getName() << " " << worstStudent.getResult() << "\n";

    cout << "Highest result: " << bestStudent.getName() << " " << bestStudent.getResult() << "\n";
    cout << "Lowest result: " << worstStudent.getName() << " " << worstStudent.getResult() << "\n";

    outFile.close();
    
    cout << "End Of App\n";
    return 0;
}

void checkStudentResult(string name, int result,string grade) {
    if (bestStudent.getResult() == -1 || bestStudent.getResult() < result) {
        putNewResult(bestStudent, name, result, grade);
    } 
    if (worstStudent.getResult() == -1 || worstStudent.getResult() > result) {
        putNewResult(worstStudent, name, result, grade);
    }
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
