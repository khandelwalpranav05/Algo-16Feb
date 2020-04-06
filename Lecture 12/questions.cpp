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

void stockSpan(int arr[], int n) {

	stack<int> s;

	for (int i = 0; i < n; i++) {

		while (!s.empty() and arr[s.top()] <= arr[i]) {
			s.pop();
		}

		if (s.empty()) {
			cout << arr[i] << " -> " << i + 1 << endl;
		} else {

			int idx = s.top();

			int diff = i - idx;
			cout << arr[i] << " -> " << diff << endl;
		}

		s.push(i);
	}
}

void nextSmaller(int arr[], int n) {
	//TODO
	//INDEX

	int brr[n];

	for (int i = 0; i < n; i++) {
		//brr;
	}
}
//.        0 1  2 3 4  5
// input[] 2 3  1 5 6  2
// outpu[] 1 1 -1 2 2 -1

int histogramArea(int arr[], int n) {

	stack<int> s;

	int maxArea = INT_MIN;

	int i = 0;

	while (i < n) {

		if (s.empty() or arr[s.top()] <= arr[i]) {
			s.push(i);
			i++;
		} else {

			int extractedTop = s.top();
			s.pop();

			int height = arr[extractedTop];

			int currArea;

			if (s.empty()) {
				currArea = height * i;
			} else {
				currArea = height * (i - s.top() - 1);
			}

			maxArea = max(currArea, maxArea);
		}
	}

	while (!s.empty()) {

		int extractedTop = s.top();
		s.pop();

		int height = arr[extractedTop];
		int currArea;

		if (s.empty()) {
			currArea = height * i;
		} else {
			currArea = height * (i - s.top() - 1);
		}

		maxArea = max(currArea, maxArea);
	}

	return maxArea;
}

int main() {

	// int arr[] = {59, 8, 7, 12, 2, 14};
	// int n = 6;

	// nextGreater(arr, n);

	// int arr[] = {100, 80, 60, 70, 60, 75, 85};
	// int n = 7;

	// stockSpan(arr, n);

	int arr[] = {6, 2, 5, 4, 5, 1, 6};
	int n = 7;

	cout << histogramArea(arr, n) << endl;

	return 0;
}