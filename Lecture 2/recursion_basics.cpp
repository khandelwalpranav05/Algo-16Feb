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

int sumTillN(int n) {
	// BASE CASE
	if (n == 1) {
		return 1;
	}

	// Recursive Case
	int recResult = sumTillN(n - 1);
	int total = recResult + n;

	return total;
}

int factorial(int n) {
	if (n == 0) {
		return 1;
	}

	int facn1 = factorial(n - 1);
	int total = facn1 * n;

	return total;
}

int power(int n, int p) {
	if (p == 0) {
		return 1;
	}

	int powen1 = power(n, p - 1);

	int total = powen1 * n;

	return total;
}

void printDecreasing(int n) {
	if (n == 1) {
		cout << n << endl;
		return;
	}

	cout << n << endl;

	printDecreasing(n - 1);
}

void printIncreasing(int n) {
	if (n == 1) {
		cout << n << endl;
		return;
	}

	printIncreasing(n - 1);

	cout << n << endl;
}

void printDecInc(int n) {
	if (n == 0) {
		return;
	}

	cout << n << endl;

	printDecInc(n - 1);

	cout << n << endl;
}

int linearSearch(int arr[], int si, int n, int data) {
	if (si == n) {
		return -1;
	}

	if (arr[si] == data) {
		return si;
	} else {
		int rescursionResult = linearSearch(arr, si + 1, n, data);
		return rescursionResult;
	}
}

bool isSorted(int arr[], int si, int n) {

}

int main() {

	// cout << sumTillN(5) << endl;

	// cout << factorial(5) << endl;

	// cout << power(2, 5) << endl;

	// printDecreasing(5);

	// printIncreasing(5);

	// printDecInc(5);

	int arr[] = {5, 3, 2, 6, 8, 9, 10};
	int n = 7;
	int data = 8;

	cout << linearSearch(arr, 0, n, data) << endl;

	return 0;
}