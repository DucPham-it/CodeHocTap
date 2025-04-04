#include <iostream>
#include <vector>
#include <cmath>
#include <list> 

using namespace std;

int h(int key, int m) {
    return key % m; 
}

int g(int key, int mod) {
    return (key * 2654435761ULL) % mod; 
}

void putToPerfectTable(vector<int>& arr, vector<vector<list<int>>>& T, vector<int>& c, int m) {
    c.resize(m, 0);
    T.resize(m);

    for (int i = 0; i < arr.size(); i++) {
        c[h(arr[i], m)]++;
    }

    for (int i = 0; i < m; i++) {
        int size = c[i] * c[i]; 
        T[i].resize(size); 
    }

    for (int i = 0; i < arr.size(); i++) {
        int j = h(arr[i], m);
        int size = c[j] * c[j];
        int k = g(arr[i], size) % size;
        T[j][k].push_back(arr[i]); 
    }

}

bool lookUpPerfectTable(int x, vector<vector<list<int>>>& T, vector<int>& c, int m) {
    int i = h(x, m);
    int size = c[i] * c[i];
    if (size == 0) return false; 
    int j = g(x, size) % size;
    
    for (int val : T[i][j]) {
        if (val == x) return true;
    }
    return false;
}

int main() {
    vector<int> arr = {10, 22, 37, 40, 52, 60, 75, 85};
    int m = 10;  

    vector<vector<list<int>>> T; 
    vector<int> c;

    putToPerfectTable(arr, T, c, m);

    cout << "FIND 37: " << (lookUpPerfectTable(37, T, c, m) ? "YES" : "NO") << endl;
    cout << "FIND 100: " << (lookUpPerfectTable(100, T, c, m) ? "YES" : "NO") << endl;
    cout << "FIND 60: " << (lookUpPerfectTable(60, T, c, m) ? "YES" : "NO") << endl; 

    for (int i = 0; i < m; i++) {
        cout << "Bucket " << i << " (" << c[i] << " items): ";
        for (int j = 0; j < T[i].size(); j++) {
            for (int val : T[i][j]) {
                cout << val << " ";
            }
        }
        cout << endl;
    }

    return 0;
}