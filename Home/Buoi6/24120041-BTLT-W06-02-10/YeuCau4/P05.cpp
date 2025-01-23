#include "header.h"

void loadOpe(char inputPath[], operation arr[], int& n){
     ifstream f(inputPath);
    if (f.is_open()==false){
        cout <<"Error input"<< endl;
        return;
    }
    n=0;
    char line[MAX];
    while (f.peek() != EOF){
        f.getline(line,MAX);
        stringstream(line) >> arr[n].ope1 >> arr[n].op >>arr[n].ope2;
        n++;
    }
}

void saveResult(char outputPath[], operation arr[], int n){
    ofstream f(outputPath);
    if (f.is_open()==false){
        cout <<"Error output"<< endl;
        return;
    }
    for (int i=0; i<n; i++)
        switch (arr[i].op)
        {
        case '+':
            f << arr[i].ope1+arr[i].ope2 << endl;
            break;
        case '-':
            f << arr[i].ope1-arr[i].ope2 << endl;
            break;
        case '*':
            f << arr[i].ope1*arr[i].ope2 << endl;
            break;
        case '/':
        if (arr[i].ope2 != 0){
            f << arr[i].ope1/arr[i].ope2 << endl;
        }
        else {
            f << "Divided by zero" << endl; 
        }
            break;        
        default:
            f << "Error" << endl;
            break;
        }
    f.close();
}
