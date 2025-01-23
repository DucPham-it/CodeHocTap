#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;
#define MAX 100

struct CharFrequency {
    char character;
    int frequency;
};

void bubbleSort(CharFrequency arr[], int n);

#endif 
