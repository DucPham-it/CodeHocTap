#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll linearSearch(ll *arr, ll n, ll key, int& comparisons);
ll binarySearch(ll* arr, ll left, ll right, ll key, int& comparisons);
bool twoPointers(ll* arr, ll n, ll target, int& comparisons);
ll sentinelLinearSreach(ll* arr, ll n, ll key, int& comparisons);
ll metaBinarySearch(ll* arr, ll n, ll key, int& comparisons);
ll ternarySearch(ll* arr, ll left, ll right, ll key, int& comparisons);
ll jumpSearch(ll* arr, ll n, ll key, int& comparisons);
ll interpolationSearch(ll* arr, ll n, ll key, int& comparisons);
ll exponentialSearch(ll* arr, ll n, ll key, int& comparisons);
ll fibonacciSearch(ll* arr, ll n, ll key, int& comparisons);
ll findTheFirstIndex(ll* arr, ll n, ll key);
ll findTheLastIndex(ll* arr, ll n, ll key);
ll findSmallestInRotateArray(ll* arr, ll n);

 int main() {
	 ll n = 10;
	 ll arr[] = { 1, 3, 3, 3, 5, 7, 7, 7, 9, 9 };
	 ll index1 = findTheFirstIndex(arr, n, 3);
	 ll index2 = findTheLastIndex(arr, n, 3);
	 cout << index1 << " " << index2 << endl;
}

ll linearSearch(ll* arr, ll n, ll key, int& comparisons) {
		for (ll i = 0; i < n; i++) {
			comparisons++;
			if (arr[i] == key) {
				return i;
			}
		}
		return -1;
}

ll binarySearch(ll* arr, ll left, ll right, ll key, int& comparisons) {
	
	comparisons++;
	if (left <= right) {
		ll mid = (left + right) / 2;
		comparisons++;
		if (arr[mid] == key) return mid;
		comparisons++;
		if (arr[mid] < key) 
			return binarySearch(arr, mid + 1, right, key, comparisons);
		comparisons++;
		if (arr[mid] > key)
			binarySearch(arr, left, mid -1 , key, comparisons);
	}
	return -1;
}

bool twoPointers(ll* arr, ll n, ll target, int& comparisons) {
	ll left = 0;
	ll right = n - 1;
	bool check = false;
	while (left < right)
	{	
		ll sum = arr[left] + arr[right];
		if (sum == target) {
			cout << left << " " << right << endl;
			check = true;
			left++;
			right--;
		}
		else if (sum < target) {
			left++;
		}
		else {
			right--;
		}
	}
	return check;
}

ll sentinelLinearSreach(ll* arr, ll n, ll key, int& comparisons) {
	ll last = arr[n - 1];
	arr[n - 1] = key;
	ll i = 0;

	while (arr[i] != key)
	{	
		comparisons++;
		i++;
	}
	arr[n - 1] = last;

	comparisons++;
	if (i < n - 1) {
		return i;
	}
	if (arr[n - 1] == key) {
		return n - 1;
	}

	return -1;
}

ll metaBinarySearch(ll* arr, ll n, ll key, int& comparisons) {
	ll pos = -1;
	for (ll bit = log2(n) -1 ; bit >= 0; bit--) {
		comparisons++;
		if (pos + (1 << bit) < n && arr[pos + (1 << bit)] < key) {
			pos += (1 << bit);
		}
	}
	return (arr[pos] == key) ? pos : -1;
}

ll ternarySearch(ll* arr, ll left, ll right, ll key, int& comparisons) {
	if (left <= right) {
		ll mid1 = left + (right - left) / 3;
		comparisons++;
		if (arr[mid1] == key) return mid1;
		ll mid2 = right - (right - left) / 3;
		comparisons++;
		if (arr[mid2] == key) return mid2;
		comparisons++;
		if (arr[mid1] > key)
			return ternarySearch(arr, left, mid1 - 1, key, comparisons);
		comparisons++;
		if (arr[mid2] < key)
			return ternarySearch(arr, mid2 + 1, right, key, comparisons);		
		return ternarySearch(arr, mid1 + 1, mid2 -1, key, comparisons);		
	}
	return -1;
}

ll jumpSearch(ll* arr, ll n, ll key, int& comparisons) {
	ll step = sqrt(n);
	ll prev = 0;

	while (arr[min(step, n) -1] < key)
	{
		comparisons++;
		prev = step;
		step += sqrt(n);
		if (step >= n)
			return -1;
	}
	while (arr[prev] < key)
	{
		prev++;
	}
	comparisons++;
	if (prev >= min(step, n)) {
		return -1;
	}
	if (arr[prev] == key) {
		return prev;
	}
	return -1;
}

ll interpolationSearch(ll* arr, ll n, ll key, int& comparisons) {
	return -1;
}

ll exponentialSearch(ll* arr, ll n, ll key, int& comparisons) {
	return -1;
}

ll min(ll a, ll b) {
	return (a > b) ? b : a;
}

ll fibonacciSearch(ll* arr, ll n, ll key, int& comparisons) {
	ll offset = -1;
	ll Fm2 = 0;
	ll Fm1 = 1;
	ll Fm = Fm2 + Fm1;
	while (Fm < n) {
		Fm2 = Fm1;
		Fm1 = Fm;
		Fm = Fm2 + Fm1;
	}
	while (Fm > 1) {
		ll i = min(offset + Fm2, n - 1);
		if (arr[i] < key) {
			Fm = Fm1;
			Fm1 = Fm2;
			Fm2 = Fm - Fm1;
			offset = i;
		}
		else if (arr[i] > key) {
			Fm = Fm2;
			Fm1 = Fm1 - Fm2;
			Fm2 = Fm - Fm1;
		}
		else
			return i;
	}
	if (Fm1 && arr[offset + 1] == key)
		return offset + 1;
	return -1;
}

ll findTheFirstIndex(ll* arr, ll n, ll key) {
	ll left = 0;
	ll right = n - 1;
	ll result = -1;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (arr[mid] == key) {
			result = mid;
			right = mid - 1;
		}
		else if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}

ll findTheLastIndex(ll* arr, ll n, ll key) {
	ll left = 0;
	ll right = n - 1;
	ll result = -1;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (arr[mid] == key) {
			result = mid;
			left = mid + 1;
		}
		else if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}

ll findSmallestInRotateArray(ll* arr, ll n) {
	ll left = 0;
	ll right = n - 1;
	ll mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] > arr[mid + 1]) {
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return mid;
}