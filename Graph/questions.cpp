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

int findJudge(int N, vector<vector<int>>& trust) {
	unordered_map<int, int> inDegree;
	unordered_map<int, int> outDegree;

	for (auto val : trust) {
		inDegree[val[1]]++;
		outDegree[val[0]]++;
	}

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == N - 1 and outDegree[i] == 0) {
			return i;
		}
	}

	return -1;
}

int n;
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

	n = graph.size();
	unordered_map<int, vector<int>> adjList;

	for (int i = 0; i < graph.size(); i++) {
		int u = i;
		for (int v : graph[i]) {
			adjList[u].push_back(v);
		}
	}

	vector<vector<int>> res;
	vector<int> temp;

	dfs(0, adjList, temp, res);

	return res;
}

void dfs(int node, unordered_map<int, vector<int>> adjList, vector<int> temp, vector<vector<int>> &res) {
	if (node == n - 1) {
		temp.push_back(node);
		res.push_back(temp);
		return;
	}

	temp.push_back(node);

	for (int neighbor : adjList[node]) {
		dfs(neighbor, adjList, temp, res);
	}
}

int numIslands(vector<vector<char>>& grid) {
	int n = grid.size();
	if (n == 0) return 0;

	int m = grid[0].size();
	if (m == 0) return 0;

	int islands = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '1') {
				islands++;
				dfsHelper(grid, i, j);
			}
		}
	}

	return islands;
}

void dfsHelper(vector<vector<char>>& grid, int i, int j) {
	int n = grid.size();
	int m = grid[0].size();

	if (i<0 or i >= n or j<0 or j >= m or grid[i][j] == '0') {
		return;
	}

	grid[i][j] = '0';
	dfsHelper(grid, i + 1, j);
	dfsHelper(grid, i, j + 1);
	dfsHelper(grid, i, j - 1);
	dfsHelper(grid, i - 1, j);
}

int orangesRotting(vector<vector<int>>& grid) {
	int n = grid.size();
	if (n == 0) return 0;

	int m = grid[0].size();
	if (m == 0) return 0;

	queue<pair<int, int>> q;

	int ones = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 2) {
				q.push({i, j});
			} else if (grid[i][j] == 1) {
				ones++;
			}
		}
	}

	if (ones == 0) {
		return 0;
	}

	if (q.empty()) {
		return -1;
	}

	int x[] = {1, 0, -1, 0};
	int y[] = {0, 1, 0, -1};

	int minutes = -1;

	while (!q.empty()) {

		int len = q.size();

		for (int i = 0; i < len; i++) {
			auto temp = q.front();
			q.pop();

			int row = temp.first;
			int col = temp.second;

			for (int k = 0; k < 4; k++) {
				int r = row + x[k];
				int c = col + y[k];

				if (r >= 0 and r<n and c >= 0 and c < m and grid[r][c] == 1) {
					grid[r][c] = 2;
					q.push({r, c});
				}
			}
		}

		minutes++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1) {
				return -1;
			}
		}
	}

	return minutes;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

	vector<int> res;
	if (n == 1) {
		res.push_back(0);
		return res;
	}

	unordered_map<int, vector<int>> adjList;
	vector<int> indegree(n, 0);

	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];

		adjList[u].push_back(v);
		adjList[v].push_back(u);

		indegree[u]++;
		indegree[v]++;
	}

	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (indegree[i] == 1) {
			q.push(i);
		}
	}


	while (!q.empty()) {

		res.clear();

		int len = q.size();

		for (int i = 0; i < len; i++) {
			int node = q.front();
			q.pop();

			res.push_back(node);

			for (int neighbor : adjList[node]) {
				indegree[neighbor]--;

				if (indegree[neighbor] == 1) {
					q.push(neighbor);
				}
			}
		}

	}

	return res;
}

int main() {


	return 0;
}