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
#include <unordered_set>

using namespace std;

// Space: O(n)
// Time: O(n)
bool subarraySumZero(int arr[], int n) {

	unordered_map<int, bool> hp;
	// unordered_set<int> hp;

	int sum = 0;
	hp[sum] = true;

	for (int i = 0; i < n; i++) {

		sum += arr[i];

		// if (sum == 0) return true;

		if (hp.count(sum)) {
			return true;
		} else {
			hp[sum] = true;
		}
	}

	return false;
}

int longestSubarraySumZero(int arr[], int n) {

	unordered_map<int, int> hp;

	int sum = 0;
	hp[sum] = -1;

	int maxLen = 0;

	for (int i = 0; i < n; i++) {

		sum += arr[i];

		// if (sum == 0) maxLen = max(maxLen, i + 1);

		if (hp.count(sum)) {
			int currLen = i - hp[sum];
			maxLen = max(maxLen, currLen);
		} else {
			hp[sum] = i;
		}
	}

	return maxLen;
}

bool subarraySumK(int arr[], int n, int k) {



}

int main() {

	// int arr[] = {1, 2, 3, 4, 3, -4, 5};
	// int n = 7;

	// cout << subarraySumZero(arr, n) << endl;

	// int arr[] = {1, 2, 3, 4, -3, -4, 0};
	// int n = 7;

	// cout << longestSubarraySumZero(arr, n) << endl;

	int arr[] = {1, 2, 3, 4, 2, 1, 7};
	int n = 7;
	int k = 7;

	cout << subarraySumK(arr, n, k) << endl;

	return 0;
}