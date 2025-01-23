#include <iostream>
#define MAX 1000
using namespace std;

void inputArray(double a[], int &n){ 
    // a là con trỏ hằng, con trỏ sẽ đến vị trí đầu của mảng là a[0], vì vậy ta không truyền tham chiếu vào đây
    cout<<"Nhap so phan tu cua mang: ";
    cin>>n;
    // n là giá trị được nhập, sẽ thay đổi nên ta truyền tham chiếu
    for (int i=0;i<n;i++){
        cout<<"Phan tu thu "<<i<<" la: ";
        cin>>a[i]; //Giá trị trực tiếp của A[i] là thứ được thay đổi, nên ta truyền để tham chiếu để thay đổi giá trị của mảng tại index i
    }
}

void printArray(double a[], int n){
    for (int i=0;i<n;i++){
        cout<<"Gia tri phan tu thu "<<i<<" la:";
        cout<<a[i]<<endl;
    }
}

double sumArray(double a[], int n){
    double sum=0;
    for (int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}

double maxArray(double a[], int n){
    double max=a[0];
    for (int i=1;i<n;i++){
    if (max<a[i]) max=a[i];
    }
    return max;
}

double firstPositiveIndex(double a[], int n){
    for (int i = 0; i < n; i++)
    {
       if (a[i]>0) return i;
    }   
    return 0;
}

bool isAscending(double a[], int n){
    for (int i = 0; i < n-1; i++)
    {
        if (a[i]>a[i+1]) return 0;
    }   
    return 1; 
}

void insertArray(double a[], int &n, int value, int position){
    if (n>=MAX)
    {
        cout<<"Khong the nhap them";
        return;
    }
    for (int i=n;i>position;i--)
    {
        a[i]=a[i-1];
    }
    a[position]=value;
    n++;   
}

int main()
{
    double a[MAX];
    int n;
    inputArray(a,n);
    printArray(a,n);
    cout<<sumArray(a,n)<<endl<<maxArray(a,n)<<endl<<firstPositiveIndex(a,n)<<endl<<isAscending(a,n)<<endl;
    insertArray(a,n,22,1);
    printArray(a,n);

    return 0;
}
