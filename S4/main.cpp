#include <iostream>
#include "sort.h"

int main()
{
    Sort s1(10, 1, 100);
    s1.Print();
    s1.InsertSort();
    s1.Print();
    cout << endl;

    Sort s2({1, 2, 3, 7, 6, 5, 4, 8, 9, 10});
    s2.QuickSort(true);
    s2.Print();
    cout << endl;

    vector<int> v = {39841, 12381549, 142813, 60024, 1824819};
    Sort s3(v, v.size());
    s3.BubbleSort(true);
    s3.Print();
    cout << s3.GetElementsCount() << endl;
    cout << s3.GetElementFromIndex(1) << endl;

    return 0;
}
