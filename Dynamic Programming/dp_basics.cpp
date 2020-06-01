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

int numTreesPUREDP(int n) {

	vector<int> dp(n + 1);

	// BASE CASE
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {

		int ans = 0;
		// i <- problem
		// RECURSIVE
		for (int x = 1; x <= i; x++) {
			int leftCount = dp[x - 1];
			int rightCount = dp[i - x];
			ans += leftCount * rightCount;
		}

		dp[i] = ans;
	}

	return dp[n];
}

int numTreesMemo(int n) {
	vector<int> dp(n + 1, -1);

	return helper(n, dp);
}

int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();

	if (n == 0) {
		return 0;
	}

	vector<int> dp(n, 1);

	int maxValue = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxValue = max(dp[i], maxValue); // 1
	}

	// for(int val:dp){    // 2
	//     maxValue = max(maxValue,val);
	// }

	return maxValue;
}


// Time:O(n^2)
int helper(int i, string &s1, int j, string &s2, vector<vector<int> > &dp) {
	// BASE CASE
	if (i == s1.length() or j == s2.length()) {
		dp[i][j] = 0;
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int result;

	if (s1[i] == s2[j]) {
		result = 1 + helper(i + 1, s1, j + 1, s2, dp);
	} else {

		int first = helper(i + 1, s1, j, s2, dp);
		int second = helper(i, s1, j + 1, s2, dp);

		result = max(first, second);
	}

	dp[i][j] = result;

	for (int x = 0; x <= s1.length(); x++) {
		for (int y = 0; y <= s2.length(); y++) {
			cout << dp[x][y] << "\t";
		}
		cout << endl;
	}
	cout << "************************************" << endl;

	return result;
}

int longestCommonSubsequenceMemo(string text1, string text2) {

	int row = text1.length() + 1;
	int col = text2.length() + 1;

	vector<vector<int> > dp(row, vector<int> (col, -1));

	return helper(0, text1, 0, text2, dp);
}


// Time:O(n^2)
int longestCommonSubsequencePUREDP(string s1, string s2) {

	int row = s1.length() + 1;
	int col = s2.length() + 1;

	vector<vector<int> > dp(row, vector<int> (col, 0));

	// BASE CASE
	for (int i = 0; i < row; i++) {
		dp[i][s2.length()] = 0;
	}

	for (int i = 0; i < col; i++) {
		dp[s1.length()][i] = 0;
	}


	for (int i = s1.length() - 1; i >= 0; i--) {
		for (int j = s2.length() - 1; j >= 0; j--) {

			int result;

			// RECURSIVE
			if (s1[i] == s2[j]) {
				result = 1 + dp[i + 1][j + 1];
			} else {
				int first = dp[i + 1][j];
				int second = dp[i][j + 1];

				result = max(first, second);
			}

			dp[i][j] = result;
		}
	}


	return dp[0][0];
}


int numDistinctMemo(int si, string &s, int ti, string &t, vector<vector<int> > &dp) {
	// BASE CASE
	if (ti == t.length()) {
		return 1;
	}

	if (si == s.length()) {
		return 0;
	}

	if (dp[si][ti] != -1) {
		return dp[si][ti];
	}

	// RECURSIVE CASE
	int count = 0;

	if (s[si] == t[ti]) {
		count += numDistinctMemo(si + 1, s, ti + 1, t, dp);
	}

	count += numDistinctMemo(si + 1, s, ti, t, dp);

	dp[si][ti] = count;

	for (int x = 0; x <= s.length(); x++) {
		for (int y = 0; y <= t.length(); y++) {
			cout << dp[x][y] << "\t";
		}
		cout << endl;
	}
	cout << "************************************" << endl;

	return count;
}

int numDistinct(string s, string t) {

	int row = s.length() + 1;
	int col = t.length() + 1;

	vector<vector<int> > dp(row, vector<int> (col, -1));

	return numDistinctMemo(0, s, 0, t, dp);
}

int numDistinctPUREDP(string s, string t) {

	int row = s.length() + 1;
	int col = t.length() + 1;

	vector<vector<long> > dp(row, vector<long> (col, 0));

	// BASE CASE

	for (int i = 0; i < col; i++) {
		dp[s.length()][i] = 0;
	}

	for (int i = 0; i < row; i++) {
		dp[i][t.length()] = 1;
	}

	for (int si = s.length() - 1; si >= 0; si--) {
		for (int ti = t.length() - 1; ti >= 0; ti--) {
			// RECURSIVE

			int count = 0;

			if (s[si] == t[ti]) {
				count += dp[si + 1][ti + 1];
			}

			count += dp[si + 1][ti];

			dp[si][ti] = count;
		}
	}

	return dp[0][0];
}

int helper(string &s, int left, int right, vector<vector<int> > &dp) {
	//BASE CASE
	if (left == right) {
		return 1;
	}

	if (left > right) {
		return 0;
	}

	if (dp[left][right] != -1) {
		return dp[left][right];
	}

	// RECURSIVE
	int result;

	if (s[left] == s[right]) {
		result = helper(s, left + 1, right - 1, dp) + 2;
	} else {
		int first = helper(s, left + 1, right, dp);
		int second = helper(s, left, right - 1, dp);

		result = max(first, second);
	}

	dp[left][right] = result;

	return result;
}

int longestPalindromeSubseq(string s) {
	int n = s.length();

	vector<vector<int> > dp(n, vector<int> (n, -1));

	return helper(s, 0, n - 1, dp);
}

int helper(vector<vector<int> >& grid, int sr, int sc, vector<vector<int> > &dp) {
	int n = grid.size();
	int m = grid[0].size();
	// BASE CASE
	if (sr == n - 1 and sc == m - 1) {
		return grid[n - 1][m - 1];
	}

	if (sr > n - 1 or sc > m - 1) {
		return INT_MAX;
	}

	if (dp[sr][sc] != -1) {
		return dp[sr][sc];
	}

	// RECURSIVE
	int value = grid[sr][sc];

	int rightMinSum = helper(grid, sr, sc + 1, dp);
	int downMinSum = helper(grid, sr + 1, sc, dp);

	int result = min(rightMinSum, downMinSum) + value;

	dp[sr][sc] = result;

	return result;
}

int minPathSum(vector<vector<int> >& grid) {
	int n = grid.size();
	if (n == 0) {
		return 0;
	}
	int m = grid[0].size();

	vector<vector<int> > dp(n, vector<int> (m, -1));

	return helper(grid, 0, 0, dp);
}

int maxEnvelopes(vector<vector<int> > &envelopes) {

	int n = envelopes.size();

	if (n == 0) {
		return 0;
	}

	sort(envelopes.begin(), envelopes.end());

	vector<int> dp(n, 1);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	return *max_element(dp.begin(), dp.end());
}

int longestPalindromeSubseqPUREDP(string s) {

	int n = s.length();

	vector<vector<int> > dp(n, vector<int> (n, 0));

	//BASE CASE
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	for (int col = 1; col < n; col++) {
		for (int row = col - 1; row >= 0; row--) {
			// RECURSIVE

			if (s[row] == s[col]) {
				dp[row][col] = dp[row + 1][col - 1] + 2;
			} else {
				dp[row][col] = max(dp[row + 1][col], dp[row][col - 1]);
			}
		}
	}

	return dp[0][n - 1];
}

int knapSackDP[5][9];

int knapSack(int si, int weight[], int value[], int capacity, int n) {
	//BASE CASE
	if (si == n) {
		knapSackDP[si][capacity] = 0;
		return 0;
	}

	if (knapSackDP[si][capacity] != -1) {
		return knapSackDP[si][capacity];
	}

	int include = INT_MIN;
	int exclude = INT_MIN;

	if (weight[si] <= capacity) {
		include = value[si] + knapSack(si + 1, weight, value, capacity - weight[si], n);
	}

	exclude = knapSack(si + 1, weight, value, capacity, n);

	int result = max(include, exclude);

	knapSackDP[si][capacity] = result;

	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 8; j++) {
			cout << knapSackDP[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "*******************************" << endl;

	return result;
}

int knapSackDIFF(int n, int weight[], int value[], int capacity ) {
	if (n == 0) {
		knapSackDP[n][capacity] = 0;
		return 0;
	}

	if (knapSackDP[n][capacity] != -1) {
		return knapSackDP[n][capacity];
	}

	int include = INT_MIN;
	int exclude = INT_MIN;

	// n = 2
	// capacity = 5

	if (capacity >= weight[n - 1]) {
		include = value[n - 1] + knapSackDIFF(n - 1, weight, value, capacity - weight[n - 1]);
	}

	exclude = knapSackDIFF(n - 1, weight, value, capacity);

	int result = max(include, exclude);

	knapSackDP[n][capacity] = result;

	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 8; j++) {
			cout << knapSackDP[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "*******************************" << endl;

	return result;
}

int knapSackPUREDP(int weight[], int value[], int capacity, int n) {

	vector<vector<int> > dp(n + 1, vector<int> (capacity + 1, 0));

	//BASE CASE
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}

	for (int i = 0; i <= capacity; i++) {
		dp[0][i] = 0;
	}

	// all dp states

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= capacity; j++) {
			// RECURSIVE CASE

			int include = INT_MIN;
			int exclude = INT_MIN;

			// j <- capacity reference
			// i <- n reference

			if (j >= weight[i - 1]) {
				include = value[i - 1] + dp[i - 1][j - weight[i - 1]];
			}

			exclude = dp[i - 1][j];

			dp[i][j] = max(include, exclude);
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= capacity; j++) {
			cout << dp[i][j] << "\t";
		}
		cout << endl;
	}

	return dp[n][capacity];
}

int coinChangeiiMemo(int si, vector<int> &coins, int amount, vector<vector<int> > &dp) {
	// BASE CASE
	if (amount == 0) {
		return 1;
	}

	if (si == coins.size()) {
		return 0;
	}

	if (dp[si][amount] != -1) {
		return dp[si][amount];
	}

	// RECURSIVE CASE
	int count = 0;

	if (amount >= coins[si]) {
		count += coinChangeiiMemo(si, coins, amount - coins[si], dp);
	}

	count += coinChangeiiMemo(si + 1, coins, amount, dp);

	dp[si][amount] = count;

	return count;
}

int coinChangeii(int amount, vector<int>& coins) {
	int n = coins.size();

	if (amount == 0) {
		return 1;
	}

	if (n == 0) {
		return 0;
	}

	vector<vector<int> > dp(n + 1, vector<int> (amount + 1, -1));

	return coinChangeiiMemo(0, coins, amount, dp);
}

int coinChangeiiPUREDP(int amount, vector<int>& coins) {
	if (amount == 0) return 1;

	if (coins.size() == 0) return 0;

	int dp[amount + 1] = {0};

	dp[0] = 1;

	for (int coin : coins) {
		for (int i = 1; i <= amount; i++) {
			if (coin <= i) {
				dp[i] += dp[i - coin];
			}
		}
	}

	return dp[amount];
}

// start = 0 end = n
int countBoardPathDIFF(int n, int dp[]) {
	if (n == 0) return 1;

	if (n < 0) return 0;

	if (dp[n] != -1) return dp[n];

	int count = 0;

	for (int dice = 1; dice <= 6; dice++) {
		count += countBoardPathDIFF(n - dice, dp);
	}

	dp[n] = count;

	for (int i = 0; i <= 10; i++) {
		cout << dp[i] << "\t";
	}
	cout << endl << "*************************" << endl;

	return count;
}


int coinChangeImemo(vector<int> &coins, int amount, vector<int> &dp) {
	//BASE CASE
	if (amount == 0) {
		return 0;
	}

	if (amount < 0) {
		return -1;
	}

	if (dp[amount] != -2) {
		return dp[amount];
	}

	// RECURSIVE CASE
	int minValue = INT_MAX;

	for (int coin : coins) {
		int recursionResult = coinChangeImemo(coins, amount - coin, dp);

		if (recursionResult >= 0) {
			minValue = min(minValue, recursionResult + 1);
		}
	}

	// minValue <- INT_MAX

	dp[amount] = minValue == INT_MAX ? -1 : minValue;

	return dp[amount];
}

int coinChange(vector<int>& coins, int amount) {

	vector<int> dp(amount + 1, -2);
	return coinChangeImemo(coins, amount, dp);
}

int coinChangeIPUREDP(vector<int>& coins, int amount) {
	if (amount == 0) {
		return 0;
	}

	int dp[amount + 1];

	for (int i = 0; i <= amount; i++) dp[i] = amount + 1;

	dp[0] = 0;

	for (int i = 1; i <= amount; i++) {
		for (int coin : coins) {
			if (coin <= i) {
				dp[i] = min(dp[i], dp[i - coin] + 1);
			}
		}
	}

	return dp[amount] > amount ? -1 : dp[amount];
}

int onesAndZeros(int si, vector<string> &strs, int m, int n, vector<vector<vector<int>>> &dp) {
	// BASE CASE
	if (si == strs.size()) {
		return 0;
	}

	if (dp[si][m][n] != -1) {
		return dp[si][m][n];
	}

	// RECURSIVE CASE
	int include = 0;

	string curr = strs[si];

	int zeros = 0;
	int ones = 0;

	for (char ch : curr) {
		if (ch == '1') {
			ones++;
		} else {
			zeros++;
		}
	}

	if (ones <= n and zeros <= m) {
		include = onesAndZeros(si + 1, strs, m - zeros, n - ones, dp) + 1;
	}

	int exclude = onesAndZeros(si + 1, strs, m, n, dp);

	int result = max(include, exclude);

	dp[si][m][n] = result;

	return result;
}

int findMaxForm(vector<string>& strs, int m, int n) {

	int len = strs.size();

	vector<vector<vector<int>>> dp(len + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));

	return onesAndZeros(0, strs, m, n, dp);
}


bool isPalindrome(string &str, int left, int right) {
	while (left <= right) {
		if (str[left] != str[right]) {
			return false;
		}
		left++;
		right--;
	}

	return true;
}

int partitioningPalindrome(string &str, int left, int right, vector<vector<int> > &dp) {
	if (left >= right) {
		return 0;
	}

	if (isPalindrome(str, left, right)) {
		dp[left][right] = 0;
		return 0;
	}

	if (dp[left][right] != -1) {
		return dp[left][right];
	}

	int minValue = INT_MAX;

	for (int i = left; i < right; i++) {

		if (isPalindrome(str, left, i)) {
			int rightCuts = partitioningPalindrome(str, i + 1, right, dp);
			int currentCuts = 1 + rightCuts;

			minValue = min(minValue, currentCuts);
		}

	}

	dp[left][right] = minValue;

	return minValue;
}

int minCut(string s) {
	int n = s.length();

	vector<vector<int> > dp(n, vector<int> (n, -1));

	return partitioningPalindrome(s, 0, n - 1, dp);
}

int matrixChainMultiplication(int arr[], int i, int j) {
	if (i >= j) {
		return 0;
	}

	int minCost = INT_MAX;

	for (int x = i; x < j; x++) {

		int leftCost = matrixChainMultiplication(arr, i, x);
		int rightCost = matrixChainMultiplication(arr, x + 1, j);

		int meriCost = leftCost + arr[i - 1] * arr[x] * arr[j] + rightCost;

		minCost = min(minCost, meriCost);
	}

	return minCost;
}

int MOD = 1e9 + 7;
int restoreArray(int si, string &str, int k, vector<int> &dp) {
	if (si == str.length()) {
		return 1;
	}

	if (str[si] == '0') {
		return 0;
	}

	if (dp[si] != -1) {
		return dp[si];
	}

	int count = 0;

	long val = 0;

	for (int i = si; i < str.length(); i++) {
		char ch = str[i];

		int num = ch - '0';

		val = val * 10. + num;

		if (val > k) {
			break;
		}

		int recursionResult = restoreArray(i + 1, str, k, dp);
		count = (count + recursionResult) % MOD;
	}

	dp[si] = count;

	return count;
}

int numberOfArrays(string s, int k) {
	int n = s.length();

	vector<int> dp(n + 1, -1);

	return restoreArray(0, s, k, dp);
}


int combinationSumIVHelper(vector<int> &nums, int target, vector<int> &dp) {

	if (target == 0) return 1;

	if (dp[target] != -1) return dp[target];

	int count = 0;

	for (int num : nums) {
		if (num <= target) {
			count += combinationSumIVHelper(nums, target - num, dp);
		}
	}

	dp[target] = count;
	return count;
}

int combinationSumIVMemo(vector<int>& nums, int target) {

	vector<int> dp(target + 1, -1);

	return combinationSumIVHelper(nums, target, dp);
}

int combinationSumIVPUREDP(vector<int>& nums, int target) {
	vector<unsigned int> dp(target + 1, 0);

	dp[0] = 1;

	for (int currTarget = 1; currTarget <= target; currTarget++) {
		for (int num : nums) {
			if (num <= currTarget) {
				dp[currTarget] += dp[currTarget - num];
			}
		}
	}

	return dp[target];
}



int minInsertionsMemo(string &str, int left, int right, vector<vector<int> > &dp) {
	// if(left>right) return INT_MAX;

	if (left >= right) return 0;

	if (dp[left][right] != -1) return dp[left][right];

	int result = INT_MAX;

	if (str[left] == str[right]) {

		result = minInsertionsMemo(str, left + 1, right - 1, dp);

	} else {

		int first = minInsertionsMemo(str, left + 1, right, dp);
		int second = minInsertionsMemo(str, left, right - 1, dp);

		result = min(first, second) + 1;
	}

	dp[left][right] = result;

	return result;
}

int minInsertions(string s) {

	vector<vector<int> > dp(s.length(), vector<int> (s.length(), -1));

	return minInsertionsMemo(s, 0, s.length() - 1, dp);
}

int minInsertionsPUREDP(string s) {
	if (s.length() == 0 or s.length() == 1) return 0;

	vector<vector<int> > dp(s.length(), vector<int> (s.length(), 0));

	for (int col = 1; col <= s.length() - 1; col++) {
		for (int row = col - 1; row >= 0; row--) {
			if (s[row] == s[col]) {
				dp[row][col] = dp[row + 1][col - 1];
			} else {
				dp[row][col] = min(dp[row + 1][col], dp[row][col - 1]) + 1;
			}
		}
	}

	return dp[0][s.length() - 1];
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

	// cout << longestCommonSubsequenceMemo("abcde", "afpcd") << endl;

	// cout << numDistinct("bbagg", "bag") << endl;

	// int value[] = {50, 40, 70, 40};
	// int weight[] = {5, 4, 6, 3};
	// int capacity = 8;
	// int n = 4;

	// memset(knapSackDP, -1, sizeof(knapSackDP));
	// cout << knapSack(0, weight, value, capacity, n) << endl;
	// cout << knapSackDIFF(n, weight, value, capacity) << endl;
	// cout << knapSackPUREDP(weight, value, capacity, n) << endl;

	// int n = 10;
	// int dp[n + 1];
	// memset(dp, -1, sizeof(dp));
	// countBoardPathDIFF(n, dp);

	// int arr[] = {40, 20, 30, 10, 30};
	// int n = 5;

	// cout << matrixChainMultiplication(arr, 1, n - 1) << endl;

	return 0;
}