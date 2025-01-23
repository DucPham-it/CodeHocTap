#include "Header.h"

void loadChar(char inputPath[], char arr[]){
    ifstream f(inputPath);
    if (f.is_open()==false){
        cout <<"Error input"<< endl;
        return;
    }
    f.getline(arr,MAX);

    f.close();
}

bool seeChar(char a){
    for (char i='a'; i<='z'; i++) if (a==i) return 1;
    for (char i='A'; i<='Z'; i++) if (a==i) return 1;
    return 0;
}

bool seeNum(char a){
    for (char i='0'; i<='9'; i++) if (a==i) return 1;   
    return 0;
}

int countNumWord(char arr[]){
    int count=0;
    for (long long i=0; i<strlen(arr); i++){
        if (seeChar(arr[i])){
            if ((i==0) || (!seeChar(arr[i-1])))  count ++; 
        }
    }
    return count;
}

int countNum(char arr[]){
     int count=0;
    for (long long i=0; i<strlen(arr); i++){
        if (seeNum(arr[i])){
            if ((i==0) || (!seeNum(arr[i-1])))  count ++; 
        }
    }
    return count;
}
void saveChar(char outputPath[], char arr[]){
    ofstream f(outputPath);
    if (f.is_open()==false){
        cout <<"Error output"<< endl;
        return;
    }
    f << "Word count: " << countNumWord(arr) << endl;
    f << "Number count: " << countNum(arr) << endl;
    f.close();
}


