#include "Math.h"
#include <iostream>
using namespace std;

int main() {
    Math m;
    cout << m.Add(1, 2) << endl;
    cout << m.Add(1, 2, 3) << endl;
    cout << m.Add(7.2, 1.1, 3.3) << endl;
    cout << m.Mul(3, 3) << endl;
    cout << m.Mul(3.3, 3.1) << endl;
    cout << m.Add(5, 1, 2, 3, 4, 5) << endl;
    cout << m.Add("OO", "P") << endl;
    return 0;
}
