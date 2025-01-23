#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool descending(int N){
    int i,j;
    bool test=1;
    while (N>10){
        i=N%10;
        N/=10;
        j=N%10;
        if (i>j) {
            test=0;
            break;
        }
    }
    return test;
}

bool symmetric(int N) {
    string m = to_string(N);
    bool test = true;

    int left = 0, right = m.length() - 1;
    
    while (left < right) {
        if (m[left] != m[right]) {
            test = false;
            break;
        }
        left++;
        right--;
    }
    
    return test;
}

int main() {
    int N;
    char line[100];
    
    cout<<"N = ";
    do {
        cin.getline(line,100);

    } while (!(stringstream(line)>>N));
   
    //Descending
    if (descending(N)){
        cout<<"Descending."<<endl;
    }
    else{
        cout<<"Not descending."<<endl;
    }

    //Symmetric
    if (symmetric(N)){
        cout<<"Symmetric.";
    }
    else{
        cout<<"Not symmetric.";
    }
    return 0;
}
