#include <iostream>
#include <utility>

int linearSearch(int arr[], int n, int key);
int sentinelLinearSearch(int arr[], int n, int key);

int main(int argc, char *argv[]) { return 0; }

int linearSearch(int arr[], int n, int key) {
    int index = -1;
    int comp = 0;
    for (int i = 0; i < n; i++) {
        comp++;
        if (arr[i] == key)
            index = i;
    }
}

int sentinelLinearSearch(int arr[], int n, int key) {}
