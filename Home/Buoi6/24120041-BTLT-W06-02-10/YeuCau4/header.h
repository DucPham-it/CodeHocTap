#ifndef HEADER_H
#define HEADER_H

#define MAX 100
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

struct operation{
    int ope1;
    char op;
    int ope2;
};

void loadOpe(char inputPath[], operation arr[], int& n);
void saveResult(char outputPath[], operation arr[], int n);

#endif 