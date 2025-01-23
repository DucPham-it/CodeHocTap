#include <iostream>

using namespace std;

int fixMark(double arr[], int n){
    int pos, first, last;
    bool firstCheck=true;
    for (int i=0; i < n; i++){
        if  (arr[i]==-1) {
            pos=i;
        }
        else {
            if (firstCheck) {
                first=i;
                firstCheck=false;
            }
            else {
                last=i;
            }
        }
    }
    
    double ruleNum=(arr[last]-arr[first])/(last-first);
    for (int i=0; i < n; i++){
        if (i!=pos && (i-1)!=pos && (i+1!=pos)){
            if (i==0){
                if (arr[i+1]-arr[i]!= ruleNum) return 0;
            }
            else{
                if (i==n-1){
                    if (arr[i]-arr[i-1]!= ruleNum) return 0;
                }
                else{
                    if (arr[i]-arr[i-1]!= ruleNum) return 0;
                    if (arr[i+1]-arr[i]!= ruleNum) return 0;
                }
            }
        }
    }

    if (pos==0) {
        double a=arr[pos+1]-ruleNum;
        if (a<0 or a>100) return 0;
        arr[pos]=a;
        return 1;
    }
    if (pos==n-1) {
        double a=arr[pos-1]+ruleNum;
        if (a<0 or a>100) return 0;
        arr[pos]=a;
        return 1;
    }
    if (arr[pos+1]-ruleNum == arr[pos-1]+ruleNum) {
       double a=arr[pos+1]-ruleNum;
       if (a<0 or a>100) return 0;
       arr[pos]=a;
       return 1;
    }
    return 0;
}

int main(){
    int n;  
    cin >> n;
     double *a = new double[n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    if (fixMark(a,n)==1) {
        for (int i=0; i<n; i++){
            cout << a[i] << ",";
        }
    }   
    else{
        cout << "FAILED" << endl;
        for (int i=0; i<n; i++){
            cout << a[i] << " ";
        }
    }
    delete[] a;
    return 0;
}