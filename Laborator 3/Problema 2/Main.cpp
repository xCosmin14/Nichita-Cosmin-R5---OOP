#include "Canvas.h"

int main() {
    Canvas c(100, 100);

    c.DrawRect(20, 15, 15, 8, '#');

    c.FillCircle(45, 30, 10, '*');

    c.DrawCircle(10, 15, 3, '~');

    c.SetPoint(17, 20, 'X');

    c.DrawLine(0, 0, 59, 19, '.');

    c.FillRect(25, 2, 35, 6, '+');

    c.Print();

    c.Clear();
    c.Print();

    return 0;
}
