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


int connectSticks(vector<int>& sticks) {

	priority_queue<int, vector<int>, greater<int> > pq;

	for (int val : sticks) {
		pq.push(val);
	}

	int sum = 0;

	while (pq.size() > 1) {
		int first = pq.top();
		pq.pop();

		int second = pq.top();
		pq.pop();

		int val = first + second;
		sum += val;
		pq.push(val);
	}

	return sum;
}

int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < k; i++) {
		pq.push(nums[i]);
	}

	for (int i = k; i < nums.size(); i++) {
		if (nums[i] > pq.top()) {
			pq.pop();
			pq.push(nums[i]);
		}
	}

	return pq.top();
}

class Compare {
public:
	bool operator()(vector<int> &a, vector<int> &b) {
		int x = a[0] * a[0] + a[1] * a[1];
		int y = b[0] * b[0] + b[1] * b[1];

		return x < y;
	}
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	priority_queue< vector<int>, vector< vector<int> >, Compare> pq;

	vector<vector<int>> res;

	for (vector<int> point : points) {
		pq.push(point);
	}

	while (pq.size() > K) {
		pq.pop();
	}

	while (!pq.empty()) {
		res.push_back(pq.top());
		pq.pop();
	}

	return res;
}

int main() {



	return 0;
}