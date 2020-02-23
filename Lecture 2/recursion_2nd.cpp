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

string removeDuplicates(string str) {
	if (str.length() == 0) {
		return str;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = removeDuplicates(ros);

	if (recursionResult[0] == ch) {
		return recursionResult;
	} else {
		return ch + recursionResult;
	}
}

string addStarBetweenDuplicates(string str) {
	if (str.length() == 0) return str;

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = addStarBetweenDuplicates(ros);

	if (recursionResult[0] == ch) {
		// return ch + string("*") + recursionResult;

		recursionResult = '*' + recursionResult;
		return ch + recursionResult;
	} else {
		return ch + recursionResult;
	}
}

string moveXToEnd(string str) {
	if (str.length() == 0) return str;

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = moveXToEnd(ros);

	if (ch == 'x') {
		return recursionResult + ch;
	} else {
		return ch + recursionResult;
	}
}

string replacePi(string str) {
	if (str.length() == 0) return str;

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = replacePi(ros);

	if (ch == 'p' and recursionResult[0] == 'i') {
		return "3.14" + recursionResult.substr(1);

	} else {
		return ch + recursionResult;
	}
}

void printSubsequence(string str, string ans) {
	if (str.length() == 0) {
		cout << "" << endl;
		// cout << ans << endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	printSubsequence(ros, ans + ch);
	printSubsequence(ros, ans);
}

void printPermutations(string str, string ans) {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];

		string ros = str.substr(0, i) + str.substr(i + 1);

		printPermutations(ros, ans + ch);
	}
}

// string code[] = {" ", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printBoardPath(int start, int end, string path) {
	if (start == end) {
		cout << path << endl;
		return;
	}

	if (start > end) {
		return;
	}

	for (int dice = 1; dice <= 6; dice++) {
		char ch = dice + '0';
		printBoardPath(start + dice, end, path + ch);
	}
}

void printMazePath(int sr, int sc, int er, int ec, string path) {
	if (sr == er and sc == ec) {
		cout << path << endl;
		return;
	}

	if (sr > er or sc > ec) {
		return;
	}

	printMazePath(sr + 1, sc, er, ec, path + "V->");
	printMazePath(sr, sc + 1, er, ec, path + "H->");
}

int main() {

	// cout << removeDuplicates("abbccdggf") << endl;

	// cout << addStarBetweenDuplicates("hhelloo") << endl;

	// cout << moveXToEnd("xabcxxyx") << endl;

	// cout << replacePi("xxpiipixxppix") << endl;

	// printSubsequence("abc", "");

	// printPermutations("abc", "");

	printBoardPath(0, 3, "");

	printMazePath(0, 0, 2, 2, "");

	return 0;
}