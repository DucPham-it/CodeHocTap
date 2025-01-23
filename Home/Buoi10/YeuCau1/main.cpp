#include "Header.h"

int main() {
    char src[1000], sub[100], rep[100];

    cout << "src= ";
    cin.getline(src, 1000);

    cout << "sub= ";
    cin.getline(sub, 100);

    cout << "rep= ";
    cin.getline(rep, 100);

    char* result = replaceStr(src, sub, rep);
    if (result != nullptr) {
        cout << "Result string= " << result << endl;
        delete[] result;
    } else {
        cout << "Error" << endl;
    }

    return 0;
}
