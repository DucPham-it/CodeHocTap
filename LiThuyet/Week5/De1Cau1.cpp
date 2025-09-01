#include <iostream>
#include<vector>
using namespace std;
int partition(vector<char> &arr, int left,int right)
{
    int pivot=arr[right];
    int j=right-1;
    for(int i=right-1;i>=left;i--)
    {
        if(arr[i]<pivot)
        {
            swap(arr[i],arr[j]);
            j--;
        }
    }
    swap(arr[right],arr[j+1]);
    return j+1;
}
void quicksort(vector<char> &arr, int left, int right)
{
    int pivot=partition(arr,left,right);
    if(left<pivot-1)
    {
        quicksort(arr,left,pivot-1);
    }
    if(pivot<right)
    {
        quicksort(arr,pivot,right);
    }
}
int main()
{
    vector<char> arr={'F','I','T','A','N','N','I','V','E','R','S','A','R','Y','3','0'};
    int n=arr.size();
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

