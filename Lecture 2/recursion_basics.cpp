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

int main() {

	// cout << sumTillN(5) << endl;

	cout << factorial(5) << endl;

	return 0;
}