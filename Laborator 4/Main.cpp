#include <iostream>
#include "Sort.h"

using namespace std;

int main() {
    Sort s1(10, 10, 99);
    s1.Print();
    s1.InsertSort(true); 
    s1.Print();
    cout << '\n';

    Sort s2 = { 5, 2, 9, 1, 5 };
    s2.Print();
    s2.QuickSort(true); 
    s2.Print();
    cout << '\n';

    int v[] = { 10, 20, 30, 5, 2 };
    Sort s3(v, 5);
    s3.Print();
    s3.BubbleSort(true); 
    s3.Print();
    cout << '\n';

    Sort s4(6, 4, 1, 8, 3, 9, 2);
    s4.Print();
    s4.QuickSort(false); 
    s4.Print();
    cout << '\n';

    Sort s5("10,40,100,5,70");
    s5.Print();
    s5.InsertSort(true);
    s5.Print();
    cout << '\n';

    cout << "Numar elemente: " << s5.GetElementsCount() << '\n';

    if (s5.GetElementsCount() > 0) 
        cout << s5.GetElementFromIndex(1);
    

    return 0;
}
