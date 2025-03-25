#include <iostream>
#include <string>
#include <vector>
using namespace std;

int charToIndex(char c) {
    if (c >= '0' && c <= '9') return c - '0';       
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;  
    return 0; 
}

string getMax(const vector<string>& arr)
{
    int n = arr.size();
    string max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i].length() > max.length())   
            max = arr[i];
    return max;
}

void countingSort(vector<string>& arr,int index)
{
    int n = arr.size();
    vector <string> output(n);
    int count[37] = {0};
    
    for (int i = 0; i < n; i++){
        char key;
        if (index < arr[i].length()){
            key =arr[i][index];
        }
        else {
            key = '0';
        }
        count[charToIndex(key)]++;
    }

    for (int i = 1; i < 37; i++){
        count[i] += count[i-1];
    }

    for (int i = n-1; i>= 0; i--) {
        char key;
        if (index < arr[i].length()){
            key =arr[i][index];
        }
        else {
            key = '0';
        }
        output[count[charToIndex(key)] -1] = arr[i];
        count[charToIndex(key)]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<string>& arr)
{
    int max = getMax(arr).length();
    for (int i = max - 1; i >= 0; i--) {
        countingSort(arr, i);
    }
}



int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <string> arr(n);
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, arr[i]);
    }

    radixSort(arr);

    for (int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}



