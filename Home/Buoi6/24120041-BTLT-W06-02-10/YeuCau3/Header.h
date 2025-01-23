#ifndef HEADER_H
#define HEADER_H

#define MAX 100
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void loadArray(char inputPath[], int arr[], int& n);
bool primeNumber(int n);
void primeNumberArray(int arr[],  int primeArray[], int n, int& count);
void saveArray(char outputPath[], int arr[], int n);

#endif 