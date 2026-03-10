#include <iostream>
#include "Math.h"
using namespace std;

int main() {
    Math();

    cout << Math::Add(1, 2) << '\n';
    cout << Math::Add(1, 2, 3) << '\n';

    cout << Math::Add(4.5, 6.7) << '\n';
    cout << Math::Add(4.20, 9.99, 10.5) << '\n';
    cout << '\n';

    cout << Math::Mul(1, 2) << '\n';
    cout << Math::Mul(1, 2, 3) << '\n';

    cout << Math::Mul(4.5, 6.7) << '\n';
    cout << Math::Mul(4.20, 9.99, 10.5) << '\n';
    cout << '\n';

    cout << Math::Add(3, 12, 13, 14);
    cout << '\n';

    cout << Math::Add("67", "69");
}
