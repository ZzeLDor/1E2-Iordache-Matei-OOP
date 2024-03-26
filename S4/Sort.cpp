#include "Sort.h"
#include <iostream>
#include <sstream>
#include <cstdarg>

using namespace std;

Sort::Sort(int n, int min, int max)
{
    srand(time(nullptr));
    elem.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int s = (rand() % (max - min + 1)) + min;
        elem.push_back(s);
    }
}

Sort::Sort(initializer_list<int> list) : elem(list) {}

Sort::Sort(const vector<int> &v, int n) : elem(v.begin(), v.begin() + n) {}

Sort::Sort(int n, ...)
{
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; ++i)
        elem.push_back(va_arg(args, int));
    va_end(args);
}

Sort::Sort(const char *s)
{
    stringstream ss(s);
    int num;
    char vir;
    while (ss >> num >> vir)
        elem.push_back(num);
    ss >> num;
    elem.push_back(num);
}

void Sort::InsertSort(bool ascendent)
{
    int n = elem.size();
    for (int i = 1; i < n; ++i) {
        int curr = elem[i];
        int j = i - 1;
        while (j >= 0 && ((ascendent && elem[j] > curr) || (!ascendent && elem[j] < curr))) {
            elem[j + 1] = elem[j];
            --j;
        }
        elem[j + 1] = curr;
    }
}

int partition(int v[], int l, int h, bool ascendent)
{
    int x = v[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if ((ascendent && v[j] <= x) || (!ascendent && v[j] >= x)) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[h]);
    return (i + 1);
}

void Sort::QuickSort(bool ascendent)
{
    int n = elem.size();
    int stack[n];
    int top = -1;
    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0) {
        int h = stack[top--];
        int l = stack[top--];

        int p = partition(elem.data(), l, h, ascendent);
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

void Sort::BubbleSort(bool ascendent)
{
    int n = elem.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapp = false;
        for (int j = 0; j < n - i - 1; j++) {
            if ((ascendent && elem[j] > elem[j + 1]) || (!ascendent && elem[j] < elem[j + 1])) {
                std::swap(elem[j], elem[j + 1]);
                swapp = true;
            }
        }
        if (!swapp)
            break;
    }
}

void Sort::Print()
{
    for (int elem : elem)
        cout << elem << " ";
    cout << endl;
}

int Sort::GetElementsCount()
{
    return elem.size();
}

int Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index < elem.size())
        return elem[index];
    else
        return NULL;
}
