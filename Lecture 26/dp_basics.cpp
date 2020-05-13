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

//Time: O(2^n)
//Space: O(n)
int fib(int n) {
	if (n == 0 or n == 1) {
		return n;
	}

	cout << n << endl;

	int fibn1 = fib(n - 1);
	int fibn2 = fib(n - 2);

	int fibn = fibn1 + fibn2;
	return fibn;
}

//TOP DOWN
int fibMemo(int n, int dp[]) {
	if (n == 0 or n == 1) {
		dp[n] = n;
		return n;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	//RECURSIVE CASE
	int fibn1 = fibMemo(n - 1, dp);
	int fibn2 = fibMemo(n - 2, dp);

	int fibn = fibn1 + fibn2;

	dp[n] = fibn; // STORE IT IN YOUR DP

	for (int i = 0; i <= 5; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "**************************" << endl;

	return fibn;
}

// BOTTOM UP
int fibPUREDP(int n) {
	int dp[n + 1];

	// BASE CASE
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2]; // IMAGINE RECURSIVE CASE
	}

	return dp[n];
}


int reduceToOne(int n) {
	if (n == 1) {
		return 0;
	}

	int count1 = INT_MAX , count2 = INT_MAX , count3 = INT_MAX;

	if (n % 2 == 0) {
		count2 = reduceToOne(n / 2) + 1;
	}

	if (n % 3 == 0) {
		count3 = reduceToOne(n / 3) + 1;
	}

	count1 = reduceToOne(n - 1) + 1;

	int minOpertion = min(count1, min(count2, count3));

	return minOpertion;
}


int reduceToOneMemo(int n, int dp[]) {
	if (n == 1) {
		dp[n] = 0;
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n]; // CHECK
	}

	int count1 = INT_MAX , count2 = INT_MAX , count3 = INT_MAX;

	if (n % 2 == 0) {
		count2 = reduceToOneMemo(n / 2, dp) + 1;
	}

	if (n % 3 == 0) {
		count3 = reduceToOneMemo(n / 3, dp) + 1;
	}

	count1 = reduceToOneMemo(n - 1, dp) + 1;

	int minOpertion = min(count1, min(count2, count3));

	dp[n] = minOpertion; // STORE

	for (int i = 0; i <= 10; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "**************************" << endl;

	return minOpertion;
}

// BOTTOM UP
int reduceToOnePUREDP(int n) {

	int dp[n + 1];

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		// IMAGINE RECURSIVE

		// i < - input
		// if(i%2==0)reduceToOne(i/2) REPLACE->> dp[i/2]
		// if(i%3==0)reduceToOne(i/3) REPLACE->> dp[i/3]
		// reduceToOne(i-1) REPLACE->> dp[i-1]

		int count1 = INT_MAX , count2 = INT_MAX , count3 = INT_MAX;

		if (i % 2 == 0) {
			count2 = dp[i / 2] + 1;
		}

		if (i % 3 == 0) {
			count3 = dp[i / 3] + 1;
		}

		count1 = dp[i - 1] + 1;

		int minOpertion = min(count1, min(count2, count3));

		dp[i] = minOpertion;
	}

	return dp[n];
}

// MEMO
int countBoardPath(int start, int end) {
	if (start == end) {
		return 1;
	}

	if (start > end) {
		return 0;
	}

	int count = 0;

	for (int dice = 1; dice <= 6; dice++) {
		count += countBoardPath(start + dice, end);
	}

	return count;
}

int countBoardPathMemo(int start, int end, int dp[]) {
	if (start == end) {
		dp[start] = 1;
		return 1;
	}

	if (start > end) {
		return 0;
	}

	if (dp[start] != -1) {
		return dp[start]; // CHECK
	}

	int count = 0;

	for (int dice = 1; dice <= 6; dice++) {
		count += countBoardPathMemo(start + dice, end, dp);
	}

	dp[start] = count; // STORE

	for (int i = 0; i <= end; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "**************************" << endl;

	return count;
}

int countBoardPathPUREDP(int start, int end) {
	int dp[end + 1];

	//BASE
	dp[end] = 1;

	for (int i = end - 1; i >= 0; i--) {
		int count = 0;
		for (int dice = 1; dice <= 6; dice++) {
			if (i + dice > end) {
				break;
			}

			count += dp[i + dice];
		}
		dp[i] = count;
	}

	return dp[0];
}

// int countBoardPath(int end) {

// 	for (int i = 0; i = 6; i++) {
// 		count += countBoardPath(end - i);
// 	}

// 	return count;
// }

int numSquaresMemo(int n, vector<int> &dp) {
	if (n == 0) {
		dp[n] = 0;
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int minValue = INT_MAX;

	for (int i = 1; i * i <= n; i++) {
		int abhiTakKaAnswer = numSquaresMemo(n - i * i, dp) + 1;
		minValue = min(minValue, abhiTakKaAnswer);
	}

	dp[n] = minValue;

	for (int i = 0; i <= 10; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "**************************" << endl;


	return minValue;
}

int numSquaresPUREDP(int n) {
	vector<int> dp(n + 1, 0);

	// BASE CASE
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {

		// RECURSIVE
		int minValue = INT_MAX;

		for (int j = 1; j * j <= i; j++) {
			int abhiTakKaAnswer = dp[i - j * j] + 1;
			minValue = min(abhiTakKaAnswer, minValue);
		}

		dp[i] = minValue;
	}

	return dp[n];
}

int helper(int si, vector<int> &nums, vector<int> &dp) {
	if (si >= nums.size()) {
		return 0;
	}

	if (dp[si] != -1) {
		return dp[si];
	}

	int include = nums[si] + helper(si + 2, nums, dp);
	int skip = helper(si + 1, nums, dp);

	int result = max(include, skip);

	dp[si] = result;

	return result;
}

int rob(vector<int>& nums) {
	if (nums.size() == 0) return 0;

	vector<int> dp(nums.size() + 1, -1);

	return helper(0, nums, dp);
}

int robPUREDP(vector<int>& nums) {
	int n = nums.size();

	if (n == 0) return 0;

	vector<int> dp(n + 2);

	//BASE CASE
	dp[n + 1] = 0;
	dp[n] = 0;

	//RECURSIVE
	for (int i = n - 1; i >= 0; i--) {

		int include = nums[i] + dp[i + 2];
		int skip = dp[i + 1];

		dp[i] = max(include, skip);
	}

	return dp[0];
}


int helper(int n, vector<int> &dp) {
	if (n == 0 or n == 1) {
		return 1;
	}

	// check
	if (dp[n] != -1) {
		return dp[n];
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		int leftCount = helper(i - 1, dp);
		int rightCount = helper(n - i, dp);

		int mujheRoot = leftCount * rightCount;

		ans += mujheRoot;
	}

	//store
	dp[n] = ans;

	return ans;
}


int numTreesMemo(int n) {
	vector<int> dp(n + 1, -1);

	return helper(n, dp);
}

int main() {

	// int n = 5;

	// int dp[n + 1];
	// memset(dp, -1, sizeof(dp));
	// cout << fibMemo(n, dp) << endl;

	// int n = 10;
	// cout << reduceToOne(21) << endl;

	// int dp[n + 1];
	// memset(dp, -1, sizeof(dp));
	// cout << reduceToOneMemo(n, dp) << endl;

	// cout << reduceToOnePUREDP(n) << endl;

	// int start = 0;
	// int end = 10;
	// int dp[end + 1];
	// memset(dp, -1, sizeof(dp));
	// cout << countBoardPathMemo(start, end, dp) << endl;

	// int n = 10;
	// cout << numSquares(n) << endl;

	return 0;
}