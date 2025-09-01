#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    int *arr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << reinterpret_cast<uintptr_t>(&(arr[i])) << " ";
    }
    
    return 0;
}