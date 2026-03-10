#pragma once

class Math {
    public:
        static int Add(int x1_i, int y1_i);
        static int Add(int x2_i, int y2_i, int z1_i);
        static int Add(double x1_d, double y1_d);
        static int Add(double x2_d, double y2_d, double z2_d);
        static int Mul(int x1_i, int y1_i);
        static int Mul(int x2_i, int y2_i, int z1_i);
        static int Mul(double x1_d, double y1_d);
        static int Mul(double x2_d, double y2_d, double z1_d);
        static int Add(int count, ...); // sums up a list of integers
        static char* Add(const char* x1, const char* y1);
};