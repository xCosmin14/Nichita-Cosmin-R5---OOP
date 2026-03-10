#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height) : width(width), height(height) {
    matrix = new char* [height];
    for (int i = 0; i < height; i++) matrix[i] = new char[width];
    
    Clear();
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) matrix[y][x] = ch;
}

void Canvas::DrawCircle(int x, int y, int raza, char ch) {
    for (int i = 0; i < height; i++) 
        for (int j = 0; j < width; j++) {
            int dist = (j - x) * (j - x) + (i - y) * (i - y);

            if (dist >= (raza - 1) * (raza - 1) && dist <= raza * raza) 
                SetPoint(j, i, ch);
        }
}

void Canvas::FillCircle(int x, int y, int raza, char ch) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if ((j - x) * (j - x) + (i - y) * (i - y) <= raza * raza)
                SetPoint(j, i, ch);    
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(left, top, right, top, ch);
    DrawLine(right, top, right, bottom, ch);
    DrawLine(right, bottom, left, bottom, ch);
    DrawLine(left, bottom, left, top, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) SetPoint(j, i, ch);
        
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;

        e2 = 2 * err;
        if (e2 >= dy) err += dy, x1 += sx;
        if (e2 <= dx)  err += dx, y1 += sy;
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) 
            std::cout << matrix[i][j];
        std::cout << "\n";
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++) 
        for (int j = 0; j < width; j++) matrix[i][j] = ' ';   
}