#include <iostream>
#include <cmath>
using namespace std;

struct timeRoom {
	int start;
	int end;
};

void interChangeSort(int* arr, int n);
void insertionSort(int* arr, int n);
void selectionSort(int* arr, int n);
void bubbleSort(int* arr, int n);
void quickSort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);
void mergeSort(int* arr, int left, int right);
bool ascendingOrder(int a, int b);
bool descendingOrder(int a, int b);
void heapify(int* arr, int n, int i, bool (*comparator) (int, int));
void heapSort(int* arr, int n, bool(*comparator) (int, int));
void shellSort(int* arr, int left, int right);
void countingSort(int* arr, int n);
void radixSort(int* arr, int n); 
void quickSortTimeStart(timeRoom* arr, int l, int r);
bool checkTime(timeRoom* arr, int n);
int findMiniumDay(timeRoom* arr, int n);

