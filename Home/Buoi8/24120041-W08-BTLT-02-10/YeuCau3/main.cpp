#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int toNumInAlphaB(char *a) {
    const char* alphaB = "abcdefghijklmnopqrstuvwxyz"; 

    char copy1[100] = ""; 

    for (int i = 0; i < strlen(a); i++) {
      
        int position = strchr(alphaB, a[i]) - alphaB;
        char cp1[10];
        sprintf(cp1, "%d", position);
        strcat(copy1, cp1);
    }

    return atoi(copy1);
}

bool checkEqual(char* first, char* second, char* target){
    int a= toNumInAlphaB(first) + toNumInAlphaB(second);
    int b= toNumInAlphaB(target);
    return a==b;
}

int main(){
    char *first = new char[1000];
    char *second = new char[1000];
    char *target = new char[1000];
    cin.getline(first,1000);
    cin.getline(second,1000);
    cin.getline(target,1000);

    if (checkEqual(first, second, target))
        cout << "YES";
    else
        cout << "NO";
        
    delete[] first;
    delete[] second;
    delete[] target;
    return 0;
}