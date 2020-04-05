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

bool balancedParathesis(string str) {

	stack<char> s;

	for (int i = 0; i < str.length(); i++) {

		char ch = str[i];

		if (ch == '(') {
			s.push(ch);
		} else {

			if (s.empty()) {
				return false;
			}

			s.pop();
		}
	}

	// if (s.empty()) {
	// 	return true;
	// } else {
	// 	false;
	// }
	return s.empty();
}

bool isDuplicate(string str) {

	stack<char> s;

	for (int i = 0; i < str.length(); i++) {

		char ch = str[i];

		if (ch != ')') {
			s.push(ch);
		} else {
			if (s.top() == '(') {
				return true;
			}

			while (s.top() != '(') {
				s.pop();
			}
			s.pop();
		}
	}

	return false;
}

void nextGreater(int arr[], int n) {

	stack<int> s;

	for (int i = 0; i < n; i++) {

		while (!s.empty() and s.top() < arr[i]) {
			int temp = s.top();
			s.pop();

			cout << temp << "->" << arr[i] << endl;
		}

		s.push(arr[i]);
	}

	while (!s.empty()) {
		int temp = s.top();
		s.pop();

		cout << temp << "->" << -1 << endl;
	}
}

int main() {

	int arr[] = {59, 8, 7, 12, 2, 14};
	int n = 6;

	nextGreater(arr, n);

	return 0;
}