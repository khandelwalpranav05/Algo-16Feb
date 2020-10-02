#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main() {

	int arr[] = {1, 2, 3, 4};
	int n = 4;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	swap(arr, 0, 3);
	cout << "****************" << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// cout << arr[6] << endl;

	// cout << arr << endl;
	// cout << (arr + 1) << endl;

	// cout << sizeof(arr) << endl;

	// char brr[] = {'a', 'b', 'c', 'd', '\0'};

	// cout << brr << endl;

	// char brr[] = "abcd";
	// cout << brr << endl;

	return 0;
}
