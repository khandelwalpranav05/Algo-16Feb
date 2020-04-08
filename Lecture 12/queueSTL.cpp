#include <iostream>
#include <queue>

using namespace std;

int main() {

	// queue<int> q;

	// q.push(2);
	// q.push(5);
	// q.push(7);
	// q.push(45);

	// while (!q.empty()) {
	// 	cout << q.front() << endl;
	// 	q.pop();
	// }

	// cout << q.empty() << endl;

	deque<int> dq;

	dq.push_back(12);
	dq.push_back(13);
	dq.push_back(14);
	dq.push_back(15);

	cout << dq.at(2) << endl;

	dq[2] = 678;

	cout << dq.at(2) << endl;

	return 0;
}