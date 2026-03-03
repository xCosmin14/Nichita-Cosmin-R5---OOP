#include <iostream>
#include <string.h>
#include "Student.h"

Student::Student(){
	mathsGrade = 0;
	englishGrade = 0;
	historyGrade = 0;
	strcpy(name, "\0");
};

void Student::SetName(const char* newName) {
    if (newName != nullptr) strcpy(name, newName);
    
}

bool Student::SetMathGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        mathsGrade = grade;
        return true;
    }
    return false;
}

bool Student::SetEnglishGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        englishGrade = grade;
        return true;
    }
    return false;
}

bool Student::SetHistoryGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        historyGrade = grade;
        return true;
    }
    return false;
}

char* Student::GetName() {
    return name;
}

float Student::GetMathGrade() {
    return mathsGrade;
}

float Student::GetEnglishGrade() {
    return englishGrade;
}

float Student::GetHistoryGrade() {
    return historyGrade;
}

float Student::GetAverage() {
    if (mathsGrade == 0 || englishGrade == 0 || historyGrade == 0) 
        return 0; 
    
    return (mathsGrade + englishGrade + historyGrade) / 3.0f;
}