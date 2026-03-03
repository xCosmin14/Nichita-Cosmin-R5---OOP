#include "Student.h"
#include <string.h>
#include "GlobalFunc.h"

short int compName(Student* s1, Student* s2) {
	int res = strcmp(s1->GetName(), s2->GetName());

	return res;
}

short int compMathsGrade(Student* s1, Student* s2) {
	if (s1->GetMathGrade() > s2->GetMathGrade()) return 1;
	else if (s1->GetMathGrade() < s2->GetMathGrade()) return -1;
	else return 0;
}

short int compEnglishGrade(Student* s1, Student* s2) {
	if (s1->GetEnglishGrade() > s2->GetEnglishGrade()) return 1;
	else if (s1->GetEnglishGrade() < s2->GetEnglishGrade()) return -1;
	else return 0;
}

short int compHistoryGrade(Student* s1, Student* s2) {
	if (s1->GetHistoryGrade() > s2->GetHistoryGrade()) return 1;
	else if (s1->GetHistoryGrade() < s2->GetHistoryGrade()) return -1;
	else return 0;
}

short int compAverage(Student* s1, Student* s2) {
	if (s1->GetAverage() > s2->GetAverage()) return 1;
	else if (s1->GetAverage() < s2->GetAverage()) return -1;
	else return 0;
}