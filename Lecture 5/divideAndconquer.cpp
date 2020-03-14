#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

int binarySearch(int arr[], int n, int data) {

	int start = 0;
	int end = n - 1;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (arr[mid] == data) {
			return mid;

		} else if (arr[mid] > data) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return -1;
}

int lowerBound(int arr[], int n, int data) {

	int start = 0;
	int end = n - 1;

	int ans = -1;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (arr[mid] == data) {

			ans = mid;
			end = mid - 1;

		} else if (arr[mid] > data) {

			end = mid - 1;

		} else {

			start = mid + 1;

		}
	}

	return ans;
}

int searchRotatedArray(int arr[], int start, int end, int data) {
	if (start > end) {
		return -1;
	}

	int mid = (start + end) / 2;

	if (arr[mid] == data) {
		return mid;
	}

	if (arr[mid] <= arr[end]) {

		if (data > arr[mid] and data <= arr[end]) {
			return searchRotatedArray(arr, mid + 1, end, data);
		} else {
			return searchRotatedArray(arr, start, mid - 1, data);
		}

	} else {
		if (data<arr[mid] and data >= arr[start]) {
			return searchRotatedArray(arr, start, mid - 1, data);
		} else {
			return searchRotatedArray(arr, mid + 1, end, data);
		}
	}
}

bool isPossible(int arr[], int n, int k, int time) {

	int painter = 1;
	int painterTime = 0;

	for (int i = 0; i < n; i++) {

		painterTime += arr[i];

		if (painterTime > time) {
			painter += 1;
			painterTime = arr[i];

			if (arr[i] > time) return false;

			if (painter > k) {
				return false;
			}
		}

	}

	return true;
}

int painterProblem(int arr[], int n, int k) {

	int minTime = INT_MIN;
	int maxTime = 0;

	for (int i = 0; i < n; i++) {
		minTime = max(minTime, arr[i]);
		maxTime += arr[i];
	}

	int ans;

	int start = minTime;
	int end = maxTime;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (isPossible(arr, n, k, mid)) {
			ans = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ans;
}

int main() {

	// int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// int n = 9;
	// int data = 8;

	// cout << binarySearch(arr, n, data) << endl;

	// int arr[] = {1, 2, 2, 2, 2, 6, 6, 9, 9};
	// int n = 9;
	// int data = 2;

	// cout << lowerBound(arr, n, data) << endl;

	// int arr[] = {6, 7, 1, 2, 3, 4, 5};
	// int n = 7;
	// int data = 4;

	// cout << searchRotatedArray(arr, 0, n - 1, data) << endl;

	int board[] = {10, 20, 30, 40};
	int n = 4;
	int k = 2;

	cout << painterProblem(board, n, k) << endl;

	return 0;
}