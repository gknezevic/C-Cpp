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
}