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

void printSubarrays(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			//Printing
			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}
			cout << endl;
		}
	}
}

int maxSubarraySum(int arr[], int n) {

	int maxSum = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			int sum = 0;

			//Sum
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}

			// if (sum > maxSum) {
			// 	maxSum = sum;
			// }

			maxSum = max(maxSum, sum);
		}
	}

	return maxSum;
}

int main() {

	int arr[] = {1, -2, 3, 4};
	int n = 4;

	printSubarrays(arr, n);

	cout << maxSubarraySum(arr, n) << endl;

	return 0;
}