#include <iostream>

using namespace std;

// char *a = new char[23];

template <typename T>
class Stack {
// public: // 2
	T *arr;
	int top;
	int maxSize;

public: // 1
	Stack(int capacity = 5) {
		this->maxSize = capacity;
		this->arr = new T[this->maxSize];
		this->top = -1;
	}

	// Stack() {
	// 	this->arr = new int[5];
	// 	this->top = -1;
	// }

	void push(T data) {
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

	T getTop() {
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

	Stack<char> s;

	s.push('A');
	s.push('C');
	s.push('R');
	s.push('T');

	cout << s.size() << endl;

	s.pop();

	// s.push("khandelwal");
	// s.push(67.89);

	cout << s.getTop() << endl;

	// Stack<int> s;

	// s.push(3);
	// s.push(2);
	// s.push(45);
	// s.push(37);
	// s.push(9);

	// s.push(789);

	// s.pop();
	// s.pop();

	// cout << s.size() << endl;

	// s.pop();

	// cout << s.getTop() << endl;

	// s.pop();
	// s.pop();
	// s.pop();

	// cout << s.empty() << endl;

	// vector<int> v;
	// vector<char> v;
	// vector<string> v;

	return 0;
}