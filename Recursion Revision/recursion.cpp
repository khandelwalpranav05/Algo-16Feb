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

void printDecreasing(int n) {
	if (n == 0) {
		return;
	}

	cout << n << endl;
	printDecreasing(n - 1);
}

int power(int n, int p) {
	if (p == 0) return 1;

	int subProblem = power(n, p - 1);
	int ans = n * subProblem;
	return ans;
}

int linearSearch(int si, int arr[], int n, int key) {
	if (si == n) {
		return -1;
	}

	if (arr[si] == key) {
		return si;
	} else {
		return linearSearch(si + 1, arr, n, key);
	}
}

bool isSorted(int si, int arr[], int n) {
	if (si == n - 1) return true;

	if (arr[si] > arr[si + 1]) {
		return false;
	} else {
		bool isMySubproblemSorted = isSorted(si + 1, arr, n);
		return isMySubproblemSorted;
	}
}

string removeDuplicate(string str) {
	if (str.length() == 0) {
		// return "";
		return str;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = removeDuplicate(ros);

	if (ch == recursionResult[0]) {
		return recursionResult;
	} else {
		return ch + recursionResult;
	}
}

void printSubsequence(string str, string subseq = "") {
	if (str.length() == 0) {
		cout << subseq << endl;
		return;
	}

	char ch = str[0];
	string subProblemString = str.substr(1);

	printSubsequence(subProblemString, subseq);
	printSubsequence(subProblemString, subseq + ch);

}

int perfectSquare(int n) {
	if (n == 0) return 0;

	int minValue = INT_MAX;

	for (int i = 1; i * i <= n; i++) {
		int abhiTakKaAnswer = perfectSquare(n - i * i) + 1;
		minValue = min(minValue, abhiTakKaAnswer);
	}

	return minValue;
}

int main() {

	// cout << power(2, 5) << endl;

	// int arr[] = {4, 5, 3, 2, 4, 6, 7};
	// int n = 7;
	// int key = 2;

	// cout << linearSearch(0, arr, n, key) << endl;

	// int arr[] = {1, 2, 3, 14, 5, 6, 7};
	// int n = 7;

	// cout << isSorted(0, arr, n) << endl;

	// cout << removeDuplicate("aabccdeeh") << endl;

	// printSubsequence("abc");

	cout << perfectSquare(12) << endl;

	return 0;
}