#ifndef HEADER_H
#define HEADER_H

#define MAX 100
#include <iostream>
#include <fstream>
using namespace std;

void loadMatrix(char inputPath[], int arr[][MAX], int& row, int& col);
void turnLeftMatrix(int arr[][MAX], int& row, int& col);
void saveMatrix(char outputPath[], int arr[][MAX], int row, int col);

#endif 