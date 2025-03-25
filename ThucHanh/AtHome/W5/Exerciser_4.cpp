#include <iostream>
#include <cstring>
using namespace std;

struct Student{
	char ID[11];
	float GPA;
	short age;
};

bool checkSort(Student a,Student b)
{
	if (a.GPA != b.GPA) return a.GPA < b.GPA;
	if (a.age != b.age) return a.age > b.age;
	return  strcmp(a.ID, b.ID) > 0;
}

void heapify(Student *arr, int n, int i ) {
	int  largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if (l < n && checkSort(arr[l], arr[largest]))
		largest = l;
	if (r < n && checkSort(arr[r], arr[largest]))
		largest = r;
	if (largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}	
}

void  heapSort(Student *arr, int n)
{
	for (int i = n/2 -1; i >=0; i--)
	 	heapify(arr,n, i);
	for (int i = n-1; i > 0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printListStudent(Student *arr, int n)
{
	for (int i = 0; i < n; i++){
		cout << arr[i].ID << " " << arr[i]. GPA << " " << arr[i].age << endl;
	}
}

int main(){
	int n;
	cin >> n;
	Student *a = new Student[n];
	for (int i = 0; i < n; i++){
		
		cin >> a[i].ID >> a[i].GPA >> a[i].age;
	}
	heapSort(a,n);

	cout << "Final : " << endl;
	
	printListStudent(a,n);

	delete[] a;
	return 0;
}
