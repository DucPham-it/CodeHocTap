#include "Header.h"

int main(){
    char arr[MAX];
    char inputPath[]="INPUT.TXT";
    char outputPath[]="OUTPUT.TXT";
    loadChar(inputPath, arr);
    saveChar(outputPath, arr);
    return 0;
}