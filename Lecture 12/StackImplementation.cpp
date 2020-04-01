#include <iostream>

using namespace std;

class Stack {
// public: // 2
	int *arr;
	int top;
	int maxSize;

public: // 1
	Stack(int capacity = 5) {
		this->maxSize = capacity;
		this->arr = new int[this->maxSize];
		this->top = -1;
	}

	// Stack() {
	// 	this->arr = new int[5];
	// 	this->top = -1;
	// }

	void push(int data) {
		if (this->top == this->maxSize - 1) {
			cout << "Stack is full" << endl;
			return;
		}

		this->top++;
		this->arr[this->top] = data;
	}

	void pop() {
		if (this->top == -1) {
			cout << "Stack is empty" << endl;
			return;
		}

		this->top--;
	}

	int getTop() {
		return this->arr[this->top];
	}

	int size() {
		return this->top + 1;
	}

	bool empty() {
		// if (this->size() == 0) {
		// 	return true;
		// } else {
		// 	return false;
		// }

		return this->size() == 0;
	}
};

int main() {

	Stack s;

	s.push(3);
	s.push(2);
	s.push(45);
	s.push(37);
	s.push(9);

	s.push(789);

	s.pop();
	s.pop();

	cout << s.size() << endl;

	s.pop();

	cout << s.getTop() << endl;

	s.pop();
	s.pop();
	s.pop();

	cout << s.empty() << endl;

	return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// #include <climits>
// #include <algorithm>
// #include <cmath>
// #include <bitset>
// #include <cstdio>
// #include <cstring>
// #include <stack>
// #include <iomanip>
// #include <set>
// #include <map>

// using namespace std;

// void display(vector<int> v) {

// 	for (int i = 0; i < v.size(); i++) {
// 		cout << v[i] << " ";
// 	}
// 	cout << endl;
// }

// void subsets(int si, vector<int> nums, vector<int> temp) {
// 	if (si == nums.size()) {
// 		display(temp);
// 		return;
// 	}

// 	// Add Karo
// 	temp.push_back(nums[si]);
// 	subsets(si + 1, nums, temp);

// 	// mat Karo
// 	temp.pop_back();
// 	subsets(si + 1, nums, temp);

// }

// void helper(int si, vector<int> nums, vector<int> temp) {
// 	display(temp);

// 	for (int i = si; i < nums.size(); i++) {
// 		temp.push_back(nums[i]);
// 		helper(i + 1, nums, temp);
// 		temp.pop_back();
// 	}
// }

// int main() {

// 	vector<int> v; // dynamic array

// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);

// 	vector<int> temp;
// 	// subsets(0, v, temp);

// 	helper(0, v, temp);

// 	return 0;
// }