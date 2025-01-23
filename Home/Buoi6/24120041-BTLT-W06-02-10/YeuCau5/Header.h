#ifndef HEADER_H
#define HEADER_H

#define MAX 100
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

void loadChar(char inputPath[], char arr[]);
bool seeChar(char a);
bool seeNum(char a);
int countNumWord(char arr[]);
int countNum(char arr[]);
void saveChar(char outputPath[], char arr[]);

#endif 