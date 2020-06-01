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


bool jumpGameIII(vector<int> &arr, int idx, unordered_set<int> &visited) {
	if (visited.count(idx)) {
		return false;
	}

	visited.insert(idx);

	if (arr[idx] == 0) {
		return true;
	}

	bool left = false;
	bool right = false;

	if (idx + arr[idx] < arr.size()) {
		left = jumpGameIII(arr, idx + arr[idx], visited);
	}

	if (idx - arr[idx] >= 0) {
		right = jumpGameIII(arr, idx - arr[idx], visited);
	}

	return left or right;
}

bool canReach(vector<int>& arr, int start) {

	unordered_set<int> visited;

	return jumpGameIII(arr, start, visited);
}


bool CourseSchedule(int numCourses, vector<vector<int>>& prerequisites) {

	unordered_map<int, vector<int> > adjList;

	vector<int> indegree(numCourses, 0);

	for (auto val : prerequisites) {
		adjList[val[1]].push_back(val[0]);
		indegree[val[0]]++;
	}

	queue<int> q;

	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		for (int neighbor : adjList[node]) {
			indegree[neighbor]--;

			if (indegree[neighbor] == 0) {
				q.push(neighbor);
			}
		}

	}

	for (int val : indegree) {
		if (val) {
			return false;
		}
	}

	return true;
}

vector<int> CourseScheduleII(int numCourses, vector<vector<int>>& prerequisites) {
	unordered_map<int, vector<int> > adjList;

	vector<int> indegree(numCourses, 0);

	for (auto val : prerequisites) {
		adjList[val[1]].push_back(val[0]);
		indegree[val[0]]++;
	}

	queue<int> q;

	vector<int> res;

	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
			res.push_back(i);
		}
	}

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		for (int neighbor : adjList[node]) {
			indegree[neighbor]--;

			if (indegree[neighbor] == 0) {
				q.push(neighbor);
				res.push_back(neighbor);
			}
		}

	}

	for (int val : indegree) {
		if (val) {
			res.clear();
			return res;
		}
	}

	return res;
}


vector<vector<int>> maxtrix01(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<int> > res(n, vector<int> (m, INT_MAX));

	queue<pair<pair<int, int>, int> > q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				res[i][j] = 0;
				q.push({{i, j}, 0});
			}
		}
	}

	int x[] = {1, 0, -1, 0};
	int y[] = {0, 1, 0, -1};

	while (!q.empty()) {

		auto temp = q.front();
		q.pop();

		int row = temp.first.first;
		int col = temp.first.second;
		int dist = temp.second;

		for (int i = 0; i < 4; i++) {
			int r = row + x[i];
			int c = col + y[i];

			if (r >= 0 and c >= 0 and r < n and c < m and res[r][c] == INT_MAX) {
				res[r][c] = 1 + dist;
				q.push({{r, c}, dist + 1});
			}
		}
	}

	return res;
}

void helper(int root, unordered_map<int, vector<int> > &adjList, unordered_set<int> &visited) {
	if (visited.count(root)) {
		return;
	}

	visited.insert(root);

	for (int neighbor : adjList[root]) {
		helper(neighbor, adjList, visited);
	}
}

bool keysAndRoom(vector<vector<int>>& rooms) {

	unordered_map<int, vector<int> > adjList;

	for (int i = 0; i < rooms.size(); i++) {
		for (int val : rooms[i]) {
			adjList[i].push_back(val);
		}
	}

	unordered_set<int> visited;

	helper(0, adjList, visited);

	if (visited.size() == rooms.size()) {
		return true;
	}

	return false;
}

int main() {


	return 0;
}