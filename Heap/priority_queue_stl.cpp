#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	priority_queue<int, vector<int> > pq;

	pq.push(45);
	pq.push(5);
	pq.push(43);
	pq.push(15);
	pq.push(89);

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}