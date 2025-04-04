#include <iostream>
using namespace std;

struct Job{
	char name[256];
	float time;
};

void insertionSort(Job *arr, int n)
{
	for (int i = 1; i < n; i++){
		Job key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j].time > key.time){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

float average(Job *arr, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i].time;
	}
	return (sum / (float)n);
}

int main(){
  	int n;
    cin >> n;
	Job *arr = new Job[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].time;
	}
	insertionSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].name << endl;
	}
	cout << average(arr, n) << endl;

    delete[] arr;

	return 0;
}
