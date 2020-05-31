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

void performUnion(int parent[], int a, int b) {
	if (abs(parent[a]) > abs(parent[b])) {
		parent[a] += parent[b];
		parent[b] = a;
	} else {
		parent[b] += parent[a];
		parent[a] = b;
	}
}

int find(int parent[], int a) {
	if (parent[a] < 0) {
		return a;
	}

	return find(parent, parent[a]);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	int n = edges.size();

	int parent[n + 1];
	memset(parent, -1, sizeof(parent));

	for (auto val : edges) {

		int u = val[0];
		int v = val[1];

		int a = find(parent, u);
		int b = find(parent, v);

		if (a == b) {
			return val;
		}

		performUnion(parent, a, b);
	}

	vector<int> res;
	return res;
}


int findCircleNum(vector<vector<int>>& M) {
	int n = M.size();
	if (n == 0) return 0;

	int parent[n];
	memset(parent, -1, sizeof(parent));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (M[i][j]) {
				int a = find(parent, i);
				int b = find(parent, j);

				if (a != b) {
					performUnion(parent, a, b);
				}
			}
		}
	}

	int count  = 0;

	for (int i = 0; i < n; i++) {
		if (parent[i] < 0) {
			count++;
		}
	}

	return count;
}

bool myCompare(vector<int> &a, vector<int> &b) {
	return a[2] < b[2];
}

int commutableIslands(int A, vector<vector<int> > &B) {

	int parent[A + 1];
	memset(parent, -1, sizeof(parent));

	sort(B.begin(), B.end(), myCompare);

	int totalCost = 0;

	for (auto val : B) {

		int u = val[0];
		int v = val[1];
		int cost = val[2];

		int a = find(parent, u);
		int b = find(parent, v);

		if (a != b) {
			totalCost += cost;
			performUnion(parent, a, b);
		}
	}

	return totalCost;
}

int main() {


	return 0;
}