#pragma once
#include <iostream>
#include <math.h>
using namespace std;

#define MY_EPS 2*1e-2

// struct coord{
//     double x;
//     double y;
// };

class coord{
    public:
        coord();
        coord(double x, double y);
        double x;
        double y;
        ~coord();
};

double distance(coord a, coord b); 
bool double_cmp(double a, double b); 
bool cmp(coord a, coord b);