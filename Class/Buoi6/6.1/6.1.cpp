#include <iostream>
#include <cstring>  
using namespace std;

void cleanSpaces(char str[]) {
    int i = 0, j = 0;  
    while (str[i] == ' ') {
        i++;
    }

    bool spaceFound = false;  
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];  
            spaceFound = false;
        } else if (!spaceFound) {  
            str[j++] = ' ';
            spaceFound = true;
        }
        i++;
    }

    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }

    str[j] = '\0';  
}

int main() {
    char str[] = "     today is a  beautiful day "; 

    cleanSpaces(str);  
    cout << str << endl; 

    return 0;
}
