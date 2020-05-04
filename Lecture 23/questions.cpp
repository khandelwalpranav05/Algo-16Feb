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

	unordered_map<int, bool> hp;

	int sum = 0;
	hp[sum] = true;

	for (int i = 0; i < n; i++) {

		sum += arr[i];

		// if (sum == k) return true;

		if (hp.count(sum - k)) {
			return true;
		} else {
			hp[sum] = true;
		}
	}

	return false;
}

int longestSubarraySumK(int arr[], int n, int k) {
	// TODO

	return 0;
}

int lengthOfLongestSubstring(string str) {

	int left = 0;
	int right = 0;

	unordered_map<char, int> hp;

	int maxLen = 0;

	while (right < str.length()) {
		char ch = str[right];
		if (hp[ch] == 0) {
			hp[ch] += 1;
			right++;
			int currLen = right - left;
			maxLen = max(currLen, maxLen);
		} else {
			char leftCh = str[left];
			hp[leftCh]--;
			left++;
		}
	}

	return maxLen;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> >> pq;

	unordered_map<int, int> hp;

	for (int num : nums) {
		hp[num] += 1;
	}

	for (auto val : hp) {
		pq.push({val.second, val.first});
	}

	while (pq.size() > k) {
		pq.pop();
	}

	vector<int> res;

	while (!pq.empty()) {
		auto temp = pq.top();
		pq.pop();

		res.push_back(temp.second);
	}

	return res;
}

int main() {

	// int arr[] = {1, 2, 3, 4, 3, -4, 5};
	// int n = 7;

	// cout << subarraySumZero(arr, n) << endl;

	// int arr[] = {1, 2, 3, 4, -3, -4, 0};
	// int n = 7;

	// cout << longestSubarraySumZero(arr, n) << endl;

	// int arr[] = {1, 2, 3, 4, 2, 1, 7};
	// int n = 7;
	// int k = 7;

	// cout << subarraySumK(arr, n, k) << endl;

	// auto a = 10.23;

	// cout << sizeof(a) << endl;

	return 0;
}