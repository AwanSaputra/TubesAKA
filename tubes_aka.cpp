#include <bits/stdc++.h>
using namespace std;


void Iterative_sorting(int *arr, int n) { // bubble sort
	// n = size of array
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n-1-i; ++j) {
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}
	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << endl;
	}
}

void Recursive_sort(int *arr, int left, int right) { // merge sort
	int n = right-left + 1;
	int tmp[n];
	int mid = (left + right)/2;

	if (n > 1) {
		// recursive

		Recursive_sort(arr, left, mid);
		Recursive_sort(arr, mid+1, right);
		int i = left, j = mid+1, idx = left;
		// merge section
		while (i <= mid && j <= right) {
			if (arr[i] < arr[j]) tmp[idx++] = arr[i++];
			else tmp[idx++] = arr[j++];
		}
		while (i <= mid) tmp[idx++] = arr[i++];
		while (j <= right) tmp[idx++] = arr[j++];
	} else return; // base case


	for (int k = left; k <= right; ++k)
		arr[k] = tmp[k];
}

int main() {
	int arr[5] = {5,2,1,4,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	Recursive_sort(arr, 0, n-1);
	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << endl;
	}
	//Iterative_sorting(arr, n);
}
