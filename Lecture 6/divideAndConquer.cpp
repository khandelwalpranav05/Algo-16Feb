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

bool canWePlace(int arr[], int n, int cows, long minDist) {

	int abhiTakKiCows = 1;
	int abhiTakKiPosition = arr[0];

	for (int i = 1; i < n; i++) {

		int dist = arr[i] - abhiTakKiPosition;

		if (dist >= minDist) {
			abhiTakKiCows++;
			abhiTakKiPosition = arr[i];

			if (abhiTakKiCows == cows) {
				return true;
			}
		}
	}

	return false;
}

int aggressiveCows(int arr[], int n, int cows) {

	sort(arr, arr + n);

	long start = 0;
	long end = arr[n - 1] - arr[0];

	long ans;

	while (start <= end) {

		long mid = (start + end) / 2;

		if (canWePlace(arr, n, cows, mid)) {
			ans = mid;
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return ans;
}
// s                    e
// {2, 4, 6, 7, 1, 3, 5, 9}

void merge(int arr[], int start, int end) {

	int mid = (start + end) / 2;

	int i = start;
	int j = mid + 1;

	int temp[end - start + 1];
	int k = 0;

	while (i <= mid and j <= end) {

		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		} else {
			temp[k] = arr[j];
			j++;
			k++;
		}
	}

	while (j <= end) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	while (i <= mid) {
		temp[k] = arr[i];
		i++;
		k++;
	}

	int p = 0;
	for (int x = start; x <= end; x++) {
		arr[x] = temp[p];
		p++;
	}

}

void mergeSort(int arr[], int start, int end) {
	if (start == end) {
		return;
	}

	int mid = (start + end) / 2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	merge(arr, start, end);
}

int find(vector<int> &nums, int start, int end) {

	int n = nums.size();

	int mid = (start + end) / 2;

	if ((mid == 0 or nums[mid] > nums[mid - 1]) and (mid == n - 1 or nums[mid] > nums[mid + 1])) {
		return mid;
	}

	if (nums[mid] > nums[mid + 1]) {
		return find(nums, start, mid - 1);
	} else {
		return find(nums, mid + 1, end);
	}
}

bool isValid(vector<int> &nums, int m, long maxSum) {

	int split = 1;
	long splitSum = 0;

	for (int i = 0; i < nums.size(); i++) {

		splitSum += nums[i];

		if (splitSum > maxSum) {
			split++;
			splitSum = nums[i];

			if (split > m) {
				return false;
			}
		}
	}

	return true;
}

int splitArray(vector<int>& nums, int m) {

	int minSum = nums[0];
	long maxSum = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		minSum = max(minSum, nums[i]);
		maxSum += nums[i];
	}

	long start = minSum;
	long end = maxSum;

	long ans;

	while (start <= end) {

		long mid = (start + end) / 2;

		if (isValid(nums, m, mid)) {
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

	// int board[] = {10, 20, 30, 40};
	// int n = 4;
	// int k = 2;

	// cout << painterProblem(board, n, k) << endl;

	// int arr[] = {1 , 2 , 8 , 4 , 9};
	// int n = 5;
	// int cows = 3;

	// cout << aggressiveCows(arr, n, cows) << endl;

	// int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
	// int n = 8;

	// mergeSort(arr, 0, n - 1);

	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	return 0;
}