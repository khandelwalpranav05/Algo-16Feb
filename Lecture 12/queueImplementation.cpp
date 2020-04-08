#include <iostream>
#include <list>

using namespace std;

template <typename T>
class Queue {
	list<T> storage;

public:
	// Queue(){}
	void push(T data) {
		this->storage.push_back(data);
	}

	void pop() {
		this->storage.pop_front();
		// storage.pop_back();
	}

	T front() {
		return this->storage.front();
	}

	int size() {
		return this->storage.size();
	}

	bool empty() {
		return this->storage.empty();
	}
};

int main() {

	Queue<int> q;

	q.push(2);
	q.push(5);
	q.push(7);
	q.push(45);

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

	return 0;
}