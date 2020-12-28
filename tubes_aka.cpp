#include <bits/stdc++.h>
using namespace std;

vector<int> tmp, arr;

void Iterative_sorting(int n) { // bubble sort
	// n = size of array
	for (int i = n-1; i >= 1; --i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}
}

void Recursive_sort(int left, int right) { // merge sort
	int n = right-left + 1;
	int mid = (left + right)/2;

	if (n > 1) {
		// recursive

		Recursive_sort(left, mid);
		Recursive_sort(mid+1, right);
		int i = left, j = mid+1, idx = left;
		// merge section
		while (i <= mid && j <= right) {
			if (arr[i] < arr[j]) tmp[idx++] = arr[i++];
			else tmp[idx++] = arr[j++];
		}
		while (i <= mid) tmp[idx++] = arr[i++];
		while (j <= right) tmp[idx++] = arr[j++];
	} else return; // base case


	for (int k = left; k <= right; ++k) {
		arr[k] = tmp[k];
	}
}

int main() {
	arr = {5,2,1,4,10,3,6,7,9,8,12,14,13,15};
	int n = arr.size();
	tmp = vector<int>(n);
	//Recursive_sort(0, n-1);
	Iterative_sorting(n);
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
}
