#include <iostream>
#include "NumberList.h"
using namespace std;

int main() {
    NumberList* lista = new NumberList;
    lista->Init();
    lista->Add(10);
    lista->Add(5);
    lista->Add(20);
    lista->Add(67);
    lista->Add(42);
    lista->Add(33);
    lista->Add(14);
    lista->Add(81);
    lista->Add(99);
    lista->Add(100);
    lista->Add(20);

    lista->Sort();
    lista->Print(); 

    return 0;
}
