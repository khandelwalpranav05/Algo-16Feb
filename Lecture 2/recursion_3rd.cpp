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

void printKeypad(string str) {

}

int main() {

	// cout << countMazePathDia(0, 0, 2, 2) << endl;

	cout << reduceToOne(10) << endl;
	return 0;
}