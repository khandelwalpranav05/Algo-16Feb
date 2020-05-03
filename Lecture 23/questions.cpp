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

	unordered_map<int, string> hp;
	// unordered_set<int> hp;

	int sum = 0;

	for (int i = 0; i < n; i++) {

		sum += arr[i];

		if (hp.count(sum)) {
			return true;
		} else {
			hp[sum] = true;
		}
	}

	return false;
}

int longestSubarraySumZero(int arr[], int n) {

}

int main() {

	int arr[] = {1, 2, 3, 4, 3, -4, 5};
	int n = 7;

	cout << subarraySumZero(arr, n) << endl;

	return 0;
}