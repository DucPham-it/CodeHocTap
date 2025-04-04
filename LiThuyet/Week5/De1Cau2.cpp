#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr={7,1,2,5,8,12,32};

    sort(arr.begin(),arr.end());
    for(int c:arr)
    {
        cout<<c<<" ";
    }
    cout << endl;
    int k =3;
    int min = 1000;
    for (int i =0; i < arr.size(); i++){
        if (arr[i+k-1]-arr[i] < min && arr[i+k-1]-arr[i] > 0)
            min = arr[i+k-1]-arr[i];
    }
    cout << min << endl;
    return 0;
}
