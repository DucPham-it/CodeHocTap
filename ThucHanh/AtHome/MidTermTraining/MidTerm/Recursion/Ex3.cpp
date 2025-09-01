#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

ll findFactorial(int n);
ll findFibonacci(int n);
int sumArray(int* arr, int n);
void floodFill(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor);

int main(){
	int m, n, sr, sc, newColor, originalColor;
	cin >> m >> n;
	vector<vector<int>> image(m, vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> image[i][j];
		}
	}
	cin >> sr >> sc;
	cin >> newColor;
	cout << endl;

	originalColor = image[sr][sc];

	floodFill(image, sr, sc, originalColor, newColor);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << image[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

ll findFactorial(int n) {
	if (n <= 1) return n;
	return n + findFactorial(n - 1);
}

ll findFibonacci(int n) {
	if (n <= 1) return n;
	return findFibonacci(n - 1) + findFibonacci(n - 2);
}

int sumArray(int* arr, int n) {
	if (n <= 0) return 0;
	return arr[n - 1] + sumArray(arr, n-1);
}

void floodFill(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor) {
	if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[sr].size() || image[sr][sc] != originalColor) return;
		image[sr][sc] = newColor;
		floodFill(image, sr - 1, sc, originalColor, newColor);
		floodFill(image, sr + 1, sc, originalColor, newColor);
		floodFill(image, sr, sc + 1, originalColor, newColor);
		floodFill(image, sr, sc - 1, originalColor, newColor);
}

