#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <stdint.h>
#include <fstream>
using namespace std;

struct monomial{
    float degree;
    float coefficient;
};
struct polynomial{
    int16_t n;
    monomial* mono;
};

void readBinaryFile(polynomial* poly, int& count);
#endif