#include <iostream>
#include "Student.h"
#include "GlobalFunc.h"
using namespace std;

int main() {
    Student* s1 = new Student;
    Student* s2 = new Student;

    s1->SetName("Alin");
    s2->SetName("Iosif");

    s1->SetEnglishGrade(7.8);
    s2->SetEnglishGrade(10.0); 

    cout << s1->GetAverage() << '\n';

    cout << s1->GetEnglishGrade() << '\n';
    cout << s2->GetEnglishGrade() << '\n';

    cout << compEnglishGrade(s1, s2);

    delete s1; delete s2;
    return 0;
}
