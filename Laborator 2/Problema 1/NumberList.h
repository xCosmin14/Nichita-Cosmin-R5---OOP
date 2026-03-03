  #pragma once

class NumberList {
    int numbers[10];
    int count;

public:
    NumberList();

    void Init();
    bool Add(int x);

    void Sort();
    void Print();
};
