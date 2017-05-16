#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "resources.h"
#include "studentUtils.h"
using namespace std;
using namespace studentUtils;

void checkStudentResult(string name, int result,string grade);
void printResult(ofstream& outFile, string message, string name, int result, string grade);

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
        printResult(outFile, "", names[i], result[i], grade);
        checkStudentResult(names[i], result[i], grade);
    }
    
    printResult(outFile, "Highest result: ", bestStudent.getName(), bestStudent.getResult(), "");
    printResult(outFile, "Lowesest result: ", worstStudent.getName(), worstStudent.getResult(), "");

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

void printResult(ofstream& outFile, string message, string name, int result, string grade) {
    cout << message << name << " " << result << " " << grade << "\n";
    outFile << message << name << " " << result << " " << grade << "\n";
}
