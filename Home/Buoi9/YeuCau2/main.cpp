#include "Header.h"

int main(){
    polynomial* poly = new polynomial[1000];
    int count;

    readBinaryFile(poly, count);

    for (int i=0; i <count ; i++){
        cout << poly[i].n << " ";
        for (int j=0; j<poly[i].n; j++){
            cout << poly[i].mono[j].degree << " ";
            cout << poly[i].mono[j].coefficient << " ; ";
        }
        cout << endl;
    }

    for (int i = 0; i < count; i++) {
        delete[] poly[i].mono;
    }
    delete[] poly;
}