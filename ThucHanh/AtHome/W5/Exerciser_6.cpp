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
int main(){
	Job arr[5] = {{"JobA", 3},
		{"JobB", 1},
		{"JobC", 4},
		{"JobD", 2},
		{"JobE", 5}};
	insertionSort(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i].time << endl;
	}
	
	return 0;
}
