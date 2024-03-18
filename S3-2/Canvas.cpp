#include <iostream>
#include "Canvas.h"

using namespace std;

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    canvas = new char *[height];
    for (int i = 0; i < height; i++) {
        canvas[i] = new char [width];
        for(int j = 0; j < width; j++)
            canvas[i][j] = ' ';
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray)
                canvas[i][j] = ch;
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
                canvas[i][j] = ch;
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(((i == top || i == bottom) && j >= left && j <= right) || ((j == left || j == right) && i >= top && i <= bottom))
                canvas[i][j] = ch;
        }
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(i >= left && i <= right && j >= top && j <= bottom)
                canvas[i][j] = ch;
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int diff = 2*dy - dx;
    int y = y1;
    for(int x = x1; x <= x2; x++) {
        canvas[x][y] = ch;
        if (diff > 0) {
            y++;
            diff = diff - 2*dx;
        }
        diff = diff + 2*dy;
    }
}

void Canvas::Print() {

    for(int i = 0; i < width; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
    for(int i = 0; i < width; i++)
        cout << "-";
    cout << endl;
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas[i][j] = ' ';
        }
    }
}