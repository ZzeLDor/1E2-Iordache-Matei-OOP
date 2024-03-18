#include <iostream>
#include <cstring>
#include <cstdarg>
#include "Math.h"

using namespace std;

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return a + b;
}

int Math::Add(double a, double b, double c) {
    return a + b + c;
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

int Math::Mul(double a, double b) {
    return a * b;
}

int Math::Mul(double a, double b, double c) {
    return a * b * c;
}

int Math::Add(int count, ...) {
    int s = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        s += va_arg(args, int);
    }
    va_end(args);
    return s;
}

char* Math::Add(const char *a, const char *b) {
    if (!a || !b)
        return NULL;
    char *result = new char[strlen(a) + strlen(b) + 1];
    strcpy(result, a);
    strcat(result, b);
    return result;
}