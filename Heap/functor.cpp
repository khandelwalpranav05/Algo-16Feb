#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Compare {
public:
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main() {

	// Compare p;
	// cout << p(1, 2) << endl;

	priority_queue<int, vector<int>, Compare> pq;

	// Compare c;
	// c(45, 15);

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