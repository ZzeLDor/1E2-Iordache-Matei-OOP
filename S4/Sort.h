#pragma once

#include <vector>
#include <initializer_list>
using namespace std;

class Sort
{
private:
    std::vector<int> elem;
public:
    Sort(int n, int min, int max);
    Sort(initializer_list<int> list);
    Sort(const vector<int> &v, int n);
    Sort(int n, ...);
    Sort(const char *s);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};