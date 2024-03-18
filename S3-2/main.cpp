#include "Canvas.h"

int main() {
    Canvas c(25, 25);
    c.DrawCircle(5, 5, 5, '*');
    c.Print();
    c.FillCircle(5, 5, 3, '#');
    c.Print();
    c.DrawRect(10, 10, 20, 20, '*');
    c.Print();
    c.FillRect(12, 12, 18, 18, '#');
    c.Print();
    c.SetPoint(5, 5, 'O');
    c.SetPoint(15, 15, 'O');
    c.Print();
    c.Clear();
    c.DrawLine(1, 1, 23, 19, 'M');
    c.Print();
    return 0;
}
