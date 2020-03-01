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

int countMazePathDia(int sr, int sc, int er, int ec) {
	if (sr == er and sc == ec) {
		return 1;
	}

	if (sr > er or sc > ec) {
		return 0;
	}

	int horizontal = countMazePathDia(sr, sc + 1, er, ec);
	int vertical = countMazePathDia(sr + 1, sc, er, ec);
	int diagonal = countMazePathDia(sr + 1, sc + 1, er, ec);

	int total = horizontal + vertical + diagonal;
	return total;
}

int reduceToOne(int n) {
	if (n == 1) return 0;

	int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

	if (n % 2 == 0) {
		count2 = 1 + reduceToOne(n / 2);
	}

	if (n % 3 == 0) {
		count3 = 1 + reduceToOne(n / 3);
	}

	count1 = 1 + reduceToOne(n - 1);

	int minOp = min(count1, min(count2, count3));

	return minOp;
}

string code[] = {" ", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypad(string str, string ans) {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string key = code[ch - '0'];

	for (int i = 0; i < key.length(); i++) {
		printKeypad(ros, ans + key[i]);
	}
}

bool isPossible(int si, vector<int> &nums, int sum, int total) {
	if (sum == total) return true;

	if (sum > total or si == nums.size()) {
		return false;
	}

	bool include = isPossible(si + 1, nums, sum + nums[si], total);
	bool exclude = isPossible(si + 1, nums, sum, total);

	if (include or exclude) {
		return true;
	}

	return false;
}

bool canPartition(vector<int>& nums) {
	int total = 0;

	for (int i = 0; i < nums.size(); i++) {
		total += nums[i];
	}

	if (total % 2 == 1) return false;

	total = total / 2;

	return isPossible(0, nums, 0, total);
}

int numSquares(int n) {
	if (n == 0) {
		return 0;
	}

	int minValue = INT_MAX;

	for (int i = 1; i * i <= n; i++) {
		int abhiTakKaAnswer = numSquares(n - i * i);
		minValue = min(abhiTakKaAnswer, minValue);
	}

	return minValue + 1;
}

int powerBetter(int n, int p) {
	if (p == 0) return 1;

	int powerby2 = powerBetter(n, p / 2);

	if (p % 2) {
		return powerby2 * powerby2 * n;
	} else {
		return powerby2 * powerby2;
	}
}

void mappedString(string str, string ans) {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	char ch1 = str[0];
	string ros1 = str.substr(1);

	int ch1_int = ch1 - '0';

	ch1 = ch1 + 16;

	mappedString(ros1, ans + ch1);

	if (str.length() > 1) {

		char ch2 = str[1];

		int ch2_int = ch2 - '0';

		int num = ch1_int * 10 + ch2_int;

		if (num <= 26) {
			string ros2 = str.substr(2);

			ch2 = num + 64;

			mappedString(ros2, ans + ch2);
		}
	}

}

int helper(int si, vector<int> &nums, int sum, int S) {
	if (si == nums.size()) {
		if (sum == S) {
			return 1;
		} else {
			return 0;
		}
	}

	int positive = helper(si + 1, nums, sum + nums[si], S);
	int negative = helper(si + 1, nums, sum - nums[si], S);

	int total = positive + negative;

	return total;
}

int main() {

	// cout << countMazePathDia(0, 0, 2, 2) << endl;

	// cout << reduceToOne(10) << endl;

	// printKeypad("234", "");

	// cout << powerBetter(2, 8) << endl;

	mappedString("123", "");

	return 0;
}