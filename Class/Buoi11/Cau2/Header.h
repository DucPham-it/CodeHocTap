#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double x;
    double y;
};
struct Circle
{
    Point I;
    double radian;
};

int checkCircle(Circle C1, Circle C2);

#endif